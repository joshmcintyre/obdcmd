# This file contains a make script for the OBD utility
#
# Author: Josh McIntyre
#

# This block defines makefile variables
UI_FILES=src/ui/*.cpp
CORE_FILES=src/core/*.cpp
INCLUDE_CORE=src/core

BUILD_DIR=bin
BUILD_BIN=obd.exe

CC=g++
FLAGS=-std=c++11 -I$(INCLUDE_CORE)

# This rule builds the utility
build: $(SRC_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -o $(BUILD_DIR)/$(BUILD_BIN) $(CORE_FILES) $(UI_FILES)

# This rule cleans the build directory
clean: $(BUILD_DIR)
	rm $(BUILD_DIR)/* 
	rmdir $(BUILD_DIR)