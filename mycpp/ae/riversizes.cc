#include <vector>
using namespace std;

int dfs(int i, int j, vector<vector<int>> matrix, vector<vector<int>> &visited, int totallength)
{
	visited[i][j] = 1;
	totallength=1;

	if(j-1>=0 && matrix[i][j-1] == 1 && visited[i][j-1] == 0)
		totallength+=dfs(i,j-1,matrix,visited,totallength);

	if(i-1>=0 && matrix[i-1][j] == 1 && visited[i-1][j] == 0)
		totallength+=dfs(i-1,j,matrix,visited,totallength);

	if(j+1<matrix[0].size() && matrix[i][j+1] == 1 && visited[i][j+1] == 0)
		totallength+=dfs(i,j+1,matrix,visited,totallength);

	if(i+1<matrix.size() && matrix[i+1][j] == 1 && visited[i+1][j] == 0)
		totallength+=dfs(i+1,j,matrix,visited,totallength);

	return totallength;
}

vector<int> riverSizes(vector<vector<int>> matrix)
{

	vector<vector<int>> visited (matrix.size(), vector<int> (matrix[0].size(),0));
	vector<int> riversizes;

	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			if(matrix[i][j] == 0 || visited[i][j] == 1)
				continue;
			riversizes.push_back(dfs(i,j,matrix,visited,0));
		}
	}
	return riversizes;
}
