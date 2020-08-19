#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target)
{
	int j = matrix[0].size()-1;
	for(int i=0;i<matrix.size();i++)
	{
		for(;j>=0;j--)
		{
			if(matrix[i][j] == target)
				return {i,j};
			if(matrix[i][j]>target)
				continue;
			if(matrix[i][j]<target)
				break;
		}
	}
	return {-1,-1};
}
