#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;
#include"CStack.h"
#include"CNode.h"

CStack::CStack()
{
	top = NULL;
}
//CStack(int a);
bool CStack::isNotEmpty()const
{
	if (top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CStack::push(CNode *&ptr)
{
	ptr->next = top;
	top = ptr;
	ptr = NULL;


}
void CStack::CPrint() const
{
	CNode *ptr = top;
	while (ptr)
	{
		ptr->printData();
		ptr = ptr->next;
	}
}
CStack::CStack(CNode *&ptr)
{
	top = ptr;
	top->next = NULL;
	ptr = NULL;
}
bool CStack::isEmpty()const
{
	if (top)
		return false;
	else {
		return true;
	}
}
CStack::~CStack()
{
	CNode *ptr = top;
	while (top)
	{
		top = top->next;
		delete ptr;
		ptr = top;
	}
}
  CStack::  CStack(const CStack*&src)
{
	this->top = src->top;
	if (src->top)
	{
		CNode *sptr, *dptr;
		new CNode(*src->top);
		dptr = this->top = new CNode(*src->top);
		sptr = src->top->next;
		while (sptr)
		{
			dptr->next = new CNode(*sptr);
			sptr = sptr->next;
			dptr = dptr->next;
		}
	}
}
  CStack& CStack:: operator=(const CStack& robj)
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
	}
	return *this;
}
