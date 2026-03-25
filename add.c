#include <stdio.h>
#include "todo.h"
#include <string.h>
#include <stdlib.h>
void add(char *desc){
	FILE* fp=fopen("task.txt","a");
	if(!fp){
		printf("file cant opend");
	}
	int id=0;
	char line[256];
	FILE* read=fopen("task.txt","r");
	if(read){
		while(fgets(line,sizeof(line),read)){
			id++;
		}
		fclose(fp);
	}
	fprintf(fp,"%s%d",desc,id);
	fclose(fp);
}
