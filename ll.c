#include "utils.h"
#include "ll.h"

list * ll_new()
{
	list * l = NEW(list);
	l->head = NULL;
	return l;
}

void ll_cons(list * l, void * value)
{
	node * n = NEW(node);
	n->value = value;
	n->next = l->head;
	l->head = n;
}

void ll_remove(list * l, void * value)
{
	node * previous = NULL;
	node * n = l->head;

	while(n != NULL)
	{
		if(n->value == value)
		{
			if(previous == NULL)
			{//removing head
				l->head = n->next;
				FREE(node, n);
				n = l->head;
			}
			else
			{//removing inside the list
				previous->next = n->next;
				FREE(node, n);
				n = previous->next;
			}
		}
		else
		{
			previous = n;
			n = n->next;
		}
	}
}

int ll_count(list * l)
{
	int c = 0;
	FOREACH_X(l, void)
	{
		c++;
	}

	return c;
}

void ll_free(list * l)
{
	node * previous = NULL;
	node * n = l->head;

	while(n != NULL)
	{
		previous = n;
		n = n->next;
		FREE(node, previous);
	}

	FREE(list, l);    
}