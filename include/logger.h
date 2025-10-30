#ifndef LOGGER_H
#define LOGGER_H

#include "sensors.h"

//Function declarations
void save(struct SensorList *data, const char *filename);
void load(struct SensorList *data, const char *filename);
void view(const char *filename);

#endif
