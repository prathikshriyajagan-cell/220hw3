// Prathik Shriya Jagan, 116686482
#include "Myfloat.h"
#include <stdio.h>

float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int floatValues = 0;

   unsigned int exponentBit = 0xFF;
   unsigned int expBitPos = (exponent & exponentBit) << 23;

   unsigned int signBit = (sign_bit & 0x01);
   unsigned int signBitPos = signBit << 31;
    
   unsigned int fractionBit = 0xFFFFFFFF;
   unsigned int fracBitPos = (fraction & fractionBit);

   floatValues = signBitPos | expBitPos | fracBitPos;

   return *(float *)&floatValues;
}
// int main(void) {
//     // 1. +5.5
//     printf("f = %g\n", construct_float_sf(0x00, 0x81, 0x300000));  // 5.5

//     // 2. -5.5
//     printf("f = %g\n", construct_float_sf(0x01, 0x81, 0x300000));  // -5.5

//     // 3. +1.25
//     printf("f = %g\n", construct_float_sf(0x00, 0x7F, 0x200000));  // 1.25

//     // 4. -1.25
//     printf("f = %g\n", construct_float_sf(0x01, 0x7F, 0x200000));  // -1.25

//     // 5. +0.002588
//     printf("f = %g\n", construct_float_sf(0x00, 0x76, 0x299B6F));  // 0.002588

//     // 6. -0.002588
//     printf("f = %g\n", construct_float_sf(0x01, 0x76, 0x299B6F));  // -0.002588

//     // 7. +1374.44
//     printf("f = %g\n", construct_float_sf(0x00, 0x89, 0xABCDEF));  // 1374.44

//     // 8. -1374.44
//     printf("f = %g\n", construct_float_sf(0x01, 0x89, 0xABCDEF));  // -1374.44

//     // 9. +255439
//     printf("f = %g\n", construct_float_sf(0x00, 0x90, 0x7973C0));  // 255439

//     // 10. -255439
//     printf("f = %g\n", construct_float_sf(0x01, 0x90, 0x7973C0));  // -255439

//     return 0;
// }
