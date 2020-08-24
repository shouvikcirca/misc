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

LinkedList *shiftLinkedList(LinkedList *head, int k)
{
	int i = 0, listlength = 0;
	LinkedList *bptr = head;
	LinkedList *fptr = head;

	while(bptr)
	{
		bptr=bptr->next;
		listlength+=1;
	}

	if(listlength == 0 || listlength == 1)
		return head;

	if(k<0)
		k = listlength - (abs(k)%listlength);
	
	k = k%listlength;
	bptr = head;
	
	while(i<k)
	{
		bptr = bptr->next;
		i+=1;
	}
	while(bptr->next)
	{
		bptr = bptr->next;
		fptr = fptr->next;
	}

	bptr->next = head;
	head = fptr->next;
	fptr->next = NULL;
	return head;
}
