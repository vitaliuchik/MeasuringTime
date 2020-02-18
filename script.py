import subprocess
import sys
import math

import time


if __name__ == '__main__':

    start = time.time()

    if len(sys.argv) != 4:
        print("Argument exception")
    

    file = open(sys.argv[2])
    length = 0
    n = 0
    for line in file:
        length += len(str(int(line[:-1])))
        n += 1
    average = length / n
    file.close()
    
    minimal_time1 = float('inf')
    minimal_time2 = float('inf')
    minimal_time3 = float('inf')
    minimal_time4 = float('inf')

    result = int(subprocess.check_output("./cmake-build-debug/MeasuringTime 4 " + sys.argv[2] + " " + sys.argv[3]).strip())
    print(result)

    # for i in range(int(sys.argv[1])):
    #     result = int(subprocess.check_output("./cmake-build-debug/MeasuringTime 1 " + sys.argv[2] + " " + sys.argv[3]).strip())
    #     minimal_time1 = min(minimal_time1, result)
    #     print(result)
    #     file = open(sys.argv[3])
    #     lines = file.readlines()
    #     file.close()
    #     if length != int(lines[0][:-1]) or \
    #         not math.isclose(average, float(lines[1][:-1]), abs_tol=0.0001):
    #         print("Results with using sstream are wrong!")
    #         break

    # print()
    # for i in range(int(sys.argv[1])):
    #     result = int(subprocess.check_output("./cmake-build-debug/MeasuringTime 2 " + sys.argv[2] + " " + sys.argv[3]).strip())
    #     minimal_time2 = min(minimal_time2, result)
    #     print(result)
    #     file = open(sys.argv[3])
    #     lines = file.readlines()
    #     file.close()
    #     if length != int(lines[0][:-1]) or \
    #         not math.isclose(average, float(lines[1][:-1]), abs_tol=0.0001):
    #         print("Results with using to_string() are wrong!")
    #         break

    # print()
    # for i in range(int(sys.argv[1])):
    #     result = int(subprocess.check_output("./cmake-build-debug/MeasuringTime 3 " + sys.argv[2] + " " + sys.argv[3]).strip())
    #     minimal_time3 = min(minimal_time3, result)
    #     print(result)
    #     file = open(sys.argv[3])
    #     lines = file.readlines()
    #     file.close()
    #     if length != int(lines[0][:-1]) or \
    #         not math.isclose(average, float(lines[1][:-1]), abs_tol=0.0001):
    #         print("Results with using custom converter are wrong!")
    #         break

    # print()
    # for i in range(int(sys.argv[1])):
    #     result = int(subprocess.check_output("./cmake-build-debug/MeasuringTime 4 " + sys.argv[2] + " " + sys.argv[3]).strip())
    #     minimal_time4 = min(minimal_time4, result)
    #     print(result)
    #     file = open(sys.argv[3])
    #     lines = file.readlines()
    #     file.close()
    #     if length != int(lines[0][:-1]) or \
    #         not math.isclose(average, float(lines[1][:-1]), abs_tol=0.0001):
    #         print("Results with using sscanf converter are wrong!")
    #         break

    print("Sstream:", minimal_time1)
    print("To_string:", minimal_time2)
    print("Custom:", minimal_time3)
    print("Sscanf:", minimal_time4)


    print("Duration:", time.time() - start)