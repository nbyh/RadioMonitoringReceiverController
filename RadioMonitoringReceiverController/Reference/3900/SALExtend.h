#ifndef __EISALEXT_H
#define __EISALEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "EISAL.h"

enum SelfSurveyCmd
{
	SELF_SURVEY_RESTART = 0x0,
	SELF_SURVEY_SAVE = 0x1,
	SELF_SURVEY_DELETE = 0x2,
};

enum GPSMode
{
	GPS_FIX_MODE,
	GPS_PVT_MODE,
};

//----------------------------------GPS---------------------------------//
SAL_API salSetSelfSurveyCmd(salHandle sensorHandle, SelfSurveyCmd cmd);
SAL_API salSetSelfSurveyLength(salHandle sensorHandle, int length);
SAL_API salSetInitialPosition(salHandle sensorHandle, salLocation* location);
SAL_API salSetGPSMode(salHandle sensorHandle, GPSMode mode);
/*
 * ��ȡGPS����ģ��״̬ timeAlarms:���ջ����� 
 * 0~15λ(��1��ʾ�о��棬û�ἰ��λ������)
   0: 
   1: ���߿�·
   2: ���߶�·
   3: û�и��ٵ�����
   4: 
   5: survey������
   6: ��λ��Ϣ�޼�¼
   7: ����
   8: ����ģʽ
   9: ��λ����
   10:
   11:����δ���
   12:����������
   13:
   14:
   15:
   16~23λ		0					1
   16:			GPS time			UTC time
   17:			GPS PPS				UTC PPS
   18:			ʱ��ȷ��				ʱ��δȷ��
   19:			��UTC��Ϣ			��UTC��Ϣ
   20:			Time from user		Time form GPS
   24~31λ
   1�ֽ��޷����� ���Ȱٷֱ�
 */
//----------------------------------developer----------------------------//
SAL_API salGetGPSStatus(salHandle sensorHandle, salUInt32* timeAlarms);
SAL_API salADCAdjust(salHandle sensorHandle, salUInt32 calA, salUInt32 calB);
SAL_API salResetTunner(salHandle sensorHandle);
SAL_API salResetConnection(salHandle sensorHandle);
SAL_API salSetSensorNetworkParms(salSensorHandle sensorHandle, const char* ip, const char* msk, const char* gateway);
//----------------------------------file transfer----------------------------//
SAL_API salSendFileToSensor(salSensorHandle sensorHandle, const TCHAR* localFilePath, const TCHAR* sensorFilePath);
SAL_API salGetFileFromSensor(salSensorHandle sensorHandle, const TCHAR* localFilePath, const TCHAR* sensorFilePath);
SAL_API salLoadCalFile(salSensorHandle sensorHandle, const TCHAR* calFilePath, BOOL deleteFile);
//------------------------------------fast access--------------------------//
SAL_API salDiscoveredSensorInfo(salSensorInfo* infos, salUInt32* numSensors);
SAL_API salManagedSensorStatus(salSensorStatus2* status, salUInt32* numSensors);
//------------------------------------status period report-----------------//
//set sensor report period in second unit
SAL_API salBeginReport(char* sensorName, DWORD reportPeriod);
SAL_API salEndReport(char* sensorName);
SAL_API salRemoveAllSensors();
#ifdef __cplusplus
}
#endif

#endif /*__EISALEXT_H */