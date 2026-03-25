#include <stdio.h>
#include "todo.h"
#include <stdlib.h>
#include <string.h>
void list(){

	char line[256];	
	char print_line[256];
	FILE* read=fopen("task.txt","r");
	if(read){
		while(fgets(line,sizeof(line),read)){
			sscanf(line,"%s",print_line);
			printf("%s",print_line);
		}

	}
	fclose(read);
}
