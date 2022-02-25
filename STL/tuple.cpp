#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define debug(args...) cout << (#args) << " = " << (args) << endl
#define MOD 1000000007
#define vi vector<int>
#define fl forward_list
#define pb push_back
#define pf push_front
#define read(st) getline(cin, st)
#define FOR(i, a, b) for (int i = a; i < b; i++)

int main()
{
    fastio;
    tuple<int, string, char> thing;
    // thing = make_tuple(22,"Matheus",'C');
    thing = {22, "Matheus", 'C'};
    cout << get<0>(thing) << endl;
    cout << get<1>(thing) << endl;
    cout << get<2>(thing) << endl;
    cout << "The size of tuple is : ";
    cout << tuple_size<decltype(thing)>::value << endl;
    tuple<int, int> t1 = {2, 4};
    int x, y;
    tie(x, y) = t1;
    cout << x << " " << y << endl;

    tuple<int, char> s1 = {20, 'T'};
    tuple<char, string> s2 = {'h', "Hello"};
    auto t3 = tuple_cat(s1, s2);
    cout << get<0>(t3) << endl;
    return 0;
}