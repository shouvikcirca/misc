#include<bits/stdc++.h>
//#include<limits.h> for INT_MIN and INT_MAX 

using namespace std;

//masterandcaptain

//void egfunction(vector<vector<char>>&);
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
/*
	unordered_map<string,int> kvs;
	kvs["a"] = 1;
	kvs["b"] = 2;
	kvs["c"] = 3;

	for(auto i:kvs)
	{
		cout<<i.first<<":"<<i.second;
		cout<<endl;
	}

*/
/*
	vector<int> a;
	cout<<a.empty()<<endl;
	cout<<a.size()<<endl;

*/
/*
	unordered_map<int,int> um;
	um[1] = 2;
	um[1] = 2;

	for(auto i:um)
	{
		cout<<i.first<<":"<<i.second;
		cout<<endl;
	}
*/
/////////////////////////////////////////////////////////////

///////////////////  VECTORS ///////////////////////////////

 	
	vector<int> vec {9,4,1,0,7};
	sort(vec.begin(),vec.end());

	for(int i:vec)
		cout<<i<<" ";
	cout<<endl;
/*

	vector<int> vec {1,2,4};
	vec.insert(vec.begin()+2,3);

	for(int i:vec)
		cout<<i<<" ";
	cout<<endl;

	cout<<vec.back()<<endl;

*/
/*
	vector<int> a {1};
	a.push_back({});

	for(auto i:a)
		cout<<i<<" ";
	cout<<endl;
*/
/*
	int r = 5, c=3;
	vector<vector<int>> vec (r, vector<int> (c,7));

	for(auto i:vec)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}

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



/*
	// lambda
	auto compare = [](vector<int> lhs, vector<int> rhs)
			{
				return lhs[2]<rhs[2];
			};

	priority_queue <vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

	pq.push({1,1,3});
	pq.push({3,2,2});
	pq.push({2,3,1});

	vector<int> v;
	while(!pq.empty())
	{
		v = pq.top();
		for(auto i:v)
			cout<<i<<" ";
		cout<<endl;
		pq.pop();
	}
	cout<<endl;
*/

/*
	vector<int> array;
	vector<int> *p = &array;
	p->push_back(21);

	cout<<array.back()<<endl;
*/
////////////////////////////////////////////////////////////

/////////////////// FUNCTIONS /////////////////////////////


/*
	vector<vector<char>> board(5, vector<char> (3,' '));
	egfunction(board);


	for(auto i: board)
	{
		for(auto j:i)
			cout<<j<<"\t";
		cout<<endl;
	}
	return 0;
*/

////////////////////////////////////////////////////////////


///////////////// LIMITS //////////////////////////////////


/*
	int a = INT_MIN;
	int b = INT_MAX;
	float d = (float)INT_MIN;
	cout<<d<<endl;
	int c = 21;
	cout<<(a<c)<<endl;
	cout<<(b<c)<<endl;
*/

///////////////////////////////////////////////////////////

}

/*
void egfunction(vector<vector<char>> &board)
{
	for(int i=0;i<board.size();i++)
		for(int j=0;j<board[0].size();j++)
			if((i+j)%2 == 0)
				board[i][j] = '.';
			

}
*/




