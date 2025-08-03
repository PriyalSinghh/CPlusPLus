#include <iostream>

using namespace std;
// namespace are used to avoid naming conflicts between diff. libraries.
// let say u have to functions having same names are there inside two diff. libraries 
// but when u will use on of them in another file then u will get redefinition error
// to avoid that we use namespaces so that compiler can tell them apart by seeing their namespaces.
// namespace is a container for identifiers that helps avoid nameing conflicts.

namespace Hello{
    void greet() {
        cout << "I am from Hello's namespace" << endl;
    }
}

namespace Priyal {
    void greet() {
        cout << " I am from Priyal's namespace." << endl;
    }
}

// Nested Namespaces
namespace A :: B :: C {
    void sayHi() {
        cout << "HI from C" << endl;
    }
}
// instead of namespace A {
//  namespace B {
//      namespace C {
//        void sayHi() {}  }}}


namespace VeryLongNamespaceName{
    void show() {}
}

namespace VLN = VeryLongNamespaceName;

int main() {

    Hello :: greet();
    Priyal :: greet();

    return 0;
}



