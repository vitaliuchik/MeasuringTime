import subprocess
import sys
import math

import time


if __name__ == '__main__':


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
    
    text = {1: ("Results with using sstream are wrong!", "Sstream:"),
            2: ("Results with using to_string() are wrong!", "To_string:"),
            3: ("Results with using custom converter are wrong!", "Custom:"),
            4: ("Results with using sscanf converter are wrong!", "Sscanf:")}

    subprocess.call('cmake -S . -B build -G "Unix Makefiles"')
    subprocess.call('cmake --build build')    

    
    start = time.time()

    for j in range(1, 5):
        minimal_time = float('inf')
        for i in range(int(sys.argv[1])):
            result = int(subprocess.check_output("./build/MeasuringTime " + str(j) + " " + sys.argv[2] + " " + sys.argv[3]).strip())
            minimal_time = min(minimal_time, result)
            file = open(sys.argv[3])
            lines = file.readlines()
            file.close()
            if length != int(lines[0][:-1]) or \
                not math.isclose(average, float(lines[1][:-1]), abs_tol=0.0001):
                print(text[j][0])
                break
        print(text[j][1], minimal_time)

    print("Duration:", time.time() - start)