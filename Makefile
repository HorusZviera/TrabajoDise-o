# Flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Directorios
SRCDIR = src
INCDIR = include
OBJDIR = build

# Archivos de fuente y de encabezado
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
INCL = -I$(INCDIR)

# Nombre del ejecutable
EXEC = main

# Reglas de compilación
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCL) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(EXEC)

.PHONY: all clean
