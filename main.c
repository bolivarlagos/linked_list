#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST 3

struct Node
{
    int value;
    struct Node *next;
};

struct Node *insert(int val, struct Node *next_node)
{
    struct Node *new_node;

    new_node = malloc(sizeof(struct Node));

    new_node->value = val;
    new_node->next = next_node;

    return new_node;
}

void print_list(struct Node *list_head)
{
    while (list_head != NULL)
    {
        printf("%d\n", list_head->value);
        list_head = list_head->next;
    }
}

void free_all_pointers(struct Node *ptrs_to_free[])
{

    for (int i = 0; i <= MAX_LIST; i++)
    {
        free(ptrs_to_free[i]);
    }
}

void insert_array_values(int array_of_integers[], struct Node *curr_pointer, struct Node *ptrs_to_free[])
{
    for (int i = MAX_LIST - 1; i >= 0; i--)
    {
        struct Node *temp_pointer;
        temp_pointer = insert(array_of_integers[i], curr_pointer);
        ptrs_to_free[i] = temp_pointer;
        curr_pointer = temp_pointer;
    }
}

int main(void)
{
    struct Node *tail;
    struct Node *current_pointer;
    struct Node *pointers_to_free[MAX_LIST + 1];

    int my_array[MAX_LIST] = { 22, 33, 44 };

    tail = insert(100, NULL);
    current_pointer = tail;
    pointers_to_free[MAX_LIST] = current_pointer;

    insert_array_values(my_array, current_pointer, pointers_to_free);

    print_list(pointers_to_free[0]);

    free_all_pointers(pointers_to_free);

    return 0;
}