CC := gcc
CFLAGS := -Wall -Wextra -g
TARGET := out
BUILD_DIR := build
SOURCE_DIR := src

SOURCE := $(wildcard $(SOURCE_DIR)/*.c)
OBJECT := $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCE))

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


all: $(OBJECT) | $(BUILD_DIR)
	$(CC) $(OBJECT) -o $(BUILD_DIR)/$(TARGET)
	
run: all
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf build

.PHONY: all run clean