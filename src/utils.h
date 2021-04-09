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


/** * QuickSort. Reference: This function is modified from https://openhome.cc/Gossip/AlgorithmGossip/QuickSort3.htm#C */
void quicksort(int arr[], int left, int right);

/** * Combine fragments. This function is modifed from: https://openhome.cc/Gossip/AlgorithmGossip/QuickSort3.htm#C */
int partition(int number[], int left, int right);

/** * Switch the value store in `x` and `y`. */
void swap(int* x, int* y);


#endif