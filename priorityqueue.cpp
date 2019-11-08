#include<iostream>
#include"queue.cpp"
#include"node.h"
class PriorityQueue :public Queue
{
public:
	PriorityQueue(CNode*&ptr)
	{
	}
	PriorityQueue()
	{
	}
	PriorityQueue &add(CNode *&ptr)
	{
		if (!top)
		{
			top = tail = ptr;
			tail->next = ptr = NULL;
		}
		else if (top->priority < ptr->priority)
			CStack::push(ptr);
		else if (top->priority >= ptr->priority)
			Queue::add(ptr);
		else
		{
			CNode *rptr = top;
			while (rptr->priority >= ptr->priority)
			{
				rptr = rptr->next;
			}
			ptr->next = rptr->next;
			rptr->next = ptr;
			ptr = NULL;
		}
		return *this;
	}
	PriorityQueue(const PriorityQueue& src)
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
				dptr->next = new CNode(*sptr);
				sptr = sptr->next;
				dptr = dptr->next;
			}
			tail = dptr;
		}

	}
	PriorityQueue& operator=(const PriorityQueue& robj)
	{
		if (this == &robj)
			return *this;
		if (true)
		{
			PriorityQueue temp;
			temp.top = top;
			temp.tail = tail;
		}
		if (true)
		{
			PriorityQueue temp = robj;
			top = temp.top;
			tail = temp.tail;
			temp.top = NULL;
			temp.tail = NULL;
		}
	}
	void printqueue()
	{
		CNode *ptr =top;
		while (ptr)
		{
			ptr->printData();
			ptr = ptr->next;

		}
	}
};
