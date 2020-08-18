#include<bits/stdc++.h>
using namespace std;

vector<char> spiralize(vector<vector<char>> &mat)
{
	int l=0,u=0;
	int r = mat[0].size()-1;
	int d = mat.size()-1;
	
	int hiterator, viterator;
	vector<char> newspiral;

	while(l<=r && u<=d)
	{
		hiterator = l;
		viterator = u;
		
		while(hiterator<=r)
		{
			newspiral.push_back(mat[viterator][hiterator]);
			hiterator+=1;
		}
		hiterator-=1;
		viterator+=1;

		if(viterator>d)
			break;
		while(viterator<=d)
		{
			newspiral.push_back(mat[viterator][hiterator]);
			viterator+=1;
		}
		viterator-=1;
		hiterator-=1;
		if(hiterator<l)
			break;
		while(hiterator>=l)
		{
			newspiral.push_back(mat[viterator][hiterator]);
			hiterator-=1;
		}
		hiterator+=1;
		viterator-=1;
		if(viterator<u)
			break;
		while(viterator>u)
		{
			newspiral.push_back(mat[viterator][hiterator]);
			viterator-=1;
		}

		l+=1;
		r-=1;
		u+=1;
		d-=1;
	}

	return newspiral;

}


int main()
{
	//vector<vector<int>> matrix {{1,2,3},{4,5,6}};
	//vector<int> newspiral;

	vector<vector<char>> spiral {{'S','P'},{'L','I'},{'A','R'}};
	vector<char> ns = spiralize(spiral);
	

	for(auto i: spiral)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
		

	for(auto i: ns)
		cout<<i<<" ";
	cout<<endl;

	cout<<endl;

	//vector<vector<char>> newspiral {{'S','P','I'},{'Z','E','R'},{'I','L','A'}};
	//vector<char> newns = spiralize(newspiral);
	

	for(auto i: newspiral)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
		

	for(auto i: newns)
		cout<<i<<" ";
	cout<<endl;












}

