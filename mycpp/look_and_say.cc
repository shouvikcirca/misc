#include <bits/stdc++.h>
using namespace std;

string NextNumber(const string& s);

string LookAndSay(int n)
{
	string returnString = "1";
	for(int i=0;i<n-1;i++)
		returnString = NextNumber(returnString);
	return returnString;
}

string NextNumber(const string& s)
{
	int slength = s.length();
	int count;
	string returnString = "";

	for(int i=0;i<slength;i++)
	{
		count = 1;
		while((i+1<slength) && (s[i] == s[i+1]))
		{
			count+=1;
			i+=1;
		}
		returnString += to_string(count)+s[i];
	}	
	return returnString;
}

int main(int argc, char* argv[])
{
	int number;
	cout<<"Enter a number"<<endl;
	cin>>number;
	cout<<endl<<LookAndSay(number)<<endl;

}
