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

/*
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

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

/*
 * For Loop solution
 */
vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;

        for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
        for (int c=1; c<=3; c++)
        for (int d=1; d<=3; d++)
            if (a+b+c+d == s.length()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a+b, c));
                int D = stoi(s.substr(a+b+c, d));
                if (A<=255 && B<=255 && C<=255 && D<=255)
                    if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                        ret.push_back(ans);
            }

        return ret;
    }



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
