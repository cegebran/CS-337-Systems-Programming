#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
// create an empty list - set *node = NULL
void create_list(node** head){

	*head = NULL;

}

// add a new node to the front of the list
void add_front(node** head, node* new_node){

	node* tmp = *head;

	*head = new_node;

	(*head)->next = tmp;

}

// add a new node to the end of the list
void add_end(node** head, node* new_node){

	if(*head == NULL){
		*head = new_node;
	}else{

		if((*head)->next == NULL){
			(*head)->next = new_node;
			new_node->next = NULL;
		}else{
			node* tmp = *head;

			while(tmp->next){
				tmp = tmp->next;
			}

			tmp->next = new_node;
		}
	}

}


// Program 4_5 new functions
// add a new node in the list, in (ascending) sorted order based on
// the nodes name component's value
void add_inorder(node** head, node* new_node){

	if(*head == NULL){	// no elements in the list

		new_node->next = NULL;
		*head = new_node;

	}else if(list_len(*head) == 1){	// list with only one element

		if(strcmp((*head)->name, new_node->name) < 0){	// *head comes before new_node
			new_node->next = NULL;
			(*head)->next = new_node;
		}else{	// new_node comes before *head
			new_node->next = *head;
			*head = new_node;
		}

	}else{	// list with 2 or more elements

		if(strcmp((*head)->name, new_node->name) >= 0){	// check if new_node belongs before head so we dont have to traverse the linked list
			new_node->next = *head;
			*head = new_node;
		}else{	// new_nodes belongs after the head element so have to traverse list and find location to be slotted into

			node* tmp = *head;
			while(tmp->next){
				if( strcmp(tmp->name, new_node->name) <= 0 && strcmp(tmp->next->name, new_node->name) > 0 ){
					new_node->next = tmp->next;
					tmp->next = new_node;
					break;
				}
				tmp = tmp->next;
			}

			if(tmp->next == NULL){	// name added comes after the tail so add new_node at the tail
				new_node->next = NULL;
				tmp->next = new_node;
			}

		}

	}

}

//strcmp(x,y) <0 when x comes before y
//strcmp(x,y) == 0 when x and y are the same
//strcmp(x,y( >0 when y comes before x

// remove and return the first node in the list whose name component's value
// is equal to the given key_name
// return NULL if no such node exists in the list
node* rem_inorder(node** head, char* key_name){

	if(*head == NULL){	// test if the linked list is empty and if so return NULL to avoid nullPointerExceptions

		return NULL;

	}else if(list_len(*head) == 1){	// 1 element in linked list so check head and if head->name does not match return NULL

		if(strcmp((*head)->name, key_name) == 0){
			node* tmp = *head;
			*head = NULL;
			return tmp;
		}else{
			return NULL;
		}

	}else{ // more than 2 elements in the list so need to traverse list to find if key_name is in the list to remove

		if(strcmp((*head)->name, key_name) == 0){	// test if head has the name we are looking for before traversing the list
			node* tmp = *head;
			*head = (*head)->next;
			return tmp;
		}else{
			// know more than 2 elements in list and head-> is not the name we are looking for
			node* pre = *head;
			node* cur = (*head)->next;
			while(cur){
				if(strcmp(cur->name, key_name) == 0){
					node* tmp = cur;
					pre->next = cur->next;
					return tmp;
				}
				pre = pre->next;
				cur = cur->next;
			}
		}
	}
	return NULL;
}



// remove and return the node at the front of the list or NULL if empty
node* rem_front(node** head){

	if(*head == NULL){
		return NULL;
	}else{
		node* tmp = *head;

		*head = (*head)->next;

		return tmp;
	}

}

// remove and return the node at the end of the list or NULL if empty
node* rem_end(node** head){

	if(*head == NULL){
		return NULL;
	}else{
		node* tmp = *head;
		node* pretmp = *head;

		if((*head)->next == NULL){
			tmp = *head;
			*head = NULL;
			return tmp;
		}else{

			while(tmp->next){
				tmp = tmp->next;

				if(tmp->next){
					pretmp = pretmp->next;
				}
			}
		pretmp->next = NULL;

		return tmp;
		}
	}
}

// return the number of nodes in the list
int list_len(const node* head){

	int count = 0;

	while(head){
		++count;
		head = head->next;
	}

	return count;

}

// print the data values of all the nodes in the list (from start to end)
void print_list(const node* head){

	if(head == NULL){
		printf("\n");
	}else{

		printf("\n");

		while(head){

			printf("{");;
			printf("%d", head->soc_sec_num);
			printf(", ");
			printf("%s", head->name);
			printf("}");
			printf("\n");

			head = head->next;
		}
	}
}

// free the entire list and set *node = NULL
void free_list(node** head){

	if(*head){
		free_list( &((*head)->next) );
		free(*head);
		*head = NULL;
	}

}
