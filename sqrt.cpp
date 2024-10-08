// sqrt using newton rapson method
double sqrt_newton(double n){
  const double eps = 1E-15;
  double x = 1;
  for (;;)
  {
    double nx = (x + n / x) / 2;
    if (abs(x - nx) < eps)
      break;
    x = nx;
  }
  return x;
}
