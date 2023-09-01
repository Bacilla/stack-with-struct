#include <stdio.h> //input/output library
#include <stdlib.h> //malloc, calloc, free... functions


typedef struct stack_element {
    int data;
    struct stack_element *next_element;
} Element; // Вводим новый тип данных (структура) - Element


// Функция добавляет новый элемент на верхушку стека
Element *push(Element *top, int data) {
    Element *temp = malloc(sizeof(Element)); // Выделяем место в куче для элемента стека
    if(temp == NULL) {
        printf("Not enough memory!");
        exit;
    }

    (*temp).data = data;
    // Говорим что следующий элемент - это бывшая верхушка стека, тем самым связывая новый элемент с верхушкой.
    // После работы функции новой верхушкой стека станет данный элемент
    (*temp).next_element = top; // Если добавляется первый элемент - top содержит NULL
    return temp;
}


// Функция удаляет элемент из верхушки стека
Element *pop(Element *top) {
    if(top == NULL) { // Если стек пустой - возвращаем тот же указатель (дно стека)
        return top;
    }

    printf("Deleted element: %d\n", top->data);

    Element *p_next = top->next_element; // сохраняем указатель на следующий нижний элемент стека
    free(top); // Очищаем память, удаляя верхний элемент из стека
    return p_next;
}


// Функция выводит все элементы стека
void print_elements(Element *top) {
    Element *temp = top;
    printf("--STACK--\n");
    while(temp != NULL) {
        printf("%d\n", (*temp).data);
        temp = (*temp).next_element;    
    }
    printf("---------\n");
}


int main() {
    // Указатель на верхушку стека (изначально в стеке нет элементов, поэтому NULL)
    Element *top = NULL; 
    
    printf("Commands:\n\"1\": push\n\"2\": pop\n\"3\": print\n\"4\": exit\n\n");
    while(1) {
        int command;
        printf("your command: ");
        scanf("%d", &command);
        switch (command) {
            case 1:
                int data = 0;
                printf("data: ");
                scanf("%d", &data);
                top = push(top, data); // Теперь, вершина стека - только что добавленный элемент
                break;
            case 2:
                top = pop(top); // После удаления элемента, верхушкой стека становится следующий снизу элемент
                break;
            case 3:
                print_elements(top); // Вывод всего стека на экран
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Uncorrect command!\n");
                break;
        }
    }
    return 0;
}