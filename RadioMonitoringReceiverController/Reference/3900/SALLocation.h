#ifndef __EISALLOCATION_H
#define __EISALLOCATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "EISAL.h"

/** Information about a timeseries from a geolocation measurement.
 * \ingroup Geolocation
 **/
typedef struct salTimeseriesInfo2 {
    char        sensorName[SAL_MAX_SENSOR_NAME];  /**< Name of sensor that measured the timeseries */
    salLocation location;                  /**< Location of sensor when measurement was made */
    salFloat64  centerFrequency;           /**< Center frequency in Hertz.*/
    salFloat64  sampleRate;                /**< Sample rate used for the time series. */
    salFloat64  bandwidth;                /**<  3 dB bandwidth of the time series. */
    salFloat64  recordLength;              /**< Duration in seconds of the timeseries */
    salUInt32   numSamples;                /**< Number of samples in the timeseries */
	salFloat64  triggerLevel;              /**< Trigger level of the sensor */
	salFloat64  attenuation;               /**< The amount of attenuation the sensor used in dB */
	salUInt32   overload;                  /**< 1 if the sensor overloaded during the timeseries, 0 otherwise */
	salUInt32   timestampSeconds;          /**< Whole seconds part of the time timeseries start time */
	salUInt32   timestampNSeconds;         /**< Fractional seconds part of the time timeseries start time, in nano-seconds */
	char        triggerSource[SAL_MAX_SENSOR_NAME]; /**< Name of sensor that caused this sensor to trigger */
	salFloat64  triggerLatency;            /**< Time difference in seconds between when the triggerSource initiated the trigger and when this sensor triggered  */
	salFloat64  variance1588;              /**< Variance of IEEE-1588 time */
    salUInt32   usedInCalculation;         /**< If non-zero, this time series was used in geolocation calculation */
    salDataType dataType;                  /**< The data type of the returned timeseries data */
} salTimeseriesInfo2;

/** Description of correlation data returned by a location measurement.
 * \ingroup Geolocation */
typedef struct salCorrelationHeader2 {
    char sensorName1[SAL_MAX_SENSOR_NAME];    /**< Name of the first sensor involved in this correlation */
    char sensorName2[SAL_MAX_SENSOR_NAME] ;   /**< Name of the second sensor involved in this correlation */
    salFloat64 firstX;                        /**< X value in seconds of first point */
    salFloat64 deltaX;                        /**< Step in seconds between X values */
	salInt32    numPoints;                    /**< Number of points */
    double peakX;							  /**< X location of peak Y value */
	double rho;								  /**< rho for this cross-correlation */
	char xUnit[SAL_MAX_UNIT];				  /**< X unit label */
	char yUnit[SAL_MAX_UNIT];				  /**< Y unit label */
} salCorrelationHeader2;

/** Description of spectrum data returned by a location measurement.
 * \ingroup Geolocation */
typedef struct salSpectrumHeader2 {
    char sensorName[SAL_MAX_SENSOR_NAME];     /**< Name of the sensor that captured the time series with this spectrum */
    salFloat64 centerFrequency;               /**< Center frequency in Hertz*/
    salFloat64 span;                          /**< Frequency span between first point and last point in Hertz */
    salUInt32 numPoints;                      /**< Number of points */
	double firstX;							  /**< Start frequency */
	double deltaX;							  /**< Bin width */
	char xUnit[SAL_MAX_UNIT];				  /**< X unit label */
	char yUnit[SAL_MAX_UNIT];				  /**< Y unit label */
	salInt32 usedInCalculation;			  	  /**< If nonzero, this sensor was used in geolocation measurement */
} salSpectrumHeader2;
/** Input parameters for a location measurement.
 * \ingroup Geolocation
 **/



/** Description of a single geolocation algorithm.
 * \ingroup Geolocation */
typedef struct salGeolocationAlgorithm {
	char id[SAL_MAX_FILENAME];				 /**< ID for this algorithm. This must be provided in the salLocateResultParms struct */
	char name[SAL_MAX_FILENAME];			 /**< Descriptive name for this algorithm. */
} salGeolocationAlgorithm;

