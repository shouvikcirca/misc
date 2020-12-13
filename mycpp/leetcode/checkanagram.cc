//checkanagram.cc
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool isAnagram(string s, string t)
		{
			unordered_map<char, int> smap;
			unordered_map<char, int> tmap;

			char c,d;
			for(int i=0;i<s.length();i++)
			{
				c = s.at(i);
				d = t.at(i);

				if (smap.count(c))
					smap[c] = smap[c]+1;
				else
					smap[c] = 1;

				if (tmap.count(d))
					tmap[d] = tmap[d]+1;
				else
					tmap[d] = 1;

			}


			if(smap == tmap)
				return true;

			return false;


		}
};

int main()
{
	Solution obj;
	cout<<obj.isAnagram("anagram","nagaram")<<endl;
}
