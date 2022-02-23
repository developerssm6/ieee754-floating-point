/** @file ieee754.c
 *  @brief IEEE Floating Point Representation
 *
 *  Program to demonstrate IEEE floating point represation
 *  using static array
 *  
 *
 *  @author Siba Sankar Maharana (developessm6)
 *  @email developessm6@gmail.com
 */
 
#include<stdio.h>

/** @brief Convert integer to binary array
 *
 *  Converts an integer to binary array of given
 *  size
 *
 *  @param num Number to convert
 *  @param bin Array to store binary bits
 *  @param size Size of the binary array
 *  @return Void.
 */
void int_to_bin( int num, int bin[], int size);

/** @brief Convert fraction to binary array
 *
 *  Converts an fraction to binary array of given
 *  size
 *
 *  @param frac Fraction to convert
 *  @param bin Array to store binary bits
 *  @param size Size of the binary array
 *  @return Void.
 */
void frac_to_bin( float frac, int bin[], int size);

/** @brief Get Bias(excess)
 *
 *  Converts an integer to binary array of given
 *  size
 *
 *  @param exp_size Exponent Size of the ieee
 *  @return bias.
 */
int get_bias(int exp_size);

/** @brief number to IEEE754 format
 *
 *  Convert number to IEEE754 Floating Point
 *
 *  @param num Number to Convert
 *  @param ieee Store IEEE Floating Binary
 *  @return void.
 */
void ieee754_32(float num, int ieee[]);
void ieee754_64(float num, int ieee[]);

/** @brief Helper for array display
 *
 *  Helper function for print array
 *
 *  @param arr Array to print
 *  @param size Size of array
 *  @return void.
 */
void print_arr(int arr[], int size);

int main(void) {
	
	char value[50];
	float num=0.0;
	int ieee_32[32] = {0};
	
	printf("Enter a number : ");
	scanf("%s",value);
	
	if( sscanf(value,"%f",&num) ) {
		if(num) {
			ieee754_32(num, ieee_32);
		}
		printf("\nIEEE32 : ");
		print_arr(ieee_32,32);
		
	} else {
		printf("Please enter a valid decimal number !!");
	}
	
	return 0;
}

void int_to_bin( int num, int bin[], int size) {
	// integer to binary convertion
}

void frac_to_bin( float frac, int bin[], int size) {
	// fraction to binary convertion
}

int get_bias(int exp_size) {
	// return the bias value for the number
}

void ieee754_32(float num, int ieee[]) {
	int intpart = 0;
	float fracpart = 0.0;
	int intarr[32] = {0}, fracarr[32] = {0};
	int mantissa[23] = {0}, exponent[8] = {0};
	int sign = 0;
	int i,j,k;
	int size = 32;
	int exp_size = 8, mantissa_size = 23;
	int bias = 127;
	
	int exp0=0,exp1=0;
	
	if ( num < 0.0 ) {
		num = num * -1;
		sign = 1;
	}
	
	intpart = num;
	int_to_bin(intpart, intarr, size);
	
	fracpart = num - intpart;
	frac_to_bin(fracpart, fracarr, size);
	
	if ( intpart != 0 ) {
		// find exp in intpart
    // copy remaining intpart bits to mantissa
		
		if (fracpart != 0.0 ) {
			// copy fraction part bits to mantissa
		}
		
	} else {
		// find exp in fraction part
    // copy remaining fraction part bits to mantissa
	}
	
	exp1 = exp0+bias;
	int_to_bin(exp1,exponent,exp_size);
	
	ieee[0] = sign;
	for ( k= 1, j = 0; j < exp_size; j++, k++ ){
		ieee[k] = exponent[j];
	}
	for ( j = 0; j < mantissa_size; j++, k++ ){
		ieee[k] = mantissa[j];
	}
}

void ieee754_64(float num, int ieee[]) {
  // write code for 64 bit 
}

void print_arr(int arr[], int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		printf("%d",arr[i]);
	}
}
