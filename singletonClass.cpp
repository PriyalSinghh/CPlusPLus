#include <iostream>

using namespace std;

// A singletone class is a design pattern that ensures only one object of the class
// can ever be created during the program's lifetime.

class Singleton {
    private:
        static Singleton* instance;

        Singleton() {
            cout << "Singletone Instance Created" << endl;
        }

    public:
        static Singleton* getInstance() {
            if(instance == nullptr)
            instance = new Singleton();
            return instance;
        }

        void sayHello() {
            cout << "hello from singleton" << endl;
        }
};

// Real world use cases are Logger, Configuration Reader, Database connection Pool, THread POOl manager, Global App Satte Handler

Singleton* Singleton :: instance = nullptr;

int main() {

    Singleton* s1 = Singleton :: getInstance();
    Singleton* s2 = Singleton :: getInstance();

    s1->sayHello();


    return 0;
}