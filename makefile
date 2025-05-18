# =============================================
# CONFIGURAÇÕES DE COMPILAÇÃO
# =============================================

# Compilador C++ e flags básicas
CXX = g++                          # Usa o compilador g++
CXXFLAGS = -std=c++17 -Wall        # Padrão C++17 com todos os warnings
TARGET = sdes                      # Nome do executável final

# Diretórios e arquivos fonte
SRC_DIR = src_imprimir
SRCS = $(SRC_DIR)/main.cpp
OBJS = $(SRCS:.cpp=.o)

# =============================================
# CONFIGURAÇÕES DO DOXYGEN
# =============================================

DOXYFILE = Doxyfile                # Arquivo de configuração do Doxygen
HTML_DIR = docs/html
LATEX_DIR = docs/latex
PDF_FILE = $(LATEX_DIR)/refman.pdf # Arquivo PDF gerado

# =============================================
# REGRAS PRINCIPAIS (PHONY TARGETS)
# =============================================

.PHONY: all run clean doxygen html pdf open-html open-pdf doc-clean

# =============================================
# REGRAS DE COMPILAÇÃO E EXECUÇÃO
# =============================================

# Compila tudo (alvo padrão)
all: $(TARGET)

# Liga os objetos para criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Executa o programa após compilar
run: all
	@echo "🔧 Compilação concluída. Executando o programa...\n"
	@./$(TARGET)

# Limpa os arquivos gerados na compilação
clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o

# =============================================
# REGRAS DE DOCUMENTAÇÃO
# =============================================

# Gera toda a documentação com Doxygen
doxygen:
	mkdir -p $(HTML_DIR) $(LATEX_DIR)  # Cria diretórios se não existirem
	doxygen $(DOXYFILE)                # Executa o Doxygen

# Gera e abre a documentação HTML
html: doxygen
	xdg-open $(HTML_DIR)/index.html

# Gera a documentação em PDF (requer LaTeX instalado)
pdf: doxygen
	$(MAKE) -C $(LATEX_DIR)            # Compila o LaTeX

# Atalho para abrir HTML
open-html: html

# Atalho para abrir PDF
open-pdf: pdf
	xdg-open $(PDF_FILE)

# Limpa a documentação gerada
doc-clean:
	rm -rf $(HTML_DIR) $(LATEX_DIR)    # Remove toda a documentação