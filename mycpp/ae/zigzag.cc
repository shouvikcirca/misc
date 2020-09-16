#include<bits/stdc++.h>
using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> array)
{

	int rowlimit = array.size()-1;
	int collimit = array[0].size()-1;
	int x=0,y=0;
	vector<int> zzarray;
	zzarray.push_back(array[x][y]);
	while(true)
	{
		if(y == 0 || y == collimit)
		{
			if(x+1 <= rowlimit)
			{
				x+=1;
				zzarray.push_back(array[x][y]);
			}
			else if(y+1<=collimit)
			{
				y+=1;
				zzarray.push_back(array[x][y]);

			}
			else if(rowlimit!=0 and collimit!=0)
				continue;

			if(x == rowlimit && y == collimit)
			{
				return zzarray;
			}

			if(y<collimit)
			{
				while(x>0 && y<collimit)
				{
					x-=1;
					y+=1;
					zzarray.push_back(array[x][y]);
				}
			}
			else if(y == collimit)
			{
				while(y>0 && x<rowlimit)
				{
					x+=1;
					y-=1;
					zzarray.push_back(array[x][y]);
				}
			}

		}
		if(x == 0 || x == rowlimit)
		{
			if(y+1 <= collimit)
			{
				y+=1;
				zzarray.push_back(array[x][y]);
			}
			else if(x+1 <=rowlimit)
			{
				x+=1;
				zzarray.push_back(array[x][y]);
			}
			else if(rowlimit!=0 and collimit!=0)
				continue;

			if(x == rowlimit && y == collimit)
			{
				return zzarray;
			}

			if(x<rowlimit)
			{
				while(y>0 && x<rowlimit)
				{
					x+=1;
					y-=1;
					zzarray.push_back(array[x][y]);
				}
			}
			else if(x == rowlimit)
			{
				while(y<collimit && x>0)
				{
					x-=1;
					y+=1;
					zzarray.push_back(array[x][y]);
				}
			}

		}
	}

	return zzarray;
}


int main()
{
	vector<int> mat ;
	mat = zigzagTraverse({{1,3,4,10,11},{2,5,9,12,19},{6,8,13,18,20},{7,14,17,21,24},{15,16,22,23,25}});
	//mat = zigzagTraverse({{1,2},{2,5},{6,8},{7,13}});
	//mat = zigzagTraverse({{1,2,3,4,5}});
	//mat = zigzagTraverse({{1}});
	//mat = zigzagTraverse({{1},{2},{3},{4},{5}});
	for(auto i:mat)
		cout<<i<<" ";
	cout<<endl;
}



