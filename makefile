SOURCE_DIRECTORIES := src/
TARGET_NAME := rom
BUILD_DIR = build

THIS_MAKEFILE := $(firstword $(MAKEFILE_LIST))
SOURCE_PATH := $(dir $(realpath $(THIS_MAKEFILE)))
SOURCES := $(foreach d,$(SOURCE_DIRECTORIES),$(wildcard $(d)*.cpp))
OBJECTS := $(patsubst $(SOURCE_DIR)%,$(BUILD_DIR)/%.o,$(SOURCES))

CXXFLAGS = --std=c++20 -mcpu=arm7tdmi -nostartfiles
LDFLAGS = -T lnkscript -mcpu=arm7tdmi -nostartfiles

$(BUILD_DIR)/%.o: $(SOURCE_PATH)% $(THIS_MAKEFILE)
	@mkdir -p "$(dir $@)"
	@echo "[CXX] $@"
	@arm-none-eabi-g++ $(LDFLAGS_REQ) $(CXXFLAGS) $(INCLUDE_FLAGS) -c "$<" -o "$@"
	
	
$(TARGET_NAME): $(OBJECTS) 
	@echo "[LD] $(TARGET_NAME)"
	@arm-none-eabi-g++ crt0.s $(OBJECTS) $(LDFLAGS) -o $(TARGET_NAME)
	@echo "Stripping and formatting ROM"
	@arm-none-eabi-objcopy -O binary $(TARGET_NAME) #strip the binary
	@./ht.pl -clo $(TARGET_NAME).gba $(TARGET_NAME) #format the binary
	@rm $(TARGET_NAME) # remove the unformatted binary
	
all: $(TARGET_NAME)

clean:
	rm -rf $(TARGET_NAME).gba $(TARGET_NAME).sav
	rm -rf build/
