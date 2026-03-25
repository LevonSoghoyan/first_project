#include "todo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
int id;
char description[256];
int in_complate;
} Task;
int main(int argc,char* argv[]){

	if(strcmp(argv[1],"add")==0 && argc==3){
		add(argv[2]);
	}
	else if(strcmp(argv[1],"done")==0 && argc==3){
		done(atoi(argv[2]));
	}
	else if(argc==2 && strcmp(argv[1],"list")){
		list();
	}
	else if(argc==2 && strcmp(argv[1],"clear")){
		clear();
	}
	else{
		printf("Invalid command");
	}
}
