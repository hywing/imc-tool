#include "main_window.h"
#include "./ui_main_window.h"

#include <QThread>
#include <QMessageBox>
#include <QDebug>
#include <QtConcurrent>

ulong g_errCnt = 0;
void IsError(IMC_STATUS status)
{
    if(status == IMC_FIFO_FULL)
    {

    }
    else
    {
        g_errCnt ++;
        if(g_errCnt > 100)
        {
            QMessageBox::about(NULL, "warning", "Communication is unstable!");
            g_errCnt = 0;
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_Handle(nullptr)
    , m_netid(0)
    , m_imcid(0)
    , m_pos(0)
    , m_first(-540000)
    , m_velocity(4500000)
{
    ui->setupUi(this);

    init();
}

MainWindow::~MainWindow()
{
    closeIMC();

    if(m_timeID)
        killTimer(m_timeID);
    m_timeID = 0;
    delete ui;
}

void MainWindow::init()
{
    // net card
    ui->netid->clear();

    int max = 0;
    NIC_INFO info;
    IMC_STATUS Status;
    int i, num;
    Status = IMC_FindNetCard(&info, &num);

    if(Status == IMC_OK) {
        for(i=0; i < num; i++) {
            ui->netid->addItem(info.description[i]);
            int w = QFontMetrics(this->font()).width(info.description[i]);
            if(max < w)
                max = w;
        }
    }
    else {
        qDebug() << "Find Net Card Error : " << Status;
        QMessageBox::information(this, "error", QString("Find Net Card Error : %1").arg(Status));
    }

    if(ui->netid->count() > 0) {
        ui->netid->setCurrentIndex(0);
    }

    ui->netid->setFixedWidth(max + 5);

    // imc id
    for(int i = 0; i < 64; i++) {
        ui->imcid->addItem(QString::number(i));
    }

    for(int i = 0; i < 16; i++) {
        m_encp[i] = 0;
        m_curpos[i] = 0;
    }

    // axis
    this->m_axis = ui->axis->currentIndex();

    connect(ui->connectMotor, &QPushButton::clicked, this, [=]() {
        if(openIMC() && ui->connectMotor->text() == "Connect Motor") {
            setConnectMotorFlag(true);
        }
        else {
            setConnectMotorFlag(false);
        }
    });

    connect(ui->netid, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int id) {
        this->m_netid = id;
    });

    connect(ui->imcid, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int id) {
        this->m_imcid = id;
    });

    connect(ui->axis, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        this->m_axis = index;
    });

    connect(ui->pos, &QLineEdit::textChanged, this, [=](const QString &text) {
        this->m_pos = text.toInt();
    });

    this->m_velocity = ui->velocity->text().toInt();
    connect(ui->velocity, &QLineEdit::textChanged, this, [=](const QString &text) {
        this->m_velocity = text.toInt();
        IMC_SetParam32(m_Handle, mcsmaxvelLoc, this->m_velocity, m_axis, FIFO_SEL::SEL_IFIFO);
    });

    connect(ui->run, &QPushButton::clicked, this, [=]() {
        MoveAbs(m_pos, m_axis);
        WaitMoved(m_axis);
    });

    connect(ui->pause, &QPushButton::clicked, this, [=]() {
        this->StopPos2Pos(m_axis);
    });

    connect(ui->terminate, &QPushButton::clicked, this, [=]() {
        this->PosEmstop(m_axis);
    });

    connect(ui->find, &QPushButton::clicked, this, [=]() {
        IMC16 direction, RiseEdge, stop, useI;
        direction = ui->direction->currentIndex();
        RiseEdge = stop = useI = 0;
        IMC_SetParam32(m_Handle, homeposLoc, 0, m_axis, SEL_IFIFO);
        SetHomeVel(200000, 100000, SEL_IFIFO);
        FindHome(direction, RiseEdge, stop, useI,  m_axis);
    });

    connect(ui->stop, &QPushButton::clicked, this, [=]() {
        IMC_SetParam16(m_Handle, gohomeLoc, 0, m_axis, SEL_IFIFO);
    });

    connect(ui->set, &QPushButton::clicked, this, [=]() {
        IMC_SetParam16(m_Handle, gohomeLoc, 0, m_axis, SEL_IFIFO);
        IMC_SetParam32(m_Handle, homeposLoc, 0, m_axis, SEL_IFIFO);
        IMC_SetParam16(m_Handle, sethomeLoc, -1, m_axis, SEL_IFIFO);
    });

    this->m_first = ui->first->text().toInt();
    connect(ui->first, &QLineEdit::textChanged, this, [=](const QString &text) {
        this->m_first = text.toInt();
    });

    connect(ui->setChannels, &QPushButton::clicked, this, [=]() {
        int gap = ui->gap->text().toInt();
        this->m_angles[0] = this->m_first;
        this->m_angles[1] = this->m_first - gap;
        this->m_angles[2] = this->m_first - gap * 2;
        this->m_angles[3] = this->m_first - gap * 3;
        this->m_angles[4] = this->m_first - gap * 4;

        QMessageBox::information(this, "info", QString("Angles : [%1 %2 %3 %4 %5], click OK to continue.").arg(m_angles[0]).arg(m_angles[1]).arg(m_angles[2]).arg(m_angles[3]).arg(m_angles[4]));

        QFuture<void> future = QtConcurrent::run(this, &MainWindow::dispalyAngles);
    });

    connect(ui->zero, &QPushButton::clicked, this, [=]() {
        MoveAbs(0, m_axis);
        WaitMoved(m_axis);
    });


    for (int axis = 0; axis < m_Naxis; axis++)
    {
        m_encp[axis] = 0;
        m_curpos[axis] = 0;
        m_error[axis] = 0;

        m_encpDes[axis].addr = encpLoc;
        m_encpDes[axis].axis = axis;
        m_encpDes[axis].len = 2;

        m_curposDes[axis].addr =curposLoc;
        m_curposDes[axis].axis = axis;
        m_curposDes[axis].len = 2;

        m_errorDes[axis].addr = errorLoc;
        m_errorDes[axis].axis = axis;
        m_errorDes[axis].len = 1;
    }
}

