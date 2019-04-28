#pragma once
using namespace System;

public ref struct SalSensorInfo
{
	String macAddress;
	String modelNumber;
	String serialNumber;
	String hostName;
	String ipAddress;
	String smsAddress;
	String revision;
};
public ref struct SalSweepCompuParms
{
	double startfreq;
	double endfreq;
	double rbw;
};
public ref struct SalSweepParms {
	unsigned long numSweeps;
	unsigned long numSegments;
	SalWindowType window;
	unsigned long userWorkspace;
	SalDataType dataType;
	long reserved1;
	long syncSweepEnable;
	double sweepInterval;
	unsigned long syncSweepSec;
	unsigned long syncSweepNSec;
	SalMonitorMode monitorMode;
	double monitorInterval;
	unsigned int reserved;
};
public ref struct SalFrequencySegment {
	SalAntennaType antenna;
	long preamp;
	unsigned long numFftPoints;
	SalAverageType averageType;
	unsigned long numAverages;
	unsigned long firstPoint;
	unsigned long numPoints;
	unsigned long repeatAverage;
	double attenuation;
	double centerFrequency;
	double sampleRate;
	double duration;
	unsigned long long frequencyTriggerControl;
	SalOverlapType overlapMode;
	SalFftDataType fftDataType;
	long noTunerChange;
	unsigned long noDataTransfer;
	unsigned long long levelTriggerControl;
};
public ref struct SalSegmentData {
	unsigned long userWorkspace;
	unsigned long sequenceNumber;
	unsigned long sweepIndex;
	unsigned long timestampSec;
	unsigned long timestampNSec;
	unsigned long timeQuality;
	SalLocation location;
	double startFrequency;
	double frequencyStep;
	unsigned long overload;
	SalDataType dataType;
	unsigned long lastSegment;
	SalWindowType window;
	SalAverageType averageType;
	unsigned long numAverages;
	double fftDuration;
	double averageDuration;
	unsigned long isMonitor;
	unsigned long sweepFlags;
	unsigned long timeAlarms; double sampleRate;
};

public ref struct SalLocation {
	double latitude;
	double longitude;
	double elevation;
	String geographicDatum;//length 64 
	double eastVel;
	double northVel;
	double upVel;
	String velocity_unit;//length 32
	unsigned long latitudeType;
	unsigned long longitudeType;
	double rotation;
};

public enum SalOverlapType {
	SalOverlap_on,
	SalOverlap_off,
};
public enum SalFftDataType {
	SalFftData_db,
	SaftData_mag
};
public enum SalAverageType {
	SalAverage_off,
	SalAverage_rms,
	SalAverage_peak,
	SalAverage_unknown
};
public  enum SalAntennaType {
	SalAntenna_TestSignal = -4,
	SalAntenna_Auto = -3,
	SalAntenna_Unknown = -2,
	SalAntenna_Terminated = -1,

	SalAntenna_1 = 0,
	SalAntenna_2 = 1,

	SalAntenna_TestSignal2 = 2,
	SalAntenna_Terminated2 = 3,
	SalAntenna_Auto2 = 4
};
public enum SalDataType {
	SalDATA_TYPE_NONE = -1,
	SalCOMPLEX_32,
	SalCOMPLEX_16,
	SalCOMPLEX_FLOAT32,
	SalREAL_INT8,
	SalREAL_INT8_ALAW,
	SalREAL_INT8_ULAW,
	SalREAL_INT16,
	SalREAL_FLOAT32,
	SalREAL_FLOAT32_DBM,
};
public enum SalMonitorMode {
	SalMonitorMode_off,
	SalMonitorMode_on
};
public enum SalWindowType {
	salWindow_hann,
	salWindow_gaussTop,
	salWindow_flatTop,
	salWindow_uniform,
	salWindow_unknown,
};

ref class SalSensorCliClass
{
public:
	SalSensorCliClass();
};

