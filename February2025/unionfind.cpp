
#include <iostream>

using namespace std;

int root(int id[], int i) {                                  //[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    while (i != id[i])  // Traverse up the tree  //this is for [0, 1, 2, 3, 3, 3, 6, 7, 7, 7]
        i = id[i];
    return i;
}

int main() {
    int N;
    cin >> N;
    
    int id[N];
    for (int i = 0; i < N; i++) id[i] = i;  // Initialize: each element is its own root

    int p, q;
    while (cin >> p >> q) {
        int rootP = root(id, p);
        int rootQ = root(id, q);

        if (rootP == rootQ) continue;  // Already connected

        id[rootP] = rootQ;  // Merge trees

        cout << p << " " << q << endl;
    }

    return 0;
}
