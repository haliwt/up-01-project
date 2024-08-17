#include "bsp.h"

/***************************************************
 *
 *Function Name: 
 *Function: creat new node 
 *Input Ref: new data
 *Return Ref: new Node(add)
 *
***************************************************/
Node* creatNode(uint8_t ndata)
{
   Node* newNode = (Node*)malloc(sizeof(Node));

   newNode ->data = ndata;
   newNode ->next = NULL;
   newNode ->prev =NULL;

   return newNode;

}

/***************************************************
 *
 *Function Name: void addendNode(Node ** head,int data)
 *Function: at list of end add new node 
 *Input Ref: new data
 *Return Ref: new Node(add)
 *
***************************************************/
void addendNode(Node ** head,uint8_t ndata)
{
   Node* newNode = creatNode(ndata);
   if(*head == NULL){
      *head = newNode;
      return;
   }
   else{
      Node* temp = *head;
      while(temp->next != NULL){
         temp = temp->next;
      }
      temp->next = newNode; // 
      newNode->prev = temp;
   }
}
/********************************************************************************
 *
 *Function Name: uint8_t list_insert_new_node(Node** head,uint8_t ndata,int n)
 *Function: creat new node 
 *Input Ref: new node , new data,insert position is n
 *Return Ref: new Node(add)
 *
***********************************************************************************/
uint8_t list_insert_new_node(Node** head,uint8_t ndata,uint8_t n)
{
     uint8_t cur_i =0;

     if(*head == NULL || n< 1) return 0;

     Node* current = *head;

     while(current && cur_i<(n-1)){
         current = current->next;
         cur_i++;
     }
     if(!current){
         return 0;
     }

     Node* newNode = creatNode(ndata);
    newNode ->data = ndata;

    //list insert new node numbers "n"
    newNode ->next = current->next;
    newNode ->prev = current;

    if(current->next){
       current->next->prev = newNode;
    }
    current -> next = newNode;

    return 1;

}

uint8_t list_delete_assign_node(Node** head,uint8_t n)
{
     uint8_t cur_i =0;

     if(*head == NULL || n< 1) return 0;

     Node* current = *head;

     while(current && cur_i<(n-1)){
         current = current->next;
         cur_i++;
     }
     if(!current){
         return 0;
     }

    Node* delete = current->next; //不能把头节点删除了。
   

    delete -> prev ->next = delete -> next;
    delete ->next ->prev = delete->prev;
    
    free(delete);

    return 1;
    

}

/********************************************************************************
 *
 *Function Name: uint8_t list_find_data(Node** head,uint8_t * data,int n)
 *Function: creat new node 
 *Input Ref: new node , new data,insert position is n
 *Return Ref: new Node(add)
 *
***********************************************************************************/
uint8_t list_find_data(Node** head,uint8_t* ndata,uint8_t n)
{
     uint8_t cur_i =0;

     if(*head == NULL || n< 1|| ndata == NULL) return 0;

     Node* current = *head;

     while(current != NULL){
         if(current->data == *ndata){
             
             return current->data;
           
         }
     }
     return 0;
}


// 查找链表中第n个节点的数据
uint8_t  findNumbers_NodeData(Node** head, uint8_t n, uint8_t list_num) 
{
    int count = 0;
    Node* current = *head;
    while (current != NULL && count < list_num) {
        if (count == n) {
            return current->data;
        }
        current = current->next;
        count++;
    }
    printf("list don't find node \r\n");
    return 0; // 链表中没有第10个节点
}

