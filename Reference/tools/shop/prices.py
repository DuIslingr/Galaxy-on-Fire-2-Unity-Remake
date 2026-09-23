# Reference implementation of the shop price rule (Status::calcCargoPrices 0xb9d70) for unit tests.
#   python Reference/tools/shop/prices.py <stationIndex> <itemIdx> [itemIdx ...]
# The item list is priced IN ORDER with java.util.Random seeded with the station index (the game reseeds
# for each of its three lists: cargo, mounted equipment, station stock). Items whose current price is 0
# (free campaign items) are skipped and consume no random number.
import json, os, sys, struct, math
here = os.path.dirname(os.path.abspath(__file__))
D = os.path.join(here, '..', '..', '..', 'Assets', 'Resources', 'GoF2Data')
items = json.load(open(os.path.join(D, 'items.json'), encoding='utf-8'))
systems = json.load(open(os.path.join(D, 'systems.json'), encoding='utf-8'))
stations = json.load(open(os.path.join(D, 'stations.json'), encoding='utf-8'))


def f32(x):
    try:
        return struct.unpack('<f', struct.pack('<f', x))[0]
    except OverflowError:
        return math.copysign(math.inf, x)


class JavaRandom:  # = AbyssEngine::AERandom (0x7ad04 setSeed, 0x7add2 nextInt)
    def __init__(self, seed):
        self.s = (seed ^ 0x5DEECE66D) & ((1 << 48) - 1)

    def next(self, bits):
        self.s = (self.s * 0x5DEECE66D + 0xB) & ((1 << 48) - 1)
        r = self.s >> (48 - bits)
        return r - (1 << 32) if r >= 1 << 31 else r

    def nextInt(self, n):
        if n & -n == n:
            return (n * self.next(31)) >> 31
        while True:
            bits = self.next(31); val = bits % n
            if bits - val + (n - 1) < (1 << 31):
                return val


def dist(a, b):  # Galaxy::distancePercent = (int)sqrt(dx*dx + dy*dy) on the map x/y
    pa, pb = systems[a]['mapPosition'], systems[b]['mapPosition']
    return int(f32(math.sqrt(f32((pb['y'] - pa['y']) ** 2 + (pb['x'] - pa['x']) ** 2))))


def price_list(station, idxs, global_price_raise=0, max_price_mode=False):
    """max_price_mode = the Loma rule (system 25 and current station != Status+0x78)."""
    sysi = stations[station]['system']
    rnd = JavaRandom(station)
    out = []
    for i in idxs:
        it = items[i]
        lo, hi = it['minPrice'], it['maxPrice']
        smin, smax = it['lowestPriceSystem'], it['highestPriceSystem']
        span = f32(dist(smin, smax)); cur = f32(dist(smin, sysi))
        f = f32(f32(f32(100.0 / span) * cur) / 100.0) if span else (math.inf if cur else math.nan)
        f = f if f < 1.0 else 1.0  # NaN also ends up as 1.0
        if max_price_mode:
            p = hi
        else:
            base = lo + int(f32(f * f32(hi - lo)))
            d = max(1, int(f32(f32(base) * 0.02)))
            p = base - d + rnd.nextInt(2 * d + 1)
        if global_price_raise:
            p = int(f32(p + f32(p * global_price_raise) * 0.01))
        out.append((i, it['name'], p))
    return out


if __name__ == '__main__':
    st = int(sys.argv[1]); idx = [int(a) for a in sys.argv[2:]] or [i['index'] for i in items if i['techLevel'] <= stations[st]['techLevel']]
    print('station', st, stations[st]['name'], 'system', stations[st]['system'], 'tech', stations[st]['techLevel'])
    for i, n, p in price_list(st, idx):
        print(i, n, p, '(min %d max %d)' % (items[i]['minPrice'], items[i]['maxPrice']))
