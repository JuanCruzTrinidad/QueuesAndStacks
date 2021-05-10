#include "SingleLinkedList.h"
#include <cstddef>
#include <xlocinfo>
#include <iostream>

struct SingleNode* head = NULL;

void insertSingle(int newData) {
	struct SingleNode* newnode = (struct SingleNode*)malloc(sizeof(struct SingleNode));
	newnode->data = newData; //Al insertar un nuevo dato, se crea un nuevo nodo con el dato ingresado.
	newnode->next = head; //Y el siguiente al creado es el head (la cabeza anterior)
	head = newnode; //La cabeza pasa a ser el nodo creado.
}

void display() {
	struct SingleNode* ptr;
	ptr = head;
	while (ptr != NULL) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
}