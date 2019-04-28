/*
 * GTablaFollows.java
 *
 * 2019/04/09 20:20:38
 *
 * Archivo generado por GikGram 2.0
 *
 * Copyright © Olminsky 2011 Derechos reservados
 * Reproducción sin fines de lucro permitida
 */

package Gramatica;

/**
 * Esta clase contiene la tabla de follows
 * y los métodos necesarios para acceder a ella
 */
abstract class GTablaFollows
{
	/**
	 * Tabla de follows
	 * Contiene los números de los terminales
	 * de los follows de cada no-terminal (filas)
	 */
	private static final int[][] TablaFollows =
	{
		/* <S> */ {Gramatica.MARCA_DERECHA,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Titulo> */ {Gramatica.MARCA_DERECHA,47,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <SecConst> */ {Gramatica.MARCA_DERECHA,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <DeclConsts> */ {Gramatica.MARCA_DERECHA,25,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Constante> */ {Gramatica.MARCA_DERECHA,63,25,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <InicioConst> */ {Gramatica.MARCA_DERECHA,56,21,58,59,60,62,61,73,64,63,-1,-1,-1,-1,-1,-1},
		/* <Valor> */ {Gramatica.MARCA_DERECHA,67,70,74,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Literal> */ {Gramatica.MARCA_DERECHA,67,70,74,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <LiteralBool> */ {Gramatica.MARCA_DERECHA,67,70,74,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Arreglo> */ {Gramatica.MARCA_DERECHA,67,70,74,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Registro> */ {Gramatica.MARCA_DERECHA,67,70,74,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Elementos> */ {Gramatica.MARCA_DERECHA,74,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <MasElementos> */ {Gramatica.MARCA_DERECHA,74,65,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <SecTipos> */ {Gramatica.MARCA_DERECHA,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <DeclTipos> */ {Gramatica.MARCA_DERECHA,8,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <InicioTipo> */ {Gramatica.MARCA_DERECHA,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Tipo> */ {Gramatica.MARCA_DERECHA,63,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Atomico> */ {Gramatica.MARCA_DERECHA,63,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <TipoRegistro> */ {Gramatica.MARCA_DERECHA,67,63,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <CierreRegistro> */ {Gramatica.MARCA_DERECHA,67,63,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Espacio> */ {Gramatica.MARCA_DERECHA,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <CierreEspacio> */ {Gramatica.MARCA_DERECHA,41,28,5,16,35,24,66,15,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <MasEspacio> */ {Gramatica.MARCA_DERECHA,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <InicioArreglo> */ {Gramatica.MARCA_DERECHA,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Dimension> */ {Gramatica.MARCA_DERECHA,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <CierreDimension> */ {Gramatica.MARCA_DERECHA,71,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <MasDimension> */ {Gramatica.MARCA_DERECHA,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <TipoArreglo> */ {Gramatica.MARCA_DERECHA,67,63,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <SecVars> */ {Gramatica.MARCA_DERECHA,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <DeclVars> */ {Gramatica.MARCA_DERECHA,20,32,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Variable> */ {Gramatica.MARCA_DERECHA,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <CierreVariable> */ {Gramatica.MARCA_DERECHA,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <MasVariables> */ {Gramatica.MARCA_DERECHA,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <SecProts> */ {Gramatica.MARCA_DERECHA,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <DeclPrototipos> */ {Gramatica.MARCA_DERECHA,10,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Prototipo> */ {Gramatica.MARCA_DERECHA,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <EncabProc> */ {Gramatica.MARCA_DERECHA,8,32,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <EncabFunc> */ {Gramatica.MARCA_DERECHA,8,32,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <CierreEncabFunc> */ {Gramatica.MARCA_DERECHA,8,32,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <InicioParams> */ {Gramatica.MARCA_DERECHA,67,75,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Parametros> */ {Gramatica.MARCA_DERECHA,69,67,75,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <DefParam> */ {Gramatica.MARCA_DERECHA,70,67,69,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Ign> */ {Gramatica.MARCA_DERECHA,63,41,28,5,16,35,24,66,9,43,-1,-1,-1,-1,-1,-1},
		/* <MasParams> */ {Gramatica.MARCA_DERECHA,69,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <TipoRet> */ {Gramatica.MARCA_DERECHA,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <SecRutinas> */ {Gramatica.MARCA_DERECHA,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <DeclRutinas> */ {Gramatica.MARCA_DERECHA,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Rutina> */ {Gramatica.MARCA_DERECHA,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Commutabilis> */ {Gramatica.MARCA_DERECHA,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Cuerpo> */ {Gramatica.MARCA_DERECHA,37,6,55,67,15,22,54,30,0,33,44,52,-1,-1,-1,-1},
		/* <Instrucciones> */ {Gramatica.MARCA_DERECHA,22,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Instrucción> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <While> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <InicioWhile> */ {Gramatica.MARCA_DERECHA,42,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <CierreInstr> */ {Gramatica.MARCA_DERECHA,55,67,15,54,30,0,33,44,52,22,-1,-1,-1,-1,-1,-1},
		/* <If> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <ThenElse> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <Else> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <Then> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <Switch> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <InicioSwitch> */ {Gramatica.MARCA_DERECHA,4,12,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Casos> */ {Gramatica.MARCA_DERECHA,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Caso> */ {Gramatica.MARCA_DERECHA,67,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <Default> */ {Gramatica.MARCA_DERECHA,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <CasosDefault> */ {Gramatica.MARCA_DERECHA,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <CasoDefault> */ {Gramatica.MARCA_DERECHA,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		/* <RepeatUntil> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <CierreRepeatU> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <For> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <ForAux> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <ForAux2> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <ForAux3> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <ForAux4> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <With> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <WithAux> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <WithAux2> */ {Gramatica.MARCA_DERECHA,54,30,0,33,44,52,55,67,15,22,-1,-1,-1,-1,-1,-1},
		/* <Expresion> */ {Gramatica.MARCA_DERECHA,6,37,32,54,30,0,33,44,52,67,1,26,42,55,15,22},
		/* <Entrada> */ {Gramatica.MARCA_DERECHA,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
	};

	/**
	 * Método getTablaFollows
			Obtiene el número de terminal del follow del no-terminal
	 * @param numNoTerminal
			Número de no-terminal
	 * @param numColumna
			Número de columna
	 */
	static final int getTablaFollows(int numNoTerminal, int numColumna)
	{
		return TablaFollows[numNoTerminal][numColumna];
	}
}
