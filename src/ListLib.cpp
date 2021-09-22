#include <stdio.h>
#include <stdlib.h>
#include "ListLib.h"
namespace mylist {
	void init(list_t* list) {
		list->head = NULL;
		list->size = 0;
	}
	void destroy(list_t* list) {
		node_t* cur = list->head;
		node_t* prev = NULL;
		while (cur != NULL)
		{
			prev = cur;
			cur = cur->next;
			free(prev);
		}
	}
	void push_back(list_t* list, int val) {
		node_t* n, * cur;
		n = (node_t*)malloc(sizeof(node_t));
		if (n == NULL)
		{
			return;
		}
		n->value = val; n->next = NULL;
		if (list->head == NULL) {
			n->prev = NULL;
			list->head = n;
		}
		else {
			cur = list->head;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = n;
			n->prev = cur;
		}
		list->size++;
	}
	void printl(list_t* list) {
		node_t* cur = list->head;
		while (cur != NULL) {
			printf(" %d ", cur->value);
			cur = cur->next;
		}
		printf("\n");
	}
	void set(list_t* list, int i, int val) {
		node_t* cur = list->head; int count = 0;
		if (i < 0 || i >= list->size) return;
		while (count != i) {
			cur = cur->next;
			count++;
		}
		cur->value = val;
	}
	int get(list_t* list, int i) {
		node_t* cur = list->head; int count = 0;
		if (i < 0 || i >= list->size) return -1;
		while (count != i) {
			cur = cur->next;
			count++;
		}
		return cur->value;
	}
	void insert(list_t* list, node_t* cur, int val) {
		node_t* n = (node_t*)malloc(sizeof(node_t));
		n->value = val;
		n->next = cur->next;
		n->prev = cur;
		cur->next->prev = n;
		cur->next = n;
		list->size++;
	}
	void erase(list_t* list, node_t* cur) {
		if (cur == list->head) {
			list->head = cur->next;
			if (cur->next != NULL) cur->next->prev = NULL;
			free(cur);
		}
		else {
			cur->prev->next = cur->next;
			if (cur->next != NULL) cur->next->prev = cur->prev;
			free(cur);
		}
		list->size--;
	}
}