#include <bits/stdc++.h>
using namespace std;

int findminspaces(string pi, int start, unordered_map<string, bool> nums, unordered_map<int, bool> &minspaces)
{
	cout<<start<<endl;
	if(start == pi.length())
		return -1;

	if(minspaces.count(start))
			return minspaces[start];
		
	int mins, minsps = INT_MAX;
	string prefix;
	
	for(int i=1;i<=(pi.length() - start);i++)
	{
		prefix = pi.substr(start,i);
		//cout<<prefix<<" ";
		if(nums.count(prefix))
		{
			//cout<<"y"<<endl;
			mins = findminspaces(pi,start+i,nums,minspaces);
			minsps = (mins==INT_MAX)?min(minsps, mins):min(minsps,1+mins);
		}
		//cout<<endl;
	}
	minspaces[start] = minsps;
	return minsps;	
}


int numbersInPi(string pi, vector<string> numbers)
{
	unordered_map<string, bool> nums;
	for(string n:numbers)
		nums[n] = true;

	unordered_map<int,bool> minspaces;
	int minsps = findminspaces(pi, 0, nums, minspaces);
	return  minsps == INT_MAX?-1:minsps;
}

int main()
{
	string pi = "3141592653589793238462643383279";
	vector<string> numbers = {"3","314","49","9001","15926535897","14","9323","8462643383279","4","793"};

	cout<<numbersInPi(pi, numbers)<<endl;
}
