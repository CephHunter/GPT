#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>


typedef struct fpb_t
{
    unsigned int mantisse:23;
    unsigned int exp:8;
    unsigned int sign:1;
} fpb_t;

typedef union fpu_t
{
    fpb_t bits;
    float value;
} fpu_t;

void binprintfloat(fpu_t v) {
    int lengths[3] = {1, 8, 23};
    unsigned int values[3] = {v.bits.sign, v.bits.exp, v.bits.mantisse};
    for (int i = 0; i < 3; i++) {
        unsigned int mask = 1 << (lengths[i] - 1);
        while(mask) {
            printf("%d", ((values[i] & mask) ? 1 : 0));
            mask >>= 1;
        }
        printf(" ");
    }
    printf("\n");
}

fpu_t sum(fpu_t num1, fpu_t num2) {
    fpu_t res;
    int mantisseSmall;
    int mantisseLarge;

    if (num1.bits.exp < num2.bits.exp || (num1.bits.exp == num2.bits.exp && num1.bits.mantisse < num2.bits.mantisse)) {
        mantisseSmall = 0x00800000 | num1.bits.mantisse;
        mantisseLarge = 0x00800000 | num2.bits.mantisse;
        res.bits.exp = num2.bits.exp;
        res.bits.sign = num2.bits.sign;
    } else {
        mantisseSmall = 0x00800000 | num2.bits.mantisse;
        mantisseLarge = 0x00800000 | num1.bits.mantisse;
        res.bits.exp = num1.bits.exp;
        res.bits.sign = num1.bits.sign;
    }

    mantisseSmall >>= abs(num1.bits.exp - num2.bits.exp);
    mantisseLarge += (num1.bits.sign ^ num2.bits.sign ? -1 : 1) * mantisseSmall;
    if (num1.bits.sign ^ num2.bits.sign) {
        while (!(mantisseLarge & 0x00800000) && res.bits.exp != 0) {
            mantisseLarge <<= 1;
            res.bits.exp--;
        }
    } else {
        if (mantisseLarge & 0x01000000)
            res.bits.exp++;
    }
    res.bits.mantisse = mantisseLarge;

    if (res.bits.exp == 0)
        res.bits.sign = 0;

    return res;
}

fpu_t substract(fpu_t num1, fpu_t num2) {
    num2.bits.sign = !num2.bits.sign;
    return sum(num1, num2);
}

int main()
{
    fpu_t fpu1;
    fpu_t fpu2;
    fpu1.value = -1;
    fpu2.value = 1;

//    int value = 0x00800000 | fpu1.bits.mantisse;    // Bits worden omgekeerd voorgesteld (MSB first): 1010000... = 5
//    printf("teken: %d\nexp: %d\nmantisse: %d\nbinvalue: %d\n", fpu1.bits.sign, fpu1.bits.exp, value, fpu1.bits.mantisse);
    printf("num 1: ");
    binprintfloat(fpu1);
    printf("num 2: ");
    binprintfloat(fpu2);

    fpu_t fpu3 = sum(fpu1, fpu2);
    printf("num 3: ");
    binprintfloat(fpu3);
    printf("value: %f\n", fpu3.value);

    fpu_t fpu4 = substract(fpu1, fpu2);
    printf("num 4: ");
    binprintfloat(fpu4);
    printf("value: %f\n", fpu4.value);

    return 0;
}

















