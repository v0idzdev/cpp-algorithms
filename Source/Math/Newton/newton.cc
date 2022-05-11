#include "newton.hh"

/**
 * @brief Finds the root of a single-input polynomial
 * 
 * @param function The single-input polynomial f(x) to find the root of
 * @return double  The x value of f(x) such that f(x) = 0
 */
double EquationSolver::FindRoot(double (*function)(double)) {
    double x = RandomDouble(-100, 100);
    double a = 0.00000001;

    for (int n = 0; n < accuracy; n++)
        x -= function(x) / GetDerivative(function, x, a);

    return x;
}

/**
 * @brief Generates a random double within a range
 * 
 * @param min     The minimum value that can be generated
 * @param max     The maximum value that can be generated
 * @return double The random double that was generated
 */
double EquationSolver::RandomDouble(double min, double max) {
    double x = (double)rand() / RAND_MAX;
    return min + x * (max - min);
}

/**
 * @brief Computes the gradient of f(x) at a given x
 * 
 * @param function The function f(x) to compute the gradient of
 * @param x        The x value of f(x) to get the gradient at
 * @param a        The accuracy; lower values yield greater precision
 * @return double  The approximated gradient at f(x)
 */
double EquationSolver::GetDerivative(double (*function)(double), double x, double a) {
    return function(x + a) - function(x) / a;  // Factor out x in (x + a) - x
}