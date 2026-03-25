
typedef enum {
	PENDING=1,
	DONE=2
}Done;

typedef struct {
	int id;
	char description[256];
	Done is_complete;
}Task;


void add(char *desc);

void clear();

void list();

void done(int task_id);
