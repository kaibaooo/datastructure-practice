//QUEUE

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

unsigned SIZE = 0;

struct Queue {
    int data;
    Queue *next;
};

void printMenu() {
    printf("======================================\n");
    printf("|                1.PUSH              |\n");
    printf("|                2.POP               |\n");
    printf("|                3.FRONT             |\n");
    printf("|                4.SIZE              |\n");
    printf("|                5.EMPTY             |\n");
    printf("======================================\n");
}

void pushNode(Queue* p, int d) {
    Queue *current = p;
    Queue *tmp = (Queue*)malloc(sizeof(Queue));
    tmp->data = d;
    tmp->next = NULL;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = tmp;
    SIZE++;
}

void popNode(Queue* p) {
    if (SIZE == 0) {
        return;
    }
    Queue *tmp = p->next;
    p->next = p->next->next;
    free(tmp);
    SIZE--;
}

void front(Queue* p) {
    if(SIZE==0)
        return;
    printf("FRONT:%d\n", p->next->data);
}

int main() {
    Queue *head = (Queue*)malloc(sizeof(Queue));
    Queue *current = head;
    head->next = NULL;
    int choice = 0;
    while (1) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            int v = 0;
            printf("Please input data:");
            scanf("%d", &v);
            system("cls");
            pushNode(head, v);
            break;
        }
        case 2: {
            system("cls");
            popNode(head);
            break;
        }
        case 3: {
            system("cls");
            front(head);
            break;
        }
        case 4: {
            system("cls");
            printf("SIZE:%d\n", SIZE);
            break;
        }
        case 5: {
            system("cls");
            if (SIZE != 0) {
                printf("SOMETHING IS INSIDE QUEUE !O_O\n");
            }
            break;
        }
        default:
            system("cls");
            break;
        }
        printf("QUEUE : ");
        if (SIZE == 0) {
            printf("QUEUE IS EMPTY!\n");
            continue;
        }
        current = head->next;
        while (current != NULL) {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
    return 0;
}