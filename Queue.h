#pragma once

//Se genera la estructura para almacenar la cola. Contiene el punto a un elemento, el front, la cantidad de elementos y la cantidad maxima d ela cola.
struct queue {
    int* elements;
    int front;
    int numElements;
    int queueSize;
};

void init(struct queue* qPtr); //Se inicializa la estructura.
int enqueue(struct queue* qPtr, int val); //Se encola un nuevo elemento.
int dequeue(struct queue* qPtr); //Se retira un nuevo elemento
int empty(struct queue* qPtr); //Si la pila esta vacia
int front(struct queue* qPtr); //Cual esta al frente.