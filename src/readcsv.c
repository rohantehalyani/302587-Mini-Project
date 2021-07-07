#include "readcsv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readcsv(int days){

    // initialize file pointer

    FILE *file_p = fopen("Equity.csv","r");
    
    if(file_p == NULL){
            perror("Unable to open the file.");
            return 0;
        }

    char line[100];
    int row_count = 0;
    int col_count = 0;
    float avg = 0;
    
    int i = 0;
    while(fgets(line, sizeof(line), file_p)){
        col_count = 0;
        row_count++;
        if(row_count == 1)
            continue;
        char *field = strtok(line,",");
        while(field != NULL){
            if(col_count == 8){
                printf("%s\n", field);
                avg += (int)(field);
            }
            field = strtok(NULL,",");
            col_count++;
        }
        i++;
    }
    fclose(file_p);
    printf("%d",(i));
    return 0;   

}