/** Get all geolocation algorithms.
  * \param smsHandle [in] Handle to the SMS session.
  * \param numAlgorithms [out] Number of algorithms.
  * \param algorithmTable [out] The returned value from the sensor.  This is a pointer to the correct
  *                       sized memory for that attribute.  It is the user's responsibility to
  *                       pass the correct pointer and to have allocated the memory.
  * \param bufferSize [in] The size in bytes of the memory pointed to by attributeValue. 
  * \return salErrorType error value
  * \ingroup Geolocation
  */
SAL_API salGetAlgorithms(salHandle smsHandle, salUInt32 *numAlgorithms, void *algorithmTable, salUInt32 bufferSize);


typedef struct salLocateMeasParms2 {
    salUInt32      numSensors;       /**< Number of sensors to use. 0 means use all sensors in the SMS configured for a geolocation measurement. 
                                          If numSensors is not 0, there must be numSensor elements in the sensorTable parameter in the calling function. */
    salFloat64     frequency;         /**< The center frequency of the signal to be located in Hertz. */
    salFloat64     bandwidth;         /**< The 3dB-bandwidth of the measurement in Hertz. Must be less than or equal to 10 MHz. */
    salAntennaType antenna;           /**< Which antenna input to use */
    salFloat64     attenuation;       /**< Attenuation in dB relative to measured optimum attenuation */
    salUInt32      numSamples;        /**< Number of samples to use for the measurement */
    salTriggerType triggerType;       /**< The type of triggering to use for this measurement  */
    salFloat64     triggerLevel;      /**< Units are db or dBm depending on the triggerType */
    salInt32       triggerTimeSecs;   /**< Trigger whole seconds; used only when using time trigger */
    salInt32       triggerTimeNSecs;   /**< Trigger fractional seconds; used only when using time trigger */
    salFloat64     timeout;           /**< A timeout in seconds, after which the location measurement will be aborted */
    salPriority    priority;          /**< The priority of this measurement. */
	salFloat64     triggerHoldoff;    /**< Adjustment to timestamp (in seconds) when triggerType is salTrigger_relativeLevel or salTrigger_absoluteLevel. */
	salFloat64     triggerMinimumInterval; /**< Minimum spacing between measurements (in seconds) when triggerType is salTrigger_relativeLevel or salTrigger_absoluteLevel.  */
} salLocateMeasParms2;

typedef enum salAntennaOverride {
     salAntennaOverride_none        = 0,
     salAntennaOverride_useAntenna1 = 1,
     salAntennaOverride_useAntenna2 = 2
} salAntennaOverride;


/** Individual sensor information for a geolocation measurement.
 * \ingroup Geolocation
 **/
typedef struct salGeoSensorSetup {
    char                 sensorName[SAL_MAX_SENSOR_NAME];
    salInt32             disableTrigger;        /**<  if non-zero, do not use this sensor for level triggering */
    salAntennaOverride   antennaOverride;       /**<  allows using a different antenna than specified by salLocateMeasParms2.antenna */
	salInt32             useTriggerLevel;       /**<  if 0, use the learn environment; otherwise use the supplied trigger level */
    salInt32             reserved1;             /**<  reserved for future use */
    salFloat64           triggerLevel;          /**<  absolute trigger level in dBm (useTriggerLevel must be set to non-zero) */
    salFloat64           addAttenuation;        /**<  amount of attenuation in dB to add to salLocateMeasParms2.attenuation for this sensor. */
    salFloat64           addThreshold;          /**<  additional dB to add to salLocateMeasParms2.triggerLevel for this sensor */
    salFloat64           reserved2;             /**<  reserved for future use */
} salGeoSensorSetup;

/** Control the results returned by location measurements.
 * \ingroup Geolocation 
 *  
*/
typedef struct salLocateResultParms2 {
    salRegion              region;          /**< Geographic region over which to compute measurement */
    salLocateImageParms    imageParms;      /**< Requested image details.*/
    salLocateOutput        outputTypes;     /**< Bitmap to indicate which output types (correlation, image, etc.) to include with results. */
    salDopplerCompensation dopplerComp;     /**< Doppler compensation OFF/ON/AUTO */
    char geolocationAlgorithm[SAL_MAX_FILENAME];  /**< ID of the Geolocation Algorithm */
    salInt32               userWorkspace;   /**< User-supplied value that will be returned in the ::SAL_LOCATE_CALLBACK and in ::salLocateResult*/
    salUInt32              numSensorsMax;   /**< Hint on how many sensors may be used for this measurement.  
                                              *  If salMeasureLocation2() is called with salLocateMeasParms2.sensorGroupHandle set to zero, the SAL API
                                              *  does not know how many sensors will be used. The SAL API allocates space for the results for 5 sensors
                                              *  as a minimum. If numSensorsMax is greater than 5, space will be allocated for numSensorsMax. */
    salHandle             excludeSensorGroup; /**< Handle to the group of sensors to exclude from the measurement. 0 means use all sensors with timeseries data. */

} salLocateResultParms2;


