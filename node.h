#ifndef NODE_H
#define NODE_H
#include<string>
using namespace std;


class Node{
	friend class BST;
public:
	Node();
	Node(int val);
	Node(string op);
	~Node();
	int getValue();
	string getOp();

private:
	Node* left;
	Node* right;
	int value;
	string oper;


};



#endif