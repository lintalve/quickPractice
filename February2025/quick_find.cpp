#include <iostream>

#define N 10
using namespace std;
int main(int argc, const char* argv[]) {
    
    int p, q, id[N];
    for(int i=0; i<N; i++) id[i] = i;
    
    while(cin >> p >> q) {
        int t = id[p];
        if(t == id[q]) continue;
        for(int i=0; i<N; i++)
            if(id[i] == t) id[i] = id[q];   //would be break; or continue; a tak iterates further till end
        //cout << " " << p << " " << endl;      //and so makes N moves, opearations, incrementations
        for(int j=0; j<N; j++) cout << j << " ";
        cout << "\n";
        for(int k=0; k<N; k++) cout << id[k] << " ";
        cout << "\n";
    }
    return 0;
}
