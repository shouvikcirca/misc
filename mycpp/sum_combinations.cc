#include<bits/stdc++.h>
using namespace std;

bool correctSum(vector<int> dice, int sum)
{
	int s=0;
	for(int i:dice)
		s+=i;
	if(s==sum)
		return true;

	return false;
}


int perms(vector<int> dice, int sum, int ind, int m)
{
	int combs = 0;
	for(int i=1;i<=m;i++)
	{
		
		if(ind == dice.size()-1)
		{
			dice[ind] = i;
			if(correctSum(dice,sum))
			{
				for(int z:dice)
					cout<<z<<" ";
				cout<<endl;
				combs+=1;
			}
		}
		else
		{
			dice[ind] = i;
			combs+=perms(dice,sum,ind+1,m);
		}
	}

	return combs;
}




int main()
{
	
	vector<int> dice (4,1);
	int sum = 5;
	int m=2;

	cout<<perms(dice, sum, 0, m)<<endl;
}
