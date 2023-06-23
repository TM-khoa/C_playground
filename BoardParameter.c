#include "BoardParameter.h"

uint16_t paramMaxLimit[] = {
        //total
        16,
        //down cyc
        32,
        //clean mode
        5,
        //contrast
        200, 
        //dp low
        4000,
        //dp high
        4000,
        //warn
        5000,
        //odc high
        4000,
        //odc low
        4000,
        //pulse
        300,
        //interval
        500,
        //cyc
        100,
        //oper h
        25000,
        //serv run
        25000,
        //serv alarm
        25000,
};

uint16_t paramMinLimit[] ={
        //total
        0,
        //down cyc
        0,
        //clean mode
        1,
        //contrast
        10,
        //dp low
        250,
        //dp high
        250,
        //warn
        300,
        //odc high
        250,
        //odc low
        250,
        //pulse
        30,
        //interval
        4,
        //cyc
        2,
        //oper h
        0,
        //serv run
        0,
        //serv alarm
        0,
};

uint16_t paramValInt[]= {
        //total
        0,
        //down cyc
        6,
        // clean mode
        3,
        // contrast
        50,
        //dp low
        700,
        //dp high
        1300,
        //warn
        2300,
        //odc high
        1000,
        //odc low
        250,
        //pulse
        60,
        //interval
        10,
        //cyc
        6,
        //oper h
        0,
        // serv run
        3000,
        // serv alarm
        0,
};

const char* paramValString[]={
        "S" // combine with number to form a start of boundary for pararmeter; Ex: S1, S2, S3 ...
        "E" // combine with number to form an end of boundary for pararmeter; Ex: E1, E2, E3 ...

        // Language
        "S1", //start
        "Eng",
        "E1", // end

        // Display range
        "S2", //start
        "Pa",
        "InWc"
        "DisRange",
        "E2", // end

        // Param code
        "S3", //start
        "F2",
        "ParamCode",
        "E3", // end

        // Tech code
        "S4", //start
        "F0",
        "TechCode",
        "E4", // end

        //DP mode
        "S5", // start
        "On",
        "Off",
        "DP mode",
        "E5", // end
};

const char* paramUnit[] = {
        " ",
        "Pa",
        "ms",
        "s",
        "h",
};

const char *paramText[]={
    "Total Van :",
    "Down T Cyc:",
    "Clean Mode:",
    "Contrast  :",
    "DP-Low    :",
    "DP-High   :",
    "DP-Alarm  :",
    "OCD High  :",
    "OCD Low   :",
    "Pulse Time:",
    "Inter Time:",
    "Cycle Time:",
    "OperHours :",
    "Serv Run H:",
    "SerH Alarm:",
    // special param to handle
    "Language  :",
    "dpDisRange:",
    "Test Mode :",
    "Param code:",
    "Tech code :",
    "DP Mode   :",
};

BoardParameter brdParam;



char* Brd_GetUnit(uint8_t index){
        if(index <= INDEX_DISPLAY_CONTRAST){
                return paramUnit[0];
        } else if (index <= INDEX_ODC_LOW){
                return paramUnit[1];
        } else if (index == INDEX_PULSE_TIME){
                return paramUnit[2];
        } else if (index <= INDEX_CYCLE_INTERVAL_TIME){
                return paramUnit[3];
        } else if (index <= INDEX_SERV_RUN_HOURS_ALARM){
                return paramUnit[4];
        }
}

void Brd_SendResponeInt(uint8_t index, uint32_t val, char* outputStr)
{
    strcpy(outputStr,paramText[index]);
    sprintf((outputStr+strlen(outputStr)),"%lu",val);
    strcat(outputStr,Brd_GetUnit(index));
}

void Brd_SendResponeString(uint8_t index, char *valStr, char* outputStr)
{
    strcpy(outputStr,paramText[index]);
    sprintf((outputStr+strlen(outputStr)),"%s",valStr);
}

