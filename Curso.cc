/** @file Curso.cc
    @brief Código de la clase Curso
*/

#include "Curso.hh"


Curso::Curso() {
  usuarios_actu = 0;
  usuarios_historicos = 0;
  numero_sesiones = 0;
}

int Curso::sumar_usu() {
  ++usuarios_actu;
  return usuarios_actu;
}

void Curso::restar_usu() {
	--usuarios_actu;
}

int Curso::consultar_usu_act() const {
  return usuarios_actu;
}

int Curso::consultar_num_sesiones() const {
  return numero_sesiones;
}

int Curso::consultar_usu_historicos() const {
  return usuarios_historicos;
}

string Curso::buscar_id_sesion_2(int i) const {
	return mes[i-1];
}

bool Curso::nuevo_prob_ses(string ses, string p) {
	pair<map<string, string>::iterator, bool> found;
	found = prob_ses.insert(make_pair(p, ses));
	return found.second;
}

void Curso::nuevo_curso_ses_2(string s) {
	mes.push_back(s);
	++numero_sesiones;
}

string Curso::problema_pertenece_ses_2(string p) const{
	map<string, string>::const_iterator it = prob_ses.find(p);
	if (it==prob_ses.end()) return "no";
	else return it->second;
}

void Curso::sumar_acabado_2() {
  ++usuarios_historicos;
	--usuarios_actu;
}


void Curso::escribir_c(){
	cout << '(' << mes[0];
  for (int i = 2; i <=mes.size(); ++i) {
    cout << ' ' << mes[i-1];
  }
  cout << ')' << endl;
}

void Curso::leer_curso() {
  int x;
  cin >> x;
  for (int j = 1; j <= x; ++j) {
    string id;
    cin >> id;
    mes.push_back(id);
    ++numero_sesiones;
  }
}
