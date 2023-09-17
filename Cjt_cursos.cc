/** @file Cjt_cursos.cc
    @brief Código de la clase Cjt_cursos
*/

#include "Cjt_cursos.hh"


Cjt_cursos::Cjt_cursos() {}

bool Cjt_cursos::buscar_curso(int c) const{
  bool trobat = false;
	if(c_curso.size()>= c and c!=0) trobat = true;
	return trobat;
}

int Cjt_cursos::total_sesiones(int c) const {
	return c_curso[c-1].consultar_num_sesiones();
}

	//Utilizado para la comanda nuevo curso y por eso tiene que comprobar errores
	void Cjt_cursos::crear_nuevo_curso(Cjt_sesiones& cs, Cjt_cursos& cc) {
		int tot_ses, i = 1;
		cin >> tot_ses;
		bool found = true;
		string new_ses;
		cc.curso_vacio();
		while (found and i <= tot_ses) {
			cin >> new_ses;
			int prob_tot = cs.problemas_totales(new_ses);
			int j = 0;
			while (found and j < prob_tot) {
				string p = cs.devolver_sesion(new_ses, j);
				found = cc.nuevo_curso(new_ses, p);
				++j;
			}
			if (found) cc.nuevo_curso_ses(new_ses);
			++i;
		}

		if (!found and i-1 == tot_ses) {
			cout << "error: curso mal formado" << endl;
			cc.borrar_curso();
		}
		else if (!found and i-1 < tot_ses) {
			while (i-1 != tot_ses) {
				cin >> new_ses;
				++i;
			}
			cout << "error: curso mal formado" << endl;
			cc.borrar_curso();
		}
		else cout << cc.total_cursos() << endl;
}

bool Cjt_cursos::nuevo_curso(string ses, string p){
		int tam = c_curso.size();
		return c_curso[tam-1].nuevo_prob_ses(ses, p);
}

//Utilizado en la lectura inical de datos en la cual no pueden haber errores
void Cjt_cursos::crear_nuevo_curso_2(Cjt_sesiones& cs, Cjt_cursos& cc) {
	int tot_ses, i = 1;
	cin >> tot_ses;
	bool found = true;
	string new_ses;
	cc.curso_vacio();
	while (found and i <= tot_ses) {
		cin >> new_ses;
		int prob_tot = cs.problemas_totales(new_ses);
		int j = 0;
		while (found and j < prob_tot) {
			string p = cs.devolver_sesion(new_ses, j);
			found = cc.nuevo_curso(new_ses, p);
			++j;
		}
		if (found) cc.nuevo_curso_ses(new_ses);
		++i;
	}

	if (!found and i-1 == tot_ses) cc.borrar_curso();
	else if (!found and i-1 < tot_ses) {
		while (i-1 != tot_ses) {
			cin >> new_ses;
			++i;
		}
		cc.borrar_curso();
	}
}


void Cjt_cursos::nuevo_curso_ses(string s) {
	int tam = c_curso.size();
	c_curso[tam-1].nuevo_curso_ses_2(s);
}

string Cjt_cursos::buscar_id_sesion(int c, int i) const{
  return c_curso[c-1].buscar_id_sesion_2(i);
}

void Cjt_cursos::curso_vacio() {
	Curso c;
	c_curso.push_back(c);
}

void Cjt_cursos::borrar_curso() {
	c_curso.pop_back();
}

int Cjt_cursos::total_cursos() const {
	return c_curso.size();
}


int Cjt_cursos::inscribir_c(int c) {
	c_curso[c-1].sumar_usu();
	return c_curso[c-1].consultar_usu_act();
}

void Cjt_cursos::borrar_usu_actual(int c) {
	c_curso[c-1].restar_usu();
}

string Cjt_cursos::problema_pertenece_ses(string p, int c) const {
	return c_curso[c-1].problema_pertenece_ses_2(p);
}

void Cjt_cursos::sumar_acabado(int x) {
  c_curso[x-1].sumar_acabado_2();
}

void Cjt_cursos::leer_cjt_cursos(Cjt_sesiones& cs, Cjt_cursos& cc) {
  int y;
  cin >> y;
  for (int i = 1; i<=y; ++i) {
		/*Curso c;
		c.leer_curso();
  	c_curso.push_back(c);*/
		cc.crear_nuevo_curso_2(cs, cc);
  }
}

void Cjt_cursos::escribir_cjt_cursos() {
  for (int i = 0; i <=c_curso.size() -1; ++i) {
    cout << i+1 << ' ' << c_curso[i].consultar_usu_historicos() << ' ';
    cout << c_curso[i].consultar_usu_act() << ' ';
    cout << c_curso[i].consultar_num_sesiones() << ' ';
    c_curso[i].escribir_c();
  }
}

void Cjt_cursos::escribir_curso(int c) {
	if (c!=0) {
		cout << c << ' ' << c_curso[c-1].consultar_usu_historicos() << ' ';
		cout << c_curso[c-1].consultar_usu_act() << ' ';
		cout << c_curso[c-1].consultar_num_sesiones() << ' ';
		c_curso[c-1].escribir_c();
	}
	else cout << "error: el curso no existe" << endl;
}
