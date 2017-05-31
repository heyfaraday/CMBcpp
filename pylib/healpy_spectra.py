import healpy as hp
import numpy as np


# to fits and to dat

def write_alm(alm, name):

    lmax = hp.Alm.getlmax(len(alm))

    alm_file_cos = open('../data/alm_' + name + '_cos.dat', 'w')
    alm_file_sin = open('../data/alm_' + name + '_sin.dat', 'w')

    for m in range(0, lmax + 1):
        for l in range(m, lmax + 1):

            alm_file_cos.write(repr(m) + '  ' + repr(l) + '  ' + repr(alm[hp.Alm.getidx(lmax, l, m)].real) + '\n')
            alm_file_sin.write(repr(m) + '  ' + repr(l) + '  ' + repr(alm[hp.Alm.getidx(lmax, l, m)].imag) + '\n')

    alm_file_cos.close()
    alm_file_sin.close()


def write_cl(cl, name):

    lmax = len(cl) - 1

    alm_file_cos = open('../data/cl_' + name + '.dat', 'w')

    for l in range(0, lmax + 1):

            alm_file_cos.write(repr(l) + '  ' + repr(cl[l]) + '\n')

    alm_file_cos.close()


def alm_to_cl(alm):

    return hp.sphtfunc.alm2cl(alm, lmax=hp.Alm.getlmax(len(alm)))


def alm_gen(work_map, lmax=0, pol=False):

    if lmax == 0:
        lmax = hp.get_nside(work_map)

    if pol:
        if np.shape(work_map)[0] is not 3:
            print("np.shape(work_map)[0] is not 3")
            return None
        else:
            return hp.sphtfunc.map2alm(work_map, lmax=lmax, pol=True, use_weights=True)
    else:
        return hp.sphtfunc.map2alm(work_map, lmax=lmax, pol=False, use_weights=True)


def cl_gen(work_map, lmax=0, pol=False):

    alm = alm_gen(work_map, lmax, pol)

    return alm_to_cl(alm)


def read_alm_from_fits():

    return 0


def read_alm_from_dat():

    return 0


def read_cl_from_fits():

    return 0


def read_cl_from_dat():

    return 0
