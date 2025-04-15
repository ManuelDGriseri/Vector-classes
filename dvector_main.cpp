#include <iostream>

#include "dvector.h" 

int main()
{
    try {
        m1::DVector<3> v1;
        v1[0] = 1.0;
        v1[1] = 2.0;
        v1[2] = 3.0;
        std::cout << "v1 = " << v1 << std::endl;
        m1::DVector<3> v2 = v1;
        std::cout << "v2 = " << v2 << std::endl;
        m1::DVector<3> v3;
        v3 = v1;  // nessuna eccezione se le lunghezze sono diverse, non compila
        std::cout << "v3 = " << v3 << std::endl;
        std::cout << "v3 + v3 = " << v3 + v3 << std::endl;
        std::cout << "v3 / 2 = " << v3 / 2 << std::endl;
        std::cout << "v3 * v3 = " << (v3 * v3) << std::endl;
        std::cout << "Norme p=2 de v3 : " << v3.norm() << std::endl;
    }

    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
