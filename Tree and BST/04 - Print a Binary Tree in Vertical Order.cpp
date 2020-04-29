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

void verticalOrder(Node *root);

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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
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
        // string c;
        // getline(cin,c);
        Node* root = buildTree(s);
        
        verticalOrder(root);
        cout << endl;
    }
    return 0;
}
*/
// Stub Code Ends

void verticalOrder(Node *root)
{
    if (root == NULL)
        return;

    map <int, vector <int> > view; // Dist, Values
    queue <pair <Node *, int> > q;
    q.push({root, 0});

    while (!q.empty())
    {
        Node *curr = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (view.find(dist) != view.end()) // Dist already exists
            view[dist].push_back(curr->data);
        else
        {
            vector <int> vc;
            vc.push_back(curr->data);
            view[dist] = vc;
        }

        if(curr->left)
            q.push({curr->left, dist-1});
        if(curr->right)
            q.push({curr->right, dist+1});
    }

    for (auto tr: view)
    {
        vector <int> vc = tr.second;
        for (int i=0; i<vc.size(); i++)
            cout<<vc[i]<< " ";
    }
}
