#include "cmd_func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void clear(){
	FILE* fp=fopen("task.txt","w");
	if(!fp){
		printf("file cant opend");
	}
	fclose(fp);
}
