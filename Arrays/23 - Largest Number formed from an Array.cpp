#include<bits/stdc++.h>
//Stan
using namespace std;

bool mySort(const string num1, const string num2)
{
    int num12, num21;
    num12 = stoi(num1 + num2);
    num21 = stoi(num2 + num1);
    if(num12 > num21)
        return true;
    else
        return false;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        string arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        sort(arr, arr+n, mySort);
        string ans="";
        for(int i=0; i<n; i++)
        {
            ans += arr[i];
        }
        
        cout<<ans<<endl;
    }
    return 0;
}