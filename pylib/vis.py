import matplotlib.pyplot as plt
import healpy as hp
import numpy as np


def healpy_mollview(plot_map, fig=None, coord='G', xsize=2000, title='', min_value=0.0, max_value=0.0,
                    cbar=True, notext=False, norm=None, name_out=None, cmap=plt.cm.viridis,
                    return_projected=False):
    """
    map - healpix map (1-d array),
    fig - figure number to use,
    coord - coordinate system of the map ('G', ['G', 'E'] or ['G', 'C']),
    xsize - size of the image,
    title - title of the plot,
    min_value - minimum range value,
    max_value - maximum range value,
    cbar - display the colorbar,
    notext - if True, no text is printed around the map,
    norm - color normalization (None (linear), 'hist' or 'log'),
    name_out - name of the output picture,
    cmap - color map of the plot (jet, viridis, jet and other)
    """

    cmap.set_under("w")

    if fig is None:
        fig = plt.figure(figsize=(20, 10))

    if return_projected:
        if min_value != 0.0 or max_value != 0.0:
            plot_map_out = hp.mollview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                                       min=min_value, max=max_value,
                                       cbar=cbar, notext=notext, norm=norm, cmap=cmap, return_projected_map=True)
        else:
            plot_map_out = hp.mollview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                                       cbar=cbar, notext=notext, norm=norm, cmap=cmap, return_projected_map=True)

        if name_out is not None:
            plt.savefig(name_out, dpi=400)

        return plot_map_out
    else:
        if min_value != 0.0 or max_value != 0.0:
            hp.mollview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                        min=min_value, max=max_value,
                        cbar=cbar, notext=notext, norm=norm, cmap=cmap)
        else:
            hp.mollview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                        cbar=cbar, notext=notext, norm=norm, cmap=cmap)

        if name_out is not None:
            plt.savefig(name_out, dpi=400)


def healpy_cartview(plot_map, fig=None, coord='G', xsize=2000, title='', min_value=0.0, max_value=0.0,
                    cbar=True, notext=False, norm=None, name_out=None, cmap=plt.cm.viridis,
                    return_projected=False):
    """
    map - healpix map (1-d array),
    fig - figure number to use,
    coord - coordinate system of the map ('G', ['G', 'E'] or ['G', 'C']),
    xsize - size of the image,
    title - title of the plot,
    min_value - minimum range value,
    max_value - maximum range value,
    cbar - display the colorbar,
    notext - if True, no text is printed around the map,
    norm - color normalization (None (linear), 'hist' or 'log'),
    name_out - name of the output picture,
    cmap - color map of the plot (jet, viridis, jet and other)
    """

    cmap.set_under("w")

    if fig is None:
        fig = plt.figure(figsize=(20, 10))

    if return_projected:
        if min_value != 0.0 or max_value != 0.0:
            plot_map_out = hp.cartview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                                       min=min_value, max=max_value,
                                       cbar=cbar, notext=notext, norm=norm, cmap=cmap, return_projected_map=True)
        else:
            plot_map_out = hp.cartview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                                       cbar=cbar, notext=notext, norm=norm, cmap=cmap, return_projected_map=True)

        if name_out is not None:
            plt.savefig(name_out, dpi=400)

        return plot_map_out
    else:
        if min_value != 0.0 or max_value != 0.0:
            hp.cartview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                        min=min_value, max=max_value,
                        cbar=cbar, notext=notext, norm=norm, cmap=cmap)
        else:
            hp.cartview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                        cbar=cbar, notext=notext, norm=norm, cmap=cmap)

        if name_out is not None:
            plt.savefig(name_out, dpi=400)


def healpy_orthview(plot_map, fig=None, coord='G', xsize=2000, title='', min_value=0.0, max_value=0.0,
                    cbar=True, notext=False, norm=None, name_out=None, cmap=plt.cm.viridis,
                    return_projected=False):
    """
    map - healpix map (1-d array),
    fig - figure number to use,
    coord - coordinate system of the map ('G', ['G', 'E'] or ['G', 'C']),
    xsize - size of the image,
    title - title of the plot,
    min_value - minimum range value,
    max_value - maximum range value,
    cbar - display the colorbar,
    notext - if True, no text is printed around the map,
    norm - color normalization (None (linear), 'hist' or 'log'),
    name_out - name of the output picture,
    cmap - color map of the plot (jet, viridis, jet and other)
    """

    cmap.set_under("w")

    if fig is None:
        fig = plt.figure(figsize=(20, 10))

    if return_projected:
        if min_value != 0.0 or max_value != 0.0:
            plot_map_out = hp.orthview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                                       min=min_value, max=max_value,
                                       cbar=cbar, notext=notext, norm=norm, cmap=cmap, return_projected_map=True)
        else:
            plot_map_out = hp.orthview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                                       cbar=cbar, notext=notext, norm=norm, cmap=cmap, return_projected_map=True)

        if name_out is not None:
            plt.savefig(name_out, dpi=400)

        return plot_map_out
    else:
        if min_value != 0.0 or max_value != 0.0:
            hp.orthview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                        min=min_value, max=max_value,
                        cbar=cbar, notext=notext, norm=norm, cmap=cmap)
        else:
            hp.orthview(plot_map, fig.number, coord=coord, xsize=xsize, title=title,
                        cbar=cbar, notext=notext, norm=norm, cmap=cmap)

        if name_out is not None:
            plt.savefig(name_out, dpi=400)


def spectra_1(cl):

    l = np.arange(len(cl))

    plt.figure(figsize=(20, 10))
    plt.plot(l, cl * l * (l + 1))
    plt.xlabel('l')
    plt.ylabel('cl * l * (l + 1)')
    plt.grid()


def spectra_2(cl):

    l = np.arange(len(cl))[1: len(cl)]

    plt.figure(figsize=(20, 10))
    plt.semilogx(l, cl[1: len(cl)] * l * (l + 1))
    plt.xlabel('l')
    plt.ylabel('cl * l * (l + 1)')
    plt.grid()


def spectra_3(cl):

    l = np.arange(len(cl))

    plt.figure(figsize=(20, 10))
    plt.semilogy(l, cl)
    plt.xlabel('l')
    plt.ylabel('cl')
    plt.grid()


def spectra_4(cl):

    l = np.arange(len(cl))

    plt.figure(figsize=(20, 10))
    plt.plot(l, cl)
    plt.xlabel('l')
    plt.ylabel('cl')
    plt.grid()


