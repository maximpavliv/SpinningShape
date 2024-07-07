# Define the compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++20 -g
LDFLAGS = -lboost_program_options -lncurses

# The name of the executable
TARGET = bin/spinning_shape

# Source directory
SRC_DIR = src

# Object directory
OBJ_DIR = obj

# The source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# The object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Dependency files
DEPS = $(OBJS:.o=.d)

# Default target
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Rule to compile the source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean up the build files
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(TARGET)

# Phony targets
.PHONY: all clean
