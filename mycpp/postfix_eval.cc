#include<bits/stdc++.h>
using namespace std;

int main()
{
	string expression = "231*+9-";
	int array[expression.length()];
	int j=0,ih;
	string s="";

	for(int i=0;i<expression.length();i++)
	{
		switch(expression[i])
		{
			case '+':
				array[j-2] = array[j-2]+array[j-1];
				j-=1;
				break;
			case '-':
				if(j==1)
					array[j-1] = array[j-1]*-1;
				else
				{
					array[j-2] = array[j-2]-array[j-1];
					j-=1;
				}
				break;
			case '*':
				array[j-2] = array[j-2]*array[j-1];
				j-=1;
				break;

			case '/':
				array[j-2] = array[j-2]/array[j-1];
				j-=1;
				break;
			default:
				stringstream ch;
				s=s+expression.at(i);
				ch<<s;
				s="";
				ch>>ih;
				array[j] = ih;
				j+=1;
		}

	}
	cout<<array[0]<<endl;
}

