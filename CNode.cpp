#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;
#include"CNode.h"
CNode::CNode()
{
	data = 0;
	next = NULL;
}
CNode::~CNode()
{

}
CNode::CNode(int x)
{
	this->data = x;
	//number = x;
}
void CNode::setData()
{
	cout << " Please enter the data number" << endl;
	cin >> data;

}
void CNode::printData()

{
	cout << this->data << endl;
	//this->data jisko b point kr raha ha print that;
}
void CNode::writeToFile(ofstream& oFile)
{
	oFile.write((char *)&data, sizeof(data));
	//char*  nmbr kay address ko point kry ga
	//it will point the address of number
	//sizeof will tell us about the size number of what byte, at run time
}
void CNode::readFromFile(ifstream& iFile)
{
	iFile.read((char*)&data, sizeof(data));
}
int CNode::getData()
{
	return data;
}