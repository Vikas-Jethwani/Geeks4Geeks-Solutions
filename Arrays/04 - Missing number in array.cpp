#include<bits/stdc++.h>
//Stan
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long unsigned int n;
        cin>>n;

        long long unsigned int sum_of_all=0, req_sum;
        if(n%2)
        {
            req_sum = (n+1)/2;
            req_sum *= n;
        }
        else
        {
            req_sum = n/2;
            req_sum *= (n+1);
        }

        for(int i=0; i<n; i++)
        {
            int temp;
            cin>>temp;
            sum_of_all += temp; 
        }

        cout<<req_sum - sum_of_all<<endl;
    }
    return 0;
}