/** Request a new geolocation measurement
 * \ingroup Geolocation
 * \param locateHandle [out] User memory location to hold the new location measurement handle.
 * \param smsHandle [in]  Handle returned by salOpenSms().
 * \param measParms       [in] Parameters that control the location measurement
 * \param resultParms     [in] Parameters that control the location results
 * \param callback        [in] Callback function that will be called when the location measurement is completed
 *                             or stopped. Set to NULL (0) if you do not want to use callbacks.
 * \param pSensorTable    [in] Pointer to senor table. The table must contain measParms.numSensors salGeoSensorSetup structures.
 * \remarks 
 *
 * \par
 *  If measParms.numSamples is set to 0, the default number of samples (::SAL_MAX_GEOLOCATION_SAMPLES ) will be used.
 * \par
 *  If all four members (north,south, east, and west) of resultParms.region are set to zero, the region will be set to a region that
 *  encompasses all of the sensors in the measurement.
 * \par
 *  If you want to request a measurement at a time in the past (a lookback measuremet), you must set the sensor tuners
 *  to an appropriate center frequency and sample rate before requesting a measurement. For best results, all tuners 
 *  should be set to the same center frequency and sample rate. If the tuners cannot be set to the same center frequency and
 *  sample rate, they should be set to as high a sample rate as possible to minimize digiltal filter errors between the
 *  different downconverted time series. salSetTunerGroup() can be used to set a group of tuners.
 * \par
 *  This function returns before the measurement completes; you can use salGetLocationStatus() to query the status of the measurement.
 * \par
 *  Call salClose() when you no longer need access to the measurement results. 
 *          
  * \return salErrorType error value
  * \see \ref Geolocation \n
  *           salSetTunerGroup() \n
  *           salGetLocationStatus() \n
  *           salGetLocationResult2() \n
  *           salGetTimeseriesInfo2() \n
  *           salGetSpectrum2() \n
  *           salGetCorrelation2() \n
  *           salGetLocationImage() \n
  *           salMeasureLocationAbort() \n
  *           salClose()
  *           
*/
SAL_API  salMeasureLocation2(salHandle *locateHandle, salHandle smsHandle, salLocateMeasParms2 *measParms, 
                             salLocateResultParms2 *resultParms, SAL_LOCATE_CALLBACK callback, salGeoSensorSetup *pSensorTable);

/** Request data for a geolocation measurement, but do not do the geolocation calculation
 * \ingroup Geolocation
 * \param locateHandle [out] User memory location to hold the new location measurement handle.
 * \param smsHandle [in]  Handle returned by salOpenSms().
 * \param measParms       [in] Parameters that control the location measurement
 * \param callback        [in] Callback function that will be called when the location measurement is completed
 * \param userWorkspace   [in] User-defined value that will be returned with measurement results.
 *                             or stopped. Set to NULL (0) if you do not want to use callbacks.
 * \param pSensorTable    [in] Pointer to senor table. The table must contain measParms.numSensors salGeoSensorSetup structures.
 * \remarks 
 *
 *  This function requests the SMS to acquire time data on the specified sensors. The data will be saved in the SMS database for
 *  later processing using a geolocation algorithm.
 *
 * \par
 *  If measParms.numSamples is set to 0, the default number of samples (::SAL_MAX_GEOLOCATION_SAMPLES ) will be used.
 * \par
 *  This function returns before the measurement completes, You can use salGetLocationStatus() to query the status of the measurement.
 * \par
 *  If you want to request a measurement at a time in the past (a lookback measuremet), you must set the sensor tuners
 *  to an appropriate center frequency and sample rate before requesting a measurement. For best results, all tuners 
 *  should be set to the same center frequency and sample rate. If the tuners cannot be set to the same center frequency and
 *  sample rate, they should be set to as high a sample rate as possible to minimize digiltal filter errors between the
 *  downconverted time series. salSetTunerGroup() can be used to set a group of tuners.
 * \par
 * \par
 *  Call salClose() when you no longer need access to the measurement results. 
 *          
  * \return salErrorType error value
  * \see \ref Geolocation \n
  *           salSetTunerGroup() \n
  *           salGetLocationStatus() \n
  *           salMeasureLocationAbort() \n
  *           salClose()
*/
SAL_API salAcquireLocationData(salHandle *locateHandle, salHandle smsHandle, salLocateMeasParms2 *measParms, 
                                salInt32  userWorkspace, SAL_LOCATE_CALLBACK callback, 
                                salGeoSensorSetup *pSensorTable);

