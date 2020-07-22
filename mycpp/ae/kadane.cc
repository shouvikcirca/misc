#include <bits/stdc++.h>
using namespace std;

int kadanesAlgorithm(vector<int> array) 
{
	int maxendinghere=array[0], maxsofar=array[0];

	for(int i=1;i<array.size();i++)
	{
		maxsofar = max(array[i], maxsofar+array[i]);
		maxendinghere = max(maxsofar, maxendinghere);
	}
	return maxendinghere;
}

int main()
{
	vector<int> vec {3,5,-9,1,3,-2,3,4,7,2,-9,6,3,1,-5,4};
	cout<<kadanesAlgorithm(vec)<<endl;
}
