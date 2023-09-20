/** @file Cjt_sesiones.cc
    @brief Código de la clase Cjt_sesiones
*/

#include "Cjt_sesiones.hh"


Cjt_sesiones::Cjt_sesiones() {}

bool Cjt_sesiones::nueva_sesion(string idens) {
  pair<map<string, Sesion>::iterator, bool> s;
	Sesion ses;
	ses.leer_sesion();
  s = c_sesion.insert(make_pair(idens, ses));
  return s.second;
}

int Cjt_sesiones::total_cjt_sesiones() const {
	return c_sesion.size();
}

int Cjt_sesiones::problemas_totales(string ses) const {
	map<string, Sesion>::const_iterator it = c_sesion.find(ses);
		return it->second.tot_problemas();
}

string Cjt_sesiones::buscar_raiz(string ses) const {
	map<string, Sesion>::const_iterator it = c_sesion.find(ses);
	return it->second.raiz();
}

bool Cjt_sesiones::buscar_sesion(string iden) const {
  bool trobat = false;
  map<string, Sesion>::const_iterator it = c_sesion.find(iden);
  if (it != c_sesion.end()) trobat = true;
  return trobat;
}

string Cjt_sesiones::devolver_sesion(string ses, int posicion) const {
	map<string, Sesion>::const_iterator it = c_sesion.find(ses);
	return it->second.devolver_sesion_2(posicion);
}

bool Cjt_sesiones::buscar_interseccion(const string p, const string ses, Usuario& usu) {
	map<string, Sesion>::iterator it = c_sesion.find(ses);
	return it->second.buscar_interseccion_2(p, usu);
}
bool Cjt_sesiones::buscar_interseccion_inscribirse (const string p, const string ses, Usuario& usu) {
	map<string, Sesion>::iterator it = c_sesion.find(ses);
	return it->second.buscar_interseccion_inscribirse_2(p, usu);
}

bool Cjt_sesiones::buscar_prob_ses(string iden, string p) const{
	map<string, Sesion>::const_iterator it = c_sesion.find(iden);
	bool f = it->second.buscar_prob_sesion(p);
	return f;
}


void Cjt_sesiones::leer_cjt_sesiones() {
  int x;
  cin >> x;
  for (int i = 1; i <= x; ++i) {
    string id;
    cin >> id;
    Sesion s;
		s.leer_sesion();
    c_sesion.insert(make_pair(id,s));
  }
}

void Cjt_sesiones::escribir_cjt_sesiones() {
  for (map<string, Sesion>::iterator it = c_sesion.begin(); it != c_sesion.end(); ++it) {
    cout << it->first << ' ' << it->second.tot_problemas() << ' ';
    it->second.escribirses();
		cout << endl;
  }
}

void Cjt_sesiones::escribir_sesion(string s) {
  if(!buscar_sesion(s)) cout << "error: la sesion no existe";
  else {
    map<string, Sesion>::iterator it = c_sesion.find(s);
    cout << s << ' ' << it->second.tot_problemas() << ' ';
    it->second.escribirses();
  }
}
