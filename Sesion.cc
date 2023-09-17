/** @file Sesion.cc
    @brief Código de la clase Sesion
*/

#include "Sesion.hh"


Sesion::Sesion() {
  problemas_totales = 0;
}

bool Sesion::buscar_prob_sesion(string p) const {
	return buscar(requisitos, p);
}


bool Sesion::buscar_interseccion_2(string p, Usuario& usu) {
	return buscar_int(requisitos, p, usu);
}

bool Sesion::buscar_interseccion_inscribirse_2(string p, Usuario& usu) {
	return buscar_int_insc(requisitos, p, usu);
}


string Sesion::devolver_sesion_2(int posicion) const {
	return prob[posicion];
}


void Sesion::escribirses() {
  escribir(requisitos);
}


string Sesion::raiz() const{
	return requisitos.value();
}

int Sesion::tot_problemas() const {
  return problemas_totales;
}

void Sesion::leer_sesion() {
	string marca = "0";
  leer(requisitos, marca);
}


void Sesion::escribir(const BinTree<string> &a) {
  if (not a.empty()) {
    string x = a.value();
    cout << '(';
    escribir(a.left());
    escribir(a.right());
    cout << x << ')';
  }
}


bool Sesion::buscar(const BinTree<string>& a,string p) {
  if(a.empty()) return false;
	else if (a.value()==p) return true;
	else return (buscar(a.left(),p) or buscar(a.right(),p));
}


void Sesion::leer(BinTree<string>& a, string marca) {
  string x;
  cin >> x;
  if (x!=marca) {
		prob.push_back(x);
    BinTree<string> l;
    leer(l, marca);
    BinTree<string> r;
    leer(r, marca);
    a = BinTree<string>(x,l,r);
		++problemas_totales;
  }
}

//Actualiza problemas enviables al recibir una orden de envio
bool Sesion::buscar_int(const BinTree<string>& a, string p, Usuario& usu) {
	if(a.empty()) return false;
	else if (a.value()==p) {
			if (a.right().empty() and a.left().empty()) return true;
			else if (!a.right().empty() and a.left().empty()) {
				bool f = usu.comprovar_historico(a.right().value());
				if (!f) {
					usu.insertar_enviable(a.right().value());
					return true;
				}
				else return buscar_int(a.right(), a.right().value(), usu);
			}
			else if (a.right().empty() and !a.left().empty()) {
				bool f2 = usu.comprovar_historico(a.left().value());
				if (!f2) {
					usu.insertar_enviable(a.left().value());
					return true;
				}
				else return buscar_int(a.left(), a.left().value(), usu);
			}
			else {
				bool f3 = usu.comprovar_historico(a.right().value());
				bool f4 = usu.comprovar_historico(a.left().value());
				if (!f3 and !f4) {
					usu.insertar_enviable(a.left().value());
					usu.insertar_enviable(a.right().value());
					return true;
				}
				else if (!f3 and f4) {
					usu.insertar_enviable(a.right().value());
					return buscar_int(a.left(), a.left().value(), usu);
				}
				else if (f3 and !f4) {
					usu.insertar_enviable(a.left().value());
					return buscar_int(a.right(), a.right().value(), usu);
				}
				else return (buscar_int(a.right(), a.right().value(),usu) and buscar_int(a.left(), a.left().value(),usu));
			}
		}
	else return (buscar_int(a.left(),p, usu) or buscar_int(a.right(),p, usu));
}


//Actualiza problemas enviables al recibir una orden de inscripcion
bool Sesion::buscar_int_insc(const BinTree<string>& a, string p, Usuario& usu) {
	if(a.empty()) return false;
	else if (a.value()==p) {
		bool f = usu.comprovar_historico(a.value());
		if (!f) {
			usu.insertar_enviable(a.value());
			return true;
		}
		else {
			if (a.right().empty() and a.left().empty()) return true;
			else if (a.right().empty() and !a.left().empty()) {
				bool f2 = usu.comprovar_historico(a.left().value());
				if (!f2) {
					usu.insertar_enviable(a.left().value());
					return true;
				}
				else return buscar_int_insc(a.left(), a.left().value(), usu);
			}
			else if (!a.right().empty() and a.left().empty()) {
				bool f5 = usu.comprovar_historico(a.right().value());
				if (!f5) {
					usu.insertar_enviable(a.right().value());
					return true;
				}
				else return buscar_int_insc(a.right(), a.right().value(), usu);
			}
			else {
				bool f3 = usu.comprovar_historico(a.right().value());
				bool f4 = usu.comprovar_historico(a.left().value());
				if (!f3 and !f4) {
					usu.insertar_enviable(a.left().value());
					usu.insertar_enviable(a.right().value());
					return true;
				}
				else if (!f3 and f4) {
					usu.insertar_enviable(a.right().value());
					return buscar_int_insc(a.left(), a.left().value(), usu);
				}
				else if (f3 and !f4) {
					usu.insertar_enviable(a.left().value());
					return buscar_int_insc(a.right(), a.right().value(), usu);
				}
				else return (buscar_int_insc(a.left(), a.left().value(),usu) and buscar_int_insc(a.right(), a.right().value(),usu));
			}
		}
	}
			else return (buscar_int_insc(a.left(),p, usu) or buscar_int_insc(a.right(),p, usu));
}
