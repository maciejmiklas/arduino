#ifndef Hygrometer_H_
#define Hygrometer_H_

#include <Arduino.h>
#include "Log.h"
#include "Util.h"

#define MOISTURE_READ_PIN 0
#define MOISTURE_ADJUST_PIN 2

/*
 * After plant watering the moisture level can jump very high due to the water flowing across sensor.
 * Max time will be calculated as the lowest value during adoption time. Adoption timer starts
 * after we recognize significantly increased moisture level. Default is 10 minutes.
 */
#define MOISTURE_MAX_ADOPT_MS 600000

enum {
	// small change
	MS_CHANGED = 0x01,

	// large change
	MS_INCREASED = 0x02,
	MS_ALL = 0x7F
};

typedef struct {
	uint8_t proc;
	uint8_t maxProc;
	byte status;
} Moisture;

void hygro_init(Moisture *moisture);

void hygro_sample(Moisture *moisture);

#endif /* Hygrometer_H_ */
