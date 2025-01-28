#include <cstdio>


class Entity {
    float f;
public:
    Entity() : f(4.35f) {}
    Entity& add() {
        f += 3.45f;
        return *this;
    }
    Entity& mult() {
        f *= 3.45f;
        return *this;
    }
    Entity& sub() {
        f -= 3.45f;
        return *this;
    }
    Entity& div() {
        f /= 3.0f;
        return *this
    }
};

int main() {
    Entity obj;
    obj.add().mult().sub().div();   //executed evaluated from left to right order
    return 0;
}
