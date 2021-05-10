#include <cstddef>
#include <iostream>
#include "DoubleLinkedList.h"

struct Node* last = NULL;
struct Node* first = NULL;

int count = 0;

void insert(int newdata) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->prev =  NULL; //APunta al anterior
    newnode->next = NULL; //Apunta al siguiente.

    if (first == last && first == NULL) { //Si es el primer NODO
        first = last = newnode; //El primero y el ultimo son el mismo, el nodo que se ingresa.
        first->next = last->next = NULL; //El next de ultimo y el primero apuntan a NULL.
        first->prev = last->prev = NULL; //El prev de ultimo y el primero apuntan a NULL.
    }
    else {
        newnode->next = first; //SI no es el primero, el siguiente del nuevo nodo apunta al primero. (El nodo anterior)
        first->prev = newnode; //Y el previo del primero (nodo anterior) es ahora el nodo que ingresa.
        first = newnode; //Entonces el primer nodo pasa a ser el nodo que ingresa,
        first->prev = last; //Y el previo del nodo pasa a ser el ultimo
        last->next = first; //Y el siguiente del ultimo pasa a ser el primero.
    }
    count++;
};

void displayLIFO() {
    struct Node* ptr;
    ptr = first;
    int scopeCount = count;
    for (int i = 0; i <= scopeCount - 1; i++) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
};

void displayFIFO() {
    struct Node* ptr;
    ptr = first;
    int scopeCount = count;
    for (int i = 0; i <= scopeCount - 1; i++) {
        ptr = ptr->prev;
        std::cout << ptr->data << " ";
    }
}