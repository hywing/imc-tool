#ifndef IMC_PKG_HEAD_H
#define IMC_PKG_HEAD_H

#ifdef IMC_PKG_EXPORTS
#define IMC_PKG_API __declspec(dllexport)
#else
#define IMC_PKG_API __declspec(dllimport)
#endif

#include "IMC_Def.h"

//�豸����
//������̫����
IMC_PKG_API int WINAPI 
	PKG_IMC_FindNetCard (char  info[16][256],	//�����ҵ�����������
						int* num) ;				//�����ҵ�����������
//�򿪿��ƿ��豸�����豸����ͨ������
IMC_PKG_API IMC_HANDLE WINAPI 
	PKG_IMC_Open (int netcardsel,			//���������������������������صĽ������
						int imcid) ;		//IMC���ƿ���id���ɿ��ƿ��ϵĲ��뿪�����þ���
//�򿪿��ƿ��豸�����豸����ͨ������
IMC_PKG_API IMC_HANDLE WINAPI 
	PKG_IMC_OpenX (int netcardsel, 			//���������������������������صĽ������
						int imcid, 			//IMC���ƿ���id���ɿ��ƿ��ϵĲ��뿪�����þ���
						int timeout,		//ͨ�ų�ʱʱ�䣬��λ����
						int openMode) ;		//��ģʽ��1������ģʽ�� 0���ǻ���ģʽ
//ʹ������򿪿��ƿ��豸�����豸����ͨ������
IMC_PKG_API IMC_HANDLE WINAPI 
	PKG_IMC_OpenUsePassword (int netcardsel, 	//���������������������������صĽ������
						int imcid,  			//IMC���ƿ���id���ɿ��ƿ��ϵĲ��뿪�����þ���
						char *password);		//�����ַ���
//�رմ򿪵��豸��
IMC_PKG_API int WINAPI 
	PKG_IMC_Close (IMC_HANDLE Handle);

//���ú���
IMC_PKG_API int WINAPI PKG_IMC_InitCfg(IMC_HANDLE handle);
//�������FIFO�Ͳ����ĵȴ�ָ�
IMC_PKG_API int WINAPI 
	PKG_IMC_ClearIMC(IMC_HANDLE handle); 	//�豸�����

//�������ı�����������ָ��λ�á�Ŀ��λ�õȸ���λ�ò�����
IMC_PKG_API int WINAPI 
	PKG_IMC_ClearAxis(IMC_HANDLE handle,  	//�豸�����
					int axis);				//��Ҫ�������š�
//����ָ�������Ч��ƽ��������
IMC_PKG_API int WINAPI 
	PKG_IMC_SetPulWidth(IMC_HANDLE handle, 	//�豸�����
					unsigned int ns,		//�����ȣ���λΪ����
					int axis);				//��Ҫ���������ȵ����
//����ָ���������ͷ������Ч��ƽ
IMC_PKG_API int WINAPI 
	PKG_IMC_SetPulPolar(IMC_HANDLE handle, 	//�豸�����
					int pul,				//�����źŵ���Ч��ƽ�����㣺�ߵ�ƽ��Ч�� �㣺�͵�ƽ��Ч��
					int dir, 				//�����źŵ���Ч��ƽ�����㣺�ߵ�ƽ��Ч�� �㣺�͵�ƽ��Ч��
					int axis);				//��Ҫ������Ч��ƽ����š�
//ʹ��/��ֹ���ƿ����ձ���������
IMC_PKG_API int WINAPI 
	PKG_IMC_SetEncpEna(IMC_HANDLE handle, 	//�豸�����
					int ena, 				//ʹ�ܱ�־�����㣺ʹ�ܣ� �㣺��ʹ�ܡ�
					int axis);				//��Ҫ��/��ֹ���ƿ����ձ�������������š�
//���ÿ��ƿ����ձ����������ļ���ģʽ�ͼ�������
IMC_PKG_API int WINAPI 
	PKG_IMC_SetEncpMode(IMC_HANDLE handle, 	//�豸�����
					int mode, 				//�������ļ���ģʽ���㣺�����ź�ģʽ�� ���㣺����+����ģʽ
					int dir, 				//�������ļ�������
					int axis);				//��Ҫ���õ���š�
//���ñ�������������
IMC_PKG_API int WINAPI 
	PKG_IMC_SetEncpRate(IMC_HANDLE handle,  //�豸�����
					double rate,			//����
					int axis); 				//��Ҫ���õ���š�
//����ָ������ٶȺͼ��ٶ�����
IMC_PKG_API int WINAPI 
	PKG_IMC_SetVelAccLim(IMC_HANDLE handle, //�豸�����
					double vellim, 			//�ٶȼ��ޣ���λΪ����ÿ���롣
					double acclim, 			//���ٶȼ��ޣ���λΪ����ÿƽ�����롣
					int axis);				//��Ҫ�����ٶȺͼ��ٶȼ��޵����
//����ÿ�����ƽ����
IMC_PKG_API int WINAPI 
	PKG_IMC_SetSmooth(IMC_HANDLE handle, 	//�豸�����
						short smooth, 		//ƽ���ȣ�ֵԽ����Խƽ�������˶��켣������Խ��
						int aixs); 			//��ţ�	
//ʹ��/��ָֹ�����������
IMC_PKG_API int WINAPI 
	PKG_IMC_SetEna(IMC_HANDLE handle, 		//�豸�����
					int ena, 				//ʹ�ܱ�־�����㣺ʹ�ܣ� �㣺��ʹ�ܡ�
					int axis);				//��Ҫʹ��/��ֹ����������š�
//ʹ��/��ֹӲ����λ����˿ں���������Ч���ԡ�
IMC_PKG_API int WINAPI 
	PKG_IMC_Setlimit (IMC_HANDLE handle, 	//�豸�����
					int plimEna, 			//�Ƿ�ʹ��Ӳ������λ���ܡ����㣺ʹ�ܣ� �㣺��ʹ�ܡ�
					int plimPolar, 			//����λ���ԣ����㣺��Ч�� �㣺�͵�ƽ��Ч��
					int nlimEna, 			//�Ƿ�ʹ��Ӳ������λ���ܡ����㣺ʹ�ܣ� �㣺��ʹ�ܡ�
					int nlimPolar, 			//����λ���ԣ����㣺��Ч�� �㣺�͵�ƽ��Ч��
					int axis);				//��š�
