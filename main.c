/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** workshop linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/mylist.h"

struct linked_list *add_end(int elem, linked_list_t *list)
{
    struct linked_list *new = malloc(sizeof(linked_list_t));
    linked_list_t *incre = list;

    if (new == NULL)
        return NULL;
    new->next = NULL;
    new->data = elem;
    if (list == NULL)
        return (new);
    while (incre->next != NULL)
        incre = incre->next;
    incre->next = new;
    new->next = NULL;
    new->data = elem;
    return (list);
}

struct linked_list *add_elem(int elem, linked_list_t *list)
{
    struct linked_list *new = malloc(sizeof(linked_list_t));

    if (new == NULL)
        return NULL;
    new->data = elem;
    if (list == NULL)
        new->next = NULL;
    else
        new->next = list;
    return (new);
}

struct linked_list *free_list(linked_list_t *list)
{
    struct linked_list *temp = list;

    while (temp != NULL) {
        temp = temp->next;
        free(list);
        list = temp;
    }
    return NULL;
}

void display_list(linked_list_t *list)
{
    struct linked_list *temp = list;

    if (temp == NULL)
        return;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(int ac, char **av)
{
    int elem = 0;
    linked_list_t *list = NULL;

    while (elem != 4) {
        list = add_end(elem, list);
        elem++;
    }
    display_list(list);
    list = free_list(list);
    display_list(list);
    return (0);
}