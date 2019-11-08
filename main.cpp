#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
#include"node.h"
#include"priorityqueue.cpp"
int main()
{
	CNode *ptr = NULL;
	PriorityQueue *st = new PriorityQueue();
	cout << "Menu" << endl;
	cout << "1-Do you want to check the Cqueue?" << endl;
	cout << "2-Do you want to add in Cqueue?" << endl;
	cout << "3-Do you want to remove from Cqueue?" << endl;
	cout << "4-Do you want to show the list" << endl;

	bool flag = true;
	while (true)
	{
		char choice;
		cout << "Please enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case'1':
		{
			if (st->isEmpty())
			{
				cout << "queue is empty" << endl;
			}
			else
			{
				cout << "queue is not empty" << endl;
			}
		}
		break;
		case '2':


		{
			CNode *n = new CNode();
			n->setData();
			n->setPriority();
			st->add(n);
		}

		break;


		case'3':
		{
			if (st->isNotEmpty())
			{
				CNode *a;
				cout << "The number which you want to remove is:" << endl;
				a = st->remove();
				cout << a->getData() << endl;


			}
			else
			{
				cout << "No more values to remove" << endl;

			}


		}
		break;
		case'4':
		{
			cout << "All the numbers in queue are:" << endl;
			st->printqueue();
		}
		break;

		default:
			cout << "wrong choice! please enter correct choice" << endl;
		}

	}
	_getch();
	return 0;
}