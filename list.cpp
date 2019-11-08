#include<iostream>
#include"node.h"
//#include"node.cpp"
using namespace std;
#include<fstream>
#include<string.h>
class List
{
	int count;
public:
	CNode *head;
	List(): head(NULL),count(0)
	{}
	List(CNode *& ptr ) : head(ptr), count(1)
	{
		head->next = ptr = NULL;
	}
	/*List(ifstream& infile)
	{
		if (!(infile.is_open()))
		{
			cerr << "\n List::constructor: File not open !";
			exit(1);
		}
		if (true)
		{
			List temp;
			temp.head = this->head;
		}
		infile.read((char*)& count, sizeof(count));
		if (count > 0)
		{
			CNode* ptr = new CNode();
			ptr = head = new CNode(infile);
			for (int i = 1; i < count; ++i)
			{
				ptr->next = new CNode(infile);
				ptr = ptr->next;

			}
			ptr->next = NULL;
		}

	}*/
	List(const List &src) :head(src.head), count(src.count)
	{
		if (count > 0)
		{
			CNode *dptr, *sptr;
			dptr = head = new CNode(*src.head);
			sptr = head->next;
			for (int i = 1; i < count; ++i)
			{
				dptr->next = new CNode(*sptr);
				dptr = dptr->next;
				sptr = sptr->next;
			}
			dptr->next = NULL;
		}
	}
	~List()
	{
		void delNodes(CNode *ptr);
		delNodes(head);
	}
	void delNodes(CNode *ptr)
	{
		if (ptr)
		{
			delNodes(ptr->next);
			delete ptr;
		}
	}
	bool isEmpty()const
	{
		if (head)
			return false;
		else {
			return true;
		}
	}
	bool isNotEmpty()const
	{
		if (head)
			return true;
		else {
			return false;
		}
	}
	int getCount()const
	{
		return count;
	}
	List& insert(CNode *& ptr)
	{
		ptr->next = this->head;
		head = ptr;
		ptr = NULL;
		++count;
		return *this;
	}
	List& insertAt(int index, CNode *& ptr)
	{
		if (index <= 0)
		{
			insert(ptr); return *this;
		}
		if (index > count)
			index = count;
		CNode *rptr = head;
		for (int i = 1; i < index; ++i)
			rptr = rptr->next;
		rptr = rptr->next;
		ptr->next= rptr->next;
		rptr->next = ptr;
		++count;
		ptr = NULL;
		return *this;

	}
	CNode* remove()
	{
		CNode *ptr = head;
		head = head->next;
		ptr->next = NULL;
		--count;
		return ptr;
	}
	CNode* removeAt(int index)
	{
		if (index <= 0)
		{
			return remove();
		}
		if (index >= count)
			index = count - 1;
		CNode  *rptr = head;
		for (int i = 1; i < index; ++i)
			rptr = rptr->next;
		CNode *ptr;
		ptr = rptr->next;
		rptr->next = ptr->next;
		--count;
		ptr->next = NULL;
		return ptr;
	}
};