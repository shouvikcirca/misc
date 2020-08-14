using namespace std;

bool isMonotonic(vector<int> array)
{
	int m = 0;
	for(int i=1;i<array.size();i++)
	{
		if(array[i]>array[i-1] && m==-1)
			return false;
		else if(array[i]<array[i-1] && m==1)
			return false;
		else if(array[i]>array[i-1] && m==0)
			m=1;
		else if(array[i]<array[i-1] && m==0)
			m=-1;
	}
	return true;
}