void MainWindow::initAxis(int axis)
{
    IMC_STATUS status;
    if(m_Handle==NULL) return;
    //status = IMC_SetParam16(m_Handle, clearLoc, -1, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam32(m_Handle, accellimLoc, 50000, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam32(m_Handle, vellimLoc, 5000000, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam32(m_Handle, mcsmaxvelLoc, this->m_velocity, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam32(m_Handle, mcsaccelLoc, 1000, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam32(m_Handle, mcsdecelLoc, 1000, axis, FIFO_SEL::SEL_IFIFO);

    status = IMC_SetParam16(m_Handle, steptimeLoc, 300, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam16(m_Handle, enaLoc, -1, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam16(m_Handle, aioctrLoc, 0x0000, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam16(m_Handle, homeseqLoc, 0x0014, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam32(m_Handle, lowvelLoc, 83646, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam32(m_Handle, highvelLoc, 83646, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam16(m_Handle, exitfiltLoc, 0, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam16(m_Handle, stopfiltLoc, -1, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam16(m_Handle, gout1Loc, -1, axis, FIFO_SEL::SEL_IFIFO);
    status = IMC_SetParam16(m_Handle, runLoc, -1, axis, FIFO_SEL::SEL_IFIFO);

    g_naxis = PKG_IMC_GetNaxis(m_Handle);
}

bool MainWindow::openIMC()
{
    if(isOpen()) return true;

    IMC_STATUS st;
    st = IMC_Open(&m_Handle, m_netid, m_imcid);
    if (st != IMC_OK)
        return false;

    for(int i = 0; i < m_Naxis; i++) {
        initAxis(i);
    }

    m_timeID = startTimer(100);

    return true;
}

bool MainWindow::isOpen() const
{
    return m_Handle != nullptr;
}

bool MainWindow::closeIMC()
{
    if (!isOpen())
        return true;
    IMC_Close(m_Handle);
    m_Handle = nullptr;
    return true;
}

bool MainWindow::MoveAbs(int pos, int axis)
{
    IMC_STATUS status;
    if (!isOpen())
        return false;
    do
    {
        status = IMC_MoveAbsolute(m_Handle, pos, axis, SEL_QFIFO);
        if (status != IMC_OK){
            IsError(status);
            QThread::sleep(1);
        }
    } while (status != IMC_OK);
    return status == IMC_OK;
}

bool MainWindow::WaitMoved(int axis)
{
    IMC_STATUS status;
    if (!isOpen())
        return false;
    do
    {
        status = IMC_WaitParam(m_Handle, movingLoc, 0, 0, axis, SEL_QFIFO);
        if (status != IMC_OK){
            IsError(status);
            QThread::sleep(1);
        }
    } while (status != IMC_OK);
    return status == IMC_OK;
}

bool MainWindow::StopPos2Pos(int axis)
{
    IMC_STATUS status;
    status = IMC_SetParam16(m_Handle, mcsgoLoc, 0, axis, SEL_IFIFO);
    status = IMC_ClearFIFO(m_Handle, SEL_QFIFO);
    return status == IMC_OK;
}

bool MainWindow::PosEmstop(int axis)
{
    IMC_STATUS status;
    status = IMC_SetParam16(m_Handle, smoothLoc, 0, axis, SEL_IFIFO);
    status = IMC_SetParam16(m_Handle, mcsgoLoc, 0, axis, SEL_IFIFO);
    status = IMC_SetParam32(m_Handle, mcsvelLoc, 0, axis, SEL_IFIFO);
    status = IMC_SetParam32(m_Handle, mcstgvelLoc, 0, axis, SEL_IFIFO);
    return status == IMC_OK;
}

bool MainWindow::SetHomeVel(int highvel, int lowvel, FIFO_SEL fifo)
{
    IMC_STATUS status = IMC_OK;
    status = IMC_SetParam32(m_Handle, highvelLoc, highvel, 0, fifo);
    status = IMC_SetParam32(m_Handle, lowvelLoc, lowvel, 0, fifo);
    return status == IMC_OK;
}

IMC_STATUS MainWindow::FindHome(IMC16 direction, IMC16 RiseEdge, IMC16 stop, IMC16 useindex, IMC32 axis)
{
    IMC_STATUS status = IMC_OK;
    if (!isOpen())
        return IMC_DEVICE_NOT_OPEN;
    do
    {
        if(!useindex){
            status = IMC_HomeSwitch1(m_Handle, direction, RiseEdge, stop, axis, SEL_IFIFO);
        }else{
            status = IMC_HomeSwitchIndex1(m_Handle, direction, RiseEdge, stop, axis, SEL_IFIFO);
        }
        if (status != IMC_OK)
            IsError(status);
    } while (status != IMC_OK);
    return status;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_timeID)
    {
        if (!isOpen())
            return ;

        IMC_STATUS st;
        int i;
        st = IMC_GetMulParam(m_Handle,m_encpDes, (short)m_Naxis);
        if (st == IMC_OK)
        {
            for (i = 0; i < m_Naxis; i++)
            {
                m_encp[i] = m_encpDes[i].data[0] + (m_encpDes[i].data[1] << 16);
                if(i == m_axis) {
                    ui->machinePos->setText(QString::number(m_encp[i]));
                }
            }
        }

        st = IMC_GetMulParam(m_Handle, m_curposDes, (short)m_Naxis);
        if (st == IMC_OK)
        {
            for (i = 0; i < m_Naxis; i++)
            {
                m_curpos[i] = m_curposDes[i].data[0] + (m_curposDes[i].data[1] << 16);
                if(i == m_axis) {
                    ui->commandPos->setText(QString::number(m_curpos[i]));
                }
            }
        }
    }
}

void MainWindow::setConnectMotorFlag(bool flag)
{
    if(flag) {
        ui->connectMotorLabel->setStyleSheet("QLabel#connectMotorLabel{background-color:rgb(0, 255, 0);border-radius:10px;border:3px groove gray;border-style:outset;}");
        ui->connectMotor->setText("Disconnect");
    }
    else {
        ui->connectMotorLabel->setStyleSheet("QLabel#connectMotorLabel{background-color:rgb(195,195,195);border-radius:10px;border:3px groove gray;border-style:outset;}");
        ui->connectMotor->setText("Connect Motor");
    }
}

void MainWindow::dispalyAngles()
{
    qDebug() << "---------------------------- begin ----------------------------";
    int sleep_array[6] = {15, 10, 10, 10, 10, 15};
    for(int i = 0; i < 5; i++) {
        ui->channel->setText(QString::number(i));
        MoveAbs(m_angles[i], m_axis);
        WaitMoved(m_axis);
        QThread::sleep(sleep_array[i]);
    }

    MoveAbs(0, m_axis);
    WaitMoved(m_axis);
    QThread::sleep(sleep_array[5]);
    qDebug() << "---------------------------- end ----------------------------";
}

