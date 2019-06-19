#include<bits/stdc++.h>
//Stan
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        int freq[3]={0,0,0}, temp;
        for(int i=0; i<n; i++)
        {
            cin>>temp;
            freq[temp]++;
        }

        for(int i=0; i<=2; i++)
        {
            while(freq[i] > 0)
            {
                cout<<i<<" ";
                freq[i]--;
            }
        }
        cout<<endl;
    }
    return 0;
}