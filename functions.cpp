#include "functions.h"
#include <iostream>

using namespace std;

string infixinput(){ //function recieves the infix expression from the user

	string input;

	cout << "Please input a mathematical expression in infix notation: " << endl;
	getline(cin, input);

	return(input);

}

vector<string> tokenize(string input){//function takes the infix expression and tokenizes it, into a vector of strings, as well as removes deadspace
	
	char* tokens = new char[input.size()]; //a dynamically allocated array of chars is necessary, because the strtok function will only accept an array of chars, not a string
	char* ptr; //this pointer is created to return values from the strtok function
	vector<string> tokens2; //output vector initiliazed

	for(int i = 0;i <= input.size();i++) //converts the string to the array of chars, for use in the strtok function
		tokens[i] = input[i];
	
	ptr = strtok(tokens, " "); //strtok takes the array, and ' ' as the deliminator as arguments

	while(ptr != NULL){
		tokens2.push_back(ptr); //this loops through the char array until all of the input has been tokenized
		ptr = strtok(NULL, " ");
	}
	return(tokens2); //returns the string vector with tokens

}

vector<string> infixalgo(vector<string> input){

	string c; //variable created for temporary storage during the conversion algorithm
	stack<string> ops; //stack to temporarily store operators during the algorithm
	vector<string>::iterator iter; // iterator to iterate through the string vector for processing
	vector<string> postfix; //another string vector is created to store the postfix expression


	for(iter = input.begin(); iter != input.end();iter++){

		if(*iter == "(") // if iter == '(', push it to the stack
			ops.push(*iter);
		else if(isnumber(*iter)){ //if it's a #, push it on the vector
			postfix.push_back(*iter);
		}
		else if(*iter == ")"){ // if iter == ')'
			if(!ops.empty()){
				c = ops.top();
				ops.pop();
			}
			while(c != "("){ //while iter is not == '(', c == 
				postfix.push_back(c);
				if(!ops.empty()){
				c = ops.top();
				ops.pop();
				}
			}
		}
		else //must be operator
			if(ops.empty() || ops.top() == ")") //if stack is empty or contains ')'

				ops.push(*iter);
			
			else{
				
			if(getweight(ops.top(), *iter)){ //while top of stack has equal or higher precedence to token
					
			if(!ops.empty()){
			c = ops.top();
			ops.pop();
			postfix.push_back(c);
				}
			}
			ops.push(*iter);
			}
		}

	while(!ops.empty()){ // puts any remaining operators in the stack, onto the end of the postfix vector
		postfix.push_back(ops.top());
		ops.pop();
	}
		
	return(postfix); //returns the string vector containing the postfix expression
}


bool isoperator(string c){ //boolean function to determine if the token is an operator

	if( c == "+" || c == "-" || c == "*" || c == "/")
		return true;
	else
		return false;
}

bool isnumber(string c){//function to determine if the token is an integer
	
	
	if(c.length() == 1){ //if the token is one digit
		if(c >= "0" && c <= "9")
			return true;
		else
			return false;
	}
	for(int i = 0; i <= c.length();i++){ //if the token is multiple digits, it will check each digit to ensure it's an integer
		if( c < "0" || c > "9")
			return false;
	}

	return true;
}

bool getweight(string a, string b){//function that determines the precedence of two operators.  Returns true if the first operator has equal or higher precedence than the second

	int aweight = 0;
	int bweight = 0;
	
	if(a == "*" || a == "/")
		aweight = 2;
	else
		aweight = 1;
	if(b == "*" || b =="/")
		bweight = 2;
	else
		bweight = 1;

	
	if( aweight >= bweight)
		return(true);
	else
		return(false);
}

int intconverter(string input){//function to convert string tokens into integers

	int k = 0; //temporary variables needed for calculation
	int m = 0;
	int result = 0;
	char j = NULL;

	if(input.size() == 1){ //if one digit, the char is simply subtracted from the ascii for 0, thus returning its actual value as an int

		char j = input[0];
		k = j - '0';
		return(k);
	}
	if(input.size() >= 2){

		for(int i = 0; i < input.size();i++){

			char j = input[i]; //this loop is for multiple digit integers
			k = j - '0';
			m = (m * 10) + k;

		}
		return(m);
	}

	else
		return (0); //default return path, this would indicate an error
}