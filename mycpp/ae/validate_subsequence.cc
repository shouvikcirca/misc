#include<bits/stdc++.h>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) 
{
	int arrind = 0, seqind = 0;

	while(seqind<sequence.size() && arrind<array.size())
	{
		if(array[arrind] == sequence[seqind])
		{
			arrind+=1;seqind+=1;
			if(seqind==sequence.size())
				return true;
		}
		else
			arrind+=1;
	}

	if(seqind<=sequence.size()-1)
		return false; 
}

int main()
{
	cout<<isValidSubsequence({5,1,22,25,6,-1,8,10},{1,6,-1,10})<<endl;
}
