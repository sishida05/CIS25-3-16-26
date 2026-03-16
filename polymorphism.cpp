#include <iostream>
using namespace std;

class Animal {

    private:
        string name;
        int age;

    public:
        virtual void makeNoise() {
            cout << "I am an animal and I make noise!" << endl;
        }

};

class Dog : public Animal {
    virtual void makeNoise() {
        cout << "Woof!" << endl;
    }

};

class Cat : public Animal {
    virtual void makeNoise() {
        cout << "Meow!" << endl;
    }

};

void animalNoise(Animal * a) {
    a->makeNoise();
}

int main() {

    Cat momo;
    animalNoise(&momo);

    return 0;
}