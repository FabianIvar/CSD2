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

/* System to be examined:  difference equation  y[n] = 0.6 x[n] - 0.4 x[n-1]. */
float sys (float x)
{
    static float x1 = 0.0;   /* Private memory, inaccessable from outside. Reset
                                at compile time but remembered between calls. */
    static float x2 = 0.0;
    static float x3 = 0.0;

    static float y1 = 0.0;
    static float y2 = 0.0;

    //static float xxxx = 0.0; //n-3

    float y = 0.5 * x + 0.5 * x1 + 0.5 * x2 + 0.4 * y1 + 0.4 * y2;
    x2 = x1;
    x1 = x;
    y2 = y1;
    y1 = y;
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
    printf("System  y[n] = 0.6 x[n] - 0.4 x[n-1]\n");
    plot_impulse_response();
    plot_spectrum();
    putchar('\n');
    return 0;
}