#include<bits/stdc++.h>
using namespace std;

class Queue {
 public:
  void Enqueue(int x)
  {
	  enqueue_.emplace(x);
  }

  int Dequeue()
  {
	int result;
	if(dequeue_.empty())
		while(!enqueue_.empty())
		{
			dequeue_.emplace(enqueue_.top());
			enqueue_.pop();
		}
	result = dequeue_.top();
    	dequeue_.pop();
    	return result;
  }

  stack<int> enqueue_, dequeue_;
};


void display(Queue q)
{
	while(!q.dequeue_.empty())
	{
		cout<<q.dequeue_.top()<<" ";
		q.dequeue_.pop();
	}
	while(!q.enqueue_.empty())
	{
		q.dequeue_.emplace(q.enqueue_.top());
		q.enqueue_.pop();
	}

	while(!q.dequeue_.empty())
	{
		cout<<q.dequeue_.top()<<" ";
		q.dequeue_.pop();
	}
	cout<<endl;
	

}

			
int main()
{
	Queue q;
	display(q);
	q.Enqueue(12);
	display(q);
	q.Enqueue(21);
	display(q);
	q.Enqueue(31);
	display(q);
	q.Enqueue(41);
	display(q);
	q.Enqueue(51);
	display(q);
	q.Enqueue(61);
	display(q);

	q.Dequeue();
	display(q);
	q.Dequeue();
	display(q);
	q.Dequeue();
	display(q);
	q.Dequeue();
	display(q);
	q.Dequeue();
	display(q);
	q.Dequeue();
	display(q);


	q.Enqueue(31);
	display(q);

	return 0;
}
