// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

string all_chars_window(string& s, string& t)
{
    // req_count if there are duplicates in t, else can use t.length()
    int mn_len=INT_MAX, len_t=t.length(), len_s=s.length(), req_count=0;

    unordered_map<char, int> req_freq, freq;
    for (int i=0; i<len_t; i++)
    {
        if (req_freq[t[i]] == 0)
            req_count++;
        req_freq[t[i]]++;
    }

    int i=0, j=0, count=0, start; // j is not included in the word yet [i,j)
    while (true)
    {
        while (j < len_s && count < req_count) // increase window
        {
            freq[s[j]]++;
            if (freq[s[j]] == req_freq[s[j]])
                count++;
            j++;
        }
        if (count >= req_count && j-i < mn_len) // j is not included in the word [i,j)
        {
            mn_len = j-i;
            start = i;
        }
        while (i < j && count >= req_count) // decrease window
        {
            freq[s[i]]--;
            if (freq[s[i]] + 1 == req_freq[s[i]])
                count--;
            i++;

            if (count >= req_count && j-i < mn_len)
            {
                mn_len = j-i;
                start = i;
            }
        }
        if (j == len_s)
            break;
    }

    if (mn_len == INT_MAX)
        return "-1";
    else
        return s.substr(start, mn_len);
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s, t;
        cin>>s>>t;

        cout<< all_chars_window(s, t) <<endl;
    }
    return 0;
}
