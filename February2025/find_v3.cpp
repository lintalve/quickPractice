#include <print>
#include <iostream>
#include <random>
#define N 10
#define E 4

int randomInt() {
    // Create a random device to seed the generator
    std::random_device rd;
    // Use Mersenne Twister as the random number engine
    std::mt19937 gen(rd());
    // Define a uniform integer distribution in the range [1, 100]
    std::uniform_int_distribution<int> dist(0, 9);
    // Generate a random integer
    
    return dist(gen);
}



struct Edge {
    static int count;
    int a {};
    int b {};
    int e {};
public:
    Edge() : a(randomInt()), b(randomInt()) {
        e = count;
        count++;
    }
    
};
int Edge::count = 0;

bool connected(const Edge& a, const Edge& b) {
    if(a.a == b.a || a.a == b.b || a.b == b.a || a.b == b.b) {
        return true;
    } else { return false; }
}

void function(Edge edges[], int elength, int pts[], int plength) {
    const Edge* e = edges;
    int* pt = pts;
    for(int i=0; i<elength; i++) {  //very inderect for each pair
        const int t = pt[e->a];     //pointer!! *(pt + e->a)  //taking const element from index e->a
        //std::print("t = {}, edges.a = {} ", t, e->a);
        
        if(t == pt[e->b]) continue;     //if(t == *(pt + e->b)) continue; //if element taken from index e->a
        
        for(int j=0; j<plength; j++)
            if(pt[j] == t) pt[j] = pt[e->b];
    
        
        std::print("edge {}\n", e->e);
        e++;
    }
    
}
    
    


int main(int argc, const char* argv[]) {
    Edge edges[E];
    for(int i=0; i<E; i++) {
        std::print("{}-{} e-{}\n", edges[i].a, edges[i].b, edges[i].e);
    }
    int pts[N];
    for(int i=0; i<N; i++) pts[i] = i;
    function(edges, E, pts, N);
    for(int j=0; j<N ; j++) {
        std::print("{} ", pts[j]);
        
    }
    std::print("\n");
    return 0;
}
