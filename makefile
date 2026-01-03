# Makefile for BPM package manager

CC = cc
CFLAGS = -O2 -Wall
TARGET = bpm
SRC = bpm.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

install: $(TARGET)
	@echo "[bpm] installing to /usr/local/bin"
	sudo cp $(TARGET) /usr/local/bin/
	@echo "[bpm] done. Make sure /usr/local/bin is in your PATH"

clean:
	rm -f $(TARGET)
