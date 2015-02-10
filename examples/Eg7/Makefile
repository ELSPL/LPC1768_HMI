###
# Build all projects

###
# Directory Structure
BDIRS='Debug'

###
# Build Rules
.PHONY: all clean

all:
	for d in $(BDIRS); do $(MAKE) -C $$d; done

clean:
	for d in $(BDIRS); do $(MAKE) -C $$d clean; done
