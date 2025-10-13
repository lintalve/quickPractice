#include <iostream>
#include <format>

using namespace std;

class Instrument {
public:
    virtual void play() {
        cout << "Instrument spielt" << endl;
    }
};
class String : public Instrument {
    virtual void play() {
        cout << "String spielt" << endl;
    }
};

void tune(Instrument& inst ) {   //das heißt upcasting. Das funkzioniert mit reference und mit dem pointer
    inst.play();
}

int main(int argc, const char* argv[]) {
    String str1;
    tune(str1);
    return 0;
}
