//
// Created by geoff on 16/07/17.
//

#ifndef GEOS_TIMER_H
#define GEOS_TIMER_H

#include <inttypes.h>
#include "../system.h"


typedef enum time_weekday {
	DAY_SUNDAY = 1,
	DAY_MONDAY = 2,
	DAY_TUESDAY = 3,
	DAY_WEDNESDAY = 4,
	DAY_THURSDAY = 5,
	DAY_FRIDAY = 6,
	DAY_SATURDAY = 7
} weekday_t;

char *DAY_STRINGS[8];

typedef struct rtc_time {
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	weekday_t weekday;
	uint8_t day;
	uint8_t month;
	uint8_t year;
} rtc_time_t;

rtc_time_t getRTCTime(void);

#endif //GEOS_TIMER_H


