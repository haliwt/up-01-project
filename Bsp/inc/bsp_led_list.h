#ifndef __BSP_LED_LIST_H
#define __BSP_LED_LIST_H
#include "main.h"

typedef struct Node{

   uint8_t data;
   struct Node * next;
   struct Node * prev;


}Node;

Node* creatNode(uint8_t ndata);

void addendNode(Node ** head,uint8_t data);


uint8_t list_insert_new_node(Node** head,uint8_t data,uint8_t n);

uint8_t list_delete_assign_node(Node** head,uint8_t n);

uint8_t list_find_data(Node** head,uint8_t * data,uint8_t n);

uint8_t  findNumbers_NodeData(Node** head, uint8_t n, uint8_t lis_long) ;

#endif 

