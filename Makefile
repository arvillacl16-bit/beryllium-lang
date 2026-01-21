# --- Compiler Selection ---
LLVM_PATH := $(shell brew --prefix llvm)
CXX       := $(LLVM_PATH)/bin/clang++
AR        := ar

# --- Paths ---
# -I. ensures #include "utils/error.hpp" works from project root
# Add any other third-party paths to the INCLUDES variable
INCLUDES  := -I$(LLVM_PATH)/include -I.
LIB_DIRS  := -L$(LLVM_PATH)/lib

# --- Flags ---
# We use -fno-rtti / -fno-exceptions if you plan to link deeply with LLVM later
CXXFLAGS  := -std=c++20 -O2 $(INCLUDES)
LDFLAGS   := $(LIB_DIRS) -Wl,-rpath,$(LLVM_PATH)/lib -lLLVM

# --- Files ---
# Automatically find all .cpp files in utils/
UTILS_SRCS := $(wildcard utils/*.cpp)
UTILS_OBJS := $(UTILS_SRCS:.cpp=.o)
MAIN_SRC   := main.cpp
MAIN_OBJ   := main.o

LIB_BERYL  := libberylutils.a
TARGET     := beryl

# --- Rules ---

all: $(TARGET)

# Link the final executable
$(TARGET): $(MAIN_OBJ) $(LIB_BERYL)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJ) -L. -lberylutils $(LDFLAGS) -o $(TARGET)

# Build the static library from utils
$(LIB_BERYL): $(UTILS_OBJS)
	$(AR) rcs $@ $^

# Incremental compilation for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Utility to generate compile_commands.json for clangd
# Requires: pip install compiledb
compiledb:
	compiledb make

clean:
	rm -f $(TARGET) $(MAIN_OBJ) $(UTILS_OBJS) $(LIB_BERYL) compile_commands.json