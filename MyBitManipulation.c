// Prathik Shriya Jagan, 116686482
#include "MyBitManipulation.h"
#include <stdio.h>

/*
* Toggle the bit at position pos in num
*/
int ToggleBit(int num, int pos) {
   if (pos > 31 || pos < 0) {
        return num;
    }
	int positionBit = 1 << pos;
	num = num ^ positionBit;
   return num;
}

/*
* Return the position of the most significant set bit
* Return -1 if num == 0
*/
int GetMSB(int num) {
   if (num == 0) {
		return -1;
	}

	int pos = 0;
   unsigned int numberCopy = (unsigned int) num;

	while (numberCopy > 1) {
		++pos;
		numberCopy = numberCopy >> 1;
	}

	return pos;
}

/*
* Clear bits from start to end (inclusive)
*/
int ClearBitRange(int num, int start, int end) {
    
	if (start < 0 || end > 31 || (start > end) || start > 31 || end < 0) {
		return num;
	}

	int i = start;
   while(i <= end){
      num &= ~(1 << i);
      i++;
   }

   return num;
}

/*
* Rotate num to the left by d bits
*/
int RotateLeft(int num, int d) {
   if (d == 0 ) {
      return num;
   }
     d %= 32;

    unsigned int wrappedNum = (unsigned int)num >> (32 - d);
    unsigned int shiftedNum = (unsigned int)num << d;

    num =  (int)(shiftedNum | wrappedNum);


   return num;
}

/*
* Swap odd and even bits
*/
int SwapOddEvenBits(int num) {
    unsigned int even_bits = (num & 0xAAAAAAAA) >> 1;
    unsigned int odd_bits = (num & 0x55555555) << 1;

   num = (int)(even_bits | odd_bits);
   return num;
}

// int main(void){
//    printf("\nTesting ToggleBit (More Cases)\n");
//    printf("ToggleBit(10, 1) = %d (expected: 8)\n", ToggleBit(10, 1));  
//    printf("ToggleBit(4, 2) = %d (expected: 0)\n", ToggleBit(4, 2));   
//    printf("ToggleBit(0, 0) = %d (expected: 1)\n", ToggleBit(0, 0));   
//    printf("ToggleBit(32, 5) = %d (expected: 0)\n", ToggleBit(32, 5)); 
//    printf("ToggleBit(7, 1) = %d (expected: 5)\n", ToggleBit(7, 1));  

//    printf("\nTesting GetMSB (More Cases)\n");
//    printf("GetMSB(2) = %d (expected: 1)\n", GetMSB(2));
//    printf("GetMSB(3) = %d (expected: 1)\n", GetMSB(3));
//    printf("GetMSB(8) = %d (expected: 3)\n", GetMSB(8));
//    printf("GetMSB(1024) = %d (expected: 10)\n", GetMSB(1024));
//    printf("GetMSB(31) = %d (expected: 4)\n", GetMSB(31));

//    printf("\nTesting ClearBitRange (More Cases)\n");
//    printf("ClearBitRange(63, 0, 5) = %d (expected: 0)\n", ClearBitRange(63, 0, 5));
//    printf("ClearBitRange(100, 2, 4) = %d (expected: 96)\n", ClearBitRange(100, 2, 4));
//    printf("ClearBitRange(255, 4, 7) = %d (expected: 15)\n", ClearBitRange(255, 4, 7));
//    printf("ClearBitRange(8, 3, 3) = %d (expected: 0)\n", ClearBitRange(8, 3, 3));
//    printf("ClearBitRange(18, 1, 1) = %d (expected: 16)\n", ClearBitRange(18, 1, 1));

//    printf("\nTesting RotateLeft (More Cases)\n");
//    printf("RotateLeft(2, 1) = %d (expected: 4)\n", RotateLeft(2, 1));
//    printf("RotateLeft(4, 2) = %d (expected: 16)\n", RotateLeft(4, 2));
//    printf("RotateLeft(1, 0) = %d (expected: 1)\n", RotateLeft(1, 0));
//    printf("RotateLeft(16, 4) = %d (expected: 256)\n", RotateLeft(16, 4));
//    printf("RotateLeft(-2, 1) = %d (expected: -3)\n", RotateLeft(-2, 1));

//    printf("\nTesting SwapOddEvenBits (More Cases)\n");
//    printf("SwapOddEvenBits(10) = %d (expected: 5)\n", SwapOddEvenBits(10));
//    printf("SwapOddEvenBits(5) = %d (expected: 10)\n", SwapOddEvenBits(5));
//    printf("SwapOddEvenBits(255) = %d (expected: 255)\n", SwapOddEvenBits(255));
//    printf("SwapOddEvenBits(128) = %d (expected: 64)\n", SwapOddEvenBits(128));
//    printf("SwapOddEvenBits(64) = %d (expected: 128)\n", SwapOddEvenBits(64));

// 	return 0;
// }