/*
 * RestoreIpAddresses.cpp
 *
 *  Created on: Dec 19, 2017
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

using namespace std;

#define MAX_ENTRIES 4

class Solution {

private:

	bool validString(string s){
		int value = std::stoi(s);
		if(value >=0 && value <=255){
			return true;
		}
		return false;
	}

	vector<int>possibleValidCombo;

	void generateList(vector< vector<int> >&list,vector<int>currVec,int currTotal){
		// base condition
		if(currTotal == 0 && currVec.size() == MAX_ENTRIES){
			list.push_back(currVec);
			return;
		}else if(currTotal <0 && currVec.size() <= MAX_ENTRIES){
			return;
		}else if(currTotal > 0 && currVec.size() == MAX_ENTRIES){
			return;
		}else{
			for(int i=0;i<possibleValidCombo.size();i++){
				currVec.push_back(possibleValidCombo[i]);
				currTotal -= possibleValidCombo[i];
				generateList(list,currVec,currTotal);
				currVec.pop_back();
				currTotal += possibleValidCombo[i];
			}
		}


	}

public:

	Solution(){
		possibleValidCombo.push_back(1);
		possibleValidCombo.push_back(2);
		possibleValidCombo.push_back(3);
	}

	vector<string> restoreIpAddresses(string s)
    {

    	vector<string>result;
    	vector<int>currVec;
    	vector< vector<int> >list;
    	generateList(list,currVec,s.size());

    	for(int i=0;i<list.size();i++)
    	{
    		int startIndex = 0;
    		string ipAddress = "";
    		for(int j=0;j<list[i].size();j++)
    		{
    			//cout<<list[i][j]<<" ";
    			string curString = s.substr(startIndex,list[i][j]);
    			if(validString(curString)){
    				ipAddress += curString;
    				ipAddress += ".";
    				startIndex += list[i][j];
    			}else{
    				ipAddress = "";
    				break;
    			}
    		}
    		if(!ipAddress.empty())
    		{
    			ipAddress.erase(ipAddress.length()-1,1);
    			result.push_back(ipAddress);
    		}
    	}
    	return result;
    }
};

int main(){

	{
		Solution solution;
		vector<string>result = solution.restoreIpAddresses("25525511135");
		for(int i=0;i<result.size();i++)
		{
			cout<<result[i]<<endl;
		}
	}


	return 0;

}
