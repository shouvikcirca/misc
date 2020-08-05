#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	for(int i:array)
		cout<<i<<" ";
	cout<<endl;
}

int partition(vector<int> &array, int p, int q)
{
	int pivot = q;
	int i = p-1;

	for(int j=p;j<pivot;j++)
	{
		if(array[j]<array[pivot])
		{
			i+=1;
			swap(array, i, j);
		}
	}
	swap(array, i+1, pivot);
	return i+1;
}

void qs(vector<int> &array, int f, int l)
{
	if(f<l)
	{
		int p = partition(array, f, l);
		qs(array, f, p-1);
		qs(array, p+1, l);
	}
}

vector<int> quickSort(vector<int> array)
{
	qs(array, 0, array.size()-1);
	return array;
}

int main()
{
	vector<int> array;
	array = quickSort({8,5,2,9,5,6,3});
	for(int i:array)
		cout<<i<<" ";
	cout<<endl;
}
	




