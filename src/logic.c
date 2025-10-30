#define _CRT_SECURE_NO_WARNINGS
#include"sensors.h"
#include"logic.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Logic function definitions
void start (struct SensorList *data){
    newData (data);
    printCurrentState (data);
    action (data);
    data->length++;
}

void printCurrentState (struct SensorList *data){
    printf("Temperature: %.2fºC, distance: %.2f cm, battery: %.2f%%\n\n", data->DataList[data->length].tempData, data->DataList[data->length].distanceData, data->DataList[data->length].batteryData);
    
}


void action (struct SensorList *data){
    if (data->DataList[data->length].batteryData < 20){
        printf("Battery: %.2f%%\n", data->DataList[data->length].batteryData);
        printf("Low battery, returning to base\n\n");
        return;
    }
    if (data->DataList[data->length].tempData >= 70){
        printf("Temperature: %.2fºC\n", data->DataList[data->length].tempData);
        printf("Overheating, cooling system on\n\n");
    }
    if (data->DataList[data->length].distanceData <= 10){
        printf("Distance: %.2f cm\n", data->DataList[data->length].distanceData);
        printf("Obstacle detected, changing route\n\n");
    }
}
