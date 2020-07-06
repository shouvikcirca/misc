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


/*
	string s="";
	cout<<(s[s.length()-1] == 't')<<endl;

*/


/*
	string s="beta";
	//cout<<"alpha"+" "+s<<endl; This cannot be done
	cout<<"alpha"+s<<endl; // This can be done

	//cout<<s.append("is not","alpha")<<endl; cannot be done
	cout<<s.append("morone")<<endl; // can be done
*/


/*
	string s = "testthis is a testtest to see if testestest it works";
	string sub = "test";
	int pos=0;
	while(pos<=s.length()-1)
	{
		pos = s.find(sub,pos);
		if(pos == string::npos)
			break;
		cout<<pos<<" ";
		pos+=1;
	}
	cout<<endl;
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


/////////////////////////////////////////////////////////////

///////////////////  VECTORS ///////////////////////////////

/*
	vector<int> vec {1,2,4};
	vec.insert(vec.begin()+2,3);

	for(int i:vec)
		cout<<i<<" ";
	cout<<endl;

	cout<<vec.back()<<endl;

*/

//////////////////////////////////////////////////////////

////////////////// PRIORITY QUEUES ////////////////////////

/*
	priority_queue <int, vector<int>, less<int>> maxheap;
	priority_queue <int, vector<int>, greater<int>> minheap;
	maxheap.push(10);
	maxheap.push(5);
	maxheap.push(20);
	maxheap.push(2);

	minheap.push(10);
	minheap.push(5);
	minheap.push(20);
	minheap.push(2);

	cout<<"Minheap"<<" ";
	while(!minheap.empty())
	{
		cout<<minheap.top()<<" ";
		minheap.pop();
	}

	cout<<endl;

	cout<<"Maxheap"<<" ";
	while(!maxheap.empty())
	{
		cout<<maxheap.top()<<" ";
		maxheap.pop();
	}

	cout<<endl;
*/

////////////////////////////////////////////////////////////

	return 0;
}
