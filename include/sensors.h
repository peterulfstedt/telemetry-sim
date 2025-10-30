#ifndef SENSORS_H
#define SENSORS_H

//Struct definitions
struct Sensors {
    float batteryData;
    float distanceData;
    float tempData;
};

struct SensorList {
    struct Sensors *DataList;
    int length;
    int capacity;
};


//Data-registration function declaration
void newData (struct SensorList *data);

//Dynamic memory allocation function declarations
void memoryAllocation (struct SensorList *data);
void freeMemory (struct SensorList *data);

#endif
