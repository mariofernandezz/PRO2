/** @file Usuario.cc
    @brief Código de la clase Usuario
*/

#include "Usuario.hh"


Usuario::Usuario() {
  registrado = false;
  intentos = 0;
  aciertos = 0;
  problemas_tot = 0;
}


void Usuario::registrar_usuario(int c) {
  registrado = true;
  curs = c;
}


bool Usuario::consultar_registro() const {
  return registrado;
}

int Usuario::intentos_correctos() const {
  return aciertos;
}

void Usuario::sumar_aciertos(string p) {
	++aciertos;
	map<string, Problema>::iterator it2 = envi.find(p);
	int x = it2->second.consultar_envios();
	res.insert(make_pair(p, Problema(x)));
}

bool Usuario::curso_acabado_2() const {
	return envi.empty();
}

void Usuario::baja_usuario_2() {
	registrado = false;
	curs = 0;
}


int Usuario::intentos_envios() const {
  return intentos;
}


void Usuario::sumar_intentos(string p) {
	++intentos;
	map<string, Problema>::iterator it2 = envi.find(p);
	it2->second.sumar_intentos_2();
}

void Usuario::insertar_enviable(string p) {
	Problema pro;
	envi.insert(make_pair(p, pro));
}

bool Usuario::comprovar_historico(string p) const {
	map<string, Problema>::const_iterator it = res.find(p);
	if (it == res.end()) return false;
	else return true;
}

int Usuario::intentos_problemas() {
	problemas_tot = res.size();
	for (map<string, Problema>::iterator it = envi.begin(); it != envi.end(); ++it) {
		if (it->second.consultar_envios() != 0) ++problemas_tot;
	}
  return problemas_tot;
}

int Usuario::id_registro() const{
  return curs;
}

void Usuario::restar_enviable(string p) {
	envi.erase(p);
}

void Usuario::escribir_resul() {
  for (map<string, Problema>::iterator it = res.begin(); it != res.end(); ++it) {
    cout << it->first << '(' << it->second.consultar_envios() << ')' << endl;
  }
}


void Usuario::escribir_enviables() {
  for (map<string, Problema>::iterator it = envi.begin(); it != envi.end(); ++it) {
    cout << it->first << '(' << it->second.consultar_envios() << ')' << endl;
  }
}
