#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "DoubleLinkedList.h"

int queue();
int stack();
int doubleLinkedList();

int main()
{   
    doubleLinkedList();
    //queue();
    //stack();
    return 0;
}

int queue()
{
    std::cout << "Queues!\n";
    int i;

    // Allocate space for our queue and initialize it.
    //Inicialmente el tamaño de la cola es de diez elementos pero puede ir aumentando a medida que sea necesario para la aplicación.
    struct queue* MyQueuePtr = (struct queue*)malloc(sizeof(struct queue));
    init(MyQueuePtr);

    // Enqueue some items.
    enqueue(MyQueuePtr, 3);
    enqueue(MyQueuePtr, 7);
    enqueue(MyQueuePtr, 4);

    // Try one dequeue.
    printf("Dequeue %d\n", dequeue(MyQueuePtr));

    // Enqueue one more item, then try several dequeues and one front.
    enqueue(MyQueuePtr, 2);
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    printf("At Front of Queue Now: %d\n", front(MyQueuePtr));
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    printf("Dequeue %d\n", dequeue(MyQueuePtr));

    // See if we can detect an empty queue.
    printf("Is empty: %d\n", empty(MyQueuePtr));

    // Try enqueuing and dequeuing again to make sure that our previous
    // operations didn't "corrupt" the queue.
    enqueue(MyQueuePtr, 5);
    enqueue(MyQueuePtr, 9);

    // Try lots of enqueues to test the dynamic capability of the queue.
    for (i = 30; i < 60; i++)
        enqueue(MyQueuePtr, i);

    // Dequeue everything.
    while (!empty(MyQueuePtr))
        printf("Dequeue %d\n", dequeue(MyQueuePtr));

    return 0;
}

int stack()
{
    std::cout << "Hello World!\n";
    int i;
    struct stack mine;

    // Set up the stack and push a couple items, then pop one.
    initialize(&mine);
    push(&mine, 4);
    push(&mine, 5);
    printf("Popping %d\n", pop(&mine));

    // Push a couple more and test top.
    push(&mine, 22);
    push(&mine, 16);
    printf("At top now = %d\n", top(&mine));

    // Pop all three off.
    printf("Popping %d\n", pop(&mine));
    printf("Popping %d\n", pop(&mine));
    printf("Popping %d\n", pop(&mine));

    // Checking the empty function.
    if (empty(&mine))
        printf("The stack is empty as expected.\n");

    // Fill the stack.
    for (i = 0; i < 10; i++)
        push(&mine, i);
    
    printf("Sobrepasar el limite: %d (0 es fallo, 1 es que entra)", push(&mine, 13));

    // Check if full works.
    if (full(&mine))
        printf("This stack is full as expected.\n");

    // Pop everything back off.
    for (i = 0; i < 10; i++)
        printf("popping %d\n", pop(&mine)); //no importa el index, siempre es FIFO. La ultima en entrar es la primera en salir.

    system("PAUSE");

    return 0;
}

int doubleLinkedList() {
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);
    std::cout << "Lista LIFO: ";
    displayLIFO();
    std::cout << "\n";
    std::cout << "Lista FIFO:  ";
    displayFIFO();
    return 0;
}

//En los ejemplos mostrados la cola resulta más interesante por el hecho de poder dinamicamente modificar su tamaño, cosa que no pareciera posible en la pila.
//Ya que la pila se inicializa como un array con determinada cantidad de elementos.