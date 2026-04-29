/*
    Spectral analysis of systems using only real signals.
    Educational C code, not at all efficient, but hopefully readable and simple.
    Latest version available at: https://ecomaan.nl/c/
    COPYLEFT 2025 march 3 - Pieter Suurmond.

    Compile with:
                 cc -Wall real_spectrum_analyzer.c -lm -o real_spectrum_analyzer
    Run with:                                      ---
             ./real_spectrum_analyzer
*/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>    /* Also link with math library during compilation (-lm)! */
#include <iostream>

using namespace std;



/* System to be examined: Direct form

Difference equation
y[n] = a0*x(n) + a1*x(n-1) + a2*x(n-2) - b1*y(n-1) - b2*y(n-2)

In code:
y = a0*x + a1*xn_1 + a2*xn_2 - b1*yn_1 - b2*yn_2
*/

float sys (float x) {
  /* Private memory, inaccessable from outside.
  Reset at compile time but remembered between calls. */

  float coefficients[] = {
    2.08255,
    -1.58671,
    -0.0825479,
    1.34233,
    -1.58671,
    0.657668};

// Coefficients
  static float a0 = coefficients[0]; // Gain
  static float a1 = coefficients[1];
  static float a2 = coefficients[2];
  static float b0 = coefficients[3];
  static float b1 = coefficients[4];
  static float b2 = coefficients[5];
// Stored samples
  static float xn_1 = 0.0f;
  static float xn_2 = 0.0f;
  static float yn_1 = 0.0f;
  static float yn_2 = 0.0f;
// Output
  float y = (a0/b0)*x + (a1/b0)*xn_1 + (a2/b0)*xn_2 - (b1/b0)*yn_1 - (b2/b0)*yn_2;

  xn_2 = xn_1;
  xn_1 = x;
  yn_2 = yn_1;
  yn_1 = y;

  return y;

}

float sys_id (float x) /* Identity system to test this software: y[n] = x[n]. */
{
    return x;
}

/* Time domain analysis. */
void plot_impulse_response ()
{
    int     n;
    float   x, y ,c;

    printf(" time        Impulse response:\n");
    for (n = -2; n < 11; ++n) /* Discrete time. */
        {
        if (n)
            x = 0.0;
        else
            x = 1.0;         /* Unit sample (delta function) as input signal. */

        y = sys(x);

        printf("%4d:%5.2f   ", n, y);  /* Plot bipolar y-value. Bar of stars. */
        for (c = -1.0; (c < y) && (c < 0); c += 0.04)
            putchar(' ');
        putchar('*');
        for (; (c < 0); c += 0.04)
            putchar('*');
        for (; (y >= 0.04); y -= 0.04)
            putchar('*');
        putchar('\n');
        }
}

/* Frequency domain analysis. */
void plot_spectrum ()
{
    const float PI = 4.0 * atan(1);
    const int   num_freqs = 29;   /* A large prime number gives best results. */
    int         n, f;

    printf(" freq        Amplitude spectrum:\n");
    for (f = 0; f <= num_freqs; ++f)  /* From 0 Hz up to (inclusive) Nyquist. */
        {
        float step = PI * (float)f / (float)num_freqs;
        float peak = 0.0;

        /* Drain the system: feed some silence to clear its internal memory. */
        for (n = 0; n <= 10; ++n)
            sys(0.0);

        /* Peak-measure each test-frequency during some time (128 samples). */
        for (n = 0; n < 128; ++n)
            {
            float x = cos(step * (float)n);          /* Cosinewave generator. */

            float y = fabs( sys(x) );                  /* Floating-point abs. */

            if ((n > 10) && (y > peak))           /* Ignore first 10 samples. */
                peak = y;
            }
        printf("%.2f: %.2f   ", (float)f / (float)num_freqs, peak);
        do {
            putchar('*');
            peak -= 0.02;
            } while (peak >= 0.0);
        putchar('\n');
        }
}

int main()
{
  cout << "output: " << endl;
  plot_impulse_response();
  cout << endl;
  plot_spectrum();
  putchar('\n');
  return 0;
}
