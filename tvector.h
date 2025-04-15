#ifndef M1_TVECTOR_H
#define M1_TVECTOR_H

#include <ostream>
#include <stdexcept>
#include <cmath>

namespace m1 {

    template <typename T>
    class TVector
    {
    private:
        size_t size_;
        T* data_;

    public:
        TVector(size_t size);
        TVector(const TVector<T>& v);
        ~TVector() { delete[] data_; };
        TVector<T>& operator=(const TVector<T>& v);
        T operator[](size_t i) const;
        T& operator[](size_t i);
        size_t get_size() const { return size_; }
        double norm(int p = 2) const;  // double pour la racine
    };

    template <typename T>
    TVector<T>::TVector(size_t size)
        : size_(size),
        data_(new T[size])
    {
    }

    template <typename T>
    TVector<T>::TVector(const TVector<T>& v)
        : size_(v.size_),
        data_(new T[v.size_])
    {
        for (size_t i = 0; i < size_; i++) {
            data_[i] = v.data_[i];
        }
    }

    template <typename T>
    TVector<T>& TVector<T>::operator=(const TVector<T>& v)
    {
        if (this != &v) {
            TVector<T> tmp = v;
            size_ = tmp.size_;
            std::swap(data_, tmp.data_);
        }
        return *this;
    }

    template <typename T>
    T TVector<T>::operator[](size_t i) const
    {
        if (i >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[i];
    }

    template <typename T>
    T& TVector<T>::operator[](size_t i)
    {
        if (i >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[i];
    }

    template <typename T>
    double TVector<T>::norm(int p) const
    {
        if (p <= 0) {
            throw std::invalid_argument("Norm p<=0");
        }
        double sum = 0.0;
        for (size_t i = 0; i < size_; i++) {
            sum += std::pow(std::abs(data_[i]), p);
        }
        return std::pow(sum, 1.0 / p);
    }

} // namespace m1

template <typename T>
std::ostream& operator<<(std::ostream& os, const m1::TVector<T>& v)
{
    for (size_t i = 0; i < v.get_size(); i++) {
        os << v[i] << " ";
    }
    return os;
}

template <typename T>
m1::TVector<T> operator+(const m1::TVector<T>& v1, const m1::TVector<T>& v2)
{
    if (v1.get_size() != v2.get_size()) {
        throw std::invalid_argument("Bad size in operator+");
    }
    m1::TVector<T> res(v1.get_size());
    for (size_t i = 0; i < v1.get_size(); ++i) {
        res[i] = v1[i] + v2[i];
    }
    return res;
}

template <typename T>
T operator*(const m1::TVector<T>& v1, const m1::TVector<T>& v2)
{
    if (v1.get_size() != v2.get_size()) {
        throw std::invalid_argument("Bad size in operator*");
    }
    T ps = T();  // Initialise à 0 si T est numérique
    for (size_t i = 0; i < v1.get_size(); ++i) {
        ps += v1[i] * v2[i];
    }
    return ps;
}

template <typename T>
m1::TVector<T> operator*(const m1::TVector<T>& v, T alpha)
{
    m1::TVector<T> res(v.get_size());
    for (size_t i = 0; i < v.get_size(); ++i) {
        res[i] = v[i] * alpha;
    }
    return res;
}

template <typename T>
m1::TVector<T> operator*(T alpha, const m1::TVector<T>& v)
{
    return v * alpha;
}

template <typename T>
m1::TVector<T> operator/(const m1::TVector<T>& v, T alpha)
{
    if (alpha == 0) {
        throw std::invalid_argument("Division by 0");
    }
    return v * (1 / alpha);
}

template <typename T>
m1::TVector<T> operator-(const m1::TVector<T>& v1, const m1::TVector<T>& v2)
{
    if (v1.get_size() != v2.get_size()) {
        throw std::invalid_argument("Bad size in operator-");
    }
    return v1 + T(-1) * v2;  // T per evitare incompatibilità int e double
}

#endif // M1_TVECTOR_H

