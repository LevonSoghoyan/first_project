#include <stdio.h>
#include "todo.h"
#include <string.h>
#include <stdlib.h>
#define FILE_NAME "task.txt"

void add(char *desc) 
{
    int count = 0;
    char   *line;
    size_t size=0;
    // Open file in read mode
    FILE *read = fopen(FILE_NAME,"r");

    // Calculating lines count
    if (read) {
        while (getline(&line,&size,read) != -1) {
            count++;
        }
    }

    fclose(read);
    // Open file in append mode
    FILE *fp = fopen(FILE_NAME,"a");
    
    if (!fp) {
        printf("F/O error");
    }

    // Append new task
    fprintf(fp, "%d %d %s\n", count, 0, desc);
    fclose(fp);
} 

void clear()
{
    //open and close file to clear it
    FILE *fp = fopen(FILE_NAME,"w");

    if(!fp) { 
        printf("F/O eror");
    }
    fclose(fp);
}

void done(int taskId) 
{
    Task   temp;
    char   *line;;
    size_t size=0; 
    //open file in read mode
    FILE *fr = fopen(FILE_NAME,"r");
    if(!fr) {
        printf("F/O eror");
        fclose(fr);
    }
    //reading file lines in RAM and allocating memory for next line
    int count = 0;
    Task *pTemp;

        while (getline(&line,&size,fr) != -1) {
            sscanf(line, "%d %d %s", &temp.id, &temp.is_complete, temp.description);
            Task *pNewTemp = realloc(pTemp,(count + 1) * sizeof(Task));
            pNewTemp[count] = temp;
            count++;
            pTemp = pNewTemp;
        }

    fclose(fr);
    //open file in write mod and write the changed data stored int RAM
    FILE *fw = fopen(FILE_NAME,"w");

    if(!fw) { 
        printf("F/O error");
        fclose(fw);
    }
    pTemp[taskId].is_complete = 1;
    
    for(int i = 0; i < count; i++) {
        
        fprintf(fw,"%d %d %s\n",pTemp[i].id,pTemp[i].is_complete,pTemp[i].description);
    }
    //free allocated memory
    fclose(fw);
    free(pTemp);
    
}

void complateList()
{
    Task temp;
    FILE *fr = fopen(FILE_NAME,"r");

    if(!fr) {
        printf("F/O error");
        fclose(fr);
    }

    while(fscanf(fr,"%d %d %s\n",&temp.id,&temp.is_complete,temp.description) == 3) {
        if(temp.is_complete) {
            printf("%d %s\n",temp.id,temp.description);
        }
    }
    fclose(fr);

}
void list()
{
    Task temp;
    char *line = NULL;
    size_t size = 0;
    FILE *read = fopen(FILE_NAME,"r");

    if (!read) {
        printf("F/O error\n");
        return;
    }

    while (getline(&line, &size, read) != -1) {
        if (sscanf(line, "%d %d %255[^\n]", &temp.id, &temp.is_complete, temp.description) == 3) {
                line[strcspn(line,"\n")] = 0;       
                printf("%d | %s | %s\n",
                   temp.id,
                   temp.is_complete ? "DONE" : "IN PROGRESS",
                   temp.description);
        }
    }

    free(line);
    fclose(read);
}
