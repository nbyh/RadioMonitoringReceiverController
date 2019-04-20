#pragma once
using namespace System;

public ref struct SalSensorInfo
{
	String ^macAddress;          
	String ^modelNumber;         
	String ^serialNumber;        
	String ^hostName;            
	String ^ipAddress;           
	String ^smsAddress;          
	String ^revision;
};

ref class SalSensorCliClass
{
public:
	SalSensorCliClass();
};

