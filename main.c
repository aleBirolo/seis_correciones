/// Birolo ALejandro 36072015
#include "main.h"
#include <string.h>

int main()
{
    FILE *fp;
    FILE *fpTemp;
    char linea[TAM_LINEA]={};
    char *ptrIniPalabra,
         *ptrFinPalabra,
         *ptrCad,
         *pIniInverso,
         *pFinInverso;
    int cant;

    abrirArchivo(&fp, NOM_ARCH_TXT, "w");
    fprintf(fp, "%s\n", "Esta, Es una Linea.");
    fclose(fp);

    abrirArchivo(&fp, NOM_ARCH_TXT, "r");
    abrirArchivo(&fpTemp, NOM_ARCH_TXT_TEMP, "w");


    while(fgets(linea, 500, fp))
    {
        printf("%s",linea);
        ptrIniPalabra = linea;
        ptrCad=str_chr(linea, ' ');
        pIniInverso=str_rchr(linea, ' ');
        pFinInverso=linea;
        pFinInverso+=str_len(linea)-1;
        ptrFinPalabra = ptrCad;
        cant = cantidadLetras(pIniInverso, pFinInverso);

        while (*ptrCad)
        {

            ofuscar(ptrIniPalabra, ptrFinPalabra-1, -cant ); /// agregue un -1 (1ra correcion)
            ptrIniPalabra = ptrCad;
            ptrCad=str_chr(ptrIniPalabra + 1, ' ');
            ptrFinPalabra = ptrCad;
            pIniInverso=str_rchr(linea, ' ');
            pFinInverso=linea;
            pFinInverso+=str_len(linea)-1;
            cant = cantidadLetras(pIniInverso, pFinInverso);
        }
        ofuscar(ptrIniPalabra, ptrFinPalabra, -cant );
        fprintf(fpTemp, "%s\n", linea);
    }
    fclose(fp);
    fclose(fpTemp);

    remove(NOM_ARCH_TXT);
    rename(NOM_ARCH_TXT_TEMP,NOM_ARCH_TXT);

    return 0;
}


booleano abrirArchivo (FILE **fp, const char *nom, const char *modo)
{
    *fp=fopen(nom, modo);

    if (!*fp)
    {
        printf ("\n Error al abrir el arhivo: %s en modo %s", nom, modo);
        return falso;
    }
    return verdadero;
}

int cantidadLetras(const char *ini,const char *fin)
{
    char *aux=(char *)ini;
    int n=0;

    while (ini<=fin)
    {
        if ( ES_LETRA(*ini) )
            n++;
        ini++;
    }
    ini=aux;
    return n;
}

int posicionVocal (const char cad)
{
    int n=0;

    if (ES_MINUS(cad))
    {
        switch(cad)
        {
        case 'a':
            return 1;
        case 'e':
            return 2;
        case 'i':
            return 3;
        case 'o': /// puse un cero -> merezco el peor de los castigos (2da correcion)
            return 4;
        case 'u':
            return 5;
        }
    }
    else
    {
        switch(cad)
        {
        case 'A':
            return 1;
        case 'E':
            return 2;
        case 'I':
            return 3;
        case 'O':
            return 4;
        case 'U':
            return 5;
        }

    }


    return n;
}

void ofuscar (char *ini, char *fin, int offset)
{
    int posVocal;
    int auxOfsset= offset;
    int espacioOffset;
    char reem;
    char z='z';
    ///char A='A';
    char Z='Z'; /// esta iba    (3ra correcion)
    while (ini <= fin)
    {
        offset = auxOfsset;

        if (ES_LETRA(*ini)) /// agregue este if (4ta correcion)
        {
            if (ES_MAYUS(*ini))
            espacioOffset = *ini - 'A';

            if (ES_MINUS(*ini))
                espacioOffset = *ini - 'a';

           /// if (offset > (espacioOffset *(-1)))
                ///offset+=espacioOffset;

           if ( (-1)*offset > espacioOffset )  ///(5ta y 6ta correcion (la sexta es meterlo en un if))
           {
                offset+=espacioOffset;
                offset++;

                if (ES_MAYUS(*ini))
                    reem = z + offset;

                if (ES_MINUS(*ini))
                    reem = Z + offset;      ///(es la 3ra correcion)
                    ///reem =  A + offset;
           }
           else
           {
               reem= *ini + offset;
           }

            *ini=reem;

            if (ES_VOCAL(*ini))
            {
                posVocal= posicionVocal(*ini);
                *ini = (char)'0' + posVocal;
            }
        }


        printf ("%c", *ini);
        ini++;
    }
}
