#include <iostream>

using namespace std;

int root(int id[], int i) {
    while(i != id[i])  // Traverse up the tree  
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
