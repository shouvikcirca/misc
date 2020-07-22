#include<bits/stdc++.h>
using namespace std;

bool checkValidity(int i, int j, vector<vector<int>> &board)
{
	// Checking for same element in row
	for(int k=0;k<board[0].size();k++)
		if((k!=j) && (board[i][k] == board[i][j]))
			return false;

	// Checking for same element in column
	for(int k=0;k<board.size();k++)
		if((k!=i) && (board[k][j] == board[i][j]))
			return false;
	
	//Inferring subgrid in which element is located
	int hf,he,vf,ve;

	if(j>=0 && j<=2)
	{
		hf = 0;he = 2;
	}
	else if(j>=3 && j<=5)
	{
		hf=3;he=5;
	}
	else
	{
		hf=6;he=8;
	}
	
	if(i>=0 && i<=2)
	{
		vf = 0;ve = 2;
	}
	else if(i>=3 && i<=5)
	{
		vf=3;ve=5;
	}
	else
	{
		vf=6;ve=8;
	}

	// Checking for same element in subgrid
	for(int l=vf;l<=ve;l++)
		for(int k=hf;k<=he;k++)
			if((k!=j || l!=i) && board[l][k]==board[i][j])
				return false;
	return true;
}

string Solve(int i, int j, vector<vector<int>> &board, int z)
{
	if((j==0) && (i==board.size()))
		return "success";

	int element = 1;
	bool valid;
	string status;

	while(element<=9)
	{
		board[i][j] = element;
		valid = checkValidity(i,j,board);
		if(valid)
		{
			if(((j+1)==board[0].size()) && (i<board.size()))
				status = Solve(i+1,0,board,z+1);
			else
				status = Solve(i,j+1,board,z+1);

			if(status == "failure")
				element+=1;
			else
				return "success";
		}
		else
			element+=1;
	}

	if(element>9)
	{	
		board[i][j] = 0;
		return "failure";
	}
	else
		return "success";
}

int main()
{
        vector<vector<int>> sudokuboard(9, vector<int>(9,0));
	string status = Solve(0, 0, sudokuboard,0);
	int colcount, rowcount=0;
        if(status == "success")
	{
		for(auto i:sudokuboard)
        	{
			rowcount+=1;
			colcount = 0;
			if((rowcount-1)%3 == 0)
			{
				for(auto j:i)
					cout<<"--"<<"";
				cout<<endl;
			}
            		for(auto j:i)
			{	
				colcount+=1;
				if((colcount-1)%3 == 0)
                			cout<<"|"<<j<<" ";
				else
					cout<<j<<" ";
			}
            		cout<<endl;
        	}
	}
	else
		cout<<status<<endl;
	cout<<endl;

	// Checking if given combination is valid
	for(int i=0;i<sudokuboard.size();i++)
	{
		for(int j=0;j<sudokuboard[0].size();j++)
		{
			if(!checkValidity(i,j,sudokuboard))
			{
				cout<<"Not Valid"<<endl;
				return 0;
			}
		}
	}
	cout<<"Valid"<<endl;
	return 0;
}	

