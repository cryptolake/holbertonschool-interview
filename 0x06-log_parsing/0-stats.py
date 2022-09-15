#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics.
The prompt was phrased rather poorly in two ways:
1) The prompt gives the following format:
    <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code>
    <file size>
    It goes on to state, "If the format is not this one, the line must be
    skipped." Yet the following line is supposed to be read, even though there
    is a modification to the whitespace in the format:
    188.213.11.218-[2017-02-05 23:31:21.690755] "GET /projects/260 HTTP/1.1"
    401 1000
2) The prompt gives two conditions for printing metrics:
    "After every 10 lines and/or a keyboard interruption (CTRL + C), print
    these statistics from the beginning:"
    It does not say to print when finished reading stdin, even though it is
    expecting that as well.
"""
from sys import stdin


line_number = 1
total_file_size = 0
status_code_counts = {}

try:
    for line in stdin:
        if len(line) == 1:
            break

        try:
            status_code, file_size = line.split()[-2:]
            total_file_size += int(file_size)
            if status_code_counts.get(int(status_code)) is None:
                status_code_counts[int(status_code)] = 0
            status_code_counts[int(status_code)] += 1
        except ValueError:
            pass

        if line_number % 10 == 0:
            print('File size:', total_file_size)
            for code, count in sorted(status_code_counts.items()):
                print('{}: {}'.format(code, count))

        line_number += 1
except KeyboardInterrupt:
    pass
finally:
    print('File size:', total_file_size)
    for code, count in sorted(status_code_counts.items()):
        print('{}: {}'.format(code, count))
