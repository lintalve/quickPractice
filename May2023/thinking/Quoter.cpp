#include <stdio.h>
#include <cstdlib>
#include <ctime>

class Quoter{
    int lastquote;
public:
    Quoter();
    int lastQuote() const;
    const char* quote();
};

Quoter::Quoter(){
    lastquote = -1;
    srand(time(NULL));
}
int Quoter::lastQuote() const {
        return lastquote;
}
const char* Quoter::quote(){
    static const char* quotes[] = {
    "Are we having fun yet?",
    "Doctors always know best", 
    "Is it ... Atomic?", 
    "Fear is obscene", 
    "There is no scientific evidence", 
    "to support the idea",
    "that life is serious", 
    "Things that make us happy, make us wise"};
    const int qsize = sizeof(quotes)/sizeof(*quotes);
    int qnum = rand() % qsize;
    while(lastquote <=0 && qnum == lastquote)
            qnum = rand() % qsize;
    return quotes[lastquote = qnum];
}

int main(void){
    Quoter q;                //not const Quoter instance can call its const and non const methods
    const Quoter cq;
    cq.lastQuote();          //even autocomplete sujjests the only const method there is
    //! cq.quote();          //can't, calling non const method for instance declared const
    for(int i=0; i<20; i++){
        printf("%s\n", q.quote());
    }
    typedef struct doublesLongs{
        long int li = 23423234672;
        long long ll = 109872348567;
        double someDouble0 = 3425345.4745612341;
    }dobes;
    dobes dobess;
    dobes& doref = dobess;
    printf("the size of the ref %lu\n", sizeof(doref));
    return 0;
}