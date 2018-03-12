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

		new_node->soc_sec_num = rand() % 100;

		new_node->name = "Brandon";

		add_front(&head, new_node);

		printf("Added new node with SS: ");
		printf("%d", new_node->soc_sec_num);
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
		printf("Contents of the node removed, SS: ");
		printf("%d", removed->soc_sec_num);
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

		new_node->soc_sec_num = rand() % 100;

		new_node->name = "Cegelski";

		add_end(&head, new_node);

		printf("Added new node with SS: ");
		printf("%d", new_node->soc_sec_num);
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
		printf("Contents of the node removed, SS: ");
		printf("%d", removed->soc_sec_num);
		printf("  NAME: ");
		printf("%s", removed->name);

		printf("\n");
		printf("\n");
		printf("Linked list after removal of head (front) node");

		print_list(head);

		printf("\n");

	}


	printf("\n");
	printf("-----------------------------------------");
	printf("\n");
	printf("Testing Adding Nodes in Order based on Name");
	printf("\n\n");


	// Adding different elements to the linked list and printing list each time to
	// test if the add_inorder function is working properly

	//testing adding node to an empty list
	printf("Testing adding node to empty list");
	new_node = (node*)malloc(sizeof(node));

	new_node->soc_sec_num = rand() % 100;
	new_node->name = "Joe";
	add_inorder(&head, new_node);

	printf("\nAdded: [");
	printf("%d", new_node->soc_sec_num);
	printf(", ");
	printf("%s", new_node->name);
	printf("]\n");

	printf("Linked List after adding node to empty list");

	print_list(head);
	printf("\n\n");

	// testing adding node to list with 1 element where the name being added is the same as the name in the list
	printf("Testing adding same name to list that is already in the list");
	new_node = (node*)malloc(sizeof(node));

	new_node->soc_sec_num = rand() % 100;
	new_node->name = "Joe";
	add_inorder(&head, new_node);

	printf("\nAdded: [");
	printf("%d", new_node->soc_sec_num);
	printf(", ");
	printf("%s", new_node->name);
	printf("]\n");

	printf("Linked List after adding same name to list that was already in the list");

	print_list(head);
	printf("\n\n");


	// Testing removing name from list with 2 elements with the same name (looking to remove first occurence of name in the list starting at the head)
	printf("Testing removing name from list where 2 of the same name appears (we are looking to remove the first occurence of the name in the list)");
	node* removedSameName = rem_inorder(&head, "Joe");

	printf("\nRemoved: [");
	printf("%d", removedSameName->soc_sec_num);
	printf(", ");
	printf("%s", removedSameName->name);
	printf("]\n");

	printf("Linked list after removing in_order a name that apperead twice in the list");

	print_list(head);
	printf("\n\n");

	// testing adding node before head element with only one element in the list
	printf("Testing adding node to list with 1 element where name comes before only name in list at head\n");

	new_node = (node*)malloc(sizeof(node));

	new_node->soc_sec_num = rand() % 100;
	new_node->name = "Brad";
	add_inorder(&head, new_node);

	printf("\nAdded: [");
	printf("%d", new_node->soc_sec_num);
	printf(", ");
	printf("%s", new_node->name);
	printf("]\n");

	printf("Linked List after adding node before head of a list with only 1 element previously");

	print_list(head);
	printf("\n\n");

	// testing adding node after head element with only one element in the list
	rem_end(&head);	// remove 2nd element in list to get back to 1 node in the list
	printf("Removed end node to get back to a linked list size of 1\n");
	new_node = (node*)malloc(sizeof(node));

	new_node->soc_sec_num = rand() % 100;
	new_node->name = "Jeff";
	add_inorder(&head, new_node);

	printf("\nAdded: [");
	printf("%d", new_node->soc_sec_num);
	printf(", ");
	printf("%s", new_node->name);
	printf("]\n");

	printf("Linked List after adding node after head of a list with only 1 element previously");

	print_list(head);
	printf("\n\n");


	// adding node with name that comes before head name with a list with 2 or more nodes
	new_node = (node*)malloc(sizeof(node));

	new_node->soc_sec_num = rand() % 100;
	new_node->name = "Aaron";
	add_inorder(&head, new_node);

	printf("\nAdded: [");
	printf("%d", new_node->soc_sec_num);
	printf(", ");
	printf("%s", new_node->name);
	printf("]\n");

	printf("Linked list after adding node before head of a list with 2 or more elements in the list previously");

	print_list(head);
	printf("\n\n");


	// adding node with name between head and first node with 2 or more nodes in the list previously
	new_node = (node*)malloc(sizeof(node));

	new_node->soc_sec_num = rand() % 100;
	new_node->name = "Adam";
	add_inorder(&head, new_node);

	printf("\nAdded: [");
	printf("%d", new_node->soc_sec_num);
	printf(", ");
	printf("%s", new_node->name);
	printf("]\n");

	printf("Linked list after adding node between head and 2nd element with 2 or more elements in the list previously");

	print_list(head);
	printf("\n\n");


	// adding node with name between two different middle nodes with 2 or more nodes in the list previously
	new_node = (node*)malloc(sizeof(node));

	new_node->soc_sec_num = rand() % 100;
	new_node->name = "Carl";
	add_inorder(&head, new_node);

	printf("\nAdded: [");
	printf("%d", new_node->soc_sec_num);
	printf(", ");
	printf("%s", new_node->name);
	printf("]\n");

	printf("Linked list after adding node between two different middle nodes with 2 or more nodes in the list previously");

	print_list(head);
	printf("\n\n");


	// adding node with name after last name in the list with 2 or more nodes in the list previously
	new_node = (node*)malloc(sizeof(node));

	new_node->soc_sec_num = rand() % 100;
	new_node->name = "Kevin";
	add_inorder(&head, new_node);

	printf("\nAdded: [");
	printf("%d", new_node->soc_sec_num);
	printf(", ");
	printf("%s", new_node->name);
	printf("]\n");

	printf("Linked list after adding node at the end of list list with 2 or more nodes in the list previously");

	print_list(head);
	printf("\n\n");

	// Testing removing nodes in order based on name matching
	printf("\n\n");
	printf("Testing removing nodes from the list using the rem_inorder function\n");
	printf("------------------------------------");
	printf("\n");


	//test removing first node in list with more than 2 elements in the list
	node* removedHead = rem_inorder(&head, "Aaron");

	printf("\nRemoved: [");
	printf("%d", removedHead->soc_sec_num);
	printf(", ");
	printf("%s", removedHead->name);
	printf("]\n");
	printf("\n");

	printf("Linked list after removing head element with matching name with more than 2 elements in the list");

	print_list(head);
	printf("\n\n");


	// testing removing last node in list with more than 2 elements in the list
	node* removedEnd = rem_inorder(&head, "Kevin");

	printf("\nRemoved: [");
	printf("%d", removedEnd->soc_sec_num);
	printf(", ");
	printf("%s", removedEnd->name);
	printf("]\n");
	printf("\n");

	printf("Linked list after removed last element with match name with 2 or elements in the list");

	print_list(head);
	printf("\n\n");


	// testing removing name that is not in list with 2 or more elements in the linked list
	node* remove2Null = rem_inorder(&head, "NotinList");

	if(remove2Null == NULL){
		printf("Linked list after trying to remove name that is not in the list with 2 or more elements in the list");
		print_list(head);
		printf("\n\n");
	}else{
		printf("\nRemoved: [");
		printf("%d", remove2Null->soc_sec_num);
		printf(", ");
		printf("%s", remove2Null->name);
		printf("]\n");
		printf("\n");
	}


	// testing removing node between 2 non-Head elements from a list with more than 2 elements before removing
	node* removeMiddle = rem_inorder(&head, "Carl");

	printf("\nRemoved: [");
	printf("%d", removeMiddle->soc_sec_num);
	printf(", ");
	printf("%s", removeMiddle->name);
	printf("]\n");
	printf("\n");

	printf("Linked list after removed middle element between 2 non-Head nodes with 2 or more elements in the list");

	print_list(head);
	printf("\n\n");


	// testing removing node after head with 2 or more elements in the list previously
	node* removeAfterHead = rem_inorder(&head, "Brad");

	printf("\nRemoved: [");
	printf("%d", removeAfterHead->soc_sec_num);
	printf(", ");
	printf("%s", removeAfterHead->name);
	printf("]\n");
	printf("\n");

	printf("Linked list after removed middle element after head with 2 or more elements in the list");

	print_list(head);
	printf("\n\n");


	// testing removing node after head with only 2 elements in list where head will be only node left after removal
	node* removeTail2 = rem_inorder(&head, "Jeff");

	printf("\nRemoved: [");
	printf("%d", removeTail2->soc_sec_num);
	printf(", ");
	printf("%s", removeTail2->name);
	printf("]\n");
	printf("\n");

	printf("Linked list after removal of tail node directly after head leaving only head left in linked list");

	print_list(head);
	printf("\n\n");


	// Testing not finding name in list with only 1 node remaining in the entire linked list at the head pointer
	node* remove1Null = rem_inorder(&head, "NoFind");

	if(remove1Null == NULL){
		printf("Linked list after trying to remove name from list with 1 node and name not being in list");
		print_list(head);
		printf("\n\n");
	}else{
		printf("\nRemoved: [");
		printf("%d", remove1Null->soc_sec_num);
		printf(", ");
		printf("%s", remove1Null->name);
		printf("]\n");
		printf("\n");

		print_list(head);
		printf("\n\n");
	}


	// Testing removing head node in list where only 1 node in list before removal and after removal no nodes in list
	node* removeHead0 = rem_inorder(&head, "Adam");

	printf("\nRemoved: [");
	printf("%d", removeHead0->soc_sec_num);
	printf(", ");
	printf("%s", removeHead0->name);
	printf("]\n");
	printf("\n");

	printf("Linked list after removal of head node when only the head was in the list. After no nodes in list");

	print_list(head);
	printf("\n\n");


	// Testing removing node from an empty list with no nodes to remove
	node* removeEmpty = rem_inorder(&head, "Empty");

	if(removeEmpty == NULL){
		printf("Linked List after trying to remove a node from an empty list");
		print_list(head);
		printf("\n\n");
	}else{
		printf("\nRemoved: [");
		printf("%d", removeEmpty->soc_sec_num);
		printf(", ");
		printf("%s", removeEmpty->name);
		printf("]\n");
		printf("\n");

		print_list(head);
		printf("\n\n");
	}

	free_list(&head);

	return 0;
}
