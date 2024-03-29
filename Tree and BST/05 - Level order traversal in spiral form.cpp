// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

// Stub Code
/*
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void printSpiral(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        printSpiral(root);
        cout << endl;
    }
    return 0;
}
*/
// Stub Code Ends

void printSpiral(Node *root)
{
    if (root == NULL)
        return;

    queue < pair< Node *, int> > q; // Level Order
    stack <int> s; // Even Rows ko reverse. 0-based.
    q.push({root, 0});

    while (!q.empty())
    {
        Node *curr = q.front().first;
        int lvl = q.front().second;
        q.pop();

        if (lvl % 2 == 0)
            s.push(curr->data);
        else
        {
            while (!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
            cout<<curr->data<<" ";
        }

        if(curr->left)
            q.push({curr->left, lvl+1});
        if(curr->right)
            q.push({curr->right, lvl+1});
    }

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
