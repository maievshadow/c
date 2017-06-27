typedef struct list{
	int data;
	int len;
	struct list* next;
}list, *plist;

plist init_list(plist list){
	list->data = 0;
	list->len = 0;
	list->next = NULL;
}

void print_list(plist list){
	plist p;
	p = list->next;
	int len = list->len;
	int i = 0 ;
	if (len == 0)
		printf("the is no elem in this list");
	for(;p != NULL;p++){
		++i;
		printf("the current loc is %d and data is %d", i, p->data);
	}
}

int insert_list(plist list, int i, int len){
}

int delete_list(plist list, int i){
}

int get_list(plist list, in i){
}

int search_list(plist list, int elem){
}

int update_list(plist list, int i ,int elem){
}
