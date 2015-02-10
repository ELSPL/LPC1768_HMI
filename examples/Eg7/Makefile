###
# Build all projects

###
# Directory Structure
BDIRS='Debug'

###
# Build Rules
.PHONY: all clean $(BDIRS)

all: $(BDIRS) 

$(BDIRS):
	$(MAKE) all -C Debug

clean:
	for d in $(BDIRS); do $(MAKE) -C $$d clean; done