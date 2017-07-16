#pragma once

void correlation_function(long double** map, unsigned int n, long double* function);

void correlation_function_with_mask(long double** map, int** mask, unsigned int n, long double* function);
