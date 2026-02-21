// Prathik Shriya Jagan, 116686482
#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>

void repr_convert(char source_repr, char target_repr, unsigned int repr) {
    if ((source_repr != '2' && source_repr != 'S') || (target_repr != '2' && target_repr != 'S')) {
		printf("error\n");
		return;
	} else if (source_repr == target_repr) {
		printf("%08x\n", repr);
		return;
	} else {
		unsigned int signBit = 1 << 31;
		unsigned int sign = repr & signBit;

		if (source_repr == 'S' && target_repr == '2') {
			if (sign == 0) {
				printf("%08x\n", repr); 
				return;
			} 
			unsigned int mag = repr & 0x7FFFFFFF;
			unsigned int twosComplimentMag = 1+(~mag);
			printf("%08x\n", twosComplimentMag);
			
		} else {
			if (repr == 0x80000000) {
				printf("undefined\n");
				return;
			}

			if (sign == 0){
				printf("%08x\n", repr);
				return;
			} 
			unsigned int mag = repr & 0x7FFFFFFF;
			unsigned int signRepMag = ~(mag -1);
			printf("%08x\n", signRepMag);
		}

	}
}
// int main(void) {
  

//     repr_convert('F', '2', 0x00394812);   // should be an error
//     repr_convert('2', 'X', 0x12345678);   // must be anerror

   
//     repr_convert('2', '2', 0x59f2ca50);   // 59f2ca50
//     repr_convert('2', '2', 0x00000000);   // 00000000
//     repr_convert('S', 'S', 0x80000001);   // 80000001

    
//     repr_convert('S', '2', 0x80000001);   // ffffffff (-1)
//     repr_convert('S', '2', 0x80000000);   // 00000000 
//     repr_convert('S', '2', 0x0000000A);   // 0000000a 

    
//     repr_convert('2', 'S', 0x80000000);   // undefined
//     repr_convert('2', 'S', 0xFFFFFFFF);   // 80000001 (-1)
//     repr_convert('2', 'S', 0xFFFFFFFB);   // 80000005 (-5)
//     repr_convert('2', 'S', 0x00000007);   // 00000007 (+7) remains unchanged

   
//     return 0;
// }