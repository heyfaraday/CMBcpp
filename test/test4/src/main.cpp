#include <iostream>
#include <fstream>
#include <random>

#include "utils.hpp"
#include "parameters.hpp"
#include "correlation.hpp"
#include "aml.hpp"
#include "fft.hpp"
#include "io.hpp"

int main(){

    std::default_random_engine generator
            (static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));

    typedef std::numeric_limits<long double> dbl;
    std::cout.precision(dbl::max_digits10);

    long double** map = n_matrix_generator(npix + 1, npix / 2 + 1);
    long double** cos_ml = n_matrix_generator(nmod, nmod);
    long double** sin_ml = n_matrix_generator(nmod, nmod);

    aml_gasdev(generator, cos_ml, sin_ml, 0.0l, 1.0l);

    i_aml("../../test1/data/alm_Q_nilc_cos.dat", cos_ml);
    i_aml("../../test1/data/alm_Q_nilc_sin.dat", sin_ml);

    fft_map_forward(map, cos_ml, sin_ml);

    long double* graphic = n_vector_generator(70);

    correlation_function(map, 64, graphic);

    for (int i = 0; i < 64; ++i) {
        std::cout << i << " " << graphic[i] << std::endl;
    }

    std::ofstream out_file;
    out_file.open("correlation.dat");

    typedef std::numeric_limits<long double> dbl;

    out_file.precision(dbl::max_digits10);

    for (unsigned int l = 0; l < 64; ++l) {
        out_file << l << "  "
                 << std::scientific << graphic[l] << std::endl;
    }

    out_file.close();

    return 0;
}
