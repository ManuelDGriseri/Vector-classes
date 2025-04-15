#include <iostream>

#include "tvector.h" 

int main()
{
    try{
        m1::TVector<double> v1(3);
        v1[0] = 1.0;
        v1[1] = 2.0;
        v1[2] = 3.0;
        std::cout << "v1 = " << v1 << std::endl;
        m1::TVector<double> v2 = v1;
        std::cout << "v2 = " << v2 << std::endl;
        m1::TVector<double> v3(2);
        v3 = v1;
        std::cout << "v3 = " << v3 << std::endl;
        std::cout << "v3 + v3 = " << v3 + v3 << std::endl;
        std::cout << "v3 - v3 = " << v3 - v3 << std::endl;
        std::cout << "v3 * v3 = " << (v3 * v3) << std::endl;
        std::cout << "Norme p=2 de v3 : " << v3.norm() << std::endl;
        m1::TVector<double> v4(2);
        v4[0] = 1.0;
        v4[1] = 2.0;
        std::cout << "v3 * v4 = " << (v3 * v4) << std::endl;  // bad size
    }

    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
