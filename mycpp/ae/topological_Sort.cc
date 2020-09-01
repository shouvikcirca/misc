#include <vector>
using namespace std;

vector<int> traverse(vector<int> jobs, unordered_map<int,int> &visited, vector<int> topsort, unordered_map<int, vector<int>> dmap, unordered_map<int,int> &traversed)
{
	for(int i=0;i<jobs.size();i++)
	{
		if(traversed[jobs[i]] == 1)
			return {};
		if(dmap.count(jobs[i]))
		{
			if(visited[jobs[i]] == 0)
			{
				traversed[jobs[i]] = 1;
				topsort = traverse(dmap[jobs[i]], visited, topsort, dmap, traversed);
				if(topsort.empty())
					break;
				visited[jobs[i]] = 1;
				topsort.push_back(jobs[i]);

				traversed[jobs[i]] = 0;
			}
		}
		else
		{	
			if(visited[jobs[i]] == 0)
			{
				visited[jobs[i]] = 1;
				topsort.push_back(jobs[i]);
			}
		}		
	}
	return topsort;
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps)
{

	if(deps.empty())
		return jobs;

	unordered_map<int,vector<int>> dmap;
	int el;	
	for(int i=0;i<deps.size();i++)
	{
		el = deps[i][1];
		if(dmap.count(el))
			dmap[el].push_back(deps[i][0]);
		else
			dmap[el] = {deps[i][0]};				
	}

	unordered_map<int,int> visited;
	unordered_map<int,int> traversed;


	for(int i=0;i<jobs.size();i++)
	{
		visited[jobs[i]] = 0;
		traversed[jobs[i]] = 0;
	}

	vector<int> topsort;
	topsort = traverse(jobs, visited, topsort, dmap, traversed);
	return topsort;
}

int main()
{
	vector<int> topsort;
	topsort = topologicalSort({1,2,3,4,5,6,7,8});

	for(int i:topsort)
		cout<<i<<" ";
	cout<<endl;
}



