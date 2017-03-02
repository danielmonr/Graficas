ALL: personaje
.PHONY=clean

clean:
	\rm -rf personaje

personaje: main.cpp Cuerpo.cpp Pierna.cpp Cabeza.cpp Brazo.cpp
	g++ --std=c++11 main.cpp Cuerpo.cpp Brazo.cpp Pierna.cpp -lGL -lGLU -lglut -o personaje
