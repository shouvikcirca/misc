#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap 
{
	public:
		vector<int> heap;

		MinHeap(vector<int> vector)
		{
			heap = buildHeap(&vector);
		}

		vector<int> buildHeap(vector<int> *vector) 
		{
			int size = vector->size();
			for(int i=(size-1);i>=0;i--)
			{
				siftDown(i,size-1,vector);
			}

			return *vector;
		}

		void siftDown(int currentIdx, int endIdx, vector<int> *h) 
		{
			if(currentIdx >= endIdx)
				return;

			int temp;
			int smallest = currentIdx;
			if( (((2*currentIdx)+1) <= endIdx)    &&   ((*h)[smallest] > (*h)[2*currentIdx + 1]))
			{
				smallest = 2 * currentIdx + 1;

			}
			if( (((2*currentIdx)+2) <= endIdx) && ((*h)[smallest] > (*h)[2*currentIdx + 2]))
			{
				smallest = 2 * currentIdx + 2;

			}    
			temp = (*h)[currentIdx];
			(*h)[currentIdx] = (*h)[smallest];
			(*h)[smallest] = temp;

			if(smallest != currentIdx)
				siftDown(smallest, endIdx, h);
		}

		void siftUp(int currentIdx, vector<int> *heap) 
		{

			int parent = (currentIdx-1)/2;
			int temp;

			while(  (currentIdx>0)   && ((*heap)[currentIdx] < (*heap)[parent] ) )
			{
				temp = (*heap)[currentIdx];
				(*heap)[currentIdx] = (*heap)[parent];
				(*heap)[parent] = temp;
				currentIdx = parent;
				parent = (currentIdx-1)/2;
			}
		}

		int peek()
		{
			return this->heap[0];
		}

		int remove()
		{
			int temp;
			temp = this->heap[0];
			this->heap[0] = this->heap[this->heap.size()-1];
			this->heap[this->heap.size()-1] = temp;
			this->heap.pop_back();
			siftDown(0,this->heap.size()-2,&(this->heap));
			return temp;
		}

		void insert(int value)
		{
			this->heap.push_back(value);
			siftUp(this->heap.size()-1, &(this->heap));
		}
};

