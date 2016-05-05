#include <iostream>
#include <vector>

using namespace std;

void walkit(vector<int> &v, int k, int m)
{
    if (k == m) {
        for (auto i : v) {
            cout << i << ' ';
        } 
        cout << endl;
        return;
    }
    for (int i = 0; i < 6; i++) {
        v[k] = i;
        walkit(v, k+1, m);
    }
}

int main()
{
    vector<int> v(4);
    walkit(v, 0, 4);

    return 0;
}
