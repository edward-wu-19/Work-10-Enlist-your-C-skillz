struct course {char name[20]; int students; int id; struct course *next_course;};
struct course * make_course(char course_name[20], int course_size, int course_id);
void print_course(struct course *s);

void print_list(struct course *s);
struct course * insert_front(struct course *s, char name[20], int students, int id);
struct course * free_list(struct course *s);

struct course * remove_course(struct course *front, int course_code);

void newlines(int n);