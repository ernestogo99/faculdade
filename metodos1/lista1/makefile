CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
SOURCES = main.cpp \
	src/binaryConverter.cpp \
	src/floatingpointNumber.cpp \
	src/floatingPointSystem.cpp \
	src/errorCalculator.cpp \
	src/exercises/exercise1.cpp \
	src/exercises/exercise2.cpp \
	src/exercises/exercise3.cpp \
	src/exercises/exercise4.cpp
TARGET = app.exe

ifeq ($(OS),Windows_NT)
RUN_CMD = .\$(TARGET)
CLEAN_CMD = if exist $(TARGET) del /Q $(TARGET)
else
RUN_CMD = ./$(TARGET)
CLEAN_CMD = rm -f $(TARGET)
endif

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	$(RUN_CMD)

clean:
	$(CLEAN_CMD)
