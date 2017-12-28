// CPSC 2380: Data Structures and Algorithms
//Spring 2016
//Project 2: Evaluation of Arithmetic Expressions in an Expression Tree
//Name: Bryan Waldron
//T-number (Last 4 Digits): 3600
//Description of the Program (2-3 sentences): This program is intended to take a user input infix expression, convert it to postfix,
//build a binary tree, and evaluate it
//Date Written: 19 April 2016
//Date Revised: 22 April 2016

#include <iostream>
#include "functions.h"
#include "node.h"
#include "bst.h"
#include <vector>

void main(){
	
	string input = infixinput(); //takes user input infix expression
	vector<string> tokens = tokenize(input); //tokenizes the expression into a vector of strings
	tokens = infixalgo(tokens); //converts the infix expression to postfix

	BST* tree = new BST();//constructs a binary search tree out of the postfix expression
	Node* r = tree->buildTree(tokens); //and assigns r as the root

	cout <<"The expression in prefix notation is..."<< endl;
	tree->preOrder(r); //uses preorder traversal to display the expression in prefix
	cout << endl << endl;
	
	cout << "The expression in infix notation is..." << endl;
	tree->inOrder(r); //uses inorder traversal to display the expression in infix
	cout << endl << endl;

	cout << "The expression in postfix notation is..."<< endl;
	tree->postOrder(r); // uses postorder traversal to display the expression in postfix
	cout << endl << endl;

	


	int result = tree->evaluate(r); //evaluate the tree
	
	cout << endl << "You're result is:   " << result << endl; //displays the result

	
	

	system("PAUSE");

	
}