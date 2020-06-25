// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int arr[20];
int n;
set<vector<int> > ans;
vector<int> temp;

void dfs(int pos, int req)
{
    if (pos >= n)
        return;
    if (arr[pos] == req)
    {
        temp.push_back(arr[pos]);
        ans.insert(temp);
        temp.pop_back();
    }
    if (arr[pos] > req)
        return;

    temp.push_back(arr[pos]);
    dfs(pos+1, req-arr[pos]);
    temp.pop_back();
    dfs(pos+1, req);
}


int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        ans.clear();
        temp.clear();
        int k;
        cin>>n;
        for (int i=0; i<n; i++)
            cin>>arr[i];
        cin>>k;

        sort(arr, arr+n);
        dfs(0, k);

        if (ans.size() == 0)
            cout<<"Empty";
        for (auto tr: ans)
        {
            vector<int> temp = tr;
            cout<<"(";
            for (int j=0; j<temp.size(); j++)
            {
                if (j == temp.size()-1)
                    cout<<temp[j];
                else
                    cout<<temp[j]<<" ";
            }
            cout<<")";
        }
        cout<<endl;
    }
}
