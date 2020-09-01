using namespace std;

class ContinuousMedianHandler 
{
	public:
		double median;
		priority_queue<int, vector<int>, greater<int>> left;
		priority_queue<int, vector<int>, less<int>> right;


		void insert(int number)
		{
			if(this->left.size() == this->right.size())
			{
				this->left.push(number);
				this->right.push(this->left.top());
				this->left.pop();
				median = right.top();
			}
			else
			{
				this->left.push(this->right.top());
				this->right.pop();
				this->left.push(number);
				this->right.push(this->left.top());
				this->left.pop();
				median = ((float)this->left.top()+(float)this->right.top())/2.0;
			}

		}

		double getMedian() 
		{
			return median;
		}
};