/** Request a previous location measurement from the database
 * \ingroup Geolocation
 * \param locateHandle [out] User memory location to hold the new location measurement handle.
 * \param smsHandle [in]  Handle returned by salOpenSms().
 * \param measurementId   [in] Identifier that was assigned when measurement was made. 
 * \param parms           [in] Parameters that control the data that is being returned.
 * \param callback        [in] Callback function that will be called when the location measurement is completed
 *                 or stopped. Set to NULL (0) if you do not want to use callbacks.
 * \remarks 
 * When a new TDOA location measurement is performed, a measurementId is assigned to the measurement. The 
 * salMeasureLocation() function returns the measurementId in the ::salLocateResult structure. The measurementId is
 * also appears in the historic measurement table in the SMT. 
 * \par
 *  This function returns before the measurement completes, You can use salGetLocationStatus() to query the status of the measurement.
 * \par
 * Call salClose() when you no longer need access to the measurement results.   
 * \return salErrorType error value
 * \see \ref Geolocation \n
  *           salGetLocationStatus() \n
  *           salGetLocationResult2() \n
  *           salGetTimeseriesInfo2() \n
  *           salGetSpectrum2() \n
  *           salGetCorrelation2() \n
  *           salGetLocationImage() \n
  *           salMeasureLocationAbort() \n
  *           salClose()
*/
SAL_API salRecalculateLocation2(salHandle *locateHandle, salHandle smsHandle, salInt32 measurementId, salLocateResultParms2 *parms, SAL_LOCATE_CALLBACK callback);


/** Abort a previous location measurement started with salMeasureLocation() or salMeasureLocation2()
 * \ingroup Geolocation
 * \param locateHandle [in] Measurement handle returned by call to salMeasureLocation() or salMeasureLocation2().
 * \remarks 
 * If the measurement is currently queued, it will be removed from the queue. If the measurement is in progress, the measurement will be aborted if possible.
 * If the measurement has already been completed, the measurement will not be removed from the database; no error will be returned.
 * After calling this command, you can check on the status of the measurement with ::salGetLocationStatus(). This command does not close the locateHandle;
 * you still need to call ::salClose() after the measurement is aborted.
 * \par
 * \return salErrorType error value
 * \see \ref Geolocation
*/
SAL_API salMeasureLocationAbort(salHandle locateHandle);

/** Get information about a timeseries used in a TDOA location measurement
 * \ingroup Geolocation
 * \param locateHandle [in] Unique location measurement handle returned by salMeasureLocation() or salRecalculateLocation().
 * \param sensorIndex     [in] Index of sensor you want data for; must be >=0 and < numSensors.
 * \param info            [out] Pointer to user-allocated memory to hold the salTimeseriesInfo2 structure.
 * \param buffer          [out] Pointer to buffer to hold amplitude data.
 * \param numBytesInBuffer  [in] Size in bytes of buffer.
 * \return salErrorType error value
 * \remarks The salTimeseriesInfo contains information about the sampled time measurement made
 *          at a sensor as part of a TDOA measurement. There will be one salTimeseriesInfo structure
 *          for each sensor used in a measurement. For this release, data is always returned as salCOMPLEX_FLOAT32. If
 *          time series data is not available, no error is retued, but the dataType will be salDATA_TYPE_NONE.
 * \see \ref Geolocation
*/
SAL_API salGetTimeseriesInfo2(salHandle locateHandle, salUInt32 sensorIndex, salTimeseriesInfo2 *info, 
                              void *buffer, salUInt32 numBytesInBuffer);

