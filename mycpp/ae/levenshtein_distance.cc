using namespace std;

int levenshteinDistance(string str1, string str2) 
{
	vector<vector<int>> editmatrix (str1.length()+1, vector<int> (str2.length()+1,0));
	editmatrix[0][0] = 0;

	for(int j=1;j<editmatrix[0].size();j++)
		editmatrix[0][j] = editmatrix[0][j-1] + 1;

	int minvalue;
	for(int i=1;i<editmatrix.size();i++)
	{
		for(int j=0;j<editmatrix[0].size();j++)
		{
			if(str1[i-1] != str2[j-1])
			{
				minvalue = INT_MAX;
				if(i-1>=0 && editmatrix[i-1][j]<minvalue)
					minvalue = editmatrix[i-1][j];
				if(j-1>=0 && editmatrix[i][j-1]<minvalue)
					minvalue = editmatrix[i][j-1];
				if(i-1>=0 && j-1>=0 && editmatrix[i-1][j-1]<minvalue)
					minvalue = editmatrix[i-1][j-1];
				editmatrix[i][j] = minvalue+1;
			}
			else
				editmatrix[i][j] = editmatrix[i-1][j-1];
		}
	}
	return editmatrix.back().back();	
}
