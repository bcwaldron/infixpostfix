using namespace std;
#include "node.h"
#include <iostream>
#include <string>

Node::Node(){
	
	left = NULL;
	right = NULL;
	value = 0;
	oper = "";
}

Node::Node(int val){

	left = NULL;
	right = NULL;
	value = val;
	oper = "";
}

Node::Node(string op){

	left = NULL;
	right = NULL;
	value = NULL;
	oper = op;
}

Node::~Node(){
}


int Node::getValue(){

	return value;
}

string Node::getOp(){

	return oper;
}
