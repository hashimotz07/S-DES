CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = sdes

SRC_DIR = src_imprimir
SRCS = $(SRC_DIR)/main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)
	@echo "🔧 Compilação concluída. Executando o programa...\n"
	@./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o

doxygen:
	doxygen -g

html: doxygen 
	xdg-open ./docs/html/index.html