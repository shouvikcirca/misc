#include<bits/stdc++.h>
using namespace std;

vector<int> consecutiveNums(int target)
{
	int start = 1;
	int end = start+1;
	int runningsum = start;
	vector<int> returnvec;

	while(end<=ceil(target/2.0) && start!=end)
	{	
		runningsum = runningsum+end;
		if(runningsum == target)
		{
			for(int i=start;i<=end;i++)
				returnvec.push_back(i);
			return returnvec;
		}
		else if(runningsum > target)
		{
			runningsum-=start;
			runningsum-=end;
			start+=1;
		}
		else
			end+=1;
	}
	return returnvec;
}

int main()
{

	vector<int> nums;
	for(int rnums=1;rnums<=512;rnums++)
	{
		int target = rnums;
		nums = consecutiveNums(target);

		if(nums.empty())
		{
			cout<<target<<" cannot be expressed as sum of consecs"<<endl;
			continue;
		}
		for(int i:nums)
			cout<<i<<" ";
		cout<<endl;
	}
}
