import os
import sys

'''Class for printing colour output'''


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


'''

Command to run:

echo COMPILING && g++ -std=c++14 -Wall -Wextra -Wshadow -Wfloat-equal -Wconversion -O2 -g -o $fileNameWithoutExt $fullFileName || (pause & EXIT 0) && echo temp & echo RUNNING & $fileNameWithoutExt & pause

'''


os.system("")
source_code_base = sys.argv[1]  # name of code file\
source_code = sys.argv[2]  # name of code file\

file_input = int(sys.argv[3])

if file_input == 0:
    print(u"\u001b[0m\u001b[7m Compiling \u001b[0m")
    if os.system("g++ -std=c++14 -Wall -Wextra -Wshadow -Wfloat-equal -Wconversion -O2 -g -o " +
             source_code_base + " " + source_code) != 0:
        print(bcolors.FAIL + "COMPILATION ERRORS" + bcolors.ENDC)
        sys.exit(0)
    print(u"\u001b[0m\u001b[7m RUNNING \u001b[0m")
    os.system("./"+source_code_base + " </home/salil/Documents/Competitive-Programmming/Programs/C++/input.in")
elif file_input == 1:
    print(u"\u001b[0m\u001b[7m RUNNING \u001b[0m")
    os.system("./"+source_code_base + " </home/salil/Documents/Competitive-Programmming/Programs/C++/input.in")

elif file_input == 2:
    print(u"\u001b[0m\u001b[7m Compiling \u001b[0m")
    if os.system("g++ -std=c++14 -Wall -Wextra -Wshadow -Wfloat-equal -Wconversion -O2 -g -o " +
             source_code_base + " " + source_code) != 0:
        print(bcolors.FAIL + "COMPILATION ERRORS" + bcolors.ENDC)
        sys.exit(0)
    print(u"\u001b[0m\u001b[7m RUNNING \u001b[0m")
    os.system("./"+source_code_base + " >temp.out")
    print(u"\u001b[0m\u001b[7m OUTPUT \u001b[0m")
    print(open('temp.out').read(), end="")
    os.remove("temp.out")

elif file_input == 3:
    print(u"\u001b[0m\u001b[7m RUNNING \u001b[0m")
    os.system("./"+source_code_base + " >temp.out")
    print(u"\u001b[0m\u001b[7m OUTPUT \u001b[0m")
    print(open('temp.out').read(), end="")
    os.remove("temp.out")

print(bcolors.ENDC)
