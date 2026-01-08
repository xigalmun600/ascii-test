SOURCE_DIR := src
BUILD_DIR := build

CC := gcc
CFLAGS = -Wall -Wextra -g -I$(SOURCE_DIR)
TARGET := out
LIBS := -lm

SOURCE := $(wildcard $(SOURCE_DIR)/*.c)
OBJECT := $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCE))

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJECT) | $(BUILD_DIR)
	$(CC) $(OBJECT) -o $(BUILD_DIR)/$(TARGET) $(LIBS)
    
run: all
	kitty -o remember_window_size=no -o initial_window_width=120c -o initial_window_height=40c -e ./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean