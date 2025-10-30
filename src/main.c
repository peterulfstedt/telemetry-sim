#include "sensors.h"
#include"logic.h"
#include"logger.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void){
    srand((unsigned int)time(0));
    
    struct SensorList sensorList;
    sensorList.length = 0;
    sensorList.DataList = NULL;
    
    int option;
    printf("\n\nWelcome to Command-line simulation of robot sensor system!\n\n");
    
    do{
        printf("Commands:\n");
        printf("1. Start simulation\n");
        printf("2. Save data to CSV\n");
        printf("3. Load data from CSV\n");
        printf("4. View data in CSV\n");
        printf("5. End simulation\n");
        
        printf("Choose your option: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input.\n\n");
            while (getchar() != '\n');
            continue;
        };
        
        switch (option)
        {
            case 1: start(&sensorList); break;
            case 2: save(&sensorList, "data_log.csv"); break;
            case 3: load(&sensorList, "data_log.csv"); break;
            case 4: view("data_log.csv"); break;
            case 5: freeMemory(&sensorList); break;
            default: printf("Please enter valid option (1 - 5).\n\n"); break;
        }
        
    }while(option != 5);
    
    return 0;
}
