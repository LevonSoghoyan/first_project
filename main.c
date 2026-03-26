#include "todo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[]) 
{

	if(strcmp(argv[1],"add")==0 && argc>=3){
		add(argv[2]);
	
	}else if(strcmp(argv[1],"done")==0 && argc>=3){
		done(atoi(argv[2]));
	
	}else if(strcmp(argv[1],"list")==0) {
		list();

	}else if( strcmp(argv[1],"clear")==0) {
		clear();

	}else {
		printf("Invalid command\n");
	}
}
