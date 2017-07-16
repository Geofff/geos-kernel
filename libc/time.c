//
// Created by geoff on 16/07/17.
//

#include "time.h"
#include "interface.h"

char *DAY_STRINGS[] = {"NONEDAY", "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};

rtc_time_t getRTCTime(void) {
	rtc_time_t time;
	time.seconds = getCMOSRegister(0x00);
	time.minutes = getCMOSRegister(0x02);
	time.hours = getCMOSRegister(0x04);
	time.weekday = getCMOSRegister(0x06);
	time.day = getCMOSRegister(0x07);
	time.month = getCMOSRegister(0x08);
	time.year = getCMOSRegister(0x09);
	return time;
}
