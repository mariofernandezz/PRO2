/** @file Problema.cc
    @brief Código de la clase Problema
*/

#include "Problema.hh"


Problema::Problema() {
  totales = 0;
  correctos = 0;
}


Problema::Problema(int tot) {
  totales = tot;
  correctos = 0;
}


void Problema::sumar_aciertos_2() {
	++correctos;
}

void Problema::sumar_intentos_2() {
	++totales;
}

int Problema::consultar_envios() const {
  return totales;
}


int Problema::consultar_en_correctos() const {
  return correctos;
}
