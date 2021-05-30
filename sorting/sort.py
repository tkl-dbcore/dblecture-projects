#!/usr/bin/env python3

import sys
import time

def sort(array):
    # Bubble Sort algorithm
    for i in range(0, len(array)):
        is_swapped = False
        for j in range(1, len(array) - i):
            cmp = array[j - 1] > array[j]
            if cmp:
                array[j - 1], array[j] = array[j], array[j - 1]
                is_swapped = True
        if not is_swapped:
            break

def main():
    if len(sys.argv) != 3:
        print('[Usage] python3 ./sort.py INPUT_FILE OUTPUT_FILE')
        sys.exit(1)
    input_file = sys.argv[1]
    output_file =sys.argv[2]

    # read input file
    with open(input_file, 'r') as f:
        array = f.readlines()

    # sort the array
    t0 = time.time()
    sort(array)
    t1 = time.time()

    print("Sorting time: %0.3f seconds" % (t1 - t0))

    # write output file
    with open(output_file, 'w', newline='\r\n') as f:
        f.writelines(array)

    return 0

if __name__ == "__main__":
    main()
