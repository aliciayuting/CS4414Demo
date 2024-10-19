# Compiler defined as variable
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++20 -I.  # -I. means "look for headers in the current directory"

# all is used when you have multiple targets
all: output

# Listing the final target (output) first, 
# Make knows what needs to be built, 
# then works backward through the dependencies 
output: main.o hello.o
	$(CXX) main.o hello.o -o output

# Compile each .cpp file into a .o file
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

hello.o: hello.cpp
	$(CXX) $(CXXFLAGS) -c hello.cpp -o hello.o


# Clean up the object files and the executable
clean:
	rm -f *.o output
