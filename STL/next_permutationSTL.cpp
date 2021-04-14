/*

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vect = {1, 2, 3, 4};

    sort(vect.begin(), vect.end());

    cout << "The 4! possible permutations with 4 elements:\n";
    do
    {
        cout << vect[0] << ' ' << vect[1] << ' ' << vect[2] << ' ' << vect[3] << '\n';
    } while (next_permutation(vect.begin(), vect.end()));

        prev_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing prev permutation :\n ";
    for (int i = 0; i < vect.size(); i++)
        cout
            << vect[i]
            << " ";
    return 0;
}