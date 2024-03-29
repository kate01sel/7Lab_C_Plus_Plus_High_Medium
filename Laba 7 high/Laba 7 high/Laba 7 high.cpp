#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node
{
	int number;
	Node* next;
	Node* prev;
};


int main()
{
	int i, n;
	cin >> n;

	Node* head = new Node;

	head->next = head;
	head->prev = head;
	head->number = 0;

	Node* ptrLast = NULL;


	int numb = NULL;
	for (i = 0; i < n; i++)
	{
		cin >> numb;
		Node* ptr = new Node;
		ptr->number = numb;

		ptr->prev = head->prev;
		ptr->next = head;
		head->prev->next = ptr;
		head->prev = ptr;
	}


	Node* ptr = NULL;
	ptr = head->next;
	while (ptr != head)
	{
		cout << ptr->number << " ";
		ptr = ptr->next;
	}

	ptr = head;
	Node *help = NULL;
	for (i = 0; i < n; i++)
	{
		help = ptr;
		ptr = ptr->next;
		if (ptr->number == 3)
		{
			if (help == head)
				head = ptr->next;
			else
				help->next = ptr->next;

			delete (ptr);
			n--;
		}
	}

	ptr = head;
	ptr = ptr->next;
	for (i = 0; i < n; i++)
	{
		cout << ptr->number << " ";
		ptr = ptr->next;
	}

	return 0;
}