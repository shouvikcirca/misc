#include<bits/stdc++.h>
using namespace std;

void FillSurroundedRegions(vector<vector<char>>  board_ptr)
{
	int l=0,u=0;
	int r = board_ptr[0].size() - 1;
	int d = board_ptr.size() - 1;
	int hiterator, viterator;

	while(l<=r && u<=d)
	{
		hiterator = l;
		viterator = u;
		while(hiterator<=r)
		{
			if(hiterator == 0 || (hiterator == board_ptr[0].size()-1) || viterator == 0 || (viterator == board_ptr.size()-1))
				board_ptr[viterator][hiterator] = (board_ptr[viterator][hiterator] == 'W')?'Y':board_ptr[viterator][hiterator];
			else if((board_ptr[viterator][hiterator-1] == 'Y' || board_ptr[viterator][hiterator+1] == 'Y' || 
					board_ptr[viterator-1][hiterator] == 'Y' || board_ptr[viterator+1][hiterator] == 'Y'))
				board_ptr[viterator][hiterator] = (board_ptr[viterator][hiterator] == 'W')?'Y':board_ptr[viterator][hiterator];
			hiterator+=1;
		}
		hiterator-=1;
		viterator+=1;
		if(viterator>d)
			break;
		while(viterator<=d)
		{
			if(hiterator == 0 || (hiterator == board_ptr[0].size()-1) || viterator == 0 || (viterator == board_ptr.size()-1))
				board_ptr[viterator][hiterator] = (board_ptr[viterator][hiterator] == 'W')?'Y':board_ptr[viterator][hiterator];
			else if((board_ptr[viterator][hiterator-1] == 'Y' || board_ptr[viterator][hiterator+1] == 'Y' || 
					board_ptr[viterator-1][hiterator] == 'Y' || board_ptr[viterator+1][hiterator] == 'Y'))
				board_ptr[viterator][hiterator] = (board_ptr[viterator][hiterator] == 'W')?'Y':board_ptr[viterator][hiterator];
			viterator+=1;
		}
		viterator-=1;
		hiterator-=1;
		if(hiterator<l)
			break;
		while(hiterator>=l)
		{
			
			if(hiterator == 0 || (hiterator == board_ptr[0].size()-1) || viterator == 0 || (viterator == board_ptr.size()-1))
				board_ptr[viterator][hiterator] = (board_ptr[viterator][hiterator] == 'W')?'Y':board_ptr[viterator][hiterator];
			else if((board_ptr[viterator][hiterator-1] == 'Y' || board_ptr[viterator][hiterator+1] == 'Y' || 
					board_ptr[viterator-1][hiterator] == 'Y' || board_ptr[viterator+1][hiterator] == 'Y'))
				board_ptr[viterator][hiterator] = (board_ptr[viterator][hiterator] == 'W')?'Y':board_ptr[viterator][hiterator];
			hiterator-=1;
		}
		hiterator+=1;
		viterator-=1;
		if(viterator<u)
			break;
		while(viterator>u)
		{
			
			if(hiterator == 0 || (hiterator == board_ptr[0].size()-1) || viterator == 0 || (viterator == board_ptr.size()-1))
				board_ptr[viterator][hiterator] = (board_ptr[viterator][hiterator] == 'W')?'Y':board_ptr[viterator][hiterator];
			else if((board_ptr[viterator][hiterator-1] == 'Y' || board_ptr[viterator][hiterator+1] == 'Y' || 
					board_ptr[viterator-1][hiterator] == 'Y' || board_ptr[viterator+1][hiterator] == 'Y'))
				board_ptr[viterator][hiterator] = (board_ptr[viterator][hiterator] == 'W')?'Y':board_ptr[viterator][hiterator];
			viterator-=1;
		}

		l+=1;
		r-=1;
		u+=1;
		d-=1;
	}


	for(int i=0;i<board_ptr.size();i++)
		for(int j=0;j<board_ptr[0].size();j++)
			if(board_ptr[i][j] == 'Y')
				board_ptr[i][j] = 'W';
			else
				board_ptr[i][j] = 'B';



	for(auto i:board_ptr)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
	return;
}





int main(int argc, char* argv[])
{

	vector<vector<char>> grid {{'B','B','B','B'},{'W','B','W','B'},{'B','W','W','B'},{'B','B','B','B'}};
	FillSurroundedRegions(grid);

}

