#include "stdafx.h"
#include <iostream>

using namespace std;

struct Number
{
	int num;
	Number* Next;
}*p;

int main()
{
	int i, j, size;

	cin >> size;

	p = new Number;
	Number *head = p;
	p->Next = 0;

	for (i = 0; i < size; i++)
	{
		cin >> j;
		p->num = j;
		p->Next = new Number;
		p = p->Next;
		p->Next = 0;
	}
	
	p = head;
	for (i = 0; i < size; i++)
	{
		cout << p->num << " ";
		p = p->Next;
	}
	cout << endl;

	p = head;
	Number *help = NULL;
	for (i = 0; i < size; i++)
	{
		help = p;
		p = p->Next;
		if (p->num == 55)
		{
			if (help == head)
				head = p->Next;

			else
				help->Next = p->Next;

			delete(p);
			perror(" ");

			size--;
		}
	}

		p = head;
		for (i = 0; i < size; i++)
		{
			cout << p->num << " ";
			p = p->Next;
		}
		cout << endl;

    return 0;
}

