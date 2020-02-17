import subprocess


if __name__ == '__main__':
    
    file = open('results.txt')
    lines = file.readlines()
    file.close()
    digit_amount = int(lines[0][:-1])
    average_length = float(lines[1][:-1])

    for i in range(1000):
        subprocess.call("./a 1 input.txt output_sstream.txt")
        file = open('output_sstream.txt')
        lines = file.readlines()
        file.close()
        if digit_amount != int(lines[0][:-1]) or \
            average_length != float(lines[1][:-1]):
            print("Results with using sstream are wrong!")
            break


    for i in range(1000):
        subprocess.call("./a 2 input.txt output_to_string.txt")
        file = open('output_to_string.txt')
        lines = file.readlines()
        file.close()
        if digit_amount != int(lines[0][:-1]) or \
            average_length != float(lines[1][:-1]):
            print("Results with using to_string() are wrong!")
            break