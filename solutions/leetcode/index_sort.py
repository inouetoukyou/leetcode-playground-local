#!/usr/bin/env python3

def parse_line(s) -> []:
    t = s.split()
    if t[0][-1] == '.':
        t[0] = t[0][:-1]
    return t


def sort_file(file):
    f = open(file)
    lines = f.readlines()
    f.close()

    n = len(lines)
    for i in range(n):
        lines[i] = parse_line(lines[i])
    lines.sort(key=lambda s: int(s[0]))

    f = open(file, 'w')

    duplicated = []
    for i in range(n - 1):
        f.write(' '.join(lines[i]) + '\n')
        if i > 0 and lines[i][0] == lines[i - 1][0]:
            duplicated.append(lines[i][0])
    f.write(' '.join(lines[n - 1]))
    if duplicated:
        print('duplicated!!! items are as following:')
        for d in duplicated:
            print(d)
    f.close()


if __name__ == '__main__':
    sort_file('index.txt')
