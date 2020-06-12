/*
    Used queue to store correct-start to correct-end.
    Each city pushed and popped atmost once. So, O(n).
*/
// Fall 7 times and Stand-up 8
// StAn

/* // Locked Stub Code
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
*/ // Locked Stub Ends here


// Time : O(n)
// Space : O(n)
// int tour(petrolPump p[], int n)
// {
//     queue <int> q;
//     int start=0, end=0, curr=0;
//     while (true)
//     {
//         if (q.size() == n)
//             break;
//         if (curr >= 0)
//         {
//             q.push(end);
//             curr += (p[end].petrol-p[end].distance);
//             end = (end+1)%n;
//         }
//         if (curr < 0)
//         {
//             q.pop();
//             curr += (p[start].distance-p[start].petrol);
//             start = (start+1)%n;
//             if (start == 0)
//                 return -1;
//         }
//     }
//     return q.front();
// }


// Time : O(n)
// Space : O(1)
int tour(petrolPump p[], int n)
{
    int start=0, end=0, curr=0;
    while (true)
    {
        if (curr >= 0)
        {
            curr += (p[end].petrol-p[end].distance);
            end = (end+1)%n;
        }
        if (curr < 0)
        {
            curr += (p[start].distance-p[start].petrol);
            start = (start+1)%n;
            if (start == 0)
                return -1;
        }
        else
        {
            if (start == end)
                return start;
        }
    }
}
