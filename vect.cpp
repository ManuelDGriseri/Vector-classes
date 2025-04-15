#include "vect.h"

namespace m1 {

    // Constructeur 
    Vect::Vect(size_t size) : size_(size), data_(new double[size]) {
        for (size_t i = 0; i < size_; ++i) data_[i] = 0.0;
    }

    // Constructeur de copie
    Vect::Vect(const Vect& other) : size_(other.size_), data_(new double[other.size_]) {
        for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
    }

    // Destructeur
    Vect::~Vect() {
        delete[] data_;
    }

    // Accesseur pour la taille
    size_t Vect::get_size() const {
        return size_;
    }

    // Opérateurs d'accès
    double& Vect::operator[](size_t index) {
        if (index >= size_) throw std::invalid_argument("Index out of range"); //si int à la place de size_t, faut aussi vérifier index<0
        return data_[index];
    }

    double& Vect::operator[](size_t index) const {
        if (index >= size_) throw std::invalid_argument("Index out of range");
        return data_[index];
    }

    // Opérateur d'affectation
    Vect& Vect::operator=(const Vect& other) {
        if (this == &other) return *this;

        delete[] data_;
        size_ = other.size_;
        data_ = new double[size_];
        for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];

        return *this;
    }

    // Méthode pour la norme
    double Vect::norm(double p) const {
        double sum = 0.0;
        for (size_t i = 0; i < size_; ++i) sum += std::pow(std::fabs(data_[i]), p);
        return std::pow(sum, 1.0 / p);
    }

    // Opérateurs externes
    Vect operator+(const Vect& v1, const Vect& v2) {
        if (v1.get_size() != v2.get_size()) throw std::invalid_argument("Vectors must have the same size");
        Vect result(v1.get_size());
        for (size_t i = 0; i < v1.get_size(); ++i) {
            result[i] = v1[i] + v2[i];
        }
        return result;
    }

    Vect operator-(const Vect& v1, const Vect& v2) {
        if (v1.get_size() != v2.get_size()) throw std::invalid_argument("Vectors must have the same size");
        Vect result(v1.get_size());
        for (size_t i = 0; i < v1.get_size(); ++i) {
            result[i] = v1[i] - v2[i];
        }
        return result;
    }

    double operator*(const Vect& v1, const Vect& v2) {
        if (v1.get_size() != v2.get_size()) throw std::invalid_argument("Vectors must have the same size");
        double dot = 0.0;
        for (size_t i = 0; i < v1.get_size(); ++i) {
            dot += v1[i] * v2[i];
        }
        return dot;
    }

    Vect operator*(const Vect& v, double scalar) {
        Vect result(v.get_size());
        for (size_t i = 0; i < v.get_size(); ++i) {
            result[i] = v[i] * scalar;
        }
        return result;
    }

    Vect operator*(double scalar, const Vect& v) { //pour faire aussi s*v et pas seulement v*s
        return v * scalar;
    }

    Vect operator/(const Vect& v, double scalar) {
        if (scalar == 0.0) throw std::invalid_argument("Division by zero");
        Vect result(v.get_size());
        for (size_t i = 0; i < v.get_size(); ++i) {
            result[i] = v[i] / scalar;
        }
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const Vect& v) {
        os << "(";
        for (size_t i = 0; i < v.get_size(); ++i) {
            os << v[i];
            if (i < v.get_size() - 1) os << ",";
        }
        os << ")";
        return os;
    }

} // namespace m1

