import math

def walkit(g, v, edge, path = []):
    if v not in path:
        path = path + [v]

        if len(path) == len(g):
            print edge
            return True

        if walkit(g, g[v][0], edge + '0', path):
            return True
        
        if walkit(g, g[v][1], edge + '1', path):
            return True

    return False

def hamilton(n):
    g = {}
    x = pow(2, n)
    for i in xrange(0, x):
        j = (i << 1) & (x - 1)
        g[i] = [j, j + 1]
    walkit(g, 0, "0" * n)

hamilton(2)
hamilton(3)
hamilton(4)
hamilton(5)
hamilton(6)
hamilton(7)
