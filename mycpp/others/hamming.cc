#include<bits/stdc++.h>
using namespace std;

class Hamming
{
	public:
		unordered_map<int, int> umap;
		void binarize(int a)
		{
			int count = 0;
			int it = 1;


			int temp = a;

			while(it<=9)
			{
				if(temp%2==1)
					count+=1;
				temp>>=1;
				it+=1;
			}
			this->umap[a] = count;
		}

		Hamming()
		{
			for(int i=0;i<256;i++)
				this->binarize(i);
		}

		int dist(char a, char b)
		{

			char c = a^b;
			cout<<(int)a<<" "<<(int)b<<endl;
			return this->umap[(int)c];
		}

};

int main()
{
	Hamming ham;
	cout<<ham.dist(0XFF,0X00)<<endl;
}
