#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    list *listaNueva = (list*)malloc(sizeof(list));
    if (listaNueva == NULL) return NULL ; 
    
    listaNueva-> head = NULL;
    listaNueva-> tail = NULL;
    listaNueva-> current = NULL;


     return listaNueva;
}

void * firstList(List * list) {
    if (list -> head != NULL)
    {
        list->head = list->current ;
        return list->current->data;
    }
    return NULL;

}

void * nextList(List * list) {

    if(list->current != NULL && list->current->next != NULL){
        list->current = list->current->next;
        return list->current->data;
    }
    return NULL;
}

void * lastList(List * list) {

    if(list->tail != NULL){
        list->current = list->tail;
        return list->current->data;
    }

    return NULL;
}

void * prevList(List * list) {
    if(list->current != NULL){
        list->current = list->current->prev;
        if(list->current != NULL){
            return list->current->data;
        }

    }
    return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}