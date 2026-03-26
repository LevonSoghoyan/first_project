#include <stdio.h>
#include "todo.h"
#include <string.h>
#include <stdlib.h>
#define FILE_NAME "task.txt"

void add(char *desc) 
{

	int id=0;
	char line[256];
	FILE* read = fopen(FILE_NAME,"r");

	if (read) {
	
		while (fgets(line,sizeof(line),read)) {
				id++;

		}
	}
	fclose(read);
	
	FILE* fp = fopen(FILE_NAME,"a");
	
	if (!fp) {
		
		printf("file cant opend");
	}
	fprintf(fp,"%s %d %d\n",desc,id,0);
	fclose(fp);
} 

void clear()
{

	FILE* fp = fopen(FILE_NAME,"w");

	if(!fp) {

		printf("file cant opend");

	}
	fclose(fp);
}


void done(int taskId) 
{
	Task temp;
	FILE* fr = fopen(FILE_NAME,"r");

	if(!fr) {
		printf("F/O eror");
		fclose(fr);
	}

	int count = 0;
	Task *pTemp;
	while(fscanf(fr,"%s %d %d",temp.description,&temp.id,&temp.is_complete) == 3) {
	

		Task *pNewTemp = realloc(pTemp,(count + 1) * sizeof(Task));
		pNewTemp[count] = temp;
		count++;
		pTemp=pNewTemp;
		
	}

	fclose(fr);
	FILE* fw = fopen(FILE_NAME,"w");

	if(!fw) { 
		printf("F/O error");
		fclose(fw);
	}
	pTemp[taskId].is_complete = 1;
	
	for(int i = 0; i < count; i++) {
		
		fprintf(fw,"%s %d %d\n",pTemp[i].description,pTemp[i].id,pTemp[i].is_complete);
	}
	
	fclose(fw);
	free(pTemp);
	
}

void list() 
{

	char line[256];	
	char print_line[256];
	Task temp;
	FILE* read = fopen(FILE_NAME,"r");
	if(read) {
		while(fscanf(read,"%s %d %d",temp.description,&temp.id,&temp.is_complete) == 3) {
		printf("%s|%d|%d\n",temp.description,temp.id,temp.is_complete);
		}

	}
	fclose(read);
}
