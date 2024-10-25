#include "gtest/gtest.h"
#include "vec.h"

/*!
 * \brief Test Case 1: Simple test for the dot product function.
 */
TEST(VecTest, VecDot) {
    double3 a{0, 1, 2};
    double3 b{0, 0, 1};
    
    EXPECT_EQ(dot(a, b), 2);  // Test the dot product
}

/*!
 * \brief Test Fixture: vecTestClass
 *
 * This test fixture holds vectors `a` and `b` and flags to check addition and subtraction.
 */
class vecTestClass : public ::testing::Test {
protected:
    double3 a;  // Vector a
    double3 b;  // Vector b
    bool add_matches;  // Check if addition matches expected result
    bool sub_matches;  // Check if subtraction matches expected result

    /*!
     * \brief Constructor initializes vectors.
     */
    vecTestClass() : a{0, 1, 2}, b{0, 0, 1}, add_matches(false), sub_matches(false) {}

    /*!
     * \brief SetUp function runs before each test.
     *
     * Sets up the test data and checks vector addition and subtraction.
     */
    void SetUp() override {
        // Test vector addition
        double3 c = a + b;
        add_matches = true;  // Assume addition is correct
        for (int i = 0; i < 3; i++) {
            if (c[i] != a[i] + b[i]) {
                add_matches = false;  // Mark as false if any component doesn't match
            }
        }

        // Test vector subtraction
        double3 d = a - b;
        sub_matches = true;  // Assume subtraction is correct
        for (int i = 0; i < 3; i++) {
            if (d[i] != a[i] - b[i]) {
                sub_matches = false;  // Mark as false if any component doesn't match
            }
        }
    }

    /*!
     * \brief TearDown function runs after each test.
     *
     * This is optional in this case, no cleanup is necessary.
     */
    void TearDown() override {
        // No specific cleanup needed
    }
};

/*!
 * \brief Test Case 2, Test 1: Test vector addition using the fixture.
 */
TEST_F(vecTestClass, VecAdd) {
    EXPECT_EQ(add_matches, true);  // Check if vector addition passed
}

/*!
 * \brief Test Case 2, Test 2: Test vector subtraction using the fixture.
 */
TEST_F(vecTestClass, VecSub) {
    EXPECT_EQ(sub_matches, true);  // Check if vector subtraction passed
}

/*!
 * \brief Main function for running all tests.
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
