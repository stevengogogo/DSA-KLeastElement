/**
 * @file utils.h
 * @author Shao-Ting Chiu (r07945001@ntu.edu.tw)
 * @brief General Utilities for C language
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef UTILS_H
#define UTILS_H

#include <assert.h>

/** * QuickSort. Reference: This function is modified from https://openhome.cc/Gossip/AlgorithmGossip/QuickSort3.htm#C */
void quicksort(int arr[], int left, int right);

/** * Combine fragments. This function is modifed from: https://openhome.cc/Gossip/AlgorithmGossip/QuickSort3.htm#C */
int partition(int number[], int left, int right);

/** * Switch the value store in `x` and `y`. */
void swap(int* x, int* y);

/** @brief Insert a value in an array with a iven length.
 *  @warning The arr[length-1] is the place holder, and will be replaced.
 *  @note i_ means the index starts at 0.
 *  @param arr array to be inserted
 *  @param i_ the position to be inserted, starts at 0 -> (length - 1)
 *  @param x the value to be inserted.
 *  @param length length of an array, the last element arr[length-1] is the place holder for the new value.
 *  @return the number of relocations
 */
int insert_arr(int arr[], int i_, int x, int length);

/** * Insert a value at the end of the array*/
void append_arr(int arr[], int x, int length);
/** * Remove arr[i] and shift one step to the left [i,end]*/
void remove_arr(int arr[], int i, int length);
/** * Reverse array in given region [str, end]*/
void reverse_arr(int arr[], int str, int end);
/** * Compare two arrays
 * @return 0: Different; 1:same in the given length
 */
int compare_array(int A[], int B[], int length);


/**
 * @brief Find the minimum i which fullfills arr[i] > key.
 * @warning If all arr[i] < key. Return length-1
 * @param arr 
 * @param length 
 * @param key 
 * @return @i_. 
 * @note This function is inspired by [GreekforGeek](https://www.geeksforgeeks.org/first-strictly-greater-element-in-a-sorted-array-in-java/)
 */
int BinarySearch_MinBigger(int* arr, int length, int key);


#endif