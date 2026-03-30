/**************************************************************
* @file  : todo.c
* @brief : Intended for adding and modifying insormation about tasks.
**************************************************************/
#include "todo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILE_NAME "/home/levons/workspace/todoProject/build/task.txt"
/*************************************************************
* @brief Adds new tasks
* @param 
*************************************************************/
void add(char *desc) 
{
    int    count = 0;
    char   *line;
    size_t size = 0;
    // Open file in read mode
    FILE   *read = fopen(FILE_NAME, "r");
    if (!read) {
        printf("F/O error");
        return;
    }
    // Calculating lines count
    while (getline(&line, &size, read) != -1) {
        count++;
    }
    fclose(read);
    // Open file in append mode
    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp) {
        printf("F/O error");
        return;
    }
    /* Append new task*/
    fprintf(fp, "%d %d %s\n", count, 0, desc);
    fclose(fp);
} 
/*************************************************************
* @brief Clear txt file
* @param 
*************************************************************/
void clear()
{
    //Open and close file to clear it
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) { 
        printf("F/O eror");
        return;
    }
    fclose(fp);
}
/*************************************************************
* @brief Mark as done task No taskId
* @param 
*************************************************************/
void done(int taskId) 
{
    Task   temp;
    char   *line;
    size_t size=0; 
    //Open file in read mode
    FILE   *fr = fopen(FILE_NAME, "r");
    if (!fr) {
        printf("F/O eror");
        return;
    }
    //Reading file lines in RAM and allocating memory for next line
    int  count = 0;
    Task *pTemp;
    while (getline(&line, &size, fr) != -1) {
         line[strcspn(line, "\n")] = 0;       
         sscanf(line, "%d %d %255[^\n]", &temp.id, &temp.is_complete, temp.description);
         Task *pNewTemp = realloc(pTemp, (count + 1) * sizeof(Task));
         pNewTemp[count] = temp;
         count++;
         pTemp = pNewTemp;
    }
    fclose(fr);
    //Open file in write mod and write the changed data stored int RAM
    FILE *fw = fopen(FILE_NAME, "w");
    if (!fw) { 
        printf("F/O error");
        return;
    }
    pTemp[taskId].is_complete = 1;
    for (int i = 0; i < count; i++) {
        fprintf(fw, "%d %d %s\n", pTemp[i].id, pTemp[i].is_complete, pTemp[i].description);
    }
    //Free allocated memory
    fclose(fw);
    free(pTemp);
}
/*************************************************************
* @brief  Print all complete task list
* @param 
*************************************************************/
void completeList()
{
    //Open file in read mode
    Task   temp;
    FILE   *fr = fopen(FILE_NAME, "r");
    char   *line = NULL;
    size_t size = 0;
    if (!fr) {
        printf("F/O error");
        return;
    }
    /*Chack if task is done print it*/
    printf("%-20s | %-20s | %-20s\n", "Task ID", "Status", "Description");
    while (getline(&line, &size, fr) != -1) {
        line[strcspn(line, "\n")] = 0;       
        if (sscanf(line, "%d %d %255[^\n]", &temp.id, &temp.is_complete, temp.description) == 3 && temp.is_complete) {
                printf("%-20d | %-20s | %-20s\n",
                   temp.id,
                   temp.is_complete ? "DONE" : "IN PROGRESS",
                   temp.description);
        }
    }
    fclose(fr);
}
/*************************************************************
* @brief Print all task list
* @param 
*************************************************************/
void list()
{
    //Open file in read mode
    Task   temp;
    char   *line = NULL;
    size_t size = 0;
    FILE   *read = fopen(FILE_NAME, "r");
    if (!read) {
        printf("F/O error\n");
        return;
    }
    /*Print tasks list*/
    printf("%-20s | %-20s | %-20s\n", "Task ID","Status","Description");
    while (getline(&line, &size, read) != -1) {
        line[strcspn(line, "\n")] = 0;       
        if (sscanf(line, "%d %d %255[^\n]", &temp.id, &temp.is_complete, temp.description) == 3) {
                printf("%-20d | %-20s | %-20s\n",
                   temp.id,
                   temp.is_complete ? "DONE" : "IN PROGRESS",
                   temp.description);
        }
    }
    free(line);
    fclose(read);
}
void help() {
    printf("Usage\n\n");
    printf("./todo add  <Task descriptioni> --> Adds a new task to the list\n");
    printf("./todo list                     --> Show all task list\n");
    printf("./todo completes                --> Show all complated tasks\n");
    printf("./todo done <ID>                --> To mark task <ID> as completed\n");
    printf("./todo clear                    --> Deletes all tasks\n");
    printf("./todo healp                    --> Show this massage\n");
} 
