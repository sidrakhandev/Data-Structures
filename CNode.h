#pragma once
#include<fstream>
class CNode 
{
	int data;

public:
	CNode *next;
	CNode();
	CNode(int x);
	~CNode();
	void printData();
	void writeToFile(ofstream& oFile);
	void readFromFile(ifstream& iFile);
	void setData();
	int getData();
	//In this function we will take inp will take input from user
};
