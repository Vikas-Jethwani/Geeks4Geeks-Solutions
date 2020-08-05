// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* mergeKLists(Node* arr[], int N);

void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        struct Node *arr[N];
        for(int j=0;j<N;j++)
        {
            int n;
            cin>>n;

            int x;
            cin>>x;
            arr[j]=new Node(x);
            Node *curr = arr[j];
            n--;

            for(int i=0;i<n;i++)
            {
                cin>>x;
                Node *temp = new Node(x);
                curr->next =temp;
                curr=temp;
            }
        }
        Node *res = mergeKLists(arr,N);
        printList(res);
    }
    return 0;
}


/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[] */
Node* mergeKLists(Node *arr[], int N)
{
    Node * head = NULL;
    Node * prev = NULL;
    Node * ptr = NULL;
    bool found = true;
    while (found)
    {
        ptr=NULL;
        found = false;
        int idx=-1;
        for (int i=0; i<N; i++)
        {
            if (arr[i] != NULL)
            {
                found = true;
                if (ptr == NULL)
                {
                    ptr = arr[i];
                    idx = i;
                }
                else
                {
                    if (ptr->data > arr[i]->data)
                    {
                        ptr = arr[i];
                        idx = i;
                    }
                }
            }
        }
        if (prev != NULL)
            prev->next = ptr;
        prev = ptr;
        if (idx != -1)
            arr[idx] = arr[idx]->next;
        if (head == NULL)
            head = prev;
    }
    return head;
}
