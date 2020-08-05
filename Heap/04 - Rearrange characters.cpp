// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int check(string s)
{
    vector<int> freq(26, 0);
    for (auto ch: s)
        freq[ch - 'a']++;

    int lim = (s.length() + 1)/2;
    for (auto f: freq)
    {
        if (f > lim)
            return 0;
    }

    /*
    // Rearranging possible
    priority_queue<pair<int, char>> pq;
    for (int i=0; i<26; i++)
    {
        if (freq[i] > 0)
            pq.push({freq[i], i+'a'});
    }

    string ans="";
    char last_ch='0';
    while (!pq.empty())
    {
        int f = pq.top().first;
        char ch = pq.top().second;
        pq.pop();

        if (ch == last_ch)
        {
            int f2 = pq.top().first;
            char ch2 = pq.top().second;
            pq.pop();

            ans += ch2;
            f2--;
            if (f2 > 0)
                pq.push({f2, ch2});
            pq.push({f, ch});

            last_ch = ch2;
        }
        else
        {
            ans += ch;
            f--;
            if (f > 0)
                pq.push({f, ch});

            last_ch = ch;
        }
    }
    cout<< ans <<endl;
    */
    return 1;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        cout<< check(s) <<endl;
    }
    return 0;
}
