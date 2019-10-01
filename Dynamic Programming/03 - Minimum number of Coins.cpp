/*
    Better than GeeksForGeeks' Solution.
    Mine works even when the given denomination set is not a Matroid.
    Eg. denominations = {2,3,4}
        N = 5
    My code returns = 3,2
    GFG's code returns = 4
*/
// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

#define MAX 1000005
#define M 10

int denominations[M] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
int dp[MAX][M]; // Rows => How much money; Cols => Using every note before this col.

void pre_compute()
{
    // Base Case
    for(int j=0; j<M; j++)
        dp[0][j] = 0; // 0 Rs ke liye 0 notes

    // Game begins
    for(int i=1; i<MAX; i++)
    {
        for(int j=0; j<M; j++)
        {
            int choice1=INT_MAX, choice2=INT_MAX;
            if(j != 0)
                choice1 = dp[i][j-1];
            if(i - denominations[j] >= 0 && dp[i - denominations[j]][j] != INT_MAX)
                choice2 = 1 + dp[i - denominations[j]][j];

            dp[i][j] = min(choice1, choice2);
        }
    }

    // For Debug
    /*for(int i=0; i<MAX; i++)
    {
        cout<<i << " :=  ";
        for(int j=0; j<M; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
}

vector<int> reconstruct(int n)
{
    vector<int> err = {-1};
    vector<int> ans; ans.clear();
    int j=M-1;

    if(dp[n][j] == INT_MAX)
        return err;
    while(n > 0)
    {
        int choice1=INT_MAX, choice2=INT_MAX;
        if(j != 0)
            choice1 = dp[n][j-1];
        if(n - denominations[j] >= 0 && dp[n - denominations[j]][j] != INT_MAX)
            choice2 = 1 + dp[n - denominations[j]][j];

        if(choice1 < choice2)
        {
            j--;
        }
        else
        {
            ans.push_back(denominations[j]);
            n = n - denominations[j];
        }
    }

    return ans;
}


int main()
{
    pre_compute();
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        // To print min number of coins.
        // cout<<dp[n][M-1]<<endl;

        vector<int> ans = reconstruct(n);

        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}
