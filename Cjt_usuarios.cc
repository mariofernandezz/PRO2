/** @file Cjt_usuarios.cc
    @brief Código de la clase Cjt_usuarios
*/

#include "Cjt_usuarios.hh"


Cjt_usuarios::Cjt_usuarios() {}


int Cjt_usuarios::total_cjt_usuarios() const {
	return c_usuario.size();
}

bool Cjt_usuarios::alta_usuario(string idenu) {
  pair<map<string, Usuario>::iterator, bool> p;
	Usuario u;
  p = c_usuario.insert(make_pair(idenu, u));
  return p.second;
}

void Cjt_usuarios::baja_usuario(const string u) {
  c_usuario.erase(u);
	cout << c_usuario.size() << endl;
}


void Cjt_usuarios::inscribir(string u, int curs, Cjt_cursos& cc, Cjt_sesiones& cs) {
	cout << cc.inscribir_c(curs) << endl;
	map<string, Usuario>::iterator it1 = c_usuario.find(u);
  it1->second.registrar_usuario(curs);
	map<string, Usuario>::iterator it = c_usuario.find(u);
	int i = cc.total_sesiones(curs);
	int count = 1;
	while (count<=i) {
		string ses = cc.buscar_id_sesion(curs, count);
		string prob = cs.buscar_raiz(ses);
		int c = it->second.id_registro();
		string s = cc.problema_pertenece_ses(prob, c);
		cs.buscar_interseccion_inscribirse(prob, s, it->second);
		++count;
	}
}


bool Cjt_usuarios::consul_insc(const string u) const {
  bool reg = false;
  map<string, Usuario>::const_iterator it = c_usuario.find(u);
  if (it->second.consultar_registro()) reg = true;
  return reg;
}

int Cjt_usuarios::consul_iden_usu(string u) const {
  map<string, Usuario>::const_iterator it = c_usuario.find(u);
  return it->second.id_registro();
}

bool Cjt_usuarios::buscar_usuario(string u) const{
    bool trobat = false;
    map<string, Usuario>::const_iterator it = c_usuario.find(u);
    if (it != c_usuario.end()) trobat = true;
    return trobat;
}

void Cjt_usuarios::actualizar_usuario(string u, string p, int resultado, Cjt_sesiones& cs, Cjt_cursos& cc) {
	map<string, Usuario>::iterator it = c_usuario.find(u);
		it->second.sumar_intentos(p);
		if (resultado == 1) {
			int c = it->second.id_registro();
			string s = cc.problema_pertenece_ses(p, c);
			bool found = cs.buscar_interseccion(p, s, it->second);
			it->second.sumar_aciertos(p);
			it->second.restar_enviable(p);
			if (it->second.curso_acabado_2() or !found) {
				it->second.baja_usuario_2();
				cc.sumar_acabado(c);
			}
		}
}

bool Cjt_usuarios::curso_acabado(string u) const {
	map<string, Usuario>::const_iterator it = c_usuario.find(u);
	return it->second.curso_acabado_2();
}


void Cjt_usuarios::leer_cjt_usuarios() {
  int tot;
  cin >> tot;
  for (int i = 1; i <= tot; ++i) {
    string id;
    cin >> id;
		Usuario u;
    c_usuario.insert(make_pair(id,u));
  }
}

void Cjt_usuarios::cjt_problemas_resueltos(string u) {
  map<string, Usuario>::iterator it1 = c_usuario.find(u);
  it1->second.escribir_resul();
}

void Cjt_usuarios::cjt_problemas_enviables(string u){
  map<string, Usuario>::iterator it1 = c_usuario.find(u);
	it1->second.escribir_enviables();
}


void Cjt_usuarios::escribir_cjt_usuarios() {
  for (map<string, Usuario>::iterator it = c_usuario.begin(); it != c_usuario.end(); ++it) {
    cout << it->first << '(' << it->second.intentos_envios() << ',';
    cout << it->second.intentos_correctos() << ',';
    cout << it->second.intentos_problemas() << ',';
    if (!it->second.consultar_registro()) cout << "0)" << endl;
    else {
      cout << it->second.id_registro() << ')' << endl;
    }
  }
}

void Cjt_usuarios::escribir_usuario(const string u) {
  if (!buscar_usuario(u)) cout << "error: el usuario no existe" << endl;
  else {
    map<string, Usuario>::iterator it = c_usuario.find(u);
    cout << u << '(' << it->second.intentos_envios() << ',';
    cout << it->second.intentos_correctos() << ',';
    cout << it->second.intentos_problemas() << ',';
    if (!it->second.consultar_registro()) cout << "0)" << endl;
    else {
      cout << it->second.id_registro() << ')' << endl;
    }
  }
}
