#ifndef _VEC_H
#define _VEC_H

#include <ostream>
#include <math.h>

/*!
 * \class _vec3
 * \brief A templated class for 3D vector operations.
 *
 * This class provides basic operations on 3D vectors such as addition, subtraction,
 * dot product, and magnitude calculation.
 *
 * \tparam T Type of the vector components (typically float or double).
 */
template<typename T>
class _vec3 {
public:
  /*!
   * \brief Default constructor initializes the vector to (0,0,0).
   */
  _vec3<T>() : d{0, 0, 0} {}

  /*!
   * \brief Parameterized constructor initializes vector components to specified values.
   *
   * \param a X-component of the vector.
   * \param b Y-component of the vector.
   * \param c Z-component of the vector.
   */
  _vec3<T>(T a, T b, T c) : d{a, b, c} {}

  /*!
   * \brief Index operator for accessing vector components.
   *
   * \param i Index (0 for X, 1 for Y, 2 for Z).
   * \return Reference to the i-th component of the vector.
   */
  T& operator[] (int i) { return d[i]; }

  /*!
   * \brief Constant index operator for accessing vector components.
   *
   * \param i Index (0 for X, 1 for Y, 2 for Z).
   * \return Value of the i-th component of the vector.
   */
  T operator[] (int i) const { return d[i]; }

  /*!
   * \brief Overloaded addition operator for adding two vectors.
   *
   * \param a First vector.
   * \param b Second vector.
   * \return A new vector that is the sum of the two input vectors.
   */
  friend _vec3<T> operator+(const _vec3<T>& a, const _vec3<T>& b) {
    return _vec3<T>(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
  }

  /*!
   * \brief Overloaded subtraction operator for subtracting two vectors.
   *
   * \param a First vector.
   * \param b Second vector.
   * \return A new vector that is the difference of the two input vectors.
   */
  friend _vec3<T> operator-(const _vec3<T>& a, const _vec3<T>& b) {
    return _vec3<T>(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
  }

  /*!
   * \brief Computes the dot product of two vectors.
   *
   * \f$ \vec{a} \cdot \vec{b} = a_x \cdot b_x + a_y \cdot b_y + a_z \cdot b_z \f$
   *
   * \param a First vector.
   * \param b Second vector.
   * \return The dot product of the two vectors.
   */
  friend T dot(const _vec3<T>& a, const _vec3<T>& b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  }

  /*!
   * \brief Computes the magnitude of a vector.
   *
   * \f$ |\vec{a}| = \sqrt{\vec{a} \cdot \vec{a}} \f$
   *
   * \param a Vector whose magnitude is to be computed.
   * \return The magnitude of the vector.
   */
  friend double mag(const _vec3<T>& a) {
    return sqrt(dot(a, a));
  }

  /*!
   * \brief Stream insertion operator for printing vector components.
   *
   * \param out Output stream.
   * \param a Vector to be printed.
   * \return The output stream with the vector components.
   */
  friend std::ostream& operator<<(std::ostream &out, const _vec3<T>& a) {
    out << a[0] << " " << a[1] << " " << a[2];
    return out;
  }

protected:
  T d[3]; //!< Array storing the X, Y, and Z components of the vector.
};

using double3 = _vec3<double>; //!< Alias for a vector with double precision components.

#endif
