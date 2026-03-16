#include <iostream>
using namespace std;


class OtherClass {

    private:

    public:

        OtherClass(int x) {
            cout << "We're in OtherClass constructor! The value is: " << x << endl;
        }
};

class Base {

    private:

    public:
        Base(char x) {
            cout << "We're in Base constructor! The char is: " << x << endl;
        }
};

class Derived : public Base {

    private:
        OtherClass obj;
        const int x;

    public:
        Derived() : obj(5), x(3), Base('q') {
            cout << "We're in Derived constructor! The value is: " << x << endl;
        }
};

int main() {

    Derived derived;

    return 0;
}
