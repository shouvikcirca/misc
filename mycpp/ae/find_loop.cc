#include <vector>
using namespace std;

class LinkedList 
{
	public:
		int value;
		LinkedList *next;

		LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head)
{
	if(!head)
		return NULL;

	LinkedList *ptr1=head, *ptr2=ptr1->next;
	int count = 1,t;

	while(true)
	{
		if(ptr1 == ptr2)
			break;
		ptr1=ptr1->next;
		ptr2 = ptr1;
		t = 0;
		count+=1;
		while(t<count)
		{
			ptr2 = ptr2->next;
			t+=1;
		}
	}

	ptr1 = head;
	ptr2 = ptr1;

	while(ptr1)
	{
		for(int i=1;i<=count;i++)
			ptr2 = ptr2->next;
		if(ptr1 == ptr2)	
			return ptr2;
		ptr1 = ptr1->next;
		ptr2 = ptr1;
	}
	return NULL;
}
