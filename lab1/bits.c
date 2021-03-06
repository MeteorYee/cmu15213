/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */
#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s comp_1, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) { return ~(~(x & ~y) & ~(~x & y)); }
/*
 * tmin - return minimum two's comp_1 integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) { return (1 << 31); }
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's comp_1 number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) { return !((x ^ ~(x + 1)) + !(x + 1)); }
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = (0xaa << 24) + (0xaa << 16) + (0xaa << 8) + 0xaa;
  return !((x & mask) ^ mask);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) { return (~x + 1); }
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0'
 * to '9') Example: isAsciiDigit(0x35) = 1. isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int v1 = !((x | 0x7) ^ 0x37);
  int v2 = !(x ^ 0x38);
  int v3 = !(x ^ 0x39);
  return (v1 | v2 | v3);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int choose_left = ((!!x) << 31) >> 31; /* x == 0 ? 0 : -1 */
  int choose_right = ((!x) << 31) >> 31; /* x == 0 ? -1 : 0 */
  return (choose_left & y) | (choose_right & z);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int y_minus_x = y + (~x + 1);
  int result_is_non_negative = !(y_minus_x >> 31);
  int x_is_non_negative = !(x >> 31);
  int y_is_non_negative = !(y >> 31);
  return (x_is_non_negative & y_is_non_negative & result_is_non_negative) |
         ((!x_is_non_negative) & (!y_is_non_negative) &
          result_is_non_negative) |
         ((!x_is_non_negative) & y_is_non_negative);
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
  /* Naive approach, binary search
  int low_16_bits = x | (x >> 16);
  int low_8_bits = low_16_bits | (low_16_bits >> 8);
  int low_4_bits = low_8_bits | (low_8_bits >> 4);
  int low_2_bits = low_4_bits | (low_4_bits >> 2);
  int lowest_bit = low_2_bits | (low_2_bits >> 1);
  return (lowest_bit + 1) & 1;
  */
  /* +0 and -0 have got the same sign bit, this is the crux! */
  return ~((x | (~x + 1)) >> 31) & 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's comp_1
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /* We can't use abs, whereas we need 1's complement. */
  int sign = x >> 31;
  int comp_1 = (sign & ~x) | (~sign & x);
  int bit0, bit1, bit2, bit4, bit8, bit16;

  bit16 = (!!(comp_1 >> 16)) << 4;
  comp_1 = comp_1 >> bit16;
  bit8 = (!!(comp_1 >> 8)) << 3;
  comp_1 = comp_1 >> bit8;
  bit4 = (!!(comp_1 >> 4)) << 2;
  comp_1 = comp_1 >> bit4;
  bit2 = (!!(comp_1 >> 2)) << 1;
  comp_1 = comp_1 >> bit2;
  bit1 = !!(comp_1 >> 1);
  comp_1 = comp_1 >> bit1;
  bit0 = comp_1;
  return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned exponent_bit, exponent_mask, exponent;
  if ((uf & ~(1u << 31)) == 0) {
    /* zero (positive or negative) */
    return uf;
  }
  exponent_bit = 1u << 23;
  exponent_mask = 0xffu << 23;
  exponent = uf & exponent_mask;
  if (exponent == exponent_mask || (exponent + exponent_bit) > exponent_mask) {
    /* infinity or NaN */
    return uf;
  }
  if (exponent == 0u) {
    /* denormalized, just double the fraction part, it'll change to the
     * normalized version smoothly if it applies */
    return uf + (uf & (exponent_bit - 1u));
  }
  return uf + exponent_bit;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned tmin = (1u << 31);
  unsigned exponent_bit = (1u << 23);
  unsigned exponent_mask = (0xffu << 23);
  unsigned exponent = uf & exponent_mask;
  unsigned bias = (0x7fu << 23);
  unsigned fraction = uf & (exponent_bit - 1);
  unsigned scale;
  int result;
  if (exponent == exponent_mask) {
    /* infinity or NaN */
    return tmin;
  }
  if (exponent < bias) {
    /* zero */
    return 0;
  }
  scale = (exponent - bias) >> 23;
  if (scale > 30) {
    /* out of range */
    return tmin;
  }
  result = exponent_bit | fraction;
  if (scale > 23) {
    result <<= (scale - 23);
  } else {
    result >>= (23 - scale);
  }
  if ((uf & tmin) != 0) {
    /* negative */
    return -result;
  } else {
    return result;
  }
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  if (x < -149) {
    /* too small */
    return 0;
  } else if (x > 127) {
    /* +inf */
    return (0xff << 23);
  } else if (x >= -126) {
    /* norm */
    return (x + 127) << 23;
  } else {
    /* -149 <= x < -126, a denorm */
    return 1 << (149 + x);
  }
}
