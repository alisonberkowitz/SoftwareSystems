#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int numer;
    int denom;
} Rational;

// Returns a new Rational with the given numer and denom.
// If unable to allocate, prints an error message and exits.
Rational *make_rational(int numer, int denom) {
    Rational *r = malloc(sizeof(Rational));
    r->numer = numer;
    r->denom = denom;
    return r;
}

// Computes a floating-point approximation of a Rational.
double rational_to_double(Rational *rational) {
    float n = rational->numer;
    float d = rational->denom;
    double x = n/d;
    return x;
}

// Multiplies two rational numbers; returns a new Rational.
Rational *mult_rational(Rational *r1, Rational *r2) {
    int nums = (r1->numer)*(r2->numer);
    int dens = (r1->denom)*(r2->denom);
    if (dens%nums == 0){
        nums = 1;
        dens = dens/nums;
    }
    Rational *r = make_rational(nums,dens);
    return r;
}

// Frees a Rational.
void free_rational(Rational *rational) {
    free(rational);
}

// Prints a rational in fraction form.
void print_rational(Rational *rational) {
    printf("%d / %d\n", rational->numer, rational->denom);
}

int main(void)
{
    Rational *rational = make_rational(3, 7);
    print_rational(rational);

    double d = rational_to_double(rational);
    printf("%lf\n", d);

    Rational *square = mult_rational(rational, rational);
    print_rational(square);
	
    free_rational(rational);
    free_rational(square);

    return EXIT_SUCCESS;
}
