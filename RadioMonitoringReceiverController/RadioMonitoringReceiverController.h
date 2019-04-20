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
	public ref class RadioMonitoringReceiverController
	{
	public:
		UINT radioHandle;
		SalSensorInfo salSensorInfo;
		void ConnectRadioReceiver(String^ ip);

		// TODO: 在此处为此类添加方法。
	};
}
