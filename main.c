#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST 3

struct Node
{
    int value;
    struct Node *next;
};

struct Node *insert(int val, struct Node *next_node);
void print_list(struct Node *list_head);
void free_all_pointers(struct Node *ptrs_to_free[]);
struct Node *insert_array_values(int array[], struct Node *pointers[]);

int main(void)
{
    struct Node *head;
    struct Node *pointers_to_free[MAX_LIST + 1];

    int array_of_integers[MAX_LIST] = { 22, 33, 44 };

    head = insert_array_values(array_of_integers, pointers_to_free);

    print_list(head);

    free_all_pointers(pointers_to_free);

    return 0;
}

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

struct Node *insert_array_values(int array[], struct Node *pointers[])
{
    struct Node *current = NULL;
    for (int i = MAX_LIST - 1; i >= 0; i--)
    {
        pointers[i] = insert(array[i], current);
        current = pointers[i];
    }
    return current;
}
