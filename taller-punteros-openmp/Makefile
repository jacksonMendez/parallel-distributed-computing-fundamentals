# ==============================================================================
# Makefile: C Pointers & OpenMP Parallel Workshop
# Course: Parallel and Distributed Computing Fundamentals
# ==============================================================================

# Prioritize clean installation path without spaces in username if available
ifneq ($(wildcard C:/mingw64/bin/gcc.exe),)
    CC = C:/mingw64/bin/gcc.exe
else
    CC = gcc
endif

CFLAGS  = -Wall -Wextra -O2 -fopenmp
LDFLAGS = -lm

BIN_DIR   = bin
PART1_BIN = $(BIN_DIR)/part1
PART2_BIN = $(BIN_DIR)/part2

# OS-specific settings and path conversion
ifeq ($(OS),Windows_NT)
    EXE       = .exe
    FIXPATH   = $(subst /,\,$1)
    MKDIR_P1  = if not exist "$(call FIXPATH,$(PART1_BIN))" mkdir "$(call FIXPATH,$(PART1_BIN))"
    MKDIR_P2  = if not exist "$(call FIXPATH,$(PART2_BIN))" mkdir "$(call FIXPATH,$(PART2_BIN))"
    CLEAN_CMD = if exist "$(call FIXPATH,$(BIN_DIR))" rmdir /s /q "$(call FIXPATH,$(BIN_DIR))"
else
    EXE       =
    FIXPATH   = $1
    MKDIR_P1  = mkdir -p $(PART1_BIN)
    MKDIR_P2  = mkdir -p $(PART2_BIN)
    CLEAN_CMD = rm -rf $(BIN_DIR)
endif

# Source files
P1_SRCS = $(wildcard part1_pointers/*.c)
P2_SRCS = $(wildcard part2_openmp/*.c)

# Binary targets
P1_EXES = $(patsubst part1_pointers/%.c,$(PART1_BIN)/%$(EXE),$(P1_SRCS))
P2_EXES = $(patsubst part2_openmp/%.c,$(PART2_BIN)/%$(EXE),$(P2_SRCS))

.PHONY: all part1 part2 clean help run-all run-part1 run-part2 \
        run-ex1 run-ex2 run-ex3 run-ex4 run-ex5 run-ex6 run-ex7 run-ex8

all: part1 part2

part1: $(P1_EXES)

part2: $(P2_EXES)

# Compile Part 1 exercises
$(PART1_BIN)/%$(EXE): part1_pointers/%.c
	@$(MKDIR_P1)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Compile Part 2 exercises
$(PART2_BIN)/%$(EXE): part2_openmp/%.c
	@$(MKDIR_P2)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	@$(CLEAN_CMD)
	@echo Cleanup completed.

# Execution rules for Part 1
run-ex1: $(PART1_BIN)/exercise1_pointers$(EXE)
	@$(call FIXPATH,$(PART1_BIN)/exercise1_pointers$(EXE))

run-ex2: $(PART1_BIN)/exercise2_sum$(EXE)
	@$(call FIXPATH,$(PART1_BIN)/exercise2_sum$(EXE))

run-ex3: $(PART1_BIN)/exercise3_matrix$(EXE)
	@$(call FIXPATH,$(PART1_BIN)/exercise3_matrix$(EXE))

run-ex4: $(PART1_BIN)/exercise4_swap$(EXE)
	@$(call FIXPATH,$(PART1_BIN)/exercise4_swap$(EXE))

run-ex5: $(PART1_BIN)/exercise5_string$(EXE)
	@$(call FIXPATH,$(PART1_BIN)/exercise5_string$(EXE))

# Execution rules for Part 2
run-ex6: $(PART2_BIN)/exercise6_array_sum$(EXE)
	@$(call FIXPATH,$(PART2_BIN)/exercise6_array_sum$(EXE))

run-ex7: $(PART2_BIN)/exercise7_dot_product$(EXE)
	@$(call FIXPATH,$(PART2_BIN)/exercise7_dot_product$(EXE))

run-ex8: $(PART2_BIN)/exercise8_matrix_mult$(EXE)
	@$(call FIXPATH,$(PART2_BIN)/exercise8_matrix_mult$(EXE))

run-part1: part1
	@echo ========================================================
	@echo   RUNNING ALL PART 1 EXERCISES (POINTERS)
	@echo ========================================================
	@$(call FIXPATH,$(PART1_BIN)/exercise1_pointers$(EXE))
	@$(call FIXPATH,$(PART1_BIN)/exercise2_sum$(EXE))
	@$(call FIXPATH,$(PART1_BIN)/exercise3_matrix$(EXE))
	@$(call FIXPATH,$(PART1_BIN)/exercise4_swap$(EXE))
	@$(call FIXPATH,$(PART1_BIN)/exercise5_string$(EXE))

run-part2: part2
	@echo ========================================================
	@echo   RUNNING ALL PART 2 EXERCISES (OPENMP)
	@echo ========================================================
	@$(call FIXPATH,$(PART2_BIN)/exercise6_array_sum$(EXE))
	@$(call FIXPATH,$(PART2_BIN)/exercise7_dot_product$(EXE))
	@$(call FIXPATH,$(PART2_BIN)/exercise8_matrix_mult$(EXE))

run-all: run-part1 run-part2

help:
	@echo Build and Execution Commands:
	@echo   mingw32-make all        - Build all exercises (Parts 1 and 2)
	@echo   mingw32-make part1      - Build Part 1 exercises
	@echo   mingw32-make part2      - Build Part 2 exercises
	@echo   mingw32-make run-part1  - Run all Part 1 exercises
	@echo   mingw32-make run-part2  - Run all Part 2 exercises
	@echo   mingw32-make run-all    - Run all exercises in sequence
	@echo   mingw32-make clean      - Clean compiled binaries
