/*
    if new element < minEle:
        push (2*x - minEle) onto stack
        minEle = x
        notice that pushed value will always be less than minEle(=x) variable (use that advantage while popping)
*/
// Fall 7 times and Stand-up 8
// StAn

/* // Locked Stub Code
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}
*/ // Locked Stub Ends here


// returns min element from stack
int _stack::getMin()
{
    if (minEle == 0 || minEle == INT_MAX)
        return -1;
    return minEle;
}

// returns popped element from stack
int _stack::pop()
{
    if (s.size() == 0)
        return -1;
    int y = s.top();
    s.pop();
    if (y >= minEle)
        return y;
    else
    {
        int x = minEle;
        minEle = 2*x - y;
        return x;
    }
}

// push element x into the stack
void _stack::push(int x)
{
    if (minEle == 0)
        minEle = INT_MAX;
    if (x < minEle)
    {
        s.push(2*x - minEle);
        minEle = x;
    }
    else
        s.push(x);
}
