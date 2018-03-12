#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int args, char* argv[])
{
	node* head;
	node* new_node;

	create_list(&head);

	printf("Stack Implementation");

	printf("\n");

	printf("Add nodes to the linked list");

	int i;
	for(i = 1; i < 10; ++i)
	{
		printf("\n");
		new_node = (node*)malloc(sizeof(node));

		new_node->id = rand() % 100;

		new_node->name = "Brandon";

		add_front(&head, new_node);

		printf("Added new node with ID: ");
		printf("%d", new_node->id);
		printf("  NAME: ");
		printf("%s", new_node->name);
	}

	printf("\n");
	printf("Print the Stack Linked List");

	print_list(head);

	printf("\n");

	printf("Remove elements from the stack linked list and print the linked list after each removal");

	while(head){

		node* removed = rem_front(&head);
		printf("\n");
		printf("Contents of the node removed, ID: ");
		printf("%d", removed->id);
		printf("  NAME: ");
		printf("%s", removed->name);

		printf("\n");
		printf("\n");
		printf("Linked List after removal of head (front) element: ");

		print_list(head);

		printf("\n");

	}


	printf("Queue Implementation");

	printf("\n");

	printf("Add nodes to the linked list");

	for(i = 1; i < 10; ++i)
	{

		printf("\n");
		new_node = (node*)malloc(sizeof(node));

		new_node->id = rand() % 100;

		new_node->name = "Cegelski";

		add_end(&head, new_node);

		printf("Added new node with ID: ");
		printf("%d", new_node->id);
		printf("  NAME: ");
		printf("%s", new_node->name);
	}

	printf("\n");
	printf("Print the Queue Linked List");

	print_list(head);

	printf("\n");

	printf("Remove the elements from the queue linked list");

	while(head){

		node* removed = rem_front(&head);
		printf("\n");
		printf("Contents of the node removed, ID: ");
		printf("%d", removed->id);
		printf("  NAME: ");
		printf("%s", removed->name);

		printf("\n");
		printf("\n");
		printf("Linked list after removal of head (front) node");

		print_list(head);

		printf("\n");

	}

	free_list(&head);

	return 0;
}