/** Get a specified spectrum result
 * \ingroup Geolocation
 * \param locateHandle [in] Unique location measurement handle returned by salMeasureLocation() or salRecalculateLocation().
 * \param sensorIndex     [in] Sensor index; must be between 0 and n-1, where n is the number of sensors used in the measurement.
 * \param dataHeader      [out] Pointer to user-allocated memory for the spectrum data header.
 * \param buffer          [out] Pointer to user-allocated memory for the spectrum amplitude data.
 * \param numBytesInBuffer [in]  Size of buffer in bytes.
  * \return salErrorType error value
  * \remarks The spectrum amplitude data is returned in the memory pointed to by buffer. The amplitude units are dBm.
  *          The buffer must be large enough to hold ::SAL_LOCATION_SPECTRUM_POINTS 32 bit floating point values.
  * 
  * \see \ref Geolocation
*/
SAL_API salGetSpectrum2(salHandle locateHandle, salUInt32 sensorIndex,  salSpectrumHeader2 *dataHeader, salFloat32 *buffer, salUInt32 numBytesInBuffer);


/** Get a specified correlation result
 * \ingroup Geolocation
 * \param locateHandle      [in] Unique location measurement handle returned by salMeasureLocation() or salRecalculateLocation().
 * \param sensorIndex1         [in] Sensor index;  must be between 0 and n-2, where n is the number of sensors used in the measurement.
 * \param sensorIndex2         [in] Sensor index;  must be between index1+1 and n-1, where n is the number of sensors used in the measurement.
 * \param dataHeader           [out] Pointer to user-allocated memory for the correlation data header.
 * \param buffer               [out] Pointer to user-allocated memory for the correlation amplitude data. 
 * \param numBytesInBuffer     [in]  Size of buffer in bytes.
 * \remarks The correlation amplitude data is returned in the memory pointed to by buffer. The amplitude units are dBm.
 *           The buffer must be large enough to hold ::SAL_LOCATION_CORRELATION_POINTS 32 bit floating point values.
  * \return salErrorType error value
  * \see \ref Geolocation
*/
SAL_API salGetCorrelation2(salHandle locateHandle, salUInt32 sensorIndex1, salUInt32 sensorIndex2, salCorrelationHeader2 *dataHeader, salFloat32 *buffer, salUInt32 numBytesInBuffer);

/** Information about a location measurement.
 * \ingroup Geolocation */
typedef struct salLocateResult2 {
    salErrorType  errorCode;        /**< If an error occurred during the measurement, it is reported here */
    salInt32      measurementId;    /**< Measurement identifier. Use this number to recall measurements with salRecalculateLocation(). */
    salInt32      userWorkspace;    /**< User-defined value passed in with salLocateResultParms2.userWorkspace */
    salLocation   location;         /**< Computed signal location */
    salFloat64    resultQuality;    /**< A quality indicator for the result (0-1.0) */
    salInt32      numSensors;       /**< how many sensors were used to make the measurement  */
    salInt32      numImageBytes;     /**< Size in bytes of location measurement image */
    salLocateOutput validData;      /**< Bitmask of available data types for this measurement */
    salFloat64    cepRadius;        /**< Radius in meters of circular error probable */
    salFloat64    cepProbability;    /**< Probabilty (0-1.0) used for cepRadiusMeters calculation */
    char          reserved1[SAL_MAX_FILENAME]; /**< reserved for future use */
    salFloat64    reserved2;         /**< reserved for future use */
    salFloat64    reserved3;         /**< reserved for future use */
    salInt32      reserved4;         /**< reserved for future use */
    salInt32      reserved5;         /**< reserved for future use */
} salLocateResult2;

/** Get a location measurement result.
 * \ingroup Geolocation
 * \param locateHandle [in] Unique location measurement handle returned by salMeasureLocation() or salRecalculateLocation().
 * \param result          [out] Measurement result.
  * \return salErrorType error value
   * \see \ref Geolocation
*/
SAL_API salGetLocationResult2(salHandle locateHandle, salLocateResult2 *result);


#ifdef __cplusplus
}
#endif

#endif /*__EISALLOCATION_H */
