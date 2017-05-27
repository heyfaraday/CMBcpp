# mollview, cartview, orthview

import matplotlib.pyplot as plt
import healpy as hp

def test():
    ''' Takes bar and does
        some things to it '''

def mollview(map, coord = 'G', xsize = 2000, title = '', min_value = 0.0, max_value = 0.0,
             cbar = True, notext = False, norm = 'hist', flag_out = False, name_out = ''):
    ''' map - healpix 1-d map
        coord - 'G', ['G', 'E'] or ['G', 'C']
        xsize -
        title -
        min_value -
        max_value -
        cbar -
        notext -
        norm - None (linear), 'hist' or 'log'
        flag_out -
        name_out -'''


# def my_mollview(map, coord = 'G', # 'G', ['G', 'E'] or ['G', 'C']
#                 xsize = 2000, title = '', min_value = 0.0, max_value = 0.0,
#                 cbar = True, notext = False, norm = 'hist', # None, 'hist' or 'log'
#                 flag_out = False, name_out = file_name):
#
#     ''' Takes bar and does
#         some things to it '''
#
#     fig = plt.figure(figsize=(20,10))
#
#     if min_value != 0.0 or max_value != 0.0:
#         plot_map_out = hp.mollview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
#                                    min=min_value, max=max_value,
#                                    cbar=cbar, notext=notext, norm=norm, cmap=cmap, return_projected_map=True)
#     else:
#         plot_map_out = hp.mollview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
#                                    cbar=cbar, notext=notext, norm=norm, cmap=cmap, return_projected_map=True)
#
#     if flag_out:
#         plt.savefig(name_out, dpi=400)