CC= g++

SRC_PATH= src
BUILD_PATH= build

CXXFLAGS= -Wall
LIB= -lglfw -lGLEW -lGL -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs
LDFLAGS= -I/usr/local/include/ -I/public/ig/glm/
DSO= -I/usr/local

EXEC= app

SRC= $(wildcard $(SRC_PATH)/*.cpp)
OBJ= $(SRC:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o  $@ $(DSO) $^ $(LIB)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CC) -c $(LDFLAGS) $^ $(CXXFLAGS) -o $@

clean:
	rm $(BUILD_PATH)/*.o
	rm $(EXEC)