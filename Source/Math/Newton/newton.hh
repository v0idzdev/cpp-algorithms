#ifndef NEWTON_H
#define NEWTON_H

#include <iostream>

class EquationSolver {
  public:
    EquationSolver(int accuracy) : accuracy(accuracy) {};
    double FindRoot(double (*function)(double));

  private:
    double RandomDouble(double min, double max);
    double GetDerivative(double (*function)(double), double x, double a);
    const int accuracy;
};

#endif /* NEWTON_H */