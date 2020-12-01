#!/usr/bin/env python3

def sort_file(file):
    f = open(file)
    lines = sorted(f, key=lambda s: int(s.split()[0]))
    f.close()

    n = len(lines)
    if n < 1:
        return

    f = open(file, 'w')

    for i in range(n - 1):
        f.write(lines[i].strip() + '\n')
    f.write(lines[n - 1].strip())
    f.close()


if __name__ == '__main__':
    sort_file('index.txt')
