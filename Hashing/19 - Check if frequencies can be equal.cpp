/*
    Other easy way:
    Try by decreasing freq of each character by 1.
    O(26*n)
*/
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
        unordered_map<char, int> freq;
        for (auto ch: s)
            freq[ch]++;

        unordered_map<int, int> freq_of_freq;
        for (auto tr: freq)
            freq_of_freq[tr.second]++;

        vector<pair<int, int>> freq_of_freq_count; // {freq, its_count}
        for (auto tr: freq_of_freq)
            freq_of_freq_count.push_back({tr.first, tr.second});

        if (freq_of_freq_count.size() > 2)
            cout<<0<<endl;
        else if (freq_of_freq_count.size() == 1)
            cout<<1<<endl;
        else if (freq_of_freq_count.size() == 2)
        {
            sort(freq_of_freq_count.begin(), freq_of_freq_count.end());
            if (freq_of_freq_count[0].first == 1 && freq_of_freq_count[0].second == 1) // aabbc
                cout<<1<<endl;
            else if (freq_of_freq_count[1].second == 1 && freq_of_freq_count[0].first + 1 == freq_of_freq_count[1].first)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }
    return 0;
}
