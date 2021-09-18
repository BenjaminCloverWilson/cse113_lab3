/**
 * @file array.h
 * 
 * @author Benjamin Wilson
 *
 * @date September 15, 2021
 *  
 * Assignment: Lab 3 
 *
 * @brief header file for array.c
 *
 * @details see array.c for details
 *  
 * @bugs none
 *
 * @todo add floating point versions of the functions
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h> 		/* for size_t declaration */

/* function declarations go here */
void print_array(int a[], size_t size);
int find_max(int a[], size_t size);
int find_min(int a[], size_t size);
int midpoint(int min, int max);
int get_count(int a[], size_t size, int type, int x);
int linear_search(int a[], size_t size, int x);
int sum_ele(int a[], size_t size);
double avg_ele(size_t size, int sum);
void reverse(int a[], size_t size);
void sort(int a[], size_t size);
int median_ele(int a[], size_t size);
int count_even(int a[], size_t size);
int count_odd(int a[], size_t size);
int divisible_count(int a[], size_t size, int x);

/* #define stuff here */
#define LT 0 /* Less than */
#define LE 1 /* Less or equal to */
#define GT 2 /* Greater than */
#define GE 3 /* Greater or equal to */
#define E 4 /* Equal to */


#endif

