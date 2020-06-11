#include <bits/stdc++.h>
using namespace std;


long long Reverse(int x)
{
		long long returnNumber = 0;
		int sign = 0;

		if(x>=0)
			sign = 1;
		else
			sign = -1;

		x = abs(x);
		while(x>0)
		{
			returnNumber = returnNumber*10+(x%10);
			x/=10;
		}

		return returnNumber*sign;

  
}

int main(int argc, char* argv[])
{

	cout<<Reverse(76543);
	return 0;
}
