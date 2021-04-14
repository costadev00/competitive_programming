// C++ code to demonstrate the working of
// partition_copy()
#include <iostream>
#include <algorithm> // for partition algorithm
#include <vector>    // for vector
using namespace std;
int main()
{
    // Initializing vector
    vector<int> vect = {2, 1, 5, 6, 8, 7};

    // Declaring vector1
    vector<int> vect1;

    // Declaring vector1
    vector<int> vect2;

    // Resizing vectors to suitable size using count_if() and resize()
    int n = count_if(vect.begin(), vect.end(), [](int x) {
        return x % 2 == 0;
    });
    vect1.resize(n);
    vect2.resize(vect.size() - n);

    // Using partition_copy() to copy partitions
    partition_copy(vect.begin(), vect.end(), vect1.begin(),
                   vect2.begin(), [](int x) {
                       return x % 2 == 0;
                   });

    // Displaying partitioned Vector
    cout << "The elements that return true for condition are : ";
    for (int &x : vect1)
        cout << x << " ";
    cout << endl;

    // Displaying partitioned Vector
    cout << "The elements that return false for condition are : ";
    for (int &x : vect2)
        cout << x << " ";
    cout << endl;

    return 0;
}
