#define _CRT_SECURE_NO_WARNINGS
#include"sensors.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Sensor data function declarations
void read_temperature(float *data);
void read_distance(float *data);
void read_battery(float *data);



//Data-registration function definition
void newData (struct SensorList *data){
    memoryAllocation (data);
    read_temperature(&data->DataList[data->length].tempData);
    read_distance(&data->DataList[data->length].distanceData);
    read_battery(&data->DataList[data->length].batteryData);
}


//Sensor data function definitions
void read_temperature(float *data){
    *data = (rand() % 7000 + 2000) / 100.0;
}
void read_distance(float *data){
    *data = (rand() % 10000) / 100.0;
}
void read_battery(float *data){
    *data = (rand() % 10000) / 100.0;
}





//Dynamic memory allocation function definition
void memoryAllocation(struct SensorList *data){
    if (data->DataList == NULL){
        data->capacity = 2;
        data->DataList = (struct Sensors*)calloc(data->capacity,sizeof(struct Sensors));
    }else{
        if (data->capacity <= data->length){
            data->capacity *=2;
            struct Sensors *temp = realloc(data->DataList, data->capacity * sizeof(struct Sensors));
            if (!temp){
                printf("Could not expand memory!\n");
                return;
            }
            data->DataList = temp;
        }
    }
}

void freeMemory (struct SensorList *data){
    free(data->DataList);
    data->DataList = NULL;
    data->length = 0;
    data->capacity = 0;
}
