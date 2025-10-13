#include <iostream>

#define N 10
using namespace std;
int main(int argc, const char* argv[]) {
    int p, q, id[N];
    for(int i=0; i<N; i++) id[i] = i;
    
    while(cin >> p >> q) {
        //this is 
        for(i = p; i != id[i]; i = id[i]) ;
        for(j = q; j != id[j]; j = id[j]) ;
        if(i == j) continue;
        id[i] = j;
        std::cout << " " << p << " " << q << std::endl;
    }
    return 0;
}

