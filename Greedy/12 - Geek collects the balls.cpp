/*
    Similar to merge algorithm(MergeSort).
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int main() {
    int T;
    cin>>T;
    while (T--)
    {
        int n1, n2;
        cin>>n1>>n2;

        int a[n1], b[n2];
        for (int i=0; i<n1; i++)
            cin>>a[i];
        
        for (int i=0; i<n2; i++)
            cin>>b[i];
        
        int i=0, j=0, first=0, second=0, ans=0;
        while (i<n1 && j<n2)
        {
            if (a[i] < b[j])
                first += a[i++];
            else if(a[i] > b[j])
                second += b[j++];
            else
            {
                int curr = a[i];
                ans += curr;
                ans += max(first, second);
                i++; j++;
                first = second = 0;
                while (i<n1 && a[i] == curr)
                {
                    first += curr;
                    i++;
                }
                while (j<n2 && b[j] == curr)
                {
                    second += curr;
                    j++;
                }

                ans += max(first, second);
                first = second = 0;
            }
        }
        while (i<n1)
            first += a[i++];
        while (j<n2)
            second += b[j++];
        
        ans += max(first, second);

        cout<<ans<<endl;
    }
}
