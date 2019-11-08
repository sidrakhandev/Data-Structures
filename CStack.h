#pragma once
#include"CNode.h"
class CStack {
	int count;
	//to maintain data in Stack
public:
	CNode *top;
	CStack();
	~CStack();
	//CStack(int a);
	bool isNotEmpty()const;
	bool isEmpty()const;
	CNode *pop()
	{
		CNode *ptr = top;
		if (top)
		{
			top = ptr->next;
			ptr->next = NULL;
		}
		return ptr;
	}
	void push(CNode *&ptr);
	void CPrint() const;
	CStack(CNode *&ptr);
	CStack(const CStack*&src);
	CStack& operator=(const CStack& robj);
};
