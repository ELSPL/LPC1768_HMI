###
# Build all projects

###
# Directory Structure
BDIRS=$(shell find . -mindepth 1 -maxdepth 1 -type d)

###
# Build Rules
.PHONY: all

all:
	for d in $(BDIRS); do $(MAKE) -C $$d; done