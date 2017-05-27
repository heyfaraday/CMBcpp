#include <iostream>
#include <random>
#include "utils.hpp"
#include "parameters.hpp"
#include "functionals.hpp"
#include "io.hpp"
#include "aml.hpp"
#include "fft.hpp"

int main() {

    std::default_random_engine generator
            (static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));

    typedef std::numeric_limits<long double> dbl;
    std::cout.precision(dbl::max_digits10);

    long double** map = n_matrix_generator(npix + 1, npix / 2 + 1);
    long double** map_x = n_matrix_generator(npix + 1, npix / 2 + 1);
    long double** map_y = n_matrix_generator(npix + 1, npix / 2 + 1);
    long double** map_xx = n_matrix_generator(npix + 1, npix / 2 + 1);
    long double** map_yy = n_matrix_generator(npix + 1, npix / 2 + 1);
    long double** map_xy = n_matrix_generator(npix + 1, npix / 2 + 1);
    long double** q = n_matrix_generator(npix + 1, npix / 2 + 1);
    long double** u = n_matrix_generator(npix + 1, npix / 2 + 1);
    long double** p = n_matrix_generator(npix + 1, npix / 2 + 1);
    int** whitelist = n_int_matrix_generator(npix + 1, npix / 2 + 1);
    long double** cos_ml = n_matrix_generator(nmod, nmod);
    long double** sin_ml = n_matrix_generator(nmod, nmod);

    aml_gasdev(generator, cos_ml, sin_ml, 0.0l, 1.0l);

    fft_map_forward(map, cos_ml, sin_ml);
    fft_map_x_forward(map_x, cos_ml, sin_ml);
    fft_map_y_forward(map_y, cos_ml, sin_ml);
    fft_map_xx_forward(map_xx, cos_ml, sin_ml);
    fft_map_yy_forward(map_yy, cos_ml, sin_ml);
    fft_map_xy_forward(map_xy, cos_ml, sin_ml);

    for (unsigned int i = 0; i < npix + 1; ++i) {
        for (unsigned int j = 0; j < npix / 2 + 1; ++j) {
            q[i][j] = map_xx[i][j] - map_yy[i][j];
            u[i][j] = 2.0l * map_xy[i][j];
            p[i][j] = sqrtl(q[i][j] * q[i][j] + u[i][j] * u[i][j]);
        }
    }

//    points_classifier(map_x, map_y, cos_ml, sin_ml, "../data/points.dat", whitelist);

    o_map("../data/map.dat", p);

    n_matrix_destroyer(map, npix + 1);
    n_matrix_destroyer(map_x, npix + 1);
    n_matrix_destroyer(map_y, npix + 1);
    n_matrix_destroyer(map_xx, npix + 1);
    n_matrix_destroyer(map_yy, npix + 1);
    n_matrix_destroyer(map_xy, npix + 1);
    n_matrix_destroyer(q, npix + 1);
    n_matrix_destroyer(u, npix + 1);
    n_matrix_destroyer(p, npix + 1);
    n_int_matrix_destroyer(whitelist, npix + 1);
    n_matrix_destroyer(cos_ml, nmod);
    n_matrix_destroyer(sin_ml, nmod);


    return 0;
}
