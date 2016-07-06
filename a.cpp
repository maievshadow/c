#include <iostream>
#include <csetjmp>
using namespace std;

class Rainbow
{
public:
    Rainbow();
    ~Rainbow();
private:
   int _m;
};

Rainbow::Rainbow()
{
    _m = 10;
}

Rainbow::~Rainbow()
{
    cout<<"uuuu"<<endl;
}

jmp_buf zf;
void oz()
{
    Rainbow rb;
    longjmp(zf, 47);
}

int main()
{
    if (setjmp(zf) == 0){
        cout <<"..."<<endl;
        oz();
    }else{
        cout<<"iii"
            <<"zzzz"
            <<endl;
    }
    return 0;
}
