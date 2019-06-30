// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;

        int len=s.length();
        char arr[len];
        for(int i=0; i<len; i++)
        {
            arr[i] = s[i];
        }
        sort(arr, arr+len);

        do
        {
            for(int i=0; i<len; i++)
                cout<<arr[i];
            cout<<" ";
        }while(next_permutation(arr, arr+len));
        cout<<endl;
    }
    return 0;
}