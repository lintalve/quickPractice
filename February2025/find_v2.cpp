#include <print>
#include <iostream>
#include <random>
#define N 12

int randomInt() {
    // Create a random device to seed the generator
    std::random_device rd;
    // Use Mersenne Twister as the random number engine
    std::mt19937 gen(rd());
    // Define a uniform integer distribution in the range [1, 100]
    std::uniform_int_distribution<int> dist(1, 8);
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

void function(Edge edges[], int length) {
    Edge* eptrI = edges;
    Edge* eptrJ = edges;
    for(int i=0; i<N; i++) {
        const Edge& t = *eptrI;
        for(int j=0; j<N; j++) {
            //compare t to every elent
            if(t.e == (*eptrJ).e) continue;
            if(connected(t, *eptrJ)) {
                (*eptrJ).e = t.e;
                //std::print("{}", t.e);
            }
            eptrJ++;
        }
        eptrI++;
    }
    
    
}

int main(int argc, const char* argv[]) {
    Edge edges[N];
    for(int i=0; i<N; i++) {
        std::print("a-{} b-{} e-{}\n", edges[i].a, edges[i].b, edges[i].e);
    }
    
    function(edges, N);
    for(int j=0; j<N; j++) {
        std::print("{} ", edges[j].e);
        //std::cout << edges[j].e << " ";
    }
    std::print("\n");
    return 0;
}
