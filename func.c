
#include <stdio.h>
#include "todo.h"
#include <string.h>
#include <stdlib.h>

typedef struct {
	int id;
	char description[256];
	Done is_complate=NO;
}

void add(char *desc) {

	int id=0;
	char line[256];
	FILE* read=fopen("task.txt","r");

	if (read) {
	
		while (fgets(line,sizeof(line),read)) {
				id++;

		}
	}

	fclose(read);
	
	
	FILE* fp=fopen("task.txt","a");
	
	if (!fp) {
		
		printf("file cant opend");
	}

	fprintf(fp,"%s \n",desc);
	fclose(fp);
} 

void clear(){
	FILE* fp=fopen("task.txt","w");
	if(!fp){
		printf("file cant opend");
	}
	fclose(fp);
}


void done(int task_id) {

}

void list() {

	char line[256];	
	char print_line[256];
	FILE* read=fopen("task.txt","r");
	if(read){
		while(fgets(line,sizeof(line),read)){
			sscanf(line,"%s",print_line);
			printf("%s\n",print_line);
		}

	}
	fclose(read);
}
