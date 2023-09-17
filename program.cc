/**
 * @mainpage Práctica de PRO2:  Evaluator.

En esta práctica se construye un programa modular que ofrece un menú de opciones para gestionar una plataforma de problemas y cursos de programación. El programa principal se encuentra en el módulo program.cc.
Se introducen las clases <em>Cjt_cursos</em>, <em>Cjt_sesiones</em>, <em>Cjt_usuarios</em>, <em>Cjt_problemas</em>, <em>Usuario</em>, <em>Sesion</em>, <em>Curso</em> y <em>Problema</em>.

<b> Comentarios:</b>
- Los errores que puedan generar los comandos serán tratados en el programa
principal, excepto en el comando nuevo curso.

*/

/** @file program.cc
    @brief Programa principal para la práctica de PRO2 de primavera 2021 <em>Evaluator</em>.
*/

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

#include "Cjt_cursos.hh"
#include "Cjt_problemas.hh"
#include "Cjt_sesiones.hh"
#include "Cjt_usuarios.hh"



int main() {

  //lectura de la coleccion inicial de problemas
  Cjt_problemas cp;
  cp.leer_cjt_problemas();

  //lectura del repositorio inicial de sesiones
  Cjt_sesiones cs;
  cs.leer_cjt_sesiones();

  //lectura del conjunto inicial de cursos
  Cjt_cursos cc;
  cc.leer_cjt_cursos(cs, cc);

	//lectura de los usuarios iniciales
	Cjt_usuarios cu;
	cu.leer_cjt_usuarios();


  //Leer comando y realizar accion
  string comando;
  cin >> comando;
  while (comando != "fin") {


    if (comando == "nuevo_problema" or comando == "np") {
      string p;
      cin >> p;
			cout << '#' << comando << ' ' << p << endl;
      bool exito = cp.nuevo_problema(p);
      if (!exito) cout << "error: el problema ya existe" << endl;
      else cout << cp.total_cjt_problemas() << endl;
    }

    else if (comando == "nueva_sesion" or comando == "ns") {
      string s;
      cin >> s;
			cout << '#' << comando << ' ' << s << endl;
      bool exito = cs.nueva_sesion(s);
      if (!exito) cout << "error: la sesion ya existe" << endl;
			else cout << cs.total_cjt_sesiones() << endl;
    }

    else if (comando == "nuevo_curso" or comando == "nc") {
			cout << '#' << comando << endl;
			cc.crear_nuevo_curso(cs, cc);
    }

    else if (comando == "alta_usuario" or comando == "a") {
      string u;
      cin >> u;
			cout << '#' << comando << ' ' << u << endl;
      bool exito = cu.alta_usuario(u);
      if (!exito) cout << "error: el usuario ya existe" << endl;
      else cout << cu.total_cjt_usuarios() << endl;
    }

    else if (comando == "baja_usuario" or comando == "b") {
      string u;
      cin >> u;
			cout << '#' << comando << ' ' << u << endl;
      if(!cu.buscar_usuario(u)) cout << "error: el usuario no existe" << endl;
      else {
				if(cu.consul_insc(u)) {
					int x = cu.consul_iden_usu(u);
					cc.borrar_usu_actual(x);
				}
        cu.baja_usuario(u);
      }
    }

    else if (comando == "inscribir_curso" or comando == "i") {
      string u;
      int c;
      cin >> u >> c;
			cout << '#' << comando << ' ' << u << ' ' << c << endl;
      if(!cu.buscar_usuario(u)) cout << "error: el usuario no existe" << endl;
			else if(!cc.buscar_curso(c)) cout << "error: el curso no existe" << endl;
      else if(cu.consul_insc(u)) cout << "error: usuario inscrito en otro curso" << endl;
      else cu.inscribir(u, c, cc, cs);
    }


    else if (comando == "curso_usuario" or comando == "cu") {
      string u;
      cin >> u;
			cout << '#' << comando << ' ' << u << endl;
      if(cu.buscar_usuario(u)) {
        if(cu.consul_insc(u)) {
          int iden = cu.consul_iden_usu(u);
          cout << iden << endl;
        }
        else cout << '0' << endl;
      }
      else cout << "error: el usuario no existe" << endl;
    }

    else if (comando == "sesion_problema" or comando == "sp") {
      string p;
      int c;
      cin >> c >> p;
			cout << '#' << comando << ' ' << c << ' ' << p << endl;
      if(!cc.buscar_curso(c)) cout << "error: el curso no existe" << endl;
			else if (!cp.buscar_problema(p)) cout << "error: el problema no existe" << endl;
			else {
				string resul = cc.problema_pertenece_ses(p, c);
				if (resul == "no") cout << "error: el problema no pertenece al curso" << endl;
				else cout << resul << endl;
			}
    }

    else if (comando == "problemas_resueltos" or comando == "pr") {
      string u;
      cin >> u;
			cout << '#' << comando << ' ' << u << endl;
      if (!cu.buscar_usuario(u)) {
        cout << "error: el usuario no existe" << endl;
      }
      else {
        cu.cjt_problemas_resueltos(u);
      }
    }

    else if (comando == "problemas_enviables" or comando == "pe") {
      string u;
      cin >> u;
			cout << '#' << comando << ' ' << u << endl;
      if (!cu.buscar_usuario(u)) cout << "error: el usuario no existe" << endl;
			else if (!cu.consul_insc(u)) cout << "error: usuario no inscrito en ningun curso" << endl;
      else cu.cjt_problemas_enviables(u);
    }

    else if (comando == "envio" or comando == "e") {
			cout << '#' << comando << ' ';
      int r;
      string u, p;
      cin >> u >> p >> r;
      cout << u << ' ' << p << ' ' << r << endl;
      cu.actualizar_usuario(u, p, r, cs, cc);
      cp.actualizar_problema(p, r);
    }

    else if (comando == "listar_problemas" or comando == "lp") {
			cout << '#' << comando << endl;
      cp.escribir_cjt_problemas();
    }

    else if (comando == "escribir_problema" or comando == "ep") {
      string p;
      cin >> p;
			cout << '#' << comando << ' ' << p << endl;
      if (!cp.buscar_problema(p)) {
        cout << "error: el problema no existe" << endl;
      }
      else {
        cp.escribir_problema(p);
      }
    }

    else if (comando == "listar_sesiones" or comando == "ls") {
			cout << '#' << comando << endl;
      cs.escribir_cjt_sesiones();
    }

    else if (comando == "escribir_sesion" or comando == "es") {
      string s;
      cin >> s;
			cout << '#' << comando << ' ' << s << endl;
      if (!cs.buscar_sesion(s)) {
        cout << "error: la sesion no existe" << endl;
      }
      else {
        cs.escribir_sesion(s);
				cout << endl;
      }
    }

    else if (comando == "listar_cursos" or comando == "lc") {
			cout << '#' << comando << endl;
      cc.escribir_cjt_cursos();
    }

    else if (comando == "escribir_curso" or comando == "ec") {
      int c;
      cin >> c;
			cout << '#' << comando << ' ' << c << endl;
      if (!cc.buscar_curso(c)) {
        cout << "error: el curso no existe" << endl;
      }
      else {
        cc.escribir_curso(c);
      }
    }

    else if (comando == "listar_usuarios" or comando == "lu") {
			cout << '#' << comando << endl;
      cu.escribir_cjt_usuarios();
    }

    //(comando == "escribir_usuario" or comando == "eu")
    else {
      string u;
      cin >> u;
			cout << '#' << comando << ' ' << u << endl;
      if (!cu.buscar_usuario(u)) {
        cout << "error: el usuario no existe" << endl;
      }
      else {
        cu.escribir_usuario(u);
      }
    }
    cin >> comando;
  }
}
