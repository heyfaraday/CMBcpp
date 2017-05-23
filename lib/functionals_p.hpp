#pragma once

void points_classifier_p(long double** map, long double** map_x, long double** map_y, long double** map_xx,
                         long double** map_yy, long double** map_xy, std::string name, int** whitelist,
                         long double sigma_p);

void singular_points_classifier(long double** q, long double** u, long double** qx, long double** ux,
                                long double** qy, long double** uy, std::string name, int** whitelist);

void new_points_classifier_p(long double** map, long double** map_x, long double** map_y, long double** map_xx,
                             long double** map_yy, long double** map_xy, std::string name, int** whitelist,
                             long double sigma_p);

unsigned int singular_points_classifier_area(long double** q, long double** u, long double** qx, long double** ux,
                                             long double** qy, long double** uy, int** whitelist, unsigned int l_1, unsigned int l_2,
                                             unsigned int phi_1, unsigned int phi_2,
                                             unsigned int type);
