// Fall 7 times and Stand-up 8
#include <bits/stdc++.h>
// StAn
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        queue <char> q;
        map <char, int> freq;

        int n;
        cin>>n;
        for (int i=0; i<n; i++)
        {
            char ch;
            cin>>ch;
            freq[ch]++;
            if (freq[ch] == 1)
                q.push(ch);

            bool found = false;
            char candidate;
            while (!q.empty())
            {
                candidate = q.front();
                if (freq[candidate] == 1)
                {
                    found = true;
                    break;
                }
                else
                    q.pop();
            }

            if (found)
                cout<<candidate<<" ";
            else
                cout<<-1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
