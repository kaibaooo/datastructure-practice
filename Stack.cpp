//STACK

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

unsigned SIZE = 0;

struct Stack {
    int data;
    Stack *next;
};

void printMenu() {
    printf("======================================\n");
    printf("|                1.PUSH              |\n");
    printf("|                2.POP               |\n");
    printf("|                3.TOP               |\n");
    printf("|                4.SIZE              |\n");
    printf("|                5.EMPTY             |\n");
    printf("======================================\n");
}

void pushNode(Stack* p, int d) {
    Stack *current = p;
    Stack *tmp = (Stack*)malloc(sizeof(Stack));
    tmp->data = d;
    tmp->next = p->next;
    p->next = tmp;
    SIZE++;
}

void popNode(Stack* p) {
    if (SIZE == 0) {
        return;
    }
    Stack *tmp = p->next;
    p->next = p->next->next;
    free(tmp);
    SIZE--;
}

void top(Stack* p) {
    if(SIZE==0)
        return;
    printf("TOP:%d\n", p->next->data);
}

int main() {
    Stack *head = (Stack*)malloc(sizeof(Stack));
    Stack *current = head;
    head->next = NULL;
    int choice = 0;
    while (1) {
        printMenu();
        scanf("%d", &choice);
        //system("cls");
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
            top(head);
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
                printf("SOMETHING IS INSIDE STACK !O_O\n");
            }
            break;
        }
        default:
            system("cls");
            break;
        }
        printf("STACK : ");
        if (SIZE == 0) {
            printf("STACK IS EMPTY!\n");
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