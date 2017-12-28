#ifndef BST_H
#define BST_H
#include "node.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class BST{

public:
	BST();
	Node* buildTree(vector<string>);
	~BST();
	void inOrder(Node* node);
	void postOrder(Node* node);
	void preOrder(Node* node);
	int evaluate(Node* node);
private:
	Node* root;



};

#endif