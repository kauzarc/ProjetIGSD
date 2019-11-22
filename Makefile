CC= g++

SRC_PATH= src
BUILD_PATH= build

CXXFLAGS= -Wall
LIB= -lglfw -lGLEW
LDFLAGS= -I/usr/local/include/

EXEC= app

SRC= $(wildcard $(SRC_PATH)/*.cpp)
OBJ= $(SRC:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o  $@ $^ $(LIB)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CC) -c $(LDFLAGS) $^ $(CXXFLAGS) -o $@

clean:
	rm $(BUILD_PATH)/*.o
	rm $(EXEC)