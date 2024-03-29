#include <stdlib.h>
#include <stdio.h>

//  Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head)
{
	int i = 0;
	struct ListNode *tmp = head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	i = (i / 2) + 1;
	tmp = head;
	for (int j = 1; j < i; j++)
		tmp = tmp->next;
	return tmp;
}