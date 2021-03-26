#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        /* code */

        string str1;
        getline(cin, str1);
        string str(str1);
        string buf;           // Have a buffer string
        stringstream ss(str); // Insert the string into a stream

        set<string> tokens; // Create vector to hold our words
        // getline(cin, str);
        while (ss >> buf)
            tokens.insert(buf);
        int aux = 0;
        for (auto x : tokens)
        {
            if (aux + 1 != tokens.size())
            {
                cout << x << ' ';
            }
            else
            {
                cout << x << endl;
            }
            aux++;
        }
        // cout << endl;
    }

    return 0;
}