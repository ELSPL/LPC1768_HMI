###
# Build all projects

###
# Directory Structure
BDIRS='Debug'

###
# Build Rules
.PHONY: all
.PHONY: all clean

all: $(BDIRS) 

$(BDIRS):
	$(MAKE) all -C Debug

clean:
	$(MAKE) clean -C Debug