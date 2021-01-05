SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
IncludesImagen = $(INC)/imagenES.h $(INC)/imagen.h
IncludesRutas = $(INC)/Punto.h $(INC)/Pais.h $(INC)/Pais.h $(INC)/Paises.h $(INC)/Ruta.h $(INC)/almacen_rutas.h
libImagen = -L$(LIB) -lImagen
libRutas = -L$(LIB) -lRutas
CPPFLAGS = -Wall -g  -I$(INC) -c
ObjetosRutas = $(OBJ)/Punto.o $(OBJ)/Pais.o $(OBJ)/Paises.o $(OBJ)/Ruta.o $(OBJ)/almacen_rutas.o

# ********************* BIBLIOTECA RUTAS AEREAS ****************** #
$(LIB)/libRutas.a: $(ObjetosRutas)
	ar rvs $@ $^
# ********* Punto ********** #
$(OBJ)/Punto.o: $(SRC)/Punto.cpp $(INC)/Punto.h
	$(CXX) $(CPPFLAGS) -o $@ $<
# ********* Pais ********** #
$(OBJ)/Pais.o: $(INC)/Pais.h $(INC)/Punto.h
	$(CXX) $(CPPFLAGS) -o $@ $<
# ********* Paises ********** #
$(OBJ)/Paises.o: $(INC)/Paises.h $(INC)/Pais.h $(INC)/Punto.h
	$(CXX) $(CPPFLAGS) -o $@ $<
# ********* Ruta *********** #
$(OBJ)/Ruta.o: $(SRC)/Ruta.cpp $(INC)/Ruta.h $(INC)/Punto.h
	$(CXX) $(CPPFLAGS) -o $@ $<
# ********* Almacen_Rutas ********** #
$(OBJ)/almacen_rutas.o: $(SRC)/almacen_rutas.cpp $(INC)/almacen_rutas.h $(INC)/Ruta.h
	$(CXX) $(CPPFLAGS) -o $@ $<

# ********************** Biblioteca Imagen *********************** #
$(LIB)/libImagen.a: $(OBJ)/Imagen.o $(OBJ)/imagenES.o
	ar rvs $@ $^
	
$(OBJ)/Imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) -o $@ $<

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) -o $@ $< 

# ************ PRUEBAS *********** #
# ********* pruebaimagen ********* #
$(BIN)/pruebaimagen: $(OBJ)/pruebaimagen.o $(LIB)/libImagen.a
	$(CXX) -o $@ $< $(libImagen)

$(OBJ)/pruebaimagen.o: $(SRC)/pruebaimagen.cpp $(IncludesImagen)
	$(CXX) $(CPPFLAGS) -o $@ $<

# ********* modificarmascara ********** #
$(BIN)/modificarmascara: $(OBJ)/modificarmascara.o $(LIB)/libImagen.a
	$(CXX) -o $@ $< $(libImagen)

$(OBJ)/modificarmascara.o: $(SRC)/modificarmascara.cpp $(IncludesImagen)
	$(CXX) $(CPPFLAGS) -o $@ $<

# ********* pruebapegado ********* #
$(BIN)/pruebapegado: $(OBJ)/pruebapegado.o $(LIB)/libImagen.a
	$(CXX) -o $@ $< $(libImagen)
	
$(OBJ)/pruebapegado.o: $(SRC)/pruebapegado.cpp $(IncludesImagen)
	$(CXX) $(CPPFLAGS) -o $@ $<

# ********* pruebarotacion ********* #
$(BIN)/pruebarotacion: $(OBJ)/pruebarotacion.o $(LIB)/libImagen.a
	$(CXX) -o $@ $< $(libImagen)

$(OBJ)/pruebarotacion.o: $(SRC)/pruebarotacion.cpp $(IncludesImagen)
	$(CXX) $(CPPFLAGS) -o $@ $<

# ********* pruebapunto *********** #
$(BIN)/pruebapunto: $(OBJ)/pruebapunto.o $(OBJ)/Punto.o
	$(CXX) -o $@ $^

$(OBJ)/pruebapunto.o: $(SRC)/pruebapunto.cpp $(INC)/Punto.h
	$(CXX) $(CPPFLAGS) -o $@ $<

# ********* rutas_aereas ********** #
$(BIN)/rutasaereas: $(OBJ)/rutas_aereas.o $(LIB)/libImagen.a $(LIB)/libRutas.a
	$(CXX) -o $@ $< $(libImagen) $(libRutas)

$(OBJ)/rutas_aereas.o: $(SRC)/rutas_aereas.cpp $(IncludesImagen) $(IncludesRutas)
	$(CXX) $(CPPFLAGS) -o $@ $<

# ********** ejecuta *********** #
ejecuta: $(BIN)/rutasaereas
	$< datos/paises.txt datos/imagenes/mapas/mapa1.ppm datos/imagenes/banderas/ datos/almacen_rutas.txt datos/imagenes/aviones/avion1.ppm datos/imagenes/aviones/mascara_avion1.pgm

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/* $(LIB)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
