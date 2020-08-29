#include <vector>
using namespace std;

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo)
{
	if(arrayOne.empty() && arrayTwo.empty())
		return true;

	if(arrayOne[0]!=arrayTwo[0])
		return false;

	if(arrayOne.size()!=arrayTwo.size())
		return false;

	vector<int> leftone, rightone, lefttwo, righttwo;

	for(int i=1;i<arrayOne.size();i++)
	{
		if(arrayOne[i]<arrayOne[0])
			leftone.push_back(arrayOne[i]);
		if(arrayOne[i]>=arrayOne[0])
			rightone.push_back(arrayOne[i]);
		if(arrayTwo[i]<arrayTwo[0])
			lefttwo.push_back(arrayTwo[i]);
		if(arrayTwo[i]>=arrayTwo[0])
			righttwo.push_back(arrayTwo[i]);
	}

	return sameBsts(leftone, lefttwo) && sameBsts(rightone, righttwo);	
}
