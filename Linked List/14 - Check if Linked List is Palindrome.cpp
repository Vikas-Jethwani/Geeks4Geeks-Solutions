// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn

bool isPalindrome(Node *head)
{
    if(head->next == NULL) // If only 1 node
        return 1;

    Node *fast, *slow, *mid, *p, *q, *r;
    // Find mid
    slow = NULL;
    fast = head;
    while(fast != NULL)
    {
        if(slow == NULL)
            slow = head;
        else
            slow = slow->next;
        if(fast != NULL)
            fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        
    }
    mid = slow;

    // Reverse list from next of mid
    p = NULL;
    q = mid->next;
    r = q->next;
    while(q != NULL)
    {
        q->next = p;
        p = q;
        q = r;
        if(r != NULL)
            r = r->next;
    }
    mid->next = p; // Join reversed list next to mid

    // Check if Palindrome
    p = head;
    q = mid->next;
    while(q != NULL)
    {
        if(p->data != q->data)
            return 0;
        p = p->next;
        q = q->next;
    }
    
    return 1;
}