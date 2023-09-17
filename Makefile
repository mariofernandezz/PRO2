OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_problemas.o Cjt_sesiones.o Cjt_cursos.o Cjt_usuarios.o Usuario.o Sesion.o Curso.o Problema.o
	g++ -o program.exe program.o Cjt_problemas.o Cjt_usuarios.o Cjt_sesiones.o Cjt_cursos.o Problema.o Usuario.o Sesion.o Curso.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Cjt_problemas.o: Cjt_problemas.cc Cjt_problemas.hh Problema.hh
	g++ -c Cjt_problemas.cc $(OPCIONS)

Cjt_usuarios.o: Cjt_usuarios.cc Cjt_usuarios.hh Usuario.hh
	g++ -c Cjt_usuarios.cc $(OPCIONS)

Cjt_sesiones.o: Cjt_sesiones.cc Cjt_sesiones.hh Sesion.hh
	g++ -c Cjt_sesiones.cc $(OPCIONS)

Cjt_cursos.o: Cjt_cursos.cc Cjt_cursos.hh Curso.hh
	g++ -c Cjt_cursos.cc $(OPCIONS)

Problema.o: Problema.cc Problema.hh
	g++ -c Problema.cc $(OPCIONS)

Usuario.o: Usuario.cc Usuario.hh Problema.hh
	g++ -c Usuario.cc $(OPCIONS)

Sesion.o: Sesion.cc Sesion.hh BinTree.hh
	g++ -c Sesion.cc $(OPCIONS)

Curso.o: Curso.cc Curso.hh
	g++ -c Curso.cc $(OPCIONS)


clean:
	rm -f *.o
	rm -f *.exe

practica.tar: Makefile program.cc Cjt_problemas.cc Cjt_problemas.hh Cjt_usuarios.cc Cjt_usuarios.hh Cjt_sesiones.cc Cjt_sesiones.hh Cjt_cursos.cc Cjt_cursos.hh Problema.cc Problema.hh Usuario.cc Usuario.hh Sesion.cc Sesion.hh Curso.cc Curso.hh

	tar -cvf practica.tar Makefile program.cc Cjt_problemas.cc Cjt_problemas.hh Cjt_usuarios.cc Cjt_usuarios.hh Cjt_sesiones.cc Cjt_sesiones.hh Cjt_cursos.cc Cjt_cursos.hh Problema.cc Problema.hh Usuario.cc Usuario.hh Sesion.cc Sesion.hh Curso.cc Curso.hh 
