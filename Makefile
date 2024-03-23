# Makefile for ProjectBuildv01

# Target executable
TargetApp := ProjectBuildv01.exe

# Compiler
CC := gcc

# Compilation flags
CCFlag := -c
OutFlag := -save-temps

# Directories
SrcDIR := Src
IncDIR := Inc
UtilityIncDIR := $(IncDIR)/Helpers
ObjDIR := Obj
DepDIR := Dep

# wildcard all files inside the directories
SrcDs := $(wildcard *.c) $(wildcard $(SrcDIR)/*.c)
IncDs := $(wildcard *.h) $(wildcard $(IncDIR)/*.h) $(wildcard $(UtilityIncDIR)/*.h)
ObjDs := $(addprefix $(ObjDIR)/, $(patsubst %.c, %.o, $(subst $(SrcDIR)/,,$(SrcDs))))
DepDs := $(addprefix $(DepDIR)/, $(patsubst %.c, %.o, $(subst $(SrcDIR)/,,$(SrcDs))))

DepDs22 := $(subst $(SrcDIR)/,,$(patsubst %.c, %.i, $(SrcDs)) $(patsubst %.c, %.s, $(SrcDs)) $(patsubst %.c, %.o, $(SrcDs)))


# Define search paths
vpath %.c $(SrcDIR)
vpath %.h $(IncDIR)
vpath %.o $(ObjDIR)

# Build rules
all: $(ObjDIR) $(TargetApp)


$(TargetApp): $(ObjDs)
	$(CC) $^ -o $@

$(ObjDIR)/%.o: %.c $(IncDs)
	$(CC) $(CCFlag) $< -o $@

$(ObjDIR)/%.o: $(SrcDIR)/%.c $(IncDs)
	$(CC) $(CCFlag) $< -o $@

# Phony targets
.PHONY: run clean print output size

# Determine size of .text, .data, .rodata, and .bss sections for each object file and the target executable
size:
	@echo -e "\033[1;32mSize of .text, .data, .rodata, and .bss sections for $(TargetApp):\033[0m"
	@size $(ObjDs) $(TargetApp)
	
# Run the application
run: $(TargetApp)
	./$(TargetApp)

# Target for generating output files
output: $(DepDs)

# Rule to generate dep files
$(DepDIR)/%.o: %.c | $(DepDIR)
	gcc -c -save-temps -o $@ $<

# Create directory
$(ObjDIR):
	mkdir -p $@
	
$(DepDIR):
	mkdir -p $@

# Print information
print:
	@echo
	@echo TargetApp = $(TargetApp)
	@echo cCompiler = $(CC)
	@echo SrcDs = $(SrcDs)
	@echo IncDs = $(IncDs)
	@echo ObjDs = $(ObjDs)
	@echo DepDs = $(DepDs22)
	@echo

# Clean the project
clean:
	rm -r -f $(ObjDIR) $(DepDIR) $(TargetApp)
