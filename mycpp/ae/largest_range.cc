#include <bits/stdc++.h>
using namespace std;

vector<int> largestRange(vector<int> array)
{
	unordered_map<int,bool> items;

	for(auto i:array)
		items[i] = true;

	int start= array[0], end = array[0];
	vector<int> retrange {start, end};
	int k;

	for(int i:array)
	{
		if(items[i])
		{
			start = i;
			end = i;
			items[i] = false;
			k=i;
			while(items.count(k-1))
			{
				start = k-1;
				items[k-1] = false;
				k-=1;
			}
			k=i;
			while(items.count(k+1))
			{
				end = k+1;
				items[k+1] = false;
				k+=1;
			}

			if((end - start) > (retrange[1] - retrange[0]))
			{
				retrange[0] = start;
				retrange[1] = end;
			}
		}
	}
	return retrange;
}

int main()
{
	vector<int> range;
	range = largestRange({1,11,3,0,15,5,2,4,10,7,12,6});
	for(int i:range)
		cout<<i<<" ";
	cout<<endl;
}



