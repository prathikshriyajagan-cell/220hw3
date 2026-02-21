#include <criterion/criterion.h>
#include "MyBitManipulation.h"
#include "Myfloat.h"
#include "MyIntegers.h"

/* =========================
* PART 1: Bit Manipulation
* ========================= */

Test(ToggleBit, examples) {
   cr_assert_eq(ToggleBit(9, 0), 8);
   cr_assert_eq(ToggleBit(9, 3), 1);
}

Test(ToggleBit, edge_cases) {
   cr_assert_eq(ToggleBit(0, 5), 32);    
   cr_assert_eq(ToggleBit(15, 2), 11);   
   cr_assert_eq(ToggleBit(8, 0), 9);    
}

Test(GetMSB, examples) {
   cr_assert_eq(GetMSB(18), 4);
   cr_assert_eq(GetMSB(0), -1);
}

Test(GetMSB, edge_cases) {
   cr_assert_eq(GetMSB(1), 0);
   cr_assert_eq(GetMSB(7), 2);
   cr_assert_eq(GetMSB(16), 4);
   cr_assert_eq(GetMSB(255), 7);
}

Test(ClearBitRange, examples) {
   cr_assert_eq(ClearBitRange(73, 1, 3), 65);
}

Test(ClearBitRange, edge_cases) {
   cr_assert_eq(ClearBitRange(255, 0, 3), 240);
   cr_assert_eq(ClearBitRange(15, -1, 2), 15);  
   cr_assert_eq(ClearBitRange(15, 2, 1), 15);   
   cr_assert_eq(ClearBitRange(31, 0, 4), 0);
}

Test(RotateLeft, examples) {
   cr_assert_eq(RotateLeft(5, 1), 10);
   cr_assert_eq(RotateLeft(5, 2), 20);
}

Test(RotateLeft, edge_cases) {
   cr_assert_eq(RotateLeft(5, 0), 5);        
   cr_assert_eq(RotateLeft(1, 31), -2147483648); 
   cr_assert_eq(RotateLeft(8, 33), 16);         
}

Test(SwapOddEvenBits, examples) {
   cr_assert_eq(SwapOddEvenBits(23), 43);
}

Test(SwapOddEvenBits, edge_cases) {
   cr_assert_eq(SwapOddEvenBits(0), 0);
   cr_assert_eq(SwapOddEvenBits(1), 2);
   cr_assert_eq(SwapOddEvenBits(2), 1);
   cr_assert_eq(SwapOddEvenBits(15), 15);
}

/* =========================
* PART 2: IEEE 754 Float
* ========================= */

Test(ConstructFloat, positive_examples) {
   cr_assert_float_eq(construct_float_sf(0x00, 0x7F, 0x200000), 1.25, 0.00001);
   cr_assert_float_eq(construct_float_sf(0x00, 0x81, 0x300000), 5.5, 0.00001);
   cr_assert_float_eq(construct_float_sf(0x00, 0x76, 0x299B6F), 0.002588, 0.000001);
   cr_assert_float_eq(construct_float_sf(0x00, 0x89, 0xABCDEF), 1374.44, 0.01);
   cr_assert_float_eq(construct_float_sf(0x00, 0x90, 0x7973C0), 255439, 1.0);
}

Test(ConstructFloat, negative_examples) {
   cr_assert_float_eq(construct_float_sf(0x01, 0x7F, 0x200000), -1.25, 0.00001);
   cr_assert_float_eq(construct_float_sf(0x01, 0x81, 0x300000), -5.5, 0.00001);
   cr_assert_float_eq(construct_float_sf(0x01, 0x76, 0x299B6F), -0.002588, 0.000001);
   cr_assert_float_eq(construct_float_sf(0x01, 0x89, 0xABCDEF), -1374.44, 0.01);
   cr_assert_float_eq(construct_float_sf(0x01, 0x90, 0x7973C0), -255439, 1.0);
}

/* =========================
* PART 3: Integer Conversion
* ========================= */
/* NOTE:
* We do NOT test output matching here.
* Students are encouraged to visually inspect output.
* TAs will use stronger hidden tests.
*/

Test(ReprConvert, basic_run) {
   repr_convert('2', '2', 0x59f2ca50);
   repr_convert('S', '2', 0x80000000);
   repr_convert('S', '2', 0x80000001);
   repr_convert('2', 'S', 0xFFFFFFFF);
   repr_convert('2', 'S', 0x80000000);
   repr_convert('F', '2', 0x00394812);  
}