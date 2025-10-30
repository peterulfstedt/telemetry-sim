#define _CRT_SECURE_NO_WARNINGS
#include"sensors.h"
#include"logger.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Save dynamic array to CSV
void save(struct SensorList *data, const char *filename){
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: could not open %s for writing.\n", filename);
        return;
    }
    
    fprintf(fp, "Temperature, Distance, Battery\n");
    
    for (int i=0; i < data->length; i++){
        fprintf(fp, "%.2f, %.2f, %.2f\n",data->DataList[i].tempData,data->DataList[i].distanceData, data->DataList[i].batteryData);
    }
    fclose(fp);
    printf("\nData succesfully saved to %s\n\n", filename);
}

//Load CSV file back into memory
void load(struct SensorList *data, const char *filename){
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open %s for reading.\n", filename);
        return;
    }
    freeMemory(data);
    data->capacity = 2;
    data->DataList = calloc(data->capacity, sizeof(struct Sensors));
    
    float temp, dist, batt;
    while (fscanf(fp, "%f,%f,%f", &temp, &dist, &batt) == 3){
        if (data->length >= data->capacity){
            data->capacity *= 2;
            struct Sensors *tempPtr = realloc(data->DataList, data->capacity * sizeof(struct Sensors));
            if (!tempPtr) {
                printf("Error: memory reallocation failed while loading.\n");
                fclose(fp);
                return;
            }
            data->DataList = tempPtr;
        }
        data->DataList[data->length].tempData = temp;
        data->DataList[data->length].distanceData = dist;
        data->DataList[data->length].batteryData = batt;
        data->length++;
    }
    fclose(fp);
    printf("\nData succesfully loaded from %s\n\n", filename);
}

void view(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open %s\n", filename);
        return;
    }

    char line[128];
    printf("\n--- Contents of %s ---\n", filename);
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("\n--------------------------\n");
    fclose(fp);
}
