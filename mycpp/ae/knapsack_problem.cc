#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity)
{
	vector<vector<int>> ksmatrix(items.size()+1, vector<int> ((capacity+1),0));

	for(int i=1;i<ksmatrix.size();i++)
		for(int j=1;j<ksmatrix[0].size();j++)
			if(items[i-1][1] <= j)
				ksmatrix[i][j] = max(items[i-1][0]+ksmatrix[i-1][j - items[i-1][1]], ksmatrix[i-1][j]);
			else
				ksmatrix[i][j] = ksmatrix[i-1][j];

	int i = ksmatrix.size()-1, j = ksmatrix[0].size()-1;

	vector<int> inserted;
	while(i>0 && j>0)
	{
		if(items[i-1][1] <= j)
		{
			if(items[i-1][0]+ksmatrix[i-1][j - items[i-1][1]] > ksmatrix[i-1][j])
			{	
				inserted.push_back(i-1);
				j = j - items[i-1][1];
				i-=1;
			}
			else
				i-=1;
		}
		else
			i-=1;
	}

	i = 0, j = inserted.size()-1;
	int temp;

	while(i<j)
	{
		temp = inserted[i];
		inserted[i] = inserted[j],
		inserted[j] = temp;
		i+=1;
		j-=1;
	}

	return {{ksmatrix[ksmatrix.size()-1][ksmatrix[0].size()-1]},inserted};
}

int main()
{
	vector<vector<int>> res;
	res = knapsackProblem({{1,2},{4,3},{5,6},{6,7}},10);

	for(auto i:res)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
}

