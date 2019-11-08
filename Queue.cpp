#include<iostream>
#include"stack.h"
using namespace std;
class Queue : protected CStack
{
public:
	CNode *tail;
	Queue() :tail(NULL)
	{
	}
	Queue(CNode *&ptr) : CStack(ptr), tail(top)
	{
	}
	bool isnotEmpty()const
	{
		return CStack::isNotEmpty();
	}
	bool isempty()const
	{
		return CStack::isEmpty();
	}
	CNode* remove()
	{
		if (!top->next)
		{
			tail = NULL;
			return CStack::pop();
		}
	}
	Queue & add(CNode*&ptr)
	{
		if (tail)
		{
			tail->next = ptr;
			tail = tail->next;
		}
		else
		{
			tail = top = ptr;
			tail->next = NULL;
			ptr = NULL;
			return *this;
		}
	}
	void print()const

	{
		CStack::CPrint();
	}
	Queue(const Queue&src)
	{
		this->top = src.top;
		this->tail = src.tail;
		if (src.top)
		{
			CNode *sptr, *dptr;
			dptr = this->top = new CNode(*src.top);
			sptr = top->next;
			while (sptr)
			{
				dptr->next= new CNode(*sptr);
				sptr = sptr->next;
				dptr = dptr->next;
			}
			tail = dptr;
		}

	}
	Queue& operator=(const CStack& robj)
	{
		if (this == &robj)
		{
			return *this;
		}
		if (true)
		{
			CStack temp;
			temp.top = top;
		}
		if (true)
		{
			CStack temp = robj;
			top = temp.top;
			temp.top = NULL;
			tail = NULL;
		}
		return *this;
	}
	 void printqueue()
	{
		CNode *ptr = top;
		while (ptr)
		{
			ptr->printData();
			ptr = ptr->next;

		}
	}
};