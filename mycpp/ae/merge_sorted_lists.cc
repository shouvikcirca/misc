#include<bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<vector<int>> arrays)
{
	//lambda
	auto compare = [](vector<int> lhs, vector<int> rhs)
	{

		return lhs[2]>rhs[2]; // for ascending order
//		return lhs[2]<rhs[2]; // for descending order
	};

	priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> heap(compare);
	vector<int> sortedlist;
	vector<int> indices (arrays.size(), 0);

	for(int i=0;i<arrays.size();i++)
		heap.push({i,0,arrays[i][0]});

	int arrind, elind, el;
	vector<int> extracted_element;

	while(!heap.empty())
	{
		extracted_element = heap.top();
		heap.pop();
		arrind = extracted_element[0];
		elind = extracted_element[1];
		el = extracted_element[2];
		sortedlist.push_back(el);
		if(elind == (arrays[arrind].size()-1))
			continue;
		elind+=1;
		indices[arrind] = indices[arrind] + 1;
		heap.push({arrind, elind, arrays[arrind][elind]});

	}
	return sortedlist;
}

int main()
{
	vector<vector<int>> arrays {{1,5,9,21},{-1,0},{-124, 81,121},{3,6,12,20,150}}; // for ascending order
//	vector<vector<int>> arrays {{21,9,5,1}, {0,-1},{121,81,-124},{150,20,12,6,3}}; // for descending order
	
	vector<int> sortedarray;
	sortedarray = mergeSortedArrays(arrays);

	for(int i:sortedarray)
		cout<<i<<" ";
	cout<<endl;
}


