# Compilação C++
CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = sdes

SRC_DIR = src_imprimir
SRCS = $(SRC_DIR)/main.cpp
OBJS = $(SRCS:.cpp=.o)

# Doxygen
DOXYFILE = Doxyfile
HTML_DIR = docs/html
LATEX_DIR = docs/latex
PDF_FILE = $(LATEX_DIR)/refman.pdf

.PHONY: all run clean doxygen html pdf open-html open-pdf doc-clean

# Compilação e execução
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

run: all
	@echo "🔧 Compilação concluída. Executando o programa...\n"
	@./$(TARGET)

clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o

# Documentação
doxygen:
	mkdir -p $(HTML_DIR) $(LATEX_DIR)
	doxygen $(DOXYFILE)

html: doxygen
	xdg-open $(HTML_DIR)/index.html

pdf: doxygen
	$(MAKE) -C $(LATEX_DIR)

open-html: html

open-pdf: pdf
	xdg-open $(PDF_FILE)

doc-clean:
	rm -rf $(HTML_DIR) $(LATEX_DIR) 