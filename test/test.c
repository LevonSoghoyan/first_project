#include "test.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define FILE_NAME "/home/levons/workspace/todoProject/build/task.txt"
typedef struct {
	int id;
	char description[256];
	int is_complete;
} Task;
void assert(int condition, char *pTestName) {
    if (condition) {
        printf("DONE %s",pTestName);
    } else {
        printf("FAIL %s",pTestName);
    }
}
void testAdd() {
    clear();
    add("Some task");
    FILE *pRead = fopen(FILE_NAME, "r");
    if (!pRead) {
        printf("F/O error");
        return;
    }
    if (fgetc(pRead) != EOF) {
        assert(1, "Add test");
    } else {
        assert(0, "Add test");
    }
}
void testClear() {
    add("Some task");
    clear();
    FILE *pRead = fopen(FILE_NAME, "r");
    if (!pRead) {
        printf("F/O error");
        return;
    }
    if (fgetc(pRead) == EOF) {
        assert(1, "Clear test");
    } else {
        assert(0, "Clear test");
    }
}
void testDone() {
    Task    testTask;
    char    *pList;
    size_t  size;
    clear();
    add("Some task");
    done(0);
    FILE *pRead = fopen(FILE_NAME, "r");
    if (getline(&pList, &size, pRead) != -1) {
        pList[strcspn(pList,"\n")] = 0;
        sscanf(pList, "%d %d %255[^\n]", &testTask.id, &testTask.is_complete, testTask.description);
        if (testTask.id) {
            assert(1, "Done  test");
        } else {
            assert(0, "Done test");
        }
    }
}
int main() {

}
