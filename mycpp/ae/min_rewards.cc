#include <bits/stdc++.h>
using namespace std;

vector<int> minRewards(vector<int> scores)
{
	vector<int> rewards(scores.size(),1);

	for(int i=1;i<rewards.size();i++)
		if(scores[i]>scores[i-1])
			rewards[i] = rewards[i-1]+1;

	for(int i = scores.size()-2;i>=0;i--)
		if(scores[i]>scores[i+1])
			rewards[i] = max(rewards[i],rewards[i+1]+1);

	int sum = 0;
	for(int i:rewards)
		sum +=i;

	return rewards;
}

int main()
{
	vector<int> rewards;
	rewards = minRewards({8,4,2,1,3,6,7,9,5});
	int sum = 0;
	for(int i:rewards)
	{
		cout<<i<<" ";
		sum+=i;
	}
	cout<<endl;
	cout<<"Total Rewards: "<<sum<<endl;
}

