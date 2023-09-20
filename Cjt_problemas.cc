/** @file Cjt_problemas.cc
    @brief Código de la clase Cjt_problemas
*/

#include "Cjt_problemas.hh"





Cjt_problemas::Cjt_problemas() {}

bool Cjt_problemas::buscar_problema(string p) const{
  bool trobat = false;
  map<string, Problema>::const_iterator it = c_problema.find(p);
  if (it != c_problema.end()) trobat = true;
  return trobat;
}

int Cjt_problemas::total_cjt_problemas() const {
  return c_problema.size();
}


bool Cjt_problemas::nuevo_problema(string idenp) {
  pair<map<string, Problema>::iterator, bool> p;
	Problema pro;
  p = c_problema.insert(make_pair(idenp, pro));
  return p.second;
}

void Cjt_problemas::actualizar_problema(string p, int resultado){
	map<string, Problema>::iterator it = c_problema.find(p);
	it->second.sumar_intentos_2();
	if (resultado == 1) it->second.sumar_aciertos_2();
}

void Cjt_problemas::leer_cjt_problemas() {
  int tot;
  cin >> tot;
  for (int i = 1; i <= tot; ++i) {
    string id;
    cin >> id;
    Problema p;
    c_problema.insert(make_pair(id,p));
  }
}

bool Cjt_problemas::comp(const pair<string,double>& num1, const pair<string,double>& num2) {
	if(num1.second < num2.second) return true;
	else if (num1.second == num2.second) return num1.first < num2.first;
	else return false;
}

void Cjt_problemas::escribir_cjt_problemas() {
	vector<pair<string,double>> v;
  for (map<string, Problema>::const_iterator it = c_problema.begin(); it != c_problema.end(); ++it) {
		pair <string,double> p;
		p.first = it->first;
		double x = double(it->second.consultar_en_correctos()) + 1.0;
		double y = double(it->second.consultar_envios()) + 1.0;
		p.second = y/x;
		v.push_back(p);
	}
	sort (v.begin(), v.end(), comp);
	for (int i = 0; i <= v.size()-1; ++i) {
		pair<string,double> p2 = v[i];
    cout << p2.first << '(' << consultar_envios2(p2.first) << ',';
    cout << consultar_en_correctos2(p2.first) << ',';
    cout << p2.second << ')' << endl;
  }
}

int Cjt_problemas::consultar_envios2(const string p) const {
	map<string, Problema>::const_iterator it = c_problema.find(p);
	return it->second.consultar_envios();
}

int Cjt_problemas::consultar_en_correctos2(const string p) const {
	map<string, Problema>::const_iterator it = c_problema.find(p);
	return it->second.consultar_en_correctos();
}


void Cjt_problemas::escribir_problema(string p) {
    map<string, Problema>::const_iterator it = c_problema.find(p);
    cout << p << '(' << it->second.consultar_envios() << ',';
    cout << it->second.consultar_en_correctos() << ',';
    cout << (double(it->second.consultar_envios()) + 1.0)/(double(it->second.consultar_en_correctos()) + 1.0) << ')' << endl;
  }
