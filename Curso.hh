/** @file Curso.hh
    @brief Especificación de la clase Curso
*/


#ifndef _CURSO_HH_
#define _CURSO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#endif



/** @class Curso
    @brief Representa un curso de la plataforma

		Ofrece operaciones para modificar, consultar, leer y escribir un curso.
*/

class Curso
{
public:
  //Constructoras

  /** @brief Creadora por defecto.

			Se ejecuta automáticamente al declarar un curso.
      \pre <em>cierto</em>
      \post El resultado es un curso sin inicializar.
  */
  Curso();

  //Modificadoras

  /** @brief Modifica el numero de usuarios actuales del curso

      \pre <em>cierto</em>
      \post Se suma un usuario nuevo al número de usuarios totales cursando el
			curso.
  */
  int sumar_usu();

	/** @brief Modifica el numero de usuarios actuales del curso

      \pre Hay al menos un usuario cursando el curso.
      \post Se resta un usuario al número de usuarios totales cursando el curso
			debido a que el usuario se ha dado de baja.
  */
  void restar_usu();

	/** @brief Modifica el numero de sesiones del curso

			\pre No existe intersección de problemas entre las sesiones que pertenecen
			al mismo grupo.
			\post Se suma una sesió nueva al número total de sesiones y se guarda su
			identificador.
	*/
	void nuevo_curso_ses_2(string s);

	/** @brief Modifica el numero usuarios actuales y historicos

			\pre Había como mínimo un usuario cursando el curso.
			\post Se suma un usuario al número total de ellos que han completado el
			curso y se resta un usuario al número total de los que lo están cursando
			actualmente, ya que ya ha completado el curso.
	*/
  void sumar_acabado_2();

	/** @brief Añade nuevos problemas de una sesion al curso

			\pre <em>cierto</em>
			\post El resultado es true si al añadir un nuevo problema de una sesion no
			no había ningun otro problema igual en el mismo curso y el false en el
			caso que ya existiera otro problema con el mismo identificador.
	*/
	bool nuevo_prob_ses(string ses, string p);



  //Consultoras

  /** @brief Consulta los usuarios actuales

      \pre <em>cierto</em>
      \post El resultado es el número de usuarios que están cursando el curso
			actualmente.
  */
  int consultar_usu_act() const;

  /** @brief Consulta los usuarios historicos

      \pre <em>cierto</em>
      \post El resultado es el número de usuarios que han completado el curso.
  */
  int consultar_usu_historicos() const;

  /** @brief Consulta cuantas sesiones hay en el curso

      \pre <em>cierto</em>
      \post El resultado es el total de sesiones que hay en el curso.
  */
  int consultar_num_sesiones() const;

	/** @brief Consulta el identificador de la sesion

      \pre Hay mínimo i sesiones en la plataforma.
      \post El resultado es el identificador de la sesion indicada por i.
  */
	string buscar_id_sesion_2(int i) const;

	/** @brief Consulta el identificador de la sesion a la que pertenece un problema

			\pre <em>cierto</em>
			\post El resultado es el identificador de la sesion a la cual pertenece el
			problema p, si el problema p no esta en el curso, devuelve "no".
	*/
	string problema_pertenece_ses_2(string p) const;


  //Escritura

  /** @brief Operación de escritura de cursos en la plataforma actualmente

      \pre <em>cierto</em>
      \post Se escriben los identificadores de las sesiones del curso.
  */
  void escribir_c();


  //Lectura

  /** @brief Operación de lectura un curso

      \pre <em>cierto</em>
      \post Se han leido los parametros de la entrada y guardado
      en una variable Curso.
  */
  void leer_curso();


private:

	/** @brief Contiene los identificadores de las sesiones del curso */
  vector<string> mes;
	/** @brief Número de usuarios actuales cursando el curso */
  int usuarios_actu;
	/** @brief Número de usuarios que han completado el curso */
  int usuarios_historicos;
	/** @brief Número de sesiones que forman el curso */
  int numero_sesiones;

	/** @brief Map de los problemas y las sesiones del curso

	Contiene el identificador de los problemas ordenados junto a la sesion que
	pertenecen: primer string(problemas), segundo(sesion) */
  map<string, string> prob_ses;
};
#endif
