#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    // Base case: If the list (or the current pointer) is empty, stop.
    if (begin_list == NULL || *begin_list == NULL)
        return;

    t_list *cur = *begin_list;

    // Check if the current node matches the reference data
    if (((int (*)(void *, void *))cmp)(cur->data, data_ref) == 0)
    {
        // Update the pointer in the previous node (or the head) 
        // to skip the current node.
        *begin_list = cur->next;
        
        // Free the node and recurse on the same position (now the new next node)
        free(cur);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
    {
        // Data doesn't match, just move to the next node.
        ft_list_remove_if(&cur->next, data_ref, cmp);
    }
}