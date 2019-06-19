###
### @file - intermediate_make_sample
### @author - Harlan James <waldroha@oregonstate.edu> Used by Richard Joseph
### @description - Intermediate example for reasonably complete Makefile
###

#
# Project Name
#
PROJ = FinalProject

#
# Compiler
#
$(CXX) = g++

#
# Source Files
#
SRC  = main.cpp
SRC += Menu.cpp
SRC += Dice.cpp
SRC += InputValidation.cpp
SRC += Player.cpp
SRC += BlueMen.cpp
SRC += Vampire.cpp
SRC += Medusa.cpp
SRC += Gargoyle.cpp
SRC += Armor.cpp
SRC += Bag.cpp
SRC += Base.cpp
SRC += Bedroom.cpp
SRC += Dojo.cpp
SRC += EnergyDrink.cpp
SRC += Game.cpp
SRC += Hero.cpp
SRC += Home.cpp
SRC += Items.cpp
SRC += Mirror.cpp
SRC += SilverSword.cpp
SRC += Space.cpp
SRC += Stake.cpp
SRC += Store.cpp






#
# Create an object for each source file
#
OBJ = $(SRC:.cpp=.o)

#
# Output binary
#
BIN = $(PROJ).bin

#
# Compiler Flags
#
CFLAGS = -Wall -pedantic -std=gnu++11

#
# Valgrind Options
#
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

#
# Names of tags that aren't actually files. Without this, if there were ever a
# file in the directory with these names they would never run.
#
# Why? Because Make is checking to see if these files exist. If they already do
# it skips them!
#
.PHONY: default debug clean zip

#
# Default Behavior:
#     1. Remove everything to start from scratch
#     2. Compile the binary
#     3. Run it through valgrind for quicker debugging
#
default: clean $(BIN) debug

#
# Notice the dependency chain.
#
# Order assuming no files exist:
#     1. Each .o file
#     2. Binary
#     3. Valgrind
# 
# Special Symbols:
#     @     Suppresses the command from being printed to the terminal)
#     $@    Name of tag
#     $^    Name of dependency
debug: $(BIN)
	@valgrind $(VOPT) ./$(BIN)

$(BIN): $(OBJ)
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

#
# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
#
%.o: %.cpp
	@echo "CC	$^"
	@$(CXX) $(CFLAGS) -c $^

zip:
	zip $(PROJ).zip *.cpp *.hpp makefile

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM	$(ZIP)"
	@rm -f *.o $(BIN)