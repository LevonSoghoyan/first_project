#include <stdio.h>
#include "todo.h"
#include <string.h>
#include <stdlib.h>
#define FILE_NAME "task.txt"

void add(char *desc) {

	int id=0;
	char line[256];
	FILE* read=fopen("task.txt","r");

	if (read) {
	
		while (fgets(line,sizeof(line),read)) {
				id++;

		}
	}
	printf("point 1");
	fclose(read);
	
	
	FILE* fp=fopen(FILE_NAME,"a");
	
	if (!fp) {
		
		printf("file cant opend");
	}
	printf("Point 2");
	fprintf(fp,"%s|%d|%d \n",desc,id,PENDING);
	fclose(fp);
} 

void clear() {

	FILE* fp=fopen(FILE_NAME,"w");

	if(!fp) {

		printf("file cant opend");

	}
	fclose(fp);
}


void done(int task_id) {
	
	Task temp;

	FILE* fr=fopen(FILE_NAME,"r");
	FILE* fw=fopen(FILE_NAME,"w");
	
	while(fscanf(fr,"%d %s %d",&temp.id,temp.description,(int*)&temp.is_complete)==3) {
		
		if(temp.id==task_id) {	
		
			temp.is_complete=DONE;
		}

		fprintf(fw,"%d|%s|%d",temp.id,temp.description,temp.is_complete);
	}

	fclose(fr);
	fclose(fw);

}

void list() {

	char line[256];	
	char print_line[256];
	FILE* read=fopen(FILE_NAME,"r");
	if(read){
		while(fgets(line,sizeof(line),read)){
			sscanf(line,"%s",print_line);
			printf("%s\n",print_line);
		}

	}
	fclose(read);
}
