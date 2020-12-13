#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int curr = nums[0];
        int currposition = 1;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != curr)
            {
                curr = nums[i];
                nums[currposition++] = curr;
            }
        }
        return currposition;
    }
};

int main()
{
	Solution obj;
	vector<int> nums = {0,0,1,1,1,4};
	int c;
	c = obj.removeDuplicates(nums);
	cout<<c<<endl;

	for(int i=0;i<c;i++)
		cout<<nums[i]<<" ";
	cout<<endl;
}
