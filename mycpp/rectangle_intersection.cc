#include <bits/stdc++.h>
using namespace std;

struct Rect {
  int x, y, width, height;
};

Rect IntersectRectangle(const Rect& r1, const Rect& r2)
{
		  
	if(r1.x<=r2.x + r2.width && r2.x<=r1.x + r1.width && r1.y<=r2.y+r2.height && r2.y<=r1.y+r1.height)		
		return {max(r1.x, r2.x),max(r1.y, r2.y),min(r1.x+r1.width,r2.x+r2.width)-max(r1.x,r2.x),min(r1.y+r1.height,r2.y+r2.height)-max(r1.y,r2.y)};
	else
		return {0,0,-1,-1};	
		
}



int main(int argc, char* argv[]) 
{
	
	Rect r1{3,5,6,3};
	Rect r2{-3,5,3,3};


	Rect r = IntersectRectangle(r1,r2);


	cout<<r.x<<" "<<r.y<<" "<<r.width<<" "<<r.height<<endl;
	return 0;
}
