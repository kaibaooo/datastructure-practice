#include<stdio.h>
#include<stdlib.h>

int topL = -1;

void push(int arr[], int data) {
    topL++;
    arr[topL] = data;
    printf("%d added\n", data);
}

void pop(int arr[]) {
    if (topL == -1) {
        printf("Stack is empty\n");
    }
    else {
        printf("Delete %d\n", arr[topL]);
        topL--;
    }
}

void list(int arr[]) {
    if (topL == -1) {
        printf("Stack is Empty\n");
    }
    else {
        for (int i = topL; i >= 0; i--) {
            printf("%d\n", arr[i]);
        }
    }
}

int main() {
    int arr[100];
    size_t n = 0;
    int d = 0;
    while (1) {
        printf("1.Push\n2.Pop\n3.List\n");
        scanf("%u", &n);
        switch (n) {
        case 1:
            scanf("%d", &d);
            push(arr, d);
            break;
        case 2:
            pop(arr);
            break;
        case 3:
            list(arr);
            break;
        }
    }
    return 0;
}
