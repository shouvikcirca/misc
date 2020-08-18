#include <vector>
using namespace std;

class LinkedList {
	public:
		int value;
		LinkedList *next;

		LinkedList(int value) {
			this->value = value;
			next = NULL;
		}
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo)
{
	LinkedList *mergedHead = NULL;;
	LinkedList *ptr;
	while(headOne && headTwo)
	{
		if(headOne->value > headTwo->value)
		{
			if(!mergedHead)
			{
				mergedHead = headTwo;
				headTwo = headTwo->next;
				ptr = mergedHead;
			}
			else
			{
				ptr->next = headTwo;
				headTwo = headTwo->next;
				ptr = ptr->next;
			}
		}
		else if(headOne->value < headTwo->value)
		{
			if(!mergedHead)
			{
				mergedHead = headOne;
				headOne = headOne->next;
				ptr = mergedHead;
			}
			else
			{
				ptr->next = headOne;
				headOne = headOne->next;
				ptr=ptr->next;
			}
		}
		else
		{
			if(!mergedHead)
			{
				mergedHead = headOne;
				headOne = headOne->next;
				mergedHead->next = headTwo;
				headTwo = headTwo->next;
				ptr = mergedHead->next;
			}
			else
			{
				ptr->next = headOne;
				headOne = headOne->next;
				ptr = ptr->next;
				ptr->next = headTwo;
				headTwo = headTwo->next;
				ptr=ptr->next;
			}
		}
	}

	while(headOne)
	{
		ptr->next = headOne;
		headOne = headOne->next;
		ptr=ptr->next;
	}

	while(headTwo)
	{
		ptr->next = headTwo;
		headTwo = headTwo->next;
		ptr=ptr->next;
	}

	ptr->next = NULL;
	return mergedHead;
}



