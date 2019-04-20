#include "Windows.h"
#include "EISAL.h"
#include "SALExtend.h"
#include "SalFrequency.h"
#include "SalTimeData.h"
#include "SALLocation.h"
#include "SalSensorCliClass.h"
#pragma once

using namespace System;

namespace RadioMonitoringReceiverController {
	public ref class RadioReceiverCtrl
	{
	public:
		UINT radioHandle;
		SalSensorInfo salSensorInfo;

#pragma region 接收机管理
		void ConnectRadioReceiver(String^ ip);
		void DisConnectRadioReceiver();
		void GetAttributeRadioReceiver();
		void GetCapabilitiesRadioReceiver();
		void LockResourceRadioReceiver();
		void BreakResourceLockRadioReceiver();
		void UnlockResourceRadioReceiver();
		void QueryResourceRadioReceiver();
		void AbortAllRadioReceiver();
#pragma endregion

#pragma region 系统管理
		void DiscoveredSensorInfo();
		void AddSensorToSms();
		void RemoveSensorFromSms();
		void RemoveSensor();
		void BeginReport();
		void EndReport();
		void ManagedSensorStatus();
		void DiscoverSensors();
		void GetNextDiscoveredSensor();
		void OpenSensorList();
		void GetNextSensor();
		void CloseSensorList();
		void RebootSensor();
		void CloseSensor();
#pragma endregion

#pragma region 频域扫描
		void ComputeFftSegTableSize();
		void InitFftSegTabel();
		void StartSweep();
		void GetSegData();
		void SendSweepCmd();
#pragma endregion
		
#pragma region 时域扫描
		void SetTuner();
		void GetTuner();
		void RequestTimeData();
		void GetTimeData();
		void SendTimeDataCmd();
		void RequestDemodData();
		void GetDemodData();
		void SendDemodCmd();
#pragma endregion

#pragma region IQ扫描
		void StartIqSweep();
		void GetIqSweepData();
		void SendIqSweepCmd();
#pragma endregion

	};
}
