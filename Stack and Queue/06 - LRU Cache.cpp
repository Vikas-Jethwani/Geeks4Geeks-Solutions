/*
    Queue using Doubly Linked List.
    Hashed on nodes address to reorder quickly.
*/
// Fall 7 times and Stand-up 8
// StAn

/* // Locked Stub Code
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next, *pre;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = pre = NULL;
    }
};
*/ // Locked Stub Ends here
class LRUCache
{
  private:
    static unordered_map<int, Node *> hsmap;
    static int capacity, count;
    static Node *head, *tail;

  public:
    LRUCache(int cap)
    {
        capacity = cap;
        count = 0;
        head = tail = NULL;
        hsmap.clear();
    }

    static int get(int key)
    {
        if (hsmap[key])
        {
            Node* ptr = hsmap[key];
            if (ptr == head) // If head then don't need to reorder
                return ptr->value;

            Node* p = ptr->pre;
            Node* q = ptr->next;
            
            if (ptr == tail && p != NULL) // Ek hee node toh nahi hai
            {
                tail = p;
                tail->next = NULL;
            }
            else if (p != NULL)
            {
                p->next=q;
            }
            if (q != NULL)
            {
                q->pre = p;
            }
            
            if (head != ptr) // Bring to front
            {
                head->pre = ptr;
                ptr->next=head;
                ptr->pre = NULL;
                head=ptr;
            }
            return hsmap[key]->value;
        }
        else
        {
            return -1;
        }
    }

    static void set(int key, int value)
    {
        if (!hsmap[key]) // Doesn't Exist
        {
            Node* ptr = new Node(key, value);
            hsmap[key] = ptr;
            
            if (head == NULL) // First node
            {
                head = ptr;
                tail = ptr;
                count = 1;
                return;
            }
            
            if (count == capacity) // Max capacity reached
            {
                hsmap[tail->key] = 0; // Delete oldest item from cache
                if (tail->pre == NULL) // 1 == cap == count
                {
                    tail = head = ptr;
                    return;
                }
                else
                {
                    tail->pre->next = NULL;
                    tail = tail->pre;
                }

                head->pre = ptr;
                ptr->next = head;
                head = ptr;
            }
            else
            {
                head->pre = ptr;
                ptr->next = head;
                head = ptr;
                count++;
                return;
            }
        }
        else // Already exists
        {
            Node* ptr = hsmap[key];
            ptr->value = value;
            if (ptr == head)
                return ;

            Node* p = ptr->pre;
            Node* q = ptr->next;
            
            if (ptr == tail && p != NULL)
            {
                tail = p;
                tail->next = NULL;
            }
            if (p != NULL)
            {
                p->next=q;
            }
            if (q != NULL)
            {
                q->pre = p;
            }
            
            if (head != ptr)
            {
                head->pre = ptr;
                ptr->next=head;
                ptr->pre = NULL;
                head=ptr;
            }
        }
    }
};

/* // Locked Stub Code

// Initializing static members
unordered_map<int, Node *> temp;
int LRUCache::capacity = 0;
Node *LRUCache::head = new Node(0, 0);
Node *LRUCache::tail = new Node(0, 0);
int LRUCache::count = 0;
unordered_map<int, Node *> LRUCache::hsmap = temp;

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        int queries;
        cin >> queries;

        LRUCache *cache = new LRUCache(capacity);
        while (queries--) {
            string q;
            cin >> q;
            if (q == "SET") {
                int key;
                cin >> key;
                int value;
                cin >> value;

                cache->set(key, value);

            } else {
                int key;
                cin >> key;

                cout << cache->get(key) << " ";
            }
        }

        cout << endl;
    }
    return 0;
}
*/ // Locked Stub Ends here