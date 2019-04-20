#include "pch.h"
#include "RadioMonitoringReceiverController.h"

using namespace System::Runtime::InteropServices;
using namespace RadioMonitoringReceiverController;

salHandle sensorHandle, measHandle;
salErrorType error;
void RadioReceiverCtrl::ConnectRadioReceiver(String^ ip)
{
	char ipchar = (char)Marshal::StringToHGlobalAnsi(ip).ToPointer();
	error = salConnectSensor2(&sensorHandle, 0, &ipchar, NULL, 0);
	radioHandle = sensorHandle;
	Marshal::FreeHGlobal((IntPtr)ipchar);
	if (errno != SAL_ERR_NONE)
	{
		throw gcnew Exception("接收机连接失败");
	}
}

void RadioReceiverCtrl::DisConnectRadioReceiver()
{
	error = salDisconnectSensor(sensorHandle);
	if (errno != SAL_ERR_NONE)
	{
		throw gcnew Exception("接收机断开失败");
	}
}

void RadioReceiverCtrl::GetAttributeRadioReceiver()
{

}

void RadioReceiverCtrl::GetCapabilitiesRadioReceiver()
{

}

void RadioReceiverCtrl::LockResourceRadioReceiver()
{

}

void RadioReceiverCtrl::BreakResourceLockRadioReceiver()
{

}

void RadioReceiverCtrl::UnlockResourceRadioReceiver()
{

}

void RadioReceiverCtrl::QueryResourceRadioReceiver()
{

}

void RadioReceiverCtrl::AbortAllRadioReceiver()
{

}

void RadioReceiverCtrl::DiscoveredSensorInfo()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::AddSensorToSms()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::RemoveSensorFromSms()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::RemoveSensor()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::BeginReport()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::EndReport()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::ManagedSensorStatus()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::DiscoverSensors()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::GetNextDiscoveredSensor()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::OpenSensorList()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::GetNextSensor()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::CloseSensorList()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::RebootSensor()
{
	throw gcnew System::NotImplementedException();
}

void RadioReceiverCtrl::CloseSensor()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::ComputeFftSegTableSize()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::InitFftSegTabel()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::StartSweep()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::GetSegData()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::SendSweepCmd()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::SetTuner()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::GetTuner()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::RequestTimeData()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::GetTimeData()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::SendTimeDataCmd()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::RequestDemodData()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::GetDemodData()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::SendDemodCmd()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::StartIqSweep()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::GetIqSweepData()
{
	throw gcnew System::NotImplementedException();
}

void RadioMonitoringReceiverController::RadioReceiverCtrl::SendIqSweepCmd()
{
	throw gcnew System::NotImplementedException();
}

