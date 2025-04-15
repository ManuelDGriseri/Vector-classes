#ifndef VECT_H
#define VECT_H

#include <iostream>
#include <cmath>
#include <stdexcept>

namespace m1 {

    class Vect {
    private:
        double* data_;
        size_t size_;

    public:
        // Constructeur par taille
        Vect(size_t size); // size_t >=0, au lieu de int

        // Constructeur par copie
        Vect(const Vect& other);

        // Destructeur
        ~Vect();

        // Accesseur pour la taille
        size_t get_size() const;

        // Opérateurs d'accès
        double& operator[](size_t index);
        double& operator[](size_t index) const;

        // Opérateur d'affectation
        Vect& operator=(const Vect& other);

        // Méthode pour la norme
        double norm(double p = 2.0) const;
    };

    // Déclarations des opérateurs externes
    Vect operator+(const Vect& v1, const Vect& v2);
    Vect operator-(const Vect& v1, const Vect& v2);
    double operator*(const Vect& v1, const Vect& v2); // Produit scalaire
    Vect operator*(const Vect& v, double scalar);
    Vect operator*(double scalar, const Vect& v);
    Vect operator/(const Vect& v, double scalar);
    std::ostream& operator<<(std::ostream& os, const Vect& v);

} // namespace m1

#endif // VECT_H
