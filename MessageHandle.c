#include "MessageHandle.h"
#include "BoardParameter.h"
#include <stdint.h>
#include <string.h>

const char* strRxKey[] = {
	// Receive message
	"DoNothing",
	// original command
	"SetTotalVan",
    "SetDownTimeCycle",
    "SetODCCleanMode",
    "SetDPLow",
    "SetDPHigh",
    "SetDPWarn",
    "SetODCHigh",
    "SetODCLow"
	"SetPulseTime",
	"SetIntervalTime",
	"SetCycleIntervalTime",
    "SetOperateHours",
    "SetServiceRun",
    "SetServiceRunAlarm",
	// string value command
	"SetLanguage",
	"SetDisplayRange",
	"SetTestMode",
	"SetParamCode",
	"SetTechCode",
	"SetDPMode",
	// addition command
	"SetVan",
	"SetMultiVan",
	"ClearVan",
	"TrigVan",
	"SetTime",
	"GetTime",
};

const char* strTxKey[] = {
	// Transmit message
	"DoNothing",
	"Van: ",
	"VanState: ",
	"Pressure: ",
	"RTC_Time: ",
	"TotalVan: ",
    "DP-High: ",
    "DP-Low: ",
    "DP-Alarm: ",
    "ODC-High: ",
    "ODC-Low: ",
	"PulseTime: ",
	"IntervalTime: ",
	"CycleIntervalTime: ",
    "OperateHours: ",
    "ServiceRunHours: ",
    "ServiceRunHoursAlarm: ",
};

int32_t MessageRxHandle(char *inputStr, char* outputStr)
{
	uint8_t indexKey = sizeof(strRxKey)/sizeof(char*);
	for(uint8_t i=1;i < indexKey;i++){
		if(strstr(inputStr,strRxKey[i]))
            if(!Brd_SetParamInt(i,1000,inputStr)) 
            // printf("%s\n",s);
			return 0;
	}
	return -1;
}