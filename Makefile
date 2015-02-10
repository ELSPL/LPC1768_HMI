###
# Build all projects

###
# Directory Structure
BDIRS='examples'

###
# Build Rules
.PHONY: all

all:
	for d in $(BDIRS); do $(MAKE) -C $$d; done