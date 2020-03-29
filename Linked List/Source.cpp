//Samuel Aaron cooper
//09/20/2018

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>


using namespace std;
//sets head node to NULL
struct node *head = NULL;

//creates a structure for the node
struct node {

	int data; //data identifier
	struct node* next; //points to the next node in the doubly-linked list
	struct node* prev; //points to the previous node in the doubly linked list
};
//This displays the items currently in the list
void display_List()
{
	cout << "The items currently in the list are: ";
	struct node *display = head;
	while (display != NULL)
	{
		cout << " " << display->data;
		if (display->next = NULL)
		{
			break;
		}
		display = display->next;
	}
}


// This adds new data in the front/head of the list
//template <class T>
void add_head(struct node** head_ref, int new_data)
{
	//First we allocate the node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	//Second, we insert the new data (node)
	new_node->data = new_data;

	//Third, make the "next" point to the now second node, and set "prev" to null since this is the new head node
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	//Fourth step
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	//Have the head_ref node point to the new node
	(*head_ref) = new_node;
}

//Inserts new data into the inside of a linked list (not the head or tail)
//insertes it after the head node
//template <class T>
void insert_middle(struct node* prev_node, int new_data)
{
	//The first step is to use an if statement to check if the prev_node is NULL
	if (prev_node == NULL)
	{
		cout << "The previous node that was given cannot be NULL";
		return;
	}
	//Second step is to allocate a new node into the list
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	//Third is to insert the new data block
	new_node->data = new_data;

	//fourth step is to set the new_node to next of the prev_node
	new_node->next = prev_node->next;

	//Fitch step sets the prev_node to next of the new_node
	prev_node->next = new_node;

	//The Sixth step sets the prev_node to prev of the new_node
	new_node->prev = prev_node;

	//the last step would be to change the previous of the new_node's next
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

//template <class T>
void add_tail(struct node** head_ref, int new_data)
{
	//First, allocates the node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	struct node* last = *head_ref;

	//Second, we insert the new data (node)
	new_node->data = new_data;

	//Third, we set the tail node in, so we would need to set NEXT to null since nothing is to the right of it.
	new_node->next = NULL;

	// 4. an if statement to check if the list is empty, if so, the new node is set to head
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;

	}
}

//this searches/returns a node that matches a specific key input 
//template <class T>
bool search_node(struct node* head_ref, int data)
{
	int position = 0;
	struct node* current = NULL;

	if (head == NULL) {
		cout << "Linked List not yet created";
		return 0;
	}

	current = head;
	while (current != NULL) {
		position++;
		if (current->data == data) {
			cout << "The item was found at position\n" << data << position;
			return 0;
		}

		if (current->next != NULL)
			current = current->next;
		else
			break;
	}

	cout << "This item does not exist in the list\n";
}

//void function for deleting a node in the doubly-linked list
//template <class T>
void delete_node(struct node** head_ref, struct node* del)
{
	// the base if statement using an OR operator
	if (*head_ref == NULL || del == NULL)
		return;

	// if statement for if the deleted node happens to be the head node
	if (*head_ref == del)
		*head_ref = del->next;

	// This if statement will change next only if the node to be deleted is NOT the last node in the linked list
	if (del->next != NULL)
		del->next->prev = del->prev;

	// This if statement will change prev only if the node to be deleted is NOT the first node in the linked list
	if (del->prev != NULL)
		del->prev->next = del->next;

	// empty or free up the memory block that was taken up by the delete
	free(del);
	return;

}

//This will locate the largest item within the list
//template <class T>
int largestItem(struct node* head_ref)
{
	struct node *max, *temp;

	// initialize the two pointers: temp and max on the head node in the linked list
	temp = max = head_ref;

	// searches through the entire linked list 
	while (temp != NULL) {

		// if the temp's data is greater than max's data, then put max = temp and return max->data to give the largest item
		if (temp->data > max->data)
			max = temp;

		temp = temp->next;
	}
	return max->data; //returns the largest item to the user
}

//This will locate the smallest item within the list
//template <class T>
int smallestItem(struct node* head_ref)
{
	struct node *min, *temp;

	// initialize the two pointers: temp and min on the head node in the linked list
	temp = min = head_ref;

	// searches through the entire linked list 
	while (temp != NULL) {

		// if the temp's data is less than min's data, then put min = temp and return min->data to give the largest item
		if (temp->data < min->data)
			min = temp;

		temp = temp->next;
	}
	return min->data; //returns the smallest item to user
}

//The main function
int main()
{
	// Start by creating an empty linked list
	struct node* head = NULL;
	//defines the integer listChoice
	int listChoice;
	//Uses a switch/case statement to create a user menu for interfacing with the linked list
	 //do statement with cout printed options
		cout << "\nDoubly-Linked List Main Menu.\n";
		cout << "1. Insert a number at the head of the linked list \n";
		cout << "2. Insert a number at the tail of the linked list \n";
		cout << "3. Insert a number in the middle of the linked list \n";
		cout << "4. Search for a number within the linked list \n";
		cout << "5. Delete a number within the linked list \n";
		cout << "6. Show the largest number within the linked list \n";
		cout << "7. Show the smallest number within the linked list \n";
		cout << "8. Display the Doubly-Linked List \n";
		cout << "9. Exit Program";
		cout << "\nEnter Choice: ";
		cin >> listChoice;
		return listChoice;
		//switch statement with individual cases
			switch (listChoice)
			{

			case 1: //case one for adding a head node into the linked list
				int head_input;
				cout << "\nChoose a number to insert to head. \n";
				cout << "Enter: ";
				cin >> head_input;

				add_head(&head, head_input);

				break;

			case 2://case two for adding a tail node into the linked list
				int tail_input;
				cout << "\nChoose a number to insert into the tail";
				cout << "Enter: ";
				cin >> tail_input;

				add_tail(&head, tail_input);

				break;

			case 3://case three for adding a node after the head node
				int center_input;
				cout << "\nChoose a number to insert into the middle of the linked list. \n";
				cout << "(Really its just inserting after the head node value) \n";
				cout << "Enter: ";

				insert_middle(head->next, center_input);

				break;

			case 4://case four for searching a specific node within the linked list
				int search_input;
				cout << "\nChoose a number to search for within the linked list. \n";
				cout << "Enter: ";

				search_node(head, search_input) ? cout << "Yes, is in list" : cout << "Does not exist";

				break;

			case 5://case five for deleting the head node
				cout << "\nHead node has been deleted. ";
				delete_node(&head, head);

				break;

			case 6://case six for finding the largest value node

				cout << "The largest node within the linked list is: " << largestItem(head) << " \n";

				break;

			case 7://case seven for finding the smallest value node

				cout << "The smallest node within the linked list is: " << smallestItem(head) << "\n";

				break;

			case 8://case eight for displaying the current linked list nodes

				display_List();

				break;

			case 9:
				cout << "Goodbye.\n";
				return 0;

			default:
				cout << "An Invalid choice.\n" << endl;
			}
	//while (listChoice != '9'); //while statement for when listChoice is not equal to 0
	//return 0;
}