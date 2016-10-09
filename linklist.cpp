#include<iostream>

using namespace std;

struct node{
	int data;
	struct node* next;
};
struct node *newNode(int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = NULL;
	return new_node;
}

void insert(struct node ** head, struct node* node){
	struct node* cur;
	if (*head == NULL || (*head)->data >= node->data){
		node->next = *head;
		*head = node;
	}
	else{
		cur = *head;
		while (cur->next != NULL && cur->next->data < node->data){
			cur = cur->next;
		}
		node->next = cur->next;
		cur->next = node;
	}
}

void printList(struct node *head)
{
	struct node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}



void deletenode(struct node **head, int value){
	if (head == NULL || *head == NULL)
		return;
	struct node *p = NULL;
	if ((*head)->data == value){
		p = *head;
		*head = (*head)->next;
	}
	else{
		struct node *node = *head;
		while (node->next != NULL&&node->next->data != value)
			node = node->next;
		if (node->next != NULL&&node->next->data == value){
			p = node->next;
			node->next = node->next->next;
		}
	}
	if (p != NULL){
		free(p);
		p = NULL;
	}
}

void deletenodeall(struct node **head, int value){
	if (head == NULL || *head == NULL)
		return;
	struct node *p = NULL;
	if ((*head)->data == value){
		p = *head;
		*head = (*head)->next;
	}
	else{
		struct node *node = *head;
		while (node->next != NULL){
			while (node->next != NULL&&node->next->data != value)
				node = node->next;
			if (node->next != NULL&&node->next->data == value){
				p = node->next;
				node->next = node->next->next;
			}
			if (p != NULL){
				free(p);
				p = NULL;
			}
		}	
	}
	if (p != NULL){
		free(p);
		p = NULL;
	}
}

/*
struct node *merge(struct node *a, struct node *b){
	struct node * res = NULL;
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	if (a->data <= b->data){
		res = a;
		res->next = merge(a->next, b);
	}
	else{
		res = b;
		res->next = merge(a, b->next);
	}
	return res;
}
void split(struct node *head, struct node **front, struct node **behind){
	struct node *fast;
	struct node *slow;
	if (head == NULL || head->next == NULL){
		*front = head;
		*behind = NULL;
	}
	else{
		slow = head;
		fast = head->next;
		while (fast != NULL){
			fast = fast->next;
			if (fast != NULL){
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*behind = slow->next;
		slow->next = NULL;
	}
}
void mergesort(struct node ** headref){
	struct node *head = *headref;
	struct node *a;
	struct node *b;
	if (head == NULL || head->next == NULL){
		return;
	}
	split(head, &a, &b);
	mergesort(&a);
	mergesort(&b);
	*headref = merge(a, b);
}
*/

struct node* merge(struct node *a, struct node *b){
	struct node *res = NULL;
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	if (a->data <= b->data){
		res = a;
		res->next = merge(a->next, b);
	}
	else{
		res = b;
		res->next = merge(a, b->next);
	}
	return res;
}
void split(struct node* head, struct node **front, struct node **behind){
	if (head == NULL || head->next == NULL){
		*front = head;
		*behind = NULL;
	}
	struct node* slow = head;
	struct node* fast = head->next;
	while (fast != NULL){
		fast = fast->next;
		if (fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = head;
	*behind = slow->next;
	slow->next = NULL;
}
void mergesort(struct node **headref){
	struct node *head = *headref;
	struct node *a;
	struct node *b;
	if (head == NULL || head->next == NULL){
		return;
	}
	split(head, &a, &b);
	mergesort(&a);
	mergesort(&b);
	*headref = merge(a, b);
}

void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

struct node* reverse(struct node *head){
	struct node* reversehead = NULL;
	struct node * pre = NULL;
	struct node *pnode = head;
	while (pnode != NULL){
		struct node *next = pnode->next;
		if (next == NULL){
			reversehead = pnode;
		}		
		pnode->next = pre;
		pre = pnode;
		pnode = next;
	}
	return reversehead;
}

/*
int main()
{
	//Start with the empty list 
	struct node* head = NULL;
	struct node *new_node = newNode(5);
	insert(&head, new_node);
	new_node = newNode(10);
	insert(&head, new_node);
	new_node = newNode(7);
	insert(&head, new_node);
	new_node = newNode(3);
	insert(&head, new_node);
	new_node = newNode(1);
	insert(&head, new_node);
	new_node = newNode(9);
	insert(&head, new_node);
	//printList(head);
	//mergesort(&head);
	//printList(head);
	push(&head, 15);
	push(&head, 10);
	push(&head, 5);
	push(&head, 20);
	push(&head, 3);
	push(&head, 2);
	mergesort(&head);
	deletenodeall(&head, 3);
	struct node *newhead=reverse(head);
	printList(newhead);
	system("pause");
	return 0;
}
*/