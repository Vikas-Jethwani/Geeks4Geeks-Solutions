// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

// Requires Sorted Array 
vector<vector<int>> n_sum(vector<int>& nums, int N=2, int target=0, int pos=0)
{
    vector<vector<int>> ans;
    if (N == 2)
    {
        int left = pos;
        int right = nums.size()-1;
        while (left < right)
        {
            if (nums[left] + nums[right] == target)
            {
                ans.push_back({nums[left], nums[right]});
                // Comment 4 lines below this if you dont want distinct solution
                while (left < right && nums[left] == nums[left+1])
                    left++;
                while (left < right && nums[right] == nums[right-1])
                    right--;

                left++;
                right--;
                continue;
            }
            else if (nums[left]+nums[right] < target)
                left++;
            else
                right--;
        }
        return ans;
    }
    else if (N >= 3)
    {
        for (int i=pos; i<nums.size(); i++)
        {
            // Comment 2 lines below this if you DONT want distinct solution
            if (i > pos && nums[i] == nums[i-1])
                continue;

            int req = target - nums[i];
            vector<vector<int>> prev_ans = n_sum(nums, N-1, req, i+1);
            for (int j=0; j<prev_ans.size(); j++)
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                for (int k=0; k<N-1; k++)
                    temp.push_back(prev_ans[j][k]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
    else // N < 2
    {
        return vector<vector<int>> (0);
    }
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> nums(n);
        for (int i=0; i<n; i++)
            cin>>nums[i];

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = n_sum(nums, 4, k);
        if (ans.size() == 0)
            cout<<-1;
        for (int i=0; i<ans.size(); i++)
        {
            for (int j=0; j<ans[i].size(); j++)
                cout<<ans[i][j]<<" ";
            cout<<"$";
        }
        cout<<endl;
    }
    return 0;
}
