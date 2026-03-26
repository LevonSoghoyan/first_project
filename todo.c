#include <stdio.h>
#include "todo.h"
#include <string.h>
#include <stdlib.h>
#define FILE_NAME "task.txt"

void add(char *desc) 
{

	int id=0;
	char line[256];
	FILE* read = fopen("task.txt","r");

	if (read) {
	
		while (fgets(line,sizeof(line),read)) {
				id++;

		}
	}
	printf("point 1");
	fclose(read);
	
	
	FILE* fp = fopen(FILE_NAME,"a");
	
	if (!fp) {
		
		printf("file cant opend");
	}
	printf("Point 2");
	fprintf(fp,"%s %d %d \n",desc,id,0);
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

	int count  = 0;
	Task *pTemp;
	while(fscanf(fr,"%d %s %d ",&temp.id,temp.description,&temp.is_complete) == 3) {
	

		Task *pNewTemp = realloc(pTemp,(count + 1) * sizeof(Task));
		pNewTemp[count] = temp;
		count++;
		pTemp=pNewTemp;
		
	}
	
	fclose(fr);
	printf("point2");
	FILE* fw = fopen(FILE_NAME,"w");

	if(!fw) { 
		printf("F/O error");
		fclose(fw);
	}
	pTemp[taskId].is_complete = 1;
	
	for(int i = 0; i < count; i++) {
		
		printf("%d %s %d\n",pTemp[i].id,pTemp[i].description,pTemp[i].is_complete);
	}
	
	fclose(fw);
	printf("point3");
}

void list() 
{

	char line[256];	
	char print_line[256];
	FILE* read = fopen(FILE_NAME,"r");
	if(read) {
		while(fgets(line,sizeof(line),read)){
			sscanf(line,"%s",print_line);
			printf("%s\n",print_line);
		}

	}
	fclose(read);
}
