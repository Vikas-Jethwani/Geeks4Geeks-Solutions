#include<bits/stdc++.h>
//Stan
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int X, Y;
        cin>>X>>Y;

        int P[X], Q[Y];
        
        for(int i=0; i<X; i++)
            cin>>P[i];
        for(int i=0; i<Y; i++)
            cin>>Q[i];

        int i=0, j=0;
        while(i<X&&j<Y)
        {
            if(P[i] < Q[j])
            {
                cout<<P[i]<<" ";
                i++;
            }
            else
            {
                cout<<Q[j]<<" ";
                j++;
            }
        }
        while(i<X)
        {
            cout<<P[i]<<" ";
            i++;
        }
        while(j<Y)
        {
            cout<<Q[j]<<" ";
            j++;
        }
        cout<<endl;
    }
    return 0;
}