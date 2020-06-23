#include<bits/stdc++.h>
using namespace std;



double SquareRoot(double x)
{
    if(x == 1.0 || x == 0.0)
        return x;
    double start, end, mid;
    start = (x > 0.0 && x< 1.0)?x:1.0;
    end = (x > 0.0 && x< 1.0)?1.0:x;

    while(start!=end)
    {
        mid = 0.5*(start+end);
        if(abs(x-(mid*mid)) <= 0.02)
            return mid;
        else if(mid*mid > x )
            end = mid;
        else
            start = mid;
    }
}


int main(int argc, char* argv[])
{
	double input;
	cin>>input;
	cout<<SquareRoot(input)<<endl;
}
