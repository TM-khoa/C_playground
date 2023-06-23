#ifndef _MESG_H_
#define _MESG_H_

typedef enum MesgValRX{
	SET_VAN = 1,
	SET_MULTI_VAN,
	CLEAR_VAN,
	PULSE_TIME,
	TOTAL_VAN,
	CYC_INTV_TIME,
	INTERVAL_TIME,
	TRIG_VAN,
	SET_TIME,
	GET_TIME,
}MesgValRX;


#define MESG_PATTERN_KEY_VALUE_INT "%*s %lu" //Ex: SetVan: 10
#define MESG_PATTERN_KEY_VALUE_FLOAT "%*s %f" //Ex: Pressure: 0.2543
#define MESG_PATTERN_KEY_VALUE_STRING "%*s \"%s\"" //Ex: SampleString: "Test String"
#define MESG_PATTERN_KEY_VALUE_TIME "%*s %u/%u/%u %u:%u:%u"//Ex: SetTime: 3/6/23 16:00:00


#endif