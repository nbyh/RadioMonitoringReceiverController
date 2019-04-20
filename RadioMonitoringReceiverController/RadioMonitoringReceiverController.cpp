#include "pch.h"
#include "RadioMonitoringReceiverController.h"

using namespace System::Runtime::InteropServices;

salHandle sensorHandle, measHandle;
salErrorType error;
void RadioMonitoringReceiverController::RadioMonitoringReceiverController::ConnectRadioReceiver(String^ ip)
{
	char ipchar = (char)Marshal::StringToHGlobalAnsi(ip).ToPointer();
	error = salConnectSensor2(&sensorHandle, 0, &ipchar, NULL, 0);
	radioHandle = sensorHandle;
	Marshal::FreeHGlobal((IntPtr)ipchar);
}
