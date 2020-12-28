#include <stdio.h>
#include <stdlib.h>
#include "ListLib.h"
 
using namespace mylist;
int main() {
	list_t l;
	init(&l);

	push_back(&l, 5);
	push_back(&l, 242);
	push_back(&l, 23515);
	push_back(&l, -124);
	
	set(&l, 2, -111);

	insert(&l, l.head, 777);

	erase(&l, l.head->next->next);

	int a = get(&l, 2);

	printf("get: %d\n", a);
	printl(&l);

	destroy(&l);

	return 0;
}