#include <vector>
using namespace std;

class Trie
{
	public:
		unordered_map<char,Trie*> um;
};

void findWord(int i, int j, vector<vector<char>> &board,vector<vector<int>> &visited, Trie *ptr, string ns, unordered_map<string,int> &foundwords);

bool limitChecker(int i, int j, int rm, int cm, Trie *ptr, vector<vector<char>> board)
{
	return (i>=0 && i<rm && j>=0 && j<cm && ptr->um.count(board[i][j]))?true:false;
}

vector<string> boggleBoard(vector<vector<char>> board, vector<string> words)
{
	Trie *root = NULL;
	int rowmax = board.size();
	int colmax = board[0].size();
	Trie *ptr;

	for(string str: words)
	{
		ptr = root;
		for(int j=0;j<str.length();j++)
		{
			if(!root)
			{
				root = new Trie();
				ptr = root;
				ptr->um[str[j]] = new Trie();						
			}
			else
			{
				if(!ptr->um.count(str[j]))
					ptr->um[str[j]] = new Trie();							 
			}	
			ptr = ptr->um[str[j]];
		}
		ptr->um['*'] = NULL;
	}

	vector<vector<int>> visited(rowmax, vector<int> (colmax, 0));
	unordered_map<string,int> foundwords;
	ptr = root;
	string ns;

	for(int i=0;i<rowmax;i++)
	{
		for(int j=0;j<colmax;j++)
		{
			ns = "";
			findWord(i,j,board,visited,ptr, ns+=board[i][j], foundwords); 			
		}
	}

	vector<string> returnStrings;
	for(auto item:foundwords)
		returnStrings.push_back(item.first);

	return returnStrings;
}

void findWord(int i, int j, vector<vector<char>> &board,vector<vector<int>> &visited, Trie *ptr, string ns, unordered_map<string,int> &foundwords)
{
	if(!ptr->um.count(board[i][j]))
		return;
		
	visited[i][j] = 1;
	vector<vector<int>> travellingIndices;

	if(limitChecker(i,j-1,board.size(),board[0].size(), ptr->um[board[i][j]], board))
		travellingIndices.push_back({i,j-1});
	if(limitChecker(i-1,j-1,board.size(),board[0].size(), ptr->um[board[i][j]], board))
		travellingIndices.push_back({i-1,j-1});
	if(limitChecker(i-1,j,board.size(),board[0].size(), ptr->um[board[i][j]], board))
		travellingIndices.push_back({i-1,j});
	if(limitChecker(i-1,j+1,board.size(),board[0].size(), ptr->um[board[i][j]], board))
		travellingIndices.push_back({i-1,j+1});
	if(limitChecker(i,j+1,board.size(),board[0].size(), ptr->um[board[i][j]], board))
		travellingIndices.push_back({i,j+1});
	if(limitChecker(i+1,j+1,board.size(),board[0].size(), ptr->um[board[i][j]], board))
		travellingIndices.push_back({i+1,j+1});
	if(limitChecker(i+1,j,board.size(),board[0].size(), ptr->um[board[i][j]], board))
		travellingIndices.push_back({i+1,j});
	if(limitChecker(i+1,j-1,board.size(),board[0].size(), ptr->um[board[i][j]], board))
		travellingIndices.push_back({i+1,j-1});

	if((ptr->um[board[i][j]])->um.count('*'))
			foundwords[ns] = 1;

	int x,y;
	for(int k=0;k<travellingIndices.size();k++)
	{
		x = travellingIndices[k][0], y = travellingIndices[k][1];
		if(visited[x][y] == 0)
		{
			findWord(x, y, board, visited, ptr->um[board[i][j]], ns+=board[x][y], foundwords);
			visited[x][y] = 0;
		}
	}
	return;
}