int32_t Brd_SetParamInt(uint8_t index,uint32_t val,char *outputStr){
    if(val < paramMinLimit[index] || val > paramMaxLimit[index]) return -1;
        if(index >= INDEX_TOTAL_VAN && index <= INDEX_SERV_RUN_HOURS_ALARM){
                switch (index)
                {
                case INDEX_TOTAL_VAN:
                    brdParam.totalVan = (uint8_t)val;
                    break;
                case INDEX_DOWN_TIME_CYCLE:
                    brdParam.downTimeCycle = (uint8_t)val;
                    break;
                case INDEX_ODC_CLEAN_MODE:
                    brdParam.cleanMode =(uint8_t)val;
                    break;
                case INDEX_DISPLAY_CONTRAST:
                    brdParam.contrast =(uint8_t)val;
                break;
                case INDEX_DP_LOW:
                    brdParam.dpLow =(uint16_t)val;
                break;
                case INDEX_DP_HIGH:
                    brdParam.dpHigh =(uint16_t)val;
                break;
                case INDEX_DP_WARN:
                    brdParam.dpWarn =(uint16_t)val;
                break;
                case INDEX_ODC_HIGH:
                    brdParam.odcHigh =(uint16_t)val;
                break;
                case INDEX_ODC_LOW:
                    brdParam.odcLow =(uint16_t)val;
                break;
                case INDEX_PULSE_TIME:
                    brdParam.pulseTime =(uint16_t)val;
                break;
                case INDEX_INTERVAL_TIME:
                    brdParam.intervalTime =(uint16_t)val;
                break;
                case INDEX_CYCLE_INTERVAL_TIME:
                    brdParam.cycIntvTime =(uint16_t)val;
                break;
                case INDEX_OPERATE_HOURS:
                    brdParam.operateHours =(uint16_t)val;
                break;
                case INDEX_SERV_RUN_HOURS:
                    brdParam.servRunHours =(uint16_t)val;
                break;
                case INDEX_SERV_RUN_HOURS_ALARM:
                    brdParam.servAlarm =(uint16_t)val;
                break;
                default:
                    break;
                }
                if(outputStr) Brd_SendResponeInt(index,val,outputStr);
                return 0;
        }       
        return -1; 
}


int32_t Brd_SetParamString(uint8_t index, char* valStr, char *outputStr)
{
        if(index >= INDEX_LANGUAGE && index <= INDEX_DP_MODE){
                if(outputStr) Brd_SendResponeString(index,valStr,outputStr);
                switch (index)
                {
                case INDEX_LANGUAGE:
                    break;
                case INDEX_DISPLAY_RANGE:
                    
                    break;
                case INDEX_TEST_MODE:
                    
                    break;
                case INDEX_PARAM_CODE:
                    
                    break;
                case INDEX_TECH_CODE:
                    
                    break;
                case INDEX_DP_MODE:
                    
                    break;
                default:
                    break;
                }
                return 0;
        }       
        return -1; 
}

RTC_t Brd_GetRTC(){return brdParam.RTCtime;}


uint8_t Brd_GetTotalVan(){return brdParam.totalVan;}
uint8_t Brd_GetDownTimeCycle(){return brdParam.downTimeCycle;}
uint8_t Brd_GetCleanMode(){return brdParam.cleanMode;}
uint8_t Brd_GetContrast(){return brdParam.contrast;}

uint16_t Brd_ParamGetMaxLimit(uint8_t index){return paramMaxLimit[index];}
uint16_t Brd_ParamGetMinLimit(uint8_t index){return paramMinLimit[index];}
uint16_t Brd_ParamGetValueInt(uint8_t index){return paramValInt[index];}
uint16_t Brd_GetDPHigh(){return brdParam.dpHigh;}
uint16_t Brd_GetDPLow(){return brdParam.dpLow;}
uint16_t Brd_GetDPWarn(){return brdParam.dpWarn;}
uint16_t Brd_GetODCLow(){return brdParam.odcLow;}
uint16_t Brd_GetODCHigh(){return brdParam.odcHigh;}
uint16_t Brd_GetPulseTime(){return brdParam.pulseTime;}
uint16_t Brd_GetIntervalTime(){return brdParam.intervalTime;}
uint16_t Brd_GetCycleIntervalTime(){return brdParam.cycIntvTime;}
uint16_t Brd_GetServiceRunHours(){return brdParam.servRunHours;}
uint16_t Brd_GetServiceAlarm(){return brdParam.servAlarm;}

char* Brd_ParamGetValueString(uint8_t index){return paramValString[index];}
char* Brd_ParamGetUnit(uint8_t index){return paramUnit[index];}
char* Brd_GetLanguage(){return brdParam.language;}
char* Brd_GetDisplayRange(){return brdParam.disRange;}
char* Brd_GetTestMode(){return brdParam.testMode;}
char* Brd_GetParamCode(){return brdParam.paramCode;}
char* Brd_GetTechCode(){return brdParam.techCode;}
char* Brd_GetDPMode(){return brdParam.dpMode;}
char* Brd_GetParamText(uint8_t index){return paramText[index];}