//ʹ���ŷ������������������Ч����
IMC_PKG_API int WINAPI 
	PKG_IMC_SetAlm (IMC_HANDLE handle, 		//�豸�����
					int ena, 				//�Ƿ�ʹ���ŷ��������빦�ܡ����㣺ʹ�ܣ� �㣺��ʹ�ܡ�
					int polar, 				//���ԣ����㣺�ߵ�ƽ��Ч�� �㣺�͵�ƽ��Ч��
					int axis);				//��š�
//ʹ���ŷ���λ�������������Ч����
IMC_PKG_API int WINAPI 
	PKG_IMC_SetINP(IMC_HANDLE handle,  		//�豸�����
					int ena,  				//�Ƿ�ʹ���ŷ���λ���빦�ܡ����㣺ʹ�ܣ� �㣺��ʹ�ܡ�
					int polar,  			//���ԣ����㣺�ߵ�ƽ��Ч�� �㣺�͵�ƽ��Ч��
					int axis);				//��š�
//���ü�ͣ����˵���Ч����
IMC_PKG_API int WINAPI 
	PKG_IMC_SetEmstopPolar(IMC_HANDLE handle, //�豸�����
					int polar, 				//���ԣ����㣺�ߵ�ƽ��Ч�� �㣺�͵�ƽ��Ч��
					int axis);				//��š�
//����ͨ������˵���Ч����
IMC_PKG_API int WINAPI 
	PKG_IMC_SetInPolar(IMC_HANDLE handle, 	//�豸�����
					int polar, 				//���ԣ����㣺�ߵ�ƽ��Ч�� �㣺�͵�ƽ��Ч��
					int inPort);			//����˿ڣ���Χ1 - 32��
//���÷�������ʱ������Ƿ�ֹͣ�˶���
IMC_PKG_API int WINAPI 
	PKG_IMC_SetStopfilt(IMC_HANDLE handle,  //�豸�����
					int stop,				//����ʱ�Ƿ�ֹͣ���У��㣺��ֹͣ�� ���㣺ֹͣ
					int axis);				//��š�
//���÷�������ʱ������Ƿ��˳��˶���
IMC_PKG_API int WINAPI 
	PKG_IMC_SetExitfilt(IMC_HANDLE handle,  //�豸�����
					int exit,				//����ʱ�Ƿ��˳����У��㣺���˳������㣺�˳�
					int axis);				//��š�
//���þ�̬�����ķ�Χ��
IMC_PKG_API int WINAPI 
	PKG_IMC_SetRecoupRange(IMC_HANDLE handle, //�豸�����
					int range,				//����ֵ��ȡֵ��Χ0 - 32767��
					int axis);				//��š�
//��ÿ��ƿ��е�������Ϣ
IMC_PKG_API int WINAPI 
	PKG_IMC_GetConfig(IMC_HANDLE handle,  	//�豸�����
					int *steptime, 			//�����ȣ���λΪ����
					int *pulpolar, 			//�������Ч��ƽ���㣺�͵�ƽ��Ч�� ���㣺�ߵ�ƽ��Ч
					int *dirpolar, 			//�������Ч��ƽ���㣺�͵�ƽ��Ч�� ���㣺�ߵ�ƽ��Ч
					int *encpena, 			//�Ƿ�ʹ�ñ������������㣺���ã� ���㣺ʹ��
					int *encpmode, 			//����������ģʽ
					int *encpdir, 			//��������������
					double *encpfactor, 	//����������
					double *vellim, 		//�ٶȼ��ޣ���λΪ����/����
					double *acclim, 		//���ٶȼ��ޣ���λΪ����/ƽ������
					int *drvena, 			//�Ƿ�ʹ�����������㣺��ʹ�ܣ� ���㣺ʹ��
					int *plimena, 			//�Ƿ�ʹ����Ӳ����λ���㣺���ã� ���㣺ʹ��
					int *plimpolar, 		//Ӳ������λ��Ч��ƽ���㣺�͵�ƽ��Ч�� ���㣺�ߵ�ƽ��Ч
					int *nlimena, 			//�Ƿ�ʹ�ø�Ӳ����λ���㣺���ã� ���㣺ʹ��
					int *nlimpolar, 		//Ӳ������λ��Ч��ƽ���㣺�͵�ƽ��Ч�� ���㣺�ߵ�ƽ��Ч
					int *almena, 			//�Ƿ�ʹ���ŷ��������㣺���ã� ���㣺ʹ��
					int *almpolar, 			//�ŷ�������Ч��ƽ���㣺�͵�ƽ��Ч�� ���㣺�ߵ�ƽ��Ч
					int *INPena, 			//�Ƿ�ʹ���ŷ���λ���㣺���ã� ���㣺ʹ��
					int *INPpolar, 			//�ŷ���λ��Ч��ƽ���㣺�͵�ƽ��Ч�� ���㣺�ߵ�ƽ��Ч
					int axis);				//��Ҫ��ȡ��Ϣ�����
