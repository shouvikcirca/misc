#include<bits/stdc++.h>
using namespace std;


int RemoveDuplicates(int *a, int arrlen)
{
	int current = 0;
	int next = current+1;

	while(next<arrlen)
	{
		if(a[current] == a[next])
			next+=1;
		else
		{
			a[current+1] = a[next];
			current+=1;
		}
	}	

	
	return current;
}

int main(int argc, char* argv[])
{

	int arr[9] = {2,3,5,5,7,11,11,11,13};
	int arro[10] = {1,2,3,4,5,6,7,8,9,10};
	int reto = RemoveDuplicates(arro,sizeof(arro)/sizeof(arro[0]));
	int ret = RemoveDuplicates(arr,sizeof(arr)/sizeof(arr[0]));
	
	for(int i=0;i<=ret;i++)
		cout<<arr[i]<<" ";

	cout<<endl;
	for(int i=0;i<=reto;i++)
		cout<<arro[i]<<" ";


	cout<<endl;

}


