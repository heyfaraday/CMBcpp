#include <iostream>

#include <healpix_map.h>
#include <healpix_data_io.h>
#include <healpix_map_fitsio.h>

#include <alm.h>
#include <alm_fitsio.h>
#include <alm_healpix_tools.h>

// tools for Cls
#include <powspec.h>
#include <powspec_fitsio.h>
#include <alm_powspec_tools.h>

using namespace std;

// MAIN ------------------------
int main(int argc,char **argv)
{

// read a HEALPix map from a file -----------------------------
    Healpix_Map<double> map;
    read_Healpix_map_from_fits("../../../data/COM_CMB_IQU-commander_1024_R2.02_full.fits", map, 1, 2);


// prepare the alms -----------------------------
    unsigned int nside = static_cast<unsigned int>(map.Nside());
    int nlmax = 2 * nside;
    int nmmax = nlmax;

    std::cout << "nside: " << nside << std::endl;
    std::cout << "nlmax: " << nlmax << std::endl;
    std::cout << "nmmax: " << nmmax << std::endl;

    arr<double> weight;
    weight.alloc(2 * nside);
    weight.fill(1);

    Alm<xcomplex<double> > alm(nlmax, nmmax);

// test the Fourier Transform -----------------------------

// do the FFT
    if(map.Scheme()==NEST) map.swap_scheme();
    map2alm_iter(map, alm, 1, weight);

// test some of the power spectra methods ---------------

//create the Cl array:
    PowSpec mySpec(1, nlmax);

//cast the read alm into their power spectrum
    extract_powspec(alm, mySpec);

// create the fitshandle to the power spectra file
    fitshandle myCl;
    myCl.create("../data/myCl.fits");

// write the power spectrum to the file:
    write_powspec_to_fits(myCl, mySpec, 1);
// remember the last number carries the info on how many spectra: 1 OR 4 OR 6

    cout << "Done with test program!" << endl;
    return 0;
}