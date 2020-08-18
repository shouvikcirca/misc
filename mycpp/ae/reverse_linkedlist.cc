using namespace std;

class LinkedList {
	public:
		int value;
		LinkedList *next;

		LinkedList(int value) {
			this->value = value;
			this->next = NULL;
		}
};

LinkedList *reverseLinkedList(LinkedList *head)
{
	LinkedList *prev = NULL, *curr = head, *subsequent = curr;
	while(subsequent)
	{
		subsequent = curr->next;
		curr->next = prev;
		prev = curr;
		curr = subsequent;
	}
	head = prev;
	return head;
}
