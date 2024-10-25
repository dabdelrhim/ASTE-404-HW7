#include <iostream>
#include "vec.h"

/*!
 * \brief Main function that demonstrates vector operations.
 *
 * This function initializes two vectors, computes their subtraction and dot product,
 * and prints the results.
 *
 * \return 0 if the program completes successfully.
 */
int main() {
  double3 a{0, 1, 2}; //!< Vector a with components (0, 1, 2).
  double3 b{0, 0, 1}; //!< Vector b with components (0, 0, 1).

  // Print the result of vector subtraction
  std::cout << "a - b = " << a - b << std::endl;
  
  // Print the result of the dot product
  std::cout << "dot(a, b) = " << dot(a, b) << std::endl;

  return 0;
}
