#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<string>
#include<stack>
#include<vector>
#include<stdio.h>
using namespace std;

string infixinput();

vector<string> tokenize(string);

vector<string> infixalgo(vector<string>);

bool isoperator(string);

bool getweight(string, string);

bool isnumber(string);

int intconverter(string);








#endif