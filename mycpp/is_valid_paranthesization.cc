#include<bits/stdc++.h>
using namespace std;

bool IsWellFormed(const string& s)
{
	stack<char> left_chars;
	char top;
 	const unordered_map<char, char> kLookup = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
	for(int i = 0;i<s.length();i++)
	{
		if(s[i] == '(' || s[i] == '{' ||  s[i] == '['  )
			left_chars.emplace(s[i]);
		else
		{
			
			if(!left_chars.empty())
			{
				top = left_chars.top();
				if(kLookup.at(top) != s[i])
					return false;
				else
					left_chars.pop();
			}
			else
				return false;
		}
	}
	if(left_chars.size() == 0)
		return true;
	else
		return false;
}

int main(int argc, char* argv[])
{
	string s1 = "([]{})";
	string s2 = "[])";
	string s3 = "[](";
	string s4 = "";
	string s5 = ")";

	cout<<s1<<(IsWellFormed(s1)?" is well formed":" is not well formed")<<endl;
	cout<<s2<<(IsWellFormed(s2)?" is well formed":" is not well formed")<<endl;
	cout<<s3<<(IsWellFormed(s3)?" is well formed":" is not well formed")<<endl;
	cout<<s4<<(IsWellFormed(s4)?" is well formed":" is not well formed")<<endl;
	cout<<s5<<(IsWellFormed(s5)?" is well formed":" is not well formed")<<endl;
}
