#include<vector>

bool checkcompatibility(vector<vector<int>> disks, int i, int j)
{
	return (disks[i][0]>disks[j][0]) && (disks[i][1]>disks[j][1]) && (disks[i][2]>disks[j][2]);
}

void sortDisks(vector<vector<int>> &disks)
{
	vector<int> temp;
	for(int i=0;i<disks.size();i++)
	{
		for(int j=0;j<disks.size()-i-1;j++)
		{
			if(disks[j][2]>disks[j+1][2])
			{
				temp = disks[j];
				disks[j] = disks[j+1];
				disks[j+1] = temp;
			}
		}
	}
}

vector<vector<int>> diskStacking(vector<vector<int>> disks)
{
	if(disks.empty())
		return {};

	sortDisks(disks);	

	vector<vector<int>> heights {{disks[0][2], -1}};
	int maxheight = heights[0][2];
	int maxheightindex = 0;
	int thisheight, th;
	int inv = 0;

	for(int i=1;i<disks.size();i++)
	{
		thisheight = i;
		th = disks[thisheight][2];
		for(int j=i-1;j>=0;j--)
		{
			if(checkcompatibility(disks, i,j) && (disks[i][2]+heights[j][0]>th))
			{
				thisheight = j;
				th = disks[i][2]+heights[j][0];
				inv = 0;
			}

		}
		heights.push_back({th,thisheight!=i?thisheight:-1});
		if(maxheight< th)
		{
			maxheight = th;
			maxheightindex = i;
		}
	}

	int parent = maxheightindex;
	vector<vector<int>> stak;
	while(parent!=-1)
	{
		stak.insert(stak.begin(), disks[parent]);
		parent = heights[parent][1];
	}
	return stak;
}
