CXX = g++
CXXFLAGS = -std=c++20 -O3

# Executable names
EXEC1 = opt_matrix_mult
EXEC2 = slow_matrix_mult
EXEC3 = notb_matrix_mult

# Source files
SRC1 = opt_matrix_mult.cpp
SRC2 = slow_matrix_mult.cpp
SRC3 = notb_matrix_mult.cpp

all: $(EXEC1) $(EXEC2) $(EXEC3)

$(EXEC1): $(SRC1)
	$(CXX) $(CXXFLAGS) -march=native  -o $(EXEC1) $(SRC1)

$(EXEC2): $(SRC2)
	$(CXX) $(CXXFLAGS) -o $(EXEC2) $(SRC2)

$(EXEC3): $(SRC3)
	$(CXX) $(CXXFLAGS) -o $(EXEC3) $(SRC3)

clean:
	rm -f $(EXEC1) $(EXEC2) $(EXEC3)
	rm -f gmon.out
	rm -rf report.txt
