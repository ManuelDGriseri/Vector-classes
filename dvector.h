#ifndef M1_DVECTOR_H
#define M1_DVECTOR_H

#include <array>
#include <cmath>
#include <stdexcept>
#include <ostream>

namespace m1 {

    template <std::size_t N>
    class DVector : public std::array<double, N>
    {
    public:
        double norm(int p = 2) const;  // Gli altri metodi ci sono già
    };

    template <std::size_t N>
    double DVector<N>::norm(int p) const
    {
        if (p <= 0) {
            throw std::invalid_argument("Norm p<=0");
        }
        double sum = 0.0;
        for (std::size_t i = 0; i < N; i++) {
            sum += std::pow(std::abs((*this)[i]), p);
        }
        return std::pow(sum, 1.0 / p);
    }

} // namespace m1

template <std::size_t N>
std::ostream& operator<<(std::ostream& os, const m1::DVector<N>& v)
{
    for (std::size_t i = 0; i < N; i++) {
        os << v[i] << " ";
    }
    return os;
}

template <std::size_t N>
m1::DVector<N> operator+(const m1::DVector<N>& v1, const m1::DVector<N>& v2)
{
    m1::DVector<N> res;
    for (std::size_t i = 0; i < N; i++) {
        res[i] = v1[i] + v2[i];
    }
    return res;
}

template <std::size_t N>
double operator*(const m1::DVector<N>& v1, const m1::DVector<N>& v2)
{
    double ps = 0.0;
    for (std::size_t i = 0; i < N; i++) {
        ps += v1[i] * v2[i];
    }
    return ps;
}

template <std::size_t N>
m1::DVector<N> operator*(const m1::DVector<N>& v, double alpha)
{
    m1::DVector<N> res;
    for (std::size_t i = 0; i < N; i++) {
        res[i] = v[i] * alpha;
    }
    return res;
}

template <std::size_t N>
m1::DVector<N> operator*(double alpha, const m1::DVector<N>& v)
{
    return v * alpha;
}

template <std::size_t N>
m1::DVector<N> operator/(const m1::DVector<N>& v, double alpha)
{
    if (alpha == 0.0) {
        throw std::invalid_argument("Division by 0");
    }
    return v * (1 / alpha);
}

template <std::size_t N>
m1::DVector<N> operator-(const m1::DVector<N>& v1, const m1::DVector<N>& v2)
{
    return v1 + (-1.0) * v2;
}

#endif // M1_DVECTOR_H
