SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

$(BIN)/pruebaimagen: $(OBJ)/pruebaimagen.o $(OBJ)/Imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $@ $^

$(OBJ)/pruebaimagen.o: $(SRC)/pruebaimagen.cpp
	$(CXX) $(CPPFLAGS) -o $@ $<
	
$(OBJ)/Imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) -o $@ $<

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) -o $@ $< 

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
