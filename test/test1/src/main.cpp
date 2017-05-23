#include <iostream>
#include <random>
#include "utils.hpp"
#include "parameters.hpp"
#include "io.hpp"
#include "aml.hpp"
#include "fft.hpp"

int main() {

    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

    typedef std::numeric_limits<long double> dbl;
    std::cout.precision(dbl::max_digits10);

    long double** map = n_matrix_generator(npix + 1, npix / 2 + 1);
    long double** cos_ml = n_matrix_generator(nmod, nmod);
    long double** sin_ml = n_matrix_generator(nmod, nmod);

    aml_gasdev(generator, cos_ml, sin_ml, 0.0l, 1.0l);

    fft_map_forward(map, cos_ml, sin_ml);

    o_map("../data/map.dat", map);

    n_matrix_destroyer(map, npix + 1);

    return 0;
}