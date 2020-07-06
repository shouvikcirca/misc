#include<bits/stdc++.h>
using namespace std;

int main()
{


////////    SETS  ////////////////
/*
	unordered_set<int> us;
	set<int> s;

	for(int i=0;i<10;i++)
		us.insert(i);
	for(int i=0;i<10;i++)
		s.insert(i);


	for(auto i:us)
		cout<<i<<" ";
	cout<<endl;


	unordered_set<int>::iterator it = us.begin();

	while(it!=us.end())
	{
		if((*it)%2 ==1)
			it = us.erase(it);
		else
			it++;
	}
	cout<<endl;

	
	for(auto i:us)
		cout<<i<<" ";
	cout<<endl;

*/

/*
	int i=0;
	while(!us.empty() && i<us.size())
	{
		if(i%2 == 0)
			us.erase(i);
		i+=1;
	}


*/
/*
	for(auto i:us)
		cout<<i<<" ";
	cout<<endl;

	for(auto i:s)
		cout<<i<<" ";
	cout<<endl;
*/


/////////////////////////////////////////////////////////

//////////////////////  STRINGS ////////////////////////
/*
	string s = "optimusprime";
	cout<<s.substr(0,5)<<endl; // The 2nd arg of.substr() is the offset

*/

////////////////////////////////////////////////////////


//////////////////// UNORDERED MAPS ////////////////////////
/*
	unordered_map<int,int> kvs;

	kvs[2] = 20;

	cout<<kvs.at(2)<<endl;
	cout<<kvs.count(2)<<endl;

	kvs.clear();
	cout<<kvs.count(2)<<endl;
*/


	return 0;
}