//�㵽���˶�����
//ʹ��ӵ�ǰλ���ƶ���ָ����Ŀ��λ��
IMC_PKG_API int WINAPI 
	PKG_IMC_MoveAbs(IMC_HANDLE handle, 		//�豸�����
					long pos, 				//Ŀ��λ�ã���λΪ���壻
					double startvel, 		//��ʼ�ٶȣ���λΪ����ÿ���룻
					double tgvel, 			//Ŀ���ٶȣ���λΪ����ÿ���룻
					int wait, 				//�Ƿ�ȴ��˶���ɺ󣬺����ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int axis); 				//ָ�����
IMC_PKG_API int WINAPI 
	PKG_IMC_MoveAbs_P(IMC_HANDLE handle, 	//�豸�����
					long pos, 				//Ŀ��λ�ã���λΪ���壻
					double startvel, 		//��ʼ�ٶȣ���λΪ����ÿ���룻
					double tgvel, 			//Ŀ���ٶȣ���λΪ����ÿ���룻
					int wait, 				//�Ƿ�ȴ��˶���ɺ󣬺����ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int axis); 				//ָ�����
					
//ʹ��ӵ�ǰλ���ƶ���ָ���ľ���
IMC_PKG_API int WINAPI 
	PKG_IMC_MoveDist(IMC_HANDLE handle, 	//�豸�����
					long dist, 				//�ƶ����룬��λΪ���壻
					double startvel, 		//��ʼ�ٶȣ���λΪ����ÿ���룻
					double tgvel, 			//Ŀ���ٶȣ���λΪ����ÿ���룻
					int wait, 				//�Ƿ�ȴ��˶���ɺ󣬺����ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int axis); 				//ָ����ţ�
IMC_PKG_API int WINAPI 
	PKG_IMC_MoveDist_P(IMC_HANDLE handle, 	//�豸�����
					long dist, 				//�ƶ����룬��λΪ���壻
					double startvel, 		//��ʼ�ٶȣ���λΪ����ÿ���룻
					double tgvel, 			//Ŀ���ٶȣ���λΪ����ÿ���룻
					int wait, 				//�Ƿ�ȴ��˶���ɺ󣬺����ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int axis); 				//ָ����ţ�
//�����ı䵱ǰ����ִ�еĵ㵽���˶����˶��ٶ�
IMC_PKG_API int WINAPI 
	PKG_IMC_P2Pvel(IMC_HANDLE handle,		//�豸�����
					double tgvel, 			//Ŀ���ٶȣ���λΪ����ÿ���룻
					int axis);				//��ţ�
IMC_PKG_API int WINAPI 
	PKG_IMC_P2Pvel_P(IMC_HANDLE handle,		//�豸�����
					double tgvel, 			//Ŀ���ٶȣ���λΪ����ÿ���룻
					int axis);				//��ţ�
//���õ�ǰ�㵽���˶��ļ��ٶȺͼ��ٶ�
IMC_PKG_API int WINAPI 
	PKG_IMC_SetAccel(IMC_HANDLE handle, 	//�豸�����
					double accel, 			//���ٶȣ���λΪ����ÿƽ�����룻
					double decel, 			//���ٶȣ�
					int axis);				//��ţ�
IMC_PKG_API int WINAPI 
	PKG_IMC_SetAccel_P(IMC_HANDLE handle, 	//�豸�����
					double accel, 			//���ٶȣ���λΪ����ÿƽ�����룻
					double decel, 			//���ٶȣ�
					int axis);				//��ţ�
//���õ㵽���˶�ģʽ
IMC_PKG_API int WINAPI 
	PKG_IMC_P2Pmode(IMC_HANDLE handle,  	//�豸�����
					int mode, 				//�˶�ģʽ���㣺��ͨģʽ�� ���㣺����ģʽ
					int axis);				//��š�
IMC_PKG_API int WINAPI 
	PKG_IMC_P2Pmode_P(IMC_HANDLE handle,  	//�豸�����
					int mode, 				//�˶�ģʽ���㣺��ͨģʽ�� ���㣺����ģʽ
					int axis);				//��š�
//��㵽���˶���Ŀ��λ��
IMC_PKG_API int WINAPI 
	PKG_IMC_P2PnewPos(IMC_HANDLE handle,  	//�豸�����
					long tgpos, 			//�µ�Ŀ��λ�ã���λΪ���壻
					int axis);				//��š�
IMC_PKG_API int WINAPI 
	PKG_IMC_P2PnewPos_P(IMC_HANDLE handle,  	//�豸�����
					long tgpos, 			//�µ�Ŀ��λ�ã���λΪ���壻
					int axis);				//��š�
//����ֹͣ�㵽���˶�
IMC_PKG_API int WINAPI 
	PKG_IMC_P2Pstop(IMC_HANDLE handle, 		//�豸�����
					int axis);				//��š�
IMC_PKG_API int WINAPI 
	PKG_IMC_P2Pstop_P(IMC_HANDLE handle, 		//�豸�����
					int axis);				//��š�
//ʹ��������ָ�����ٶ�һֱ�˶���ֱ���ٶȱ��ı�Ϊֹ
IMC_PKG_API int WINAPI 
	PKG_IMC_MoveVel(IMC_HANDLE handle,  	//�豸�����
					double startvel, 		//��ʼ�ٶȣ���λΪ����ÿƽ�����룻 
					double tgvel, 			//ָ������˶��ٶȣ���λΪ����ÿƽ�����룻
					int axis);				//��š�
IMC_PKG_API int WINAPI 
	PKG_IMC_MoveVel_P(IMC_HANDLE handle,  	//�豸�����
					double startvel, 		//��ʼ�ٶȣ���λΪ����ÿƽ�����룻 
					double tgvel, 			//ָ������˶��ٶȣ���λΪ����ÿƽ�����룻
					int axis);				//��š�

//������
//������Ϊ�����ỹ�ǻ����ᡣ
IMC_PKG_API int WINAPI 
	PKG_IMC_SetCirAxis(IMC_HANDLE handle,  	//�豸�����
					int isCir, 				//���㣺�����ᣬ 0��������
					int axis);				//��š�
//���õ����˫�����ᡣ
IMC_PKG_API int WINAPI 
	PKG_IMC_SetCirMode(IMC_HANDLE handle,  	//�豸�����
					int mode, 				//���㣺˫����[-cirpos, cirpos]�� 0��������[0, cirpos]
					int axis);				//��š�
//���û���������λ�á�
IMC_PKG_API int WINAPI 
	PKG_IMC_SetCirPos(IMC_HANDLE handle,  	//�豸�����
					long cirpos, 			//����������λ��
					int axis);				//��š�
//�岹����
//����������岹�˶������ӳ�䵽X��Y��Z��A��B�������ȶ�Ӧ�ı�ʶ��
IMC_PKG_API int WINAPI 
	PKG_IMC_AxisMap(IMC_HANDLE handle, 		//�豸�����
					int axis[], 			//��Ҫӳ�����ŵ�����
					int num, 				//��Ҫӳ����������
					int fifo);				//���ĸ��岹�ռ����ӳ�䣬��ѡSEL_PFIFO1��SEL_PFIFO2��
//�������ò岹�ռ�
IMC_PKG_API int WINAPI
	PKG_IMC_PFIFOrun (IMC_HANDLE handle, 	//�豸�����
					int fifo);				//�����ĸ��岹�ռ䣬��ѡSEL_PFIFO1��SEL_PFIFO2��
//�����ٶȹ滮��ʽ��
IMC_PKG_API int WINAPI
	PKG_IMC_SetPFIFOvelMode (IMC_HANDLE handle, //�豸�����
					int mode,				//�ٶȹ滮ģʽ
					int fifo);				//�����ĸ��岹�ռ���ٶȹ滮ģʽ����ѡSEL_PFIFO1��SEL_PFIFO2��
//�����ı�岹�ļ��ٶ�
IMC_PKG_API int WINAPI 
	PKG_IMC_SetPFIFOaccel (IMC_HANDLE handle, //�豸�����
					double accel, 			//�岹�ļ��ٶȣ���λΪ����ÿƽ�����룻 
					int fifo);				//�����ĸ��岹�ռ�Ĳ岹�ļ��ٶȣ���ѡSEL_PFIFO1��SEL_PFIFO2��
//����ֱ�߲岹�������˶���
IMC_PKG_API int WINAPI 
	PKG_IMC_Line_Pos(IMC_HANDLE handle, 	//�豸�����
					long pos[], 			//����岹�˶������λ�ã���λΪ���壻
					int axisNum, 			//����岹�˶���������
					double tgvel, 			//�岹�˶����ٶȣ���λΪ����ÿƽ�����룻
					double endvel, 			//�岹�˶���ĩ���ٶȣ���λΪ����ÿƽ�����룻
					int wait, 				//�Ƿ�ȴ��岹�˶���ɣ������ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int fifo);				//ָ�������˶�ָ��͵��ĸ�FIFO��ִ�У���ѡSEL_PFIFO1��SEL_PFIFO2��
//����ֱ�߲岹������˶���
IMC_PKG_API int WINAPI 
	PKG_IMC_Line_Dist(IMC_HANDLE handle, 	//�豸�����
					long dist[], 			//����岹�˶�������ƶ����룬��λΪ���壻
					int axisNum, 			//����岹�˶���������
					double tgvel, 			//�岹�˶����ٶȣ���λΪ����ÿƽ�����룻
					double endvel,			//�岹�˶���ĩ���ٶȣ���λΪ����ÿƽ�����룻
					int wait, 				//�Ƿ�ȴ��岹�˶���ɣ������ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int fifo);				//ָ�������˶�ָ��͵��ĸ�FIFO��ִ�У���ѡSEL_PFIFO1��SEL_PFIFO2��
//�������ֱ�߲岹�������˶���
IMC_PKG_API int WINAPI 
	PKG_IMC_MulLine_Pos (IMC_HANDLE handle, //�豸�����
					long* pos, 				//��β���岹�˶������λ�ã���λΪ���壻
					int axisNum, 			//����岹�˶���������
					int segNum, 			//�岹�˶��Ķ�����
					double tgvel, 			//�岹�˶����ٶȣ���λΪ����ÿƽ�����룻
					double endvel, 			//�岹�˶������һ�εĽ����ٶȣ���λΪ����ÿƽ�����룻
					int wait, 				//�Ƿ�ȴ��岹�˶���ɣ������ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int fifo);				//ָ�������˶�ָ��͵��ĸ�FIFO��ִ�У���ѡSEL_PFIFO1��SEL_PFIFO2��
//�������ֱ�߲岹������˶���
IMC_PKG_API int WINAPI 
	PKG_IMC_MulLine_Dist (IMC_HANDLE handle, //�豸�����
					long* dist, 			//��β���岹�˶�������ƶ����룬��λΪ���壻 
					int axisNum, 			//����岹�˶���������
					int segNum, 			//�岹�˶��Ķ�����
					double tgvel, 			//�岹�˶����ٶȣ���λΪ����ÿƽ�����룻
					double endvel, 			//�岹�˶������һ�εĽ����ٶȣ���λΪ����ÿƽ�����룻
					int wait, 				//�Ƿ�ȴ��岹�˶���ɣ������ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int fifo);				//ָ�������˶�ָ��͵��ĸ�FIFO��ִ�У���ѡSEL_PFIFO1��SEL_PFIFO2��
//Բ���岹�������˶���
IMC_PKG_API int WINAPI 
	PKG_IMC_Arc_Pos(IMC_HANDLE handle, 		//�豸�����
					long endx, 				//����Բ���岹��X����յ��λ�ã���λΪ���壻
					long endy, 				//����Բ���岹��Y����յ��λ�ã���λΪ���壻
					long cx, 				//����Բ���岹��X���Բ�ģ���λΪ���壻
					long cy, 				//����Բ���岹��Y���Բ�ģ���λΪ���壻 
					int dir, 				//Բ���˶��ķ���
					double tgvel, 			//�岹�˶����ٶȣ���λΪ����ÿƽ�����룻
					double endvel, 			//�岹�˶��Ľ����ٶȣ���λΪ����ÿƽ�����룻
					int wait, 				//�Ƿ�ȴ��岹�˶���ɣ������ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int fifo) ;				//ָ�������˶�ָ��͵��ĸ�FIFO��ִ�У���ѡSEL_PFIFO1��SEL_PFIFO2��
//Բ���岹������˶���
IMC_PKG_API int WINAPI 
	PKG_IMC_Arc_Dist(IMC_HANDLE handle, 	//�豸�����
					long dist_x, 			//����Բ���岹��X����յ���������ľ��룬��λΪ���壻
					long dist_y, 			//����Բ���岹��Y����յ���������ľ��룬��λΪ���壻
					long dist_cx, 			//����Բ���岹��X���Բ����������ľ��룬��λΪ���壻
					long dist_cy, 			//����Բ���岹��Y���Բ����������ľ��룬��λΪ���壻
					int dir, 				//Բ���˶��ķ���
					double tgvel, 			//�岹�˶����ٶȣ���λΪ����ÿƽ�����룻
					double endvel, 			//�岹�˶��Ľ����ٶȣ���λΪ����ÿƽ�����룻
					int wait, 				//�Ƿ�ȴ��岹�˶���ɣ������ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int fifo);				//ָ�������˶�ָ��͵��ĸ�FIFO��ִ�У���ѡSEL_PFIFO1��SEL_PFIFO2��
//Բ��ֱ�߲岹�������˶���
IMC_PKG_API int WINAPI 
	PKG_IMC_ArcLine_Pos(IMC_HANDLE handle, 	//�豸�����
					long endx, 				//����Բ���岹��X����յ��λ�ã���λΪ���壻
					long endy, 				//����Բ���岹��Y����յ��λ�ã���λΪ���壻
					long cx, 				//����Բ���岹��X���Բ�ģ���λΪ���壻
					long cy, 				//����Բ���岹��Y���Բ�ģ���λΪ���壻
					int dir, 				//Բ���˶��ķ��� 
					long pos[], 			//����Բ���岹�˶������λ�ã���λΪ���壻 
					int axisNum, 			//����Բ���岹�˶���������
					double tgvel, 			//�岹�˶����ٶȣ���λΪ����ÿƽ�����룻
					double endvel, 			//�岹�˶��Ľ����ٶȣ���λΪ����ÿƽ�����룻
					int wait, 				//�Ƿ�ȴ��岹�˶���ɣ������ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int fifo);				//ָ�������˶�ָ��͵��ĸ�FIFO��ִ�У���ѡSEL_PFIFO1��SEL_PFIFO2��
//Բ��ֱ�߲岹������˶���
IMC_PKG_API int WINAPI 
	PKG_IMC_ArcLine_Dist(IMC_HANDLE handle, //�豸�����
					long dist_x, 			//����Բ���岹��X����յ���������ľ��룬��λΪ���壻
					long dist_y, 			//����Բ���岹��Y����յ���������ľ��룬��λΪ���壻
					long dist_cx, 			//����Բ���岹��X���Բ����������ľ��룬��λΪ���壻
					long dist_cy, 			//����Բ���岹��Y���Բ����������ľ��룬��λΪ���壻
					int dir, 				//Բ���˶��ķ��� 
					long dist[], 			//����Բ���岹�˶�������ƶ����룬��λΪ���壻
					int axisNum, 			//����Բ���岹�˶���������
					double tgvel, 			//�岹�˶����ٶȣ���λΪ����ÿƽ�����룻
					double endvel, 			//�岹�˶��Ľ����ٶȣ���λΪ����ÿƽ�����룻
					int wait, 				//�Ƿ�ȴ��岹�˶���ɣ������ŷ��ء����㣺�ȴ��˶���ɣ��㣺���ȴ���
					int fifo);				//ָ�������˶�ָ��͵��ĸ�FIFO��ִ�У���ѡSEL_PFIFO1��SEL_PFIFO2��
//�����ı�岹�Ľ������ʡ�������������Ϊ0ʱ����ʵ�ֲ岹����ͣ���ٴ���Ϊ����������ͣ
IMC_PKG_API int WINAPI 
	PKG_IMC_SetFeedrate (IMC_HANDLE handle, //�豸�����
					double rate, 			//�������ʣ� 
					int fifo);				//�����ĸ��岹�ռ�Ĳ岹�Ľ������ʣ���ѡSEL_PFIFO1��SEL_PFIFO2��
//����ֹͣ�岹�˶�
IMC_PKG_API int WINAPI 
	PKG_IMC_PFIFOstop (IMC_HANDLE handle, 	//�豸�����
					int fifo);				//ֹͣ�ĸ��岹�ռ�Ĳ岹����ѡSEL_PFIFO1��SEL_PFIFO2��
//����ֹͣ�岹�˶�
IMC_PKG_API int WINAPI 
	PKG_IMC_isPstop (IMC_HANDLE handle,  	//�豸�����
					int fifo);				//�ĸ��岹�ռ�Ĳ岹ֹͣ����ѡSEL_PFIFO1��SEL_PFIFO2��
//������շ����岹�ռ���δ��ִ�е�����ָ��
IMC_PKG_API int WINAPI 
	PKG_IMC_PFIFOclear (IMC_HANDLE handle, 	//�豸�����
					int fifo);				//����ĸ��岹�ռ��ָ���ѡSEL_PFIFO1��SEL_PFIFO2��

//���ֺ���
//����ָ���������������˶�
IMC_PKG_API int WINAPI  
	PKG_IMC_HandWheel(IMC_HANDLE Handle, 	//�豸�����
					double rate, 			//�������ֱ��ʣ�
					int axis);				//���������˶�����ţ�
//���ôӶ�������������˶�
IMC_PKG_API int WINAPI  
	PKG_IMC_Gear1 (IMC_HANDLE Handle, 		//�豸�����
					double rate, 			//���ֱ��ʣ�
					int master, 			//�������
					int axis);				//�Ӷ������š�
//���ôӶ�������������˶�
IMC_PKG_API int WINAPI  
	PKG_IMC_Gear2 (IMC_HANDLE Handle, 	//�豸�����
					double rate, 			//���ֱ��ʣ�
					int master, 			//�������
					int axis);				//�Ӷ������š�
//��������������ֻ���ֵ�����
IMC_PKG_API int WINAPI  
	PKG_IMC_ExitGear (IMC_HANDLE Handle, 	//�豸�����
					int axis);				//�Ӷ������š�


//IO���ú���
//������˿ڽ��п���
IMC_PKG_API int WINAPI 
	PKG_IMC_SetOut(IMC_HANDLE handle, 		//�豸�����
					int outPort, 			//����˿ڣ���Χ��1 �C 48��
					int data, 				//��������˿ڵ�״̬�� �㣺�Ͽ�����˿ڣ� ���㣺��ͨ����˿ڡ�
					int fifo);				//ָ������ָ��͵��ĸ�FIFO��ִ�С�

 //���㺯��
//���õ�ǰ���������ʹ�õĸ��ٶȺ͵��ٶ�
IMC_PKG_API int WINAPI 
	PKG_IMC_SetHomeVel(IMC_HANDLE handle, 	//�豸�����
					double hight, 			//���������ʹ�õĸ��ٶȣ���λΪ����ÿ���룻
					double low, 			//���������ʹ�õĵ��ٶȣ���λΪ����ÿ���룻
					int axis);				//��ţ�
//���ñ����������źŵļ���
IMC_PKG_API int WINAPI 
	PKG_IMC_SetHomeIndexPolar(IMC_HANDLE handle, //�豸�����
					int polar,				//�����źŵļ��ԣ� ���㣺��������Ч�� 0���½�����Ч
					int axis);				//��ţ�
//ʹ����㿪���������
IMC_PKG_API int WINAPI 
	PKG_IMC_HomeSwitch1 (IMC_HANDLE Handle, //�豸�����
					int dir, 				//���㷽���㣺���������㣻���㣺���������㣻
					int riseEdge, 			//ָ�����ԭ�㿪�صı��أ��㣺�½��أ� ���㣺������
					long pos, 				//�������ʱ����㿪�ص�λ��ֵ��
					long stpos, 			//�������ʱ�����ֹͣ��λ�ã�
					double movVel,			//���������ƶ���ֹͣλ��ʱ���ٶ�
					int wait,				//�Ƿ�ȴ��������
					int axis);				//��š�
//ʹ����㿪���������
IMC_PKG_API int WINAPI 
	PKG_IMC_HomeSwitch2 (IMC_HANDLE Handle, //�豸�����
					int dir, 				//���㷽���㣺���������㣻���㣺���������㣻
					int riseEdge, 			//ָ�����ԭ�㿪�صı��أ��㣺�½��أ� ���㣺������
					long pos, 				//�������ʱ����㿪�ص�λ��ֵ��
					long stpos, 			//�������ʱ�����ֹͣ��λ�ã�
					double movVel,			//���������ƶ���ֹͣλ��ʱ���ٶ�
					int wait,				//�Ƿ�ȴ��������
					int axis) ;				//��š�
//ʹ����㿪���������
IMC_PKG_API int WINAPI 
	PKG_IMC_HomeSwitch3 (IMC_HANDLE Handle, //�豸�����
					int dir, 				//���㷽���㣺���������㣻���㣺���������㣻
					int riseEdge, 			//ָ�����ԭ�㿪�صı��أ��㣺�½��أ� ���㣺������
					long pos, 				//�������ʱ����㿪�ص�λ��ֵ��
					long stpos, 			//�������ʱ�����ֹͣ��λ�ã�
					double movVel,			//���������ƶ���ֹͣλ��ʱ���ٶ�
					int wait,				//�Ƿ�ȴ��������
					int axis);				//��š�
//ʹ����㿪�غ������ź��������
IMC_PKG_API int WINAPI 
	PKG_IMC_HomeSwitchIndex1 (IMC_HANDLE Handle, //�豸�����
					int dir, 					//���㷽���㣺���������㣻���㣺���������㣻
					int riseEdge, 				//ָ�����ԭ�㿪�صı��أ��㣺�½��أ� ���㣺������
					long pos, 					//�������ʱ����㿪�ص�λ��ֵ��
					long stpos, 				//�������ʱ�����ֹͣ��λ�ã�
					double movVel,				//���������ƶ���ֹͣλ��ʱ���ٶ�
					int wait,					//�Ƿ�ȴ��������
					int axis);					//��š�
//ʹ����㿪�غ������ź��������
IMC_PKG_API int WINAPI 
	PKG_IMC_HomeSwitchIndex2 (IMC_HANDLE Handle, //�豸�����
					int dir, 				//���㷽���㣺���������㣻���㣺���������㣻
					int riseEdge, 			//ָ�����ԭ�㿪�صı��أ��㣺�½��أ� ���㣺������
					long pos, 				//�������ʱ����㿪�ص�λ��ֵ��
					long stpos, 			//�������ʱ�����ֹͣ��λ�ã�
					double movVel,			//���������ƶ���ֹͣλ��ʱ���ٶ�
					int wait,				//�Ƿ�ȴ��������
					int axis) ;				//��š�
//ʹ����㿪�غ������ź��������
IMC_PKG_API int WINAPI 
	PKG_IMC_HomeSwitchIndex3 (IMC_HANDLE Handle, 	//�豸�����
					int dir, 				//���㷽���㣺���������㣻���㣺���������㣻
					int riseEdge, 			//ָ�����ԭ�㿪�صı��أ��㣺�½��أ� ���㣺������
					long pos, 				//�������ʱ����㿪�ص�λ��ֵ��
					long stpos, 			//�������ʱ�����ֹͣ��λ�ã�
					double movVel,			//���������ƶ���ֹͣλ��ʱ���ٶ�
					int wait,				//�Ƿ�ȴ��������
					int axis);				//��š�
//ʹ�������ź��������
IMC_PKG_API int WINAPI 
	PKG_IMC_HomeIndex (IMC_HANDLE Handle, 	//�豸�����
					int dir, 				//���㷽���㣺���������㣻���㣺���������㣻
					long pos, 				//�������ʱ����㿪�ص�λ��ֵ��
					long stpos, 			//�������ʱ�����ֹͣ��λ�ã�
					double movVel,			//���������ƶ���ֹͣλ��ʱ���ٶ�
					int wait,				//�Ƿ�ȴ��������
					int axis);				//��š�
//�Ѹ���ĵ�ǰλ���趨Ϊָ��ֵ
IMC_PKG_API int WINAPI 
	PKG_IMC_SetPos (IMC_HANDLE Handle, 		//�豸�����
					long pos, 				//���õ�ָ��ֵ����λΪ���壻
					int axis);				//��š�
//����ֹͣ�����˶�
IMC_PKG_API int WINAPI 
	PKG_IMC_HomeStop (IMC_HANDLE Handle, 	//�豸�����
					int axis);				//��Ҫֹͣ�����˶�����š�

//��ȡ״̬����
//��ȡ����
 IMC_PKG_API int WINAPI 
 PKG_IMC_GetNaxis(IMC_HANDLE Handle); 		//�豸�����

//���������Ļ�еλ�á�
 IMC_PKG_API int WINAPI 
	 PKG_IMC_GetEncp(IMC_HANDLE Handle, 	//�豸�����
	 				long pos[], 			//���ڱ����еλ�õ����飻��λΪ���壻
					int axisnum);			//���ƿ���������
 //����������ָ��λ��
 IMC_PKG_API int WINAPI 
	 PKG_IMC_GetCurpos(IMC_HANDLE Handle, 	//�豸�����
	 				long pos[], 			//���ڱ���ָ��λ�õ����飻��λΪ���壻
					int axisnum);			//���ƿ���������
 //���������Ĵ���״̬
 IMC_PKG_API int WINAPI 
	 PKG_IMC_GetErrorReg(IMC_HANDLE Handle, //�豸�����
	 				unsigned short err[], 	//���ڱ���������Ĵ���״̬���д�������Ӧ��λ����1��
					int axisnum);			//���ƿ���������
 //�����������˶�״̬
 IMC_PKG_API int WINAPI 
	 PKG_IMC_GetMoving(IMC_HANDLE Handle, 	//�豸�����
					unsigned short moving[],//���ڱ�����������˶�״̬���㣺��ֹͣ�˶��� ���㣺�����˶���
					int axisnum);			//���ƿ���������
 //���������Ĺ�������˿�״̬
 IMC_PKG_API int WINAPI 
	 PKG_IMC_GetAin(IMC_HANDLE Handle,  	//�豸�����
					unsigned short ain[][6],//���ڱ��������Ṧ������˵�״̬
					int axisnum);			//���ƿ���������
 //�������ͨ������˿ڵ�״̬
 IMC_PKG_API int WINAPI 
	 PKG_IMC_GetGin(IMC_HANDLE Handle, 		//�豸�����
					unsigned short gin[32]);//���ڱ�������ͨ������˵�״̬��
 //�����������˿ڵ�״̬
 IMC_PKG_API int WINAPI 
	 PKG_IMC_GetGout(IMC_HANDLE Handle, 	//�豸�����
					unsigned short gout[48]);//���ڱ�����������˵�״̬
 
 IMC_PKG_API int WINAPI 
	 PKG_IMC_ClearError(IMC_HANDLE Handle,  //�豸�����
					int axis);				//��Ҫ�����������
//�������ܺ���
 //������������ͣ������ͣ״̬
IMC_PKG_API int WINAPI 
	PKG_IMC_Emstop(IMC_HANDLE Handle, 		//�豸�����
					int isStop);			//��ͣ���ǽ����ͣ�����㣺��ͣ�� �㣺�����ͣ��
//��������������ͣ������ͣ״̬
IMC_PKG_API int WINAPI 
	PKG_IMC_Pause(IMC_HANDLE Handle, 		//�豸�����
					int pause);				//��ͣ���ǽ����ͣ״̬�����㣺��ͣ�� �㣺�����ͣ��

//�˳��ȴ��˶����
IMC_PKG_API void WINAPI 
	PKG_IMC_ExitWait();
//���������ش����ǣ�ʹ�ô˺�����ô�����ʾ
IMC_PKG_API const char * WINAPI 
	PKG_IMC_GetFunErrStr();
//��ô���Ĵ������ַ���˵��
IMC_PKG_API const char * WINAPI 
	PKG_IMC_GetRegErrorStr(unsigned short err);

//ADD�¼�
//��ĳ���Ĵ�����ֵ����һ���Ĵ�����ֵ������ӣ���������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_ADD32(EventInfo *info,	//�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis,		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis, 		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ��ָ����ֵ������ӣ���������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_ADD32i(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    long data, 							//32λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ����һ���Ĵ�����ֵ������ӣ���������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_ADD48(EventInfo *info,	//�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ�� 
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ��ָ����ֵ������ӣ���������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_ADD48i(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    __int64 data, 						//64λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����

//CMP�¼�
//��ĳ���Ĵ�����ֵ����һ���Ĵ�����ֵ�����������������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_CMP32(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ��ָ����ֵ�����������������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_CMP32i(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    long data, 							//32λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ����һ���Ĵ�����ֵ�����������������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_CMP48(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ��ָ����ֵ�����������������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_CMP48i(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    __int64 data, 						//64λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����

//SCA�¼�
//��ĳ���Ĵ�����ֵ������һ���Ĵ���ָ���ı��ʣ���������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_SCA32(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ����ָ���ı��ʣ���������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_SCA32i(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    long data, 							//32λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ������һ���Ĵ���ָ���ı��ʣ���������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_SCA48(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ���Գ���ָ���ı��ʣ���������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_SCA48i(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    __int64 data, 						//64λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//MUL�¼�
//
IMC_PKG_API int WINAPI PKG_Fill_MUL32L(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//
IMC_PKG_API int WINAPI PKG_Fill_MUL32iL(EventInfo *info,//�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    long data, 							//32λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//
IMC_PKG_API int WINAPI PKG_Fill_MUL32A(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//
IMC_PKG_API int WINAPI PKG_Fill_MUL32iA(EventInfo *info,//�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    long data, 							//32λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����

//COP�¼�
//��ĳ��16λ�Ĵ�����ֵ��ֵ��Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_COP16(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ��32λ�Ĵ�����ֵ��ֵ��Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_COP32(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ��48λ�Ĵ�����ֵ��ֵ��Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_COP48(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����

//SET�¼�
//��ָ������ֵ��ֵ��16λĿ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_SET16(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short data, 						//16λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ָ������ֵ��ֵ��32λĿ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_SET32(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					long data, 							//32λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ָ������ֵ��ֵ��48λĿ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_SET48(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					__int64 data, 						//64λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����


//OR�¼�
//��ĳ���Ĵ�����ֵ����һ���Ĵ�����ֵ���л����㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_OR16(EventInfo *info,	//�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ����һ���Ĵ�����ֵ���л����㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_OR16B(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ��ָ������ֵ���л����㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_OR16i(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
					short data, 						//16λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ��ָ������ֵ���л����㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_OR16iB(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
					short data, 						//16λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����

//AND�¼�
//��ĳ���Ĵ�����ֵ����һ���Ĵ�����ֵ���������㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_AND16(EventInfo *info,  //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ����һ���Ĵ�����ֵ���������㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_AND16B(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ��ָ������ֵ���������㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_AND16i(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
					short data, 						//16λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ��ָ������ֵ���������㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_AND16iB(EventInfo *info, //�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
					short data, 						//16λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����


//XOR�¼�
//��ĳ���Ĵ�����ֵ����һ���Ĵ�����ֵ����������㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_XOR16(EventInfo *info,	//�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ����һ���Ĵ�����ֵ����������㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_XOR16B(EventInfo *info,	//�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
                    short Src2, short Src2_axis,  		//�Ĵ���2�ĵ�ַ�����Ӧ�����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ��ָ������ֵ����������㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_XOR16i(EventInfo *info,	//�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType, 					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
					short data, 						//16λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����
//��ĳ���Ĵ�����ֵ��ָ������ֵ����������㣬��������浽Ŀ��Ĵ���
IMC_PKG_API int WINAPI PKG_Fill_XOR16iB(EventInfo *info,//�¼��ṹ��ָ�룬�¼�ָ�����¼�����ָ��ָ��ĵ�ַ��
					short  EventType,					//�¼����ͣ���ö��IMC_EventType�еĳ�Ա��ֵ
					short Src1, short Src1_axis, 		//�Ĵ���1�ĵ�ַ�����Ӧ�����
					short data,							//16λ����
                    short dest, short dest_axis);		//Ŀ��Ĵ����ĵ�ַ�����Ӧ�����


//�ײ㺯����װ
//���ö���Ĵ���Ϊָ��ֵ
IMC_PKG_API int WINAPI 
	PKG_IMC_SetMulParam(IMC_HANDLE Handle,	//�豸�����
						WR_MUL_DES pdes[],	//WR_MUL_DES�ṹ�����飻
						int ArrNum,			//pdes��������Ч���ݵĸ�����
						int fifo);			//ָ������ָ��͵��ĸ�FIFO��
//����16λ�Ĵ���Ϊָ��ֵ
IMC_PKG_API int WINAPI 
	PKG_IMC_SetParam16(IMC_HANDLE Handle, 	//�豸�����
						short paramloc,		//�Ĵ�����ַ��
						short data,			//16λ��������
						int axis,			//��ţ�
						int fifo);			//ָ������ָ��͵��ĸ�FIFO��
//����32λ�Ĵ���Ϊָ��ֵ
IMC_PKG_API int WINAPI 
	PKG_IMC_SetParam32(IMC_HANDLE Handle, 	//�豸�����
						short paramloc, 	//�Ĵ�����ַ��
						int data, 			//32λ��������
						int axis,			//��ţ�
						int fifo);			//ָ������ָ��͵��ĸ�FIFO��
//����48λ�Ĵ���Ϊָ��ֵ
IMC_PKG_API int WINAPI 
	PKG_IMC_SetParam48(IMC_HANDLE Handle, 	//�豸�����
						short paramloc, 	//�Ĵ�����ַ��
						__int64 data, 		//64λ��������
						int axis,			//��ţ�
						int fifo);			//ָ������ָ��͵��ĸ�FIFO��
//���Ĵ���ĳ��λ��ֵ��Ϊָ��ֵ��1����0��
IMC_PKG_API int WINAPI 
	PKG_IMC_SetParamBit(IMC_HANDLE Handle, 	//�豸�����
						short paramloc, 	//�Ĵ�����ַ��
						short bit,			//�Ĵ�����ĳ��λ����Χ 0 �C 15��
						short val, 			//ָ����ֵ, 1����0��
						int axis,			//��ţ�
						int fifo);			//ָ������ָ��͵��ĸ�FIFO��
//���Ĵ���ָ����λ��ֵ��1��Ϊ0������0��Ϊ1
IMC_PKG_API int WINAPI 
	PKG_IMC_TurnParamBit(IMC_HANDLE Handle, //�豸�����
					short paramloc, 		//�Ĵ�����ַ��
					short bit, 				//�Ĵ�����ĳ��λ����Χ 0 �C 15��
					int axis,				//��ţ�
					int fifo);				//ָ������ָ��͵��ĸ�FIFO��
//��λ������Ĵ�����ĳЩλ
IMC_PKG_API int WINAPI 
	PKG_IMC_ORXORParam(IMC_HANDLE Handle, 	//�豸�����
					short paramloc, 		//�Ĵ�����ַ��
					short ORdata, 			//��Ĵ�����������ֵ��
					short XORdata, 			//��Ĵ�������������ֵ��
					int axis,				//��ţ�
					int fifo);				//ָ������ָ��͵��ĸ�FIFO��
//����FIFOִ�к���ָ�ֱ���Ĵ�����ĳ��λ��Ϊָ��ֵ��ʱΪֹ
IMC_PKG_API int WINAPI 
	PKG_IMC_WaitParamBit(IMC_HANDLE Handle,	//�豸�����
					short paramloc, 		//�Ĵ�����ַ��
					short bit, 				//�Ĵ�����ĳ��λ����Χ 0 �C 15��
					short val, 				//ָ��ֵ��1��0��
					int timeout, 			//��ʱʱ�䣬��λΪ���룻
					int axis, 				//��ţ�
					int fifo);				//ָ������ָ��͵��ĸ�FIFO��
//����FIFOִ�к���ָ�ֱ�������趨��ʱ��Ϊֹ
IMC_PKG_API int WINAPI 
	PKG_IMC_WaitTime(IMC_HANDLE Handle,		//�豸�����
					int time, 				//�ȴ�ʱ�䣬��λΪ����
					int fifo);				//ָ������ָ��͵��ĸ�FIFO��
//����FIFOִ�к���ָ�ֱ���Ĵ�����ֵ��Ϊָ��ֵ��ʱΪֹ
IMC_PKG_API int WINAPI 
	PKG_IMC_WaitParam(IMC_HANDLE Handle, 	//�豸�����
					short paramloc, 		//�Ĵ�����ַ��
					short data, 			//ָ����ֵ��
					int timeout, 			//��ʱʱ�䣬��λΪ���룻
					int axis, 				//��ţ�
					int fifo);				//ָ������ָ��͵��ĸ�FIFO��
//����FIFOִ�к���ָ�ֱ���Ĵ�����ֵ��mask����������ֵ��dataֵ��Ȼ�ʱΪֹ
IMC_PKG_API int WINAPI 
	PKG_IMC_WaitParamMask(IMC_HANDLE Handle,//�豸�����
					short paramloc, 		//�Ĵ�����ַ��
					short mask, 			//��Ĵ������������ֵ
					short data, 			//���ڱȽϵ�ֵ��
					int timeout, 			//��ʱʱ�䣬��λΪ���룻
					int axis, 				//��ţ�
					int fifo);				//ָ������ָ��͵��ĸ�FIFO��
//��ȡ����Ĵ�����ֵ
IMC_PKG_API int WINAPI 
	PKG_IMC_GetMulParam(IMC_HANDLE Handle, 	//�豸�����
					WR_MUL_DES pdes[], 		//WR_MUL_DES�ṹ�����飻
					int ArrNum);			//WR_MUL_DES�ṹ���������Ч��Ա������
//��ȡ16λ�Ĵ�����ֵ
IMC_PKG_API int WINAPI 
	PKG_IMC_GetParam16(IMC_HANDLE Handle, 	//�豸�����
					short paramloc, 		//�Ĵ�����ַ��
					short* data, 			//16λ���ͱ����ĵ�ַ�����ڱ���16λ�Ĵ�����ֵ��
					int axis);				//��ţ�
//��ȡ32λ�Ĵ�����ֵ
IMC_PKG_API int WINAPI 
	PKG_IMC_GetParam32(IMC_HANDLE Handle, 	//�豸�����
					short paramloc, 		//�Ĵ�����ַ��
					int *data, 				//32λ���ͱ����ĵ�ַ�����ڱ���32λ�Ĵ�����ֵ��
					int axis);				//��ţ�
//��ȡ48λ�Ĵ�����ֵ
IMC_PKG_API int WINAPI 
	PKG_IMC_GetParam48(IMC_HANDLE Handle, 	//�豸�����
					short paramloc, 		//�Ĵ�����ַ��
					__int64 *data, 			//64λ���ͱ����ĵ�ַ�����ڱ���48λ�Ĵ�����ֵ��
					int axis);				//��ţ�

//�����õ��¼���װ�����ƿ���
IMC_PKG_API int WINAPI 
	PKG_IMC_InstallEvent(IMC_HANDLE Handle, //�豸�����
					EventInfo pEvent[], 		//�¼��ṹ�����飬���¼���亯����䣻
					int EventNum	//�¼�ָ���������
					);
//ֹͣ��װ���¼�����(ж���¼���
IMC_PKG_API int WINAPI 
	PKG_IMC_StopEvent(IMC_HANDLE Handle); //�豸�����
#endif