#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "IMCnet.h"
#include "IMC_Def.h"
#include "IMC_Pkg.h"
#include "ParamDef.h"

#define m_Naxis 4

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void init();

protected:
    void initAxis(int axis);

    bool openIMC();

    bool isOpen() const;

    bool closeIMC();

    bool MoveAbs(int pos, int axis);

    bool WaitMoved(int axis);

    bool StopPos2Pos(int axis);

    bool PosEmstop(int axis);

    bool SetHomeVel(int highvel, int lowvel, FIFO_SEL fifo);

    IMC_STATUS FindHome(IMC16 direction, IMC16 RiseEdge, IMC16 stop, IMC16 useIndex, IMC32 axis);

    void timerEvent(QTimerEvent* event) override;

private:
    Ui::MainWindow *ui;

    IMC_HANDLE m_Handle;
    int m_netid;
    int m_imcid;
    int m_axis;
    int m_pos;
    int m_timeID;

    int g_naxis;

    int m_encp[m_Naxis];
    int m_curpos[m_Naxis];
    IMCU16 m_error[m_Naxis];
    IMCU16 m_gin[2];
    IMCU16 m_gout[2];

    WR_MUL_DES  m_encpDes[m_Naxis];
    WR_MUL_DES m_curposDes[m_Naxis];
    WR_MUL_DES m_errorDes[m_Naxis];
    WR_MUL_DES m_ginDes[2];
    WR_MUL_DES m_goutDes[2];
};
#endif // MAINWINDOW_H
