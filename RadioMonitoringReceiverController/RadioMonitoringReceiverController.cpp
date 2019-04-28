#include "pch.h"
#include "RadioMonitoringReceiverController.h"

using namespace System::Runtime::InteropServices;
using namespace RadioMonitoringReceiverController;

salHandle sensorHandle, measHandle;
salErrorType error;
void RadioReceiverCtrl::ConnectRadioReceiver(String^ ip)
{
	char *ipchar = (char*)Marshal::StringToHGlobalAnsi(ip).ToPointer();
	error = salConnectSensor2(&sensorHandle, 0, ipchar, NULL, 0);
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
	
}

void RadioReceiverCtrl::AddSensorToSms()
{
	
}

void RadioReceiverCtrl::RemoveSensorFromSms()
{
	
}

void RadioReceiverCtrl::RemoveSensor()
{
	
}

void RadioReceiverCtrl::BeginReport()
{
	
}

void RadioReceiverCtrl::EndReport()
{
	
}

void RadioReceiverCtrl::ManagedSensorStatus()
{
	
}

void RadioReceiverCtrl::DiscoverSensors()
{
	
}

void RadioReceiverCtrl::GetNextDiscoveredSensor()
{
	
}

void RadioReceiverCtrl::OpenSensorList()
{
	
}

void RadioReceiverCtrl::GetNextSensor()
{
	
}

void RadioReceiverCtrl::CloseSensorList()
{
	
}

void RadioReceiverCtrl::RebootSensor()
{
	
}

void RadioReceiverCtrl::CloseSensor()
{
	
}

void RadioReceiverCtrl::ComputeFftSegTableSize()
{
	salSweepComputationParms* sscp;
	sscp->startFrequency = 123;
	sscp->stopFrequency = 123;
	sscp->rbw = 1233;
	salSweepParms ssp;
	ssp.numSweeps = 123;
	salSweepComputationResults result;
	errno = salComputeFftSegmentTableSize(sscp, &ssp, &result);

}

void RadioReceiverCtrl::InitFftSegTabel()
{
	
}

void RadioReceiverCtrl::StartSweep()
{
	
}

void RadioReceiverCtrl::GetSegData()
{
	
}

void RadioReceiverCtrl::SendSweepCmd()
{
	
}

void RadioReceiverCtrl::SetTuner()
{
	
}

void RadioReceiverCtrl::GetTuner()
{
	
}

void RadioReceiverCtrl::RequestTimeData()
{
	
}

void RadioReceiverCtrl::GetTimeData()
{
	
}

void RadioReceiverCtrl::SendTimeDataCmd()
{
	
}

void RadioReceiverCtrl::RequestDemodData()
{
	
}

void RadioReceiverCtrl::GetDemodData()
{
	
}

void RadioReceiverCtrl::SendDemodCmd()
{
	
}

void RadioReceiverCtrl::StartIqSweep()
{
	
}

void RadioReceiverCtrl::GetIqSweepData()
{
	
}

void RadioReceiverCtrl::SendIqSweepCmd()
{
	
}

