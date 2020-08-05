#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &array, int f, int m, int l)
{
	vector<int> right;
	vector<int> left;

	for(int i=f;i<=m;i++)
		left.push_back(array[i]);

	for(int i=m+1;i<=l;i++)
		right.push_back(array[i]);



	int li = 0, ri = 0;
	int arrayindex = f;
	while(li<left.size() && ri<right.size())
	{
		

		if(left[li]<right[ri])
		{
			array[arrayindex] = left[li];
			arrayindex+=1;
			li+=1;
		}
		else if(left[li]>right[ri])
		{
			array[arrayindex] = right[ri];
			arrayindex+=1;
			ri+=1;
		}
		else
		{
			array[arrayindex] = left[li];
			arrayindex+=1;
			array[arrayindex] = right[ri];
			li+=1;
			ri+=1;
			arrayindex+=1;
		}
	}

	while(ri<right.size())
	{
		array[arrayindex] = right[ri];
		ri+=1;
		arrayindex+=1;
	}

	while(li<left.size())
	{
		array[arrayindex] = left[li];
		li+=1;
		arrayindex+=1;
	}
}

void ms(vector<int> &array, int f, int l)
{
	if(f<l)
	{
		int mid = (f+l)/2;
		ms(array, f, mid);
		ms(array, mid+1, l);
		merge(array, f, mid, l);
	}
}

vector<int> mergeSort(vector<int> array) 
{
	ms(array, 0, array.size()-1);
	return array;
}

int main()
{
	vector<int> array;
	array = mergeSort({8,5,2,9,5,6,3});
	for(int i:array)
		cout<<i<<" ";
	cout<<endl;
}

