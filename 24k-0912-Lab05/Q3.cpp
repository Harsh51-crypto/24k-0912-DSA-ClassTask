#include <vector>
#include <iostream>
using namespace std;

void solve()
{
    int size;
    cin >> size;

    vector<int> nums;

    for (int i = 0; i < size; ++i)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
}

int main()
{
    int t, i = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << i << endl;
        solve();
        ++i;
    }
    return 0;
}