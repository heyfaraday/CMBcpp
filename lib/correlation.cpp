
#include <math.h>

#include "correlation.hpp"

#include "parameters.hpp"
#include "distance.hpp"
#include "constants.hpp"
#include "utils.hpp"


void correlation_function(long double** map, unsigned int n, long double* function) {

    // здесь создать массив с номрировкой для каждого r
    // потестить для абсолютного рандома и гаусса и для разного кол-ва гармоник

    long double* norm = n_vector_generator(n);

    long double two_point_distance = 0.0l;

    for (unsigned int i_first_point = 0; i_first_point < npix; ++i_first_point) {
        for (unsigned int j_first_point = 1; j_first_point < npix / 2; ++j_first_point) {
            for (unsigned int i_second_point = i_first_point; i_second_point < npix; ++i_second_point) {
                for (unsigned int j_second_point = j_first_point; j_second_point < npix / 2; ++j_second_point) {

                    two_point_distance = s2(map_parameter * i_first_point, map_parameter * i_second_point,
                                            map_parameter * j_first_point, map_parameter * j_second_point);

                    function[static_cast<unsigned int>((two_point_distance / PI * n))] +=
                            map[i_first_point][j_first_point] * map[i_second_point][j_second_point];

                    norm[static_cast<unsigned int>((two_point_distance / PI * n))] += 1;
                }
            }
        }
    }

    for (unsigned int i = 0; i < n; ++i) {
        function[i] /= norm[i];
    }

    n_vector_destroyer(norm);

}


void correlation_function_with_mask(long double** map, int** mask, unsigned int n, long double* function) {

    long double* norm = n_vector_generator(n);

    long double two_point_distance = 0.0l;

    for (unsigned int i_first_point = 0; i_first_point < npix; ++i_first_point) {
        for (unsigned int j_first_point = 1; j_first_point < npix / 2; ++j_first_point) {

            if (mask[i_first_point][j_first_point] != 0) {

                for (unsigned int i_second_point = i_first_point; i_second_point < npix; ++i_second_point) {
                    for (unsigned int j_second_point = j_first_point; j_second_point < npix / 2; ++j_second_point) {

                        if (mask[i_second_point][j_second_point] != 0) {

                            two_point_distance = s2(map_parameter * i_first_point, map_parameter * i_second_point,
                                                    map_parameter * j_first_point, map_parameter * j_second_point);

                            function[static_cast<unsigned int>((two_point_distance / PI * n))] +=
                                    map[i_first_point][j_first_point] * map[i_second_point][j_second_point];

                            norm[static_cast<unsigned int>((two_point_distance / PI * n))] += 1;
                        }
                    }
                }
            }
        }
    }

    for (unsigned int i = 0; i < n; ++i) {
        function[i] /= norm[i];
    }

    n_vector_destroyer(norm);

}
