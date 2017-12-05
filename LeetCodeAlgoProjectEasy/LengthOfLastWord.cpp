/*
 * LengthOfLastWord.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(const string& s,char delim){

	stringstream ss(s);
	string item;
	vector<string>tokens;

	while(std::getline(ss,item,delim)){
		tokens.push_back(item);
	}
	return tokens;
}

int lengthOfLastWord(const string& s){

	vector<string>tokens = split(s,' ');
	string last = tokens.back();
	return last.length();
}

int main(){

	cout<<lengthOfLastWord("Hello World")<<endl;
	cout<<lengthOfLastWord("Hello ")<<endl;
	cout<<lengthOfLastWord(" ")<<endl;

	return 0;

}
