#include <iostream>
using namespace std;

class Component {

    protected:
        int width;
        int length;
        int depth;

    public:
        Component(int width, int length, int depth) {
            this->width = width;
            this->length = length;
            this->depth = depth;
        }
        
        virtual double getVolume() {
            cout << "Can't get volume if we don't know the shape!" << endl;
            return 0.0;
        }
};

class SphericalComponent : public Component {
    
    private:

    public:
        SphericalComponent(int width, int length, int depth) : Component(width, length, depth) {
            
            }
            
           virtual double getVolume() {
                return (4.0/3.0) * 3.14 * ((1.0/2.0) * width) * ((1.0/2.0) * width) * ((1.0/2.0) * width);
            }

};

class CubeComponent : public Component {
    
    private:

    public:
        CubeComponent(int width, int length, int depth) : Component(width, length, depth) {
            
            }
            
           virtual double getVolume() {
                return width * length * depth;
            }

};


class PlayPlace {

    private:
        int arraySize;
        Component** components;

    public:
        PlayPlace(Component ** components, int size) {
            this->arraySize = size;
            this->components = components;
        }
        
        double calculateVolume() {
            double sum = 0;
            for (int i = 0; i < arraySize; i++) {
                sum += components[i]->getVolume();
            }
            return sum;
        }
};

int main() {

    Component ** components = new Component*[2];
    components[0] = new SphericalComponent(5,6,7);
    components[1] = new CubeComponent(3,4,5);

    PlayPlace * mcdonalds = new PlayPlace(components, 2);

    cout << "The volume of the Play Place is: " << mcdonalds->calculateVolume() << endl;

    return 0;
}

