#include<bits/stdc++.h>
using namespace std;

// Given n, return all primes up to and including n.
bool isPrime(int n)
{
	int i = 2;
	while(1)
	{
		if(i>sqrt(n))
			break;
		if(n%i == 0)
			return 0;
		i+=1;
	}
	return 1;
}


vector<int> GeneratePrimes(int n) 
{
	if(n<2)
		return {};
	vector<int> primes;
	vector<int> numbers;

	for(int i=0;i<=n;i++)
		numbers.push_back(i);

	for(int i=2;i<numbers.size();i++)
		if(numbers[i]!=-1 && isPrime(numbers[i]))
		{
			primes.push_back(numbers[i]);

			for(int j=2;(j*numbers[i])<=n;j++)
				numbers[j*numbers[i]] = -1;
		}

	return primes;
}



int main(int argc, char* argv[])
{
	int n = 10;
	vector<int> primes = GeneratePrimes(n);


	for(auto i:primes)
		cout<<i<<" ";
	cout<<endl;
}





