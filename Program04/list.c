#include <stdlib.h>
#include <stdio.h>
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
			printf("%d", head->id);
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
