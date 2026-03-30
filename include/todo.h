typedef enum {
	PENDING=0,
	DONE=1
}Done;
typedef struct {
	int id;
	char description[256];
	int is_complete;
}Task;
void add(char *desc);

void clear();

void list();

void completeList();

void done(int taskId);

void help();
