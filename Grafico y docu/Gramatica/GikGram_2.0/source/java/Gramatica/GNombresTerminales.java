/*
 * GNombresTerminales.java
 *
 * 2019/04/28 22:34:32
 *
 * Archivo generado por GikGram 2.0
 *
 * Copyright © Olminsky 2011 Derechos reservados
 * Reproducción sin fines de lucro permitida
 */

package Gramatica;

/**
 * Esta clase contiene los nombres de los terminales
 * y los métodos necesarios para acceder a ella
 */
abstract class GNombresTerminales
{
	/**
	 * Contiene los nombres de los terminales
	 */
	private static final String[] NombresTerminales =
	{
		"aeger",
		"auctum",
		"aut",
		"autem",
		"casus",
		"catena",
		"certus",
		"claudeo",
		"commutabilis",
		"coniugo",
		"corpus",
		"decrementum",
		"detrimentum",
		"directus",
		"dito",
		"dixi",
		"dualis",
		"efficio",
		"est",
		"et",
		"exemplar",
		"falsidicus",
		"finis",
		"firmamentum",
		"fractio",
		"furibundus",
		"gradus",
		"ign",
		"imago",
		"impono",
		"in",
		"incrementum",
		"initum",
		"itero",
		"lectio",
		"liber",
		"ligo",
		"mentiri",
		"neco",
		"nomen",
		"non",
		"numerus",
		"opus",
		"ordo",
		"panis",
		"patentibus",
		"pergo",
		"perpetuus",
		"prope",
		"quantus",
		"reditus",
		"scripturam",
		"sigla",
		"sum",
		"tempus",
		"usque",
		"veridicus",
		"xaut",
		"literalEntero",
		"literalCaracter",
		"literalString",
		"literalFecha",
		"literalFraccion",
		"ID",
		"<-",
		"->",
		"diem",
		".",
		"(",
		")",
		",",
		"[",
		"]",
		"{",
		"}",
		":",
		":=",
		"+=",
		"-=",
		"*=",
		"/=",
		"%=",
		"|+=",
		"|-=",
		"||=",
		"|^=",
		"|/=",
		"|*=",
		"et=",
		"xaut=",
		"aut=",
		"-",
		"+",
		"/",
		"*",
		"%",
		"|+",
		"|-",
		"||",
		"|^",
		"|/",
		"|*",
		"[<<]",
		"[>>]",
		"[&?]",
		"[#?]",
		"&+",
		"&#",
		"&?",
		"&",
		"|<",
		"|>",
		">",
		"<",
		"=",
		">=",
		"<=",
		"><",
		"@",
		"@@",
		"Lego",
		"Scribo",
		"ReScribo",
		" EOF "
	};

	/**
	 * Método getNombresTerminales
			Obtiene el nombre del terminal
	 * @param numTerminal
			Número del terminal
	 */
	static final String getNombresTerminales(int numTerminal)
	{
		return NombresTerminales[numTerminal];
	}
}
