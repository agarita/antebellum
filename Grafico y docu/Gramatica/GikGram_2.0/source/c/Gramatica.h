/*
 * Gramatica.h
 *
 * 2019/04/28 22:34:32
 *
 * Archivo generado por GikGram 2.0
 *
 * Copyright � Olminsky 2011 Derechos reservados
 * Reproducci�n sin fines de lucro permitida
 */
#pragma once

#ifndef INC_Gramatica_h_
	#define INC_Gramatica_h_

	/* Constantes necesarias para un driver de parsing */
	#define TERMINAL(X)  ((0 <= (X)) && ((X) <= 123))
	#define NO_TERMINAL(X)  ((124 <= (X)) && ((X) <= 227))
	#define MARCA_DERECHA 123
	#define NO_TERMINAL_INICIAL 124
	#define MAX_LADO_DER 3

	/* Constantes con las rutinas sem�nticas */
	/* NO SE DETECTARON S�MBOLOS SEM�NTICOS EN LA GRAM�TICA */

	/* Prototipos de las tablas */
	extern const int TablaParsing[104][NO_TERMINAL_INICIAL];
	extern const int LadosDerechos[198][MAX_LADO_DER];

#endif /* INC_Gramatica_h_ */
