#ifndef VECTOR_LIB_H
#define VECTOR_LIB_H
namespace mylist {
	typedef struct node_t {
		int value;
		node_t* prev;
		node_t* next;
	};
	typedef struct list_t {
		node_t* head;
		size_t size;
	};
	void init(list_t* list); // O(1)
	void destroy(list_t* list); // O(n)
	void push_back(list_t* list, int val); //O(n)
	void printl(list_t* list); //O(n)
	void set(list_t* list, int i, int val); // O(n)
	int get(list_t* list, int i); // O(n)
	void insert(list_t* l, node_t* cur, int val); //O(1), insert, if head != NULL.
	void erase(list_t* list, node_t* cur); // O(1)
}
#endif