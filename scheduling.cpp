#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> I, pair<int, int> r)
{
    return I.second < r.second;
}
int main()
{
    int res = 1;
    vector<pair<int, int>> activity = {{1, 3}, {2, 5}, {3, 9}, {6, 8}};

    sort(activity.begin(), activity.end(), cmp);

    int fin = activity[0].second;

    for (int i = 1; i < activity.size(); i++)
    {

        if (activity[i].first >= fin)
        {
            fin = activity[i].second;
            res++;
        }
    }
    cout << res;
    return 0;
}