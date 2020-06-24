// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

vector<string> split(string s, char ch=' ')
{
    vector<string> ans;
    ans.clear();
    string temp = "";
    for (int i=0; i<s.size(); i++)
    {
        if (s[i] == ch)
        {
            if (temp != "")
                ans.push_back(temp);
            temp = "";
        }
        else
            temp += s[i];
    }
    // if (temp != "") // Commented out to catch "10.0.0.1."
        ans.push_back(temp);
    return ans;
}

bool validateIP4(string ip)
{
    vector<string> ans = split(ip, '.');
    if (ans.size() != 4)
        return false;
    for (int i=0; i<ans.size(); i++)
    {
        if (ans[i].size() == 0)
            return false;
        if (ans[i].size() > 3) // Avoiding stoi throwing out of bound errors "1234567899"
            return false;
        if (ans[i].size() > 1 && ans[i][0] == '0') // Leading 0
            return false;

        for (int j=0; j<ans[i].size(); j++)
        {
            if (ans[i][j] < '0' || ans[i][j] > '9')
                return false;
        }
        int val = stoi(ans[i]);
        if (val < 0 || val > 255)
            return false;
    }
    return true;
}

vector<string> genIp(string &s)
{
    vector<string> ans;
    ans.clear();
    int n = s.size();
    for (int i=1; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            for (int k=j+1; k<n; k++)
            {
                string temp = "";
                for (int l=0; l<n; l++)
                {
                    if (l == i || l == j || l == k)
                    {
                        temp += ".";
                    }
                    temp += s[l];
                }
                if (validateIP4(temp))
                    ans.push_back(temp);
            }
        }
    }
    return ans;
}
