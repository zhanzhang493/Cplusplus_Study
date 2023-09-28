INCLUDE_DIRS += -I ../../include/ac_types
OBJECTS = $(wildcard *.cpp)

all: reference_1 reference_2 reference_3 reference_const reference_const reference_function_1 reference_function_2
	@echo $(OBJECTS)

reference_1: reference_1.cpp
	g++ reference_1.cpp -o reference_1.exe -g $(INCLUDE_DIRS) -std=c++11

reference_2: reference_2.cpp
	g++ reference_2.cpp -o reference_2.exe -g $(INCLUDE_DIRS) -std=c++11

reference_3: reference_3.cpp
	g++ reference_3.cpp -o reference_3.exe -g $(INCLUDE_DIRS) -std=c++11

reference_const: reference_const.cpp
	g++ reference_const.cpp -o reference_const.exe -g $(INCLUDE_DIRS) -std=c++11

reference_function_1: reference_function_1.cpp
	g++ reference_function_1.cpp -o reference_function_1.exe -g $(INCLUDE_DIRS) -std=c++11

reference_function_2: reference_function_2.cpp
	g++ reference_function_2.cpp -o reference_function_2.exe -g $(INCLUDE_DIRS) -std=c++11


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
# g++ -E reference_1.cpp -o reference_1.i -g $(INCLUDE_DIRS) -std=c++11

# compilation
# g++ -S reference_1.i -o reference_1.s -g $(INCLUDE_DIRS) -std=c++11

# assembly
# g++ -c reference_1.s -o reference_1.o -g $(INCLUDE_DIRS) -std=c++11

# link
# g++ reference_1.o -o reference_1.exe -g $(INCLUDE_DIRS) -std=c++11