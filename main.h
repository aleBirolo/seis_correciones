/// Birolo ALejandro 36072015
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Cadena.h"

#define NOM_ARCH_TXT "archivo.txt"
#define NOM_ARCH_TXT_TEMP "archivoTemp.txt"
#define TAM_LINEA 500
#define ES_MAYUS(x) ('A'<=x && x<='Z')
#define ES_MINUS(x) ('a'<=x && x<='z')
#define ES_LETRA(x) ( ES_MAYUS(x) || ES_MINUS(x) )
#define ES_VOCAL(x) (x=='a' || x == 'e' || x== 'i' || x=='o' || x=='u' || x=='A' || x == 'E' || x== 'I' || x=='O' || x=='U')

typedef enum
{
    verdadero=1,
    falso=0
}booleano;

booleano abrirArchivo (FILE **fp, const char *nom, const char *modo);

int cantidadLetras(const char *ini,const char *fin);
int posicionVocal(const char cad);
void ofuscar (char *ini, char *fin, int offset);
#endif // MAIN_H_INCLUDED
