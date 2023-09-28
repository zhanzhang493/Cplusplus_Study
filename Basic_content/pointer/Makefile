INCLUDE_DIRS += -I ../../include/ac_types
OBJECTS = $(wildcard *.cpp)

all: pointer_1 pointer_2 pointer_3 pointer_4 pointer_function 
	@echo $(OBJECTS)

pointer_1: pointer_1.cpp
	g++ pointer_1.cpp -o pointer_1.exe -g $(INCLUDE_DIRS) -std=c++11

pointer_2: pointer_2.cpp
	g++ pointer_2.cpp -o pointer_2.exe -g $(INCLUDE_DIRS) -std=c++11

pointer_3: pointer_3.cpp
	g++ pointer_3.cpp -o pointer_3.exe -g $(INCLUDE_DIRS) -std=c++11

pointer_4: pointer_4.cpp
	g++ pointer_4.cpp -o pointer_4.exe -g $(INCLUDE_DIRS) -std=c++11

pointer_function: pointer_function.cpp
	g++ pointer_function.cpp -o pointer_function.exe -g $(INCLUDE_DIRS) -std=c++11




.PHONY: clean
clean:
	rm -f *.i
	rm -f *.s
	rm -f *.o
	rm -f *.out
	rm -f *.elf
	rm -f *.exe

# **********************************************************************
# preprocessing
# g++ -E pointer_1.cpp -o pointer_1.i -g $(INCLUDE_DIRS) -std=c++11

# compilation
# g++ -S pointer_1.i -o pointer_1.s -g $(INCLUDE_DIRS) -std=c++11

# assembly
# g++ -c pointer_1.s -o pointer_1.o -g $(INCLUDE_DIRS) -std=c++11

# link
# g++ pointer_1.o -o pointer_1.exe -g $(INCLUDE_DIRS) -std=c++11