#include "bst.h"
#include "functions.h"
#include <vector>
#include <stack>
using namespace std;


BST::BST(){ 
	root = NULL;

}

BST::~BST(){

}

Node* BST::buildTree(vector<string> tokens){//function inputs the expression into the tree
	
	stack<Node*> nodes;
	Node* ptr;
	
	for(vector<string>::iterator iter = tokens.begin(); iter != tokens.end(); iter++){

		if(isnumber(*iter)){

			ptr = new Node(intconverter(*iter));
			nodes.push(ptr);  //if the token is an int, convert it to type int and push it on the stack
		}// end if

		if(isoperator(*iter)){

			ptr = new Node(*iter);		//creats a new node out of the operator
			ptr->right = nodes.top();	//assigns the top of the stack to the right pointer of the operator
			nodes.pop();				//pop stack
			ptr->left = nodes.top();	//assigns top of the stack to the left pointer of the operator
			nodes.pop();				//pop stack

			nodes.push(ptr);			//return the operator node back to the stack
		} //end if
	} //end for

	root = nodes.top();
	return(root);
} // end function

void BST::inOrder(Node* node){//recursive function to display the tree in infix notation
	
	if(node == NULL) //default case, if tree is empty
		return;
	
	if(node->left != NULL)
		inOrder(node->left); //if not null, recursive call on left node

	if(node->value != NULL)
		cout << node->getValue() << " "; //if int, print the int
	if(node->oper != "")
		cout << node->getOp() << " "; //if operator, print the operator
	if(node->right != NULL) 
		inOrder(node->right);//if not null, recursive call on the right node

}

void BST::postOrder(Node* node){ //recursive function to display the tree in postfix notation
	
	if(node == NULL)//default case, if tree is empty
		return;
	
	if(node->left != NULL)
		postOrder(node->left); //if not null, recursive call on left node
	if(node->right != NULL)
		postOrder(node->right);//if not null, recursive call on right node

	if(node->value != NULL)
		cout << node->getValue() << " ";//if int, print the int
	if(node->oper != "")
		cout << node->getOp() << " ";//if operator, print the operator

}

void BST::preOrder(Node* node){ //non-recursive function to display the tree in prefix notation

	if(node == NULL) //default case if tree is empty
		return;

	Node* n; //temporary node
	stack<Node*> treestack; //stack used for traversal
	treestack.push(node); //push the root node

	while(!treestack.empty()){

		n = treestack.top();  //assign n to the top of the stack
		if(n->value != NULL) //if n has an int value, display it
			cout << n->getValue() << " ";
		if(n->oper != "") // if n has an operator value, display it
			cout << n->getOp() << " ";

		treestack.pop(); //pop the stack
		if(n->right != NULL)
			treestack.push(n->right); // if n has a right node, push it on the stack
		if(n->left !=NULL)
			treestack.push(n->left);// if n has a left node, push it on the stack

	}//end while

}//end function

int BST::evaluate(Node* node){ //recursive function to evaluate the expression in the tree


	if(node == NULL)//default case, if tree is empty
		return(0);

	if(node->value != NULL)
		return(node->getValue()); //if int, return the int
	
	if(node->oper == "*")
		return(evaluate(node->left) * evaluate(node->right)); //if "*", multiply the result of evaluate left and right

	if(node->oper == "+")
		return(evaluate(node->left) + evaluate(node->right)); //if "+", add the result of evaluate left and right

	if(node->oper == "-")
		return(evaluate(node->left) - evaluate(node->right)); //if "-", subtract the result of evaluate left and right

	if(node->oper == "/")
		return(evaluate(node->left) / evaluate(node->right)); //if "/", divide the result of evaluate left and right

}