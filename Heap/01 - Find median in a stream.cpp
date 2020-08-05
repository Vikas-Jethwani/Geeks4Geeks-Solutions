// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> ans(n);
    float median = 0.0;
    priority_queue<int> max_heap; // for lower than median
    priority_queue<int, vector<int>, greater<int>> min_heap; // for higher than median
    for (int num, i=0; i<n; i++)
    {
        cin>>num;
        int s1 = max_heap.size(); // lower side
        int s2 = min_heap.size(); // higher side

        if (s1 == s2)
        {
            if (num >= median) // add to higher side
            {
                min_heap.push(num);
                median = min_heap.top();
            }
            else // add to lower side
            {
                max_heap.push(num);
                median = max_heap.top();
            }
        }
        else if (s1 > s2)
        {
            if (num >= median) // after this insertion, both heaps same size
            {
                min_heap.push(num);
            }
            else // max_heap now more size
            {
                max_heap.push(num);
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            median = (min_heap.top() + max_heap.top())/2.0;
        }
        else // s1 < s2
        {
            if (num > median) // min_heap now more size
            {
                min_heap.push(num);
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            else // after this insertion, both heaps same size
            {
                max_heap.push(num);
            }
            median = (min_heap.top() + max_heap.top())/2.0;
        }

        ans[i] = int(median);
    }

    for (auto num: ans)
        cout<<num<<endl;
    return 0;
}
