from numpy import genfromtxt, zeros

from math import pi
import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap

map_from_file = genfromtxt('../data/healpix_map.dat')

N = 512
npix = 786432
projection = 'moll'  # 'cyl', 'moll', 'ortho'
save_as_png = False
save_as_svg = False

inside_map = zeros((int(npix + 1), 3))
y = zeros((int(npix + 1), 3))
x = zeros((int(npix + 1), 3))

for i in range(0, npix):
    y[i][0] = map_from_file[i][0]
    x[i][0] = map_from_file[i][1]

for i in range(0, npix):
    inside_map[i][0] = map_from_file[i][2]

rad = 180.0 / pi

fig = plt.figure(figsize=(8, 4))
fig.subplots_adjust(
    left=0.0, right=1.0, top=1.0, bottom=0.0, wspace=0.0, hspace=0.0)

ax = fig.add_axes([0.0, 0.0, 1.0, 1.0])
ax.axis('off')

cmbmap = Basemap(projection=projection, lon_0=0, resolution='l')
cmbmap.contourf(x * rad, y * rad, inside_map, 512, cmap=plt.cm.jet, latlon=True)

if save_as_png:
    plt.savefig('out.png', dpi=300)
if save_as_svg:
    plt.savefig('out.svg')

plt.show()
