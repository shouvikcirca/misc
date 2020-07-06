#include<bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string str)
{
			
		int start = 0,k;
		int end = 0;
		string fs,bs;
		
	
		for(int i=0;i<str.length();i++)
		{
				for(int j=str.length()-1;j>=i;j--)
				{
						k = j;
						fs = "";
						bs = "";
						fs = str.substr(i,(k-i+1));
						while(k>=i)
						{
							bs+=str[k];
							k-=1;
						}
						k+=1;
						if(fs == bs)
						{
								if(j-i+1>=end-start+1)
								{
										start = i;
										end = j;
								}
						}
				}
		}
	
	
  	return str.substr(start,(end-start+1));
}
