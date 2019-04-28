#include <stdio.h>
#include <inttypes.h>
#include <iostream>
#include <unitypes.h>

/*
 * Los chars de c++ son de 1 byte, en contraste con los de antebellum, que son de 2bytes
 */


struct fractio{

    int16_t numerador;
    int16_t denominador;
    fractio(){}
    fractio(int16_t num, int16_t den){
        numerador=num;
        denominador=den;
    }
};

struct liber{
    char nombre[128]; //RECORDAR QUE EL PRIMER BYTE DE ESTO ES LA LONGITUD!!!!
    int16_t handle;
    uint8_t estado;
    char buffer[34];
};


void pruebaNumerus2Imago();
void pruebaNumerus2Fractio();
void pruebaNumerus2Catena();
void pruebaNumerus2Dualis();
void pruebaImago2Numerus();
void pruebaImago2Fractio();
void pruebaImago2Catena();
void pruebaImago2Dualis();
void pruebaDualis2Catena();
void pruebaDualis2Numerus();
void pruebaDualis2Fractio();
void pruebaDualis2Imago();
void pruebaFractio2Catena();
void pruebaFractio2Numerus();
void pruebaFractio2Dualis();
void pruebaFractio2Imago();
void pruebaCatena2Fractio();
void pruebaCatena2Numerus();
void pruebaCatena2Dualis();
void pruebaCatena2Imago();


extern "C" {
//TODO: Revisar las ligas de los sriboX (Esto no es parte de la entrega 0 :) )
//TODO: Arreglar comentarios en las funciones de asm


void    ionumerus();
int16_t legonumerus();
void    scribonumerus(int16_t string);

void    ioimago();
char    legoimago();
void    scriboimago(char* buff);

void    iocatena();
void    legocatena(char*buff);
void    scribocatena(char*buff);

void    iodualis();
int16_t     legodualis();
void    scribodualis(int16_t string);

void    iofractio();
void    legofractio(fractio* fr);
void    scribofractio(fractio* fr);

void    ioliber();
void    legoliber(liber* li);
void    scriboliber(liber* li);

void    iodiem();
int64_t legodiem();
void    scribodiem(int64_t num);


void numerus2catena(int16_t num, char*buff);
char    numerus2imago(int16_t num);
fractio numerus2fractio(int16_t num);
int16_t     numerus2dualis(int16_t num);

void imago2catena (char mychar, char*buff);
int16_t imago2numerus(char mychar);
fractio imago2fractio(char mychar);
int16_t     imago2dualis (char mychar);

void    dualis2catena (int16_t  mychar, char*buff);
int16_t dualis2numerus(int16_t  mychar);
fractio dualis2fractio(int16_t  mychar);
char    dualis2imago (int16_t  mychar);

void    fractio2catena   (fractio *myfrac, char*buff);
int16_t fractio2numerus  (fractio *myfrac);
int16_t fractio2dualis   (fractio *myfrac);
char    fractio2imago    (fractio *myfrac);

fractio catena2fractio   (char*buff);
int16_t catena2numerus  (char*buff);
int16_t catena2dualis   (char*buff);
char    catena2imago    (char*buff);

void diem2catena(int64_t num, char*buff);
int64_t catena2diem(char*buff);
void trimcatena(char*str);
int16_t valrom(char ch);
int16_t hexval(char* ch);

}


int main() {

    //ionumerus();
    //ioimago();
    //iocatena();
    //iodualis();
    //iofractio();
    //ioliber();
    //iodiem();

    //pruebaNumerus2Catena
    //pruebaNumerus2Imago();
    //pruebaNumerus2Fractio();
    //pruebaNumerus2Dualis();

    //pruebaImago2Catena();
    //pruebaImago2Numerus();
    //pruebaImago2Fractio();
    //pruebaImago2Dualis();

    //pruebaDualis2Catena();
    //pruebaDualis2Numerus();
    //pruebaDualis2Fractio();
    //pruebaDualis2Imago();

    //pruebaFractio2Catena();
    //pruebaFractio2Numerus();
    //pruebaFractio2Dualis();
    //pruebaFractio2Imago();

    //pruebaCatena2Fractio();
    //pruebaCatena2Numerus();
    //pruebaCatena2Dualis();
    //pruebaCatena2Imago();

    /*char buff[32]= "9223372036854775807";
    int64_t num = catena2diem(&buff[0]);

*/


    /*
    liber liber1;
    legoliber(&liber1);

    std::cout<<liber1.nombre<<std::endl;

    scriboliber(&liber1);*/

    /*int16_t num = legodualis();

    if (num)
        std::cout<<"true";
    else
        std::cout<<"false";*/



    /*char test[32];
    legocatena(&test[0]);
    for (int i = 0; i < 32; ++i) {
        std::cout<< + test[i]<<std::endl;

    }*/

    return 0;
}

void pruebaCatena2Numerus() {
    char buff[32] = {7,'-','1','3','4','|','5'};
    std::cout<<(int16_t) catena2numerus(&buff[0]);
}
void pruebaCatena2Dualis() {
    char buff[32] = {9,'v','E','r','i','D','i','c','u','s'};
    int16_t  mybool = catena2dualis(&buff[0]);
    if (mybool)
        std::cout<<"YES" ;
    else
        std::cout<<"NO" ;

}
void pruebaCatena2Imago() {
    char buff[32] = {4,'H','O','L','A'};
    char myc=catena2imago(&buff[0]);
    std::cout<<myc;

}

void pruebaCatena2Fractio(){
    char buff[32] = {6,'-','6','4','8','|','9'};
    //fractio frac = fun(&buff[0]);
    fractio frac = catena2fractio(&buff[0]);
    std::cout<<frac.numerador<<std::endl<<frac.denominador;

}

void pruebaFractio2Numerus() {
    fractio *myfrac = new fractio(-10,2);
    std::cout<<(int16_t) fractio2numerus(myfrac);
}
void pruebaFractio2Dualis() {
    fractio *myfrac = new fractio(-5,1);
    int16_t  mybool = fractio2dualis(myfrac);
    if (mybool)
        std::cout<<"YES" ;
    else
        std::cout<<"NO" ;

}
void pruebaFractio2Imago() {
    fractio *myfrac = new fractio(65,1);
    char buff = fractio2imago(myfrac);
    std::cout<<buff;
}
void pruebaFractio2Catena(){
    char buff[32];
    fractio *myfrac = new fractio(-65,-6);
    fractio2catena(myfrac, &buff[0]);
    //trimcatena(&buff[0]);
    std::cout<< +buff[0]<<std::endl;
    for (int i = 1; i < buff[0]+1; ++i) {
        std::cout<<buff[i];
    }
}

void pruebaDualis2Fractio() {
    fractio frac = dualis2fractio(0);
    std::cout<<frac.numerador<<std::endl<<frac.denominador;
}
void pruebaDualis2Imago() {
    char buff = dualis2imago(0); //imprime una A
    std::cout<<buff;

}
void pruebaDualis2Numerus() {
    std::cout<<dualis2numerus(true);
}
void pruebaDualis2Catena(){
    char buff[32];
    dualis2catena(0, &buff[0]);
    //trimcatena(&buff[0]);
    for (char i : buff) {
        std::cout<< i;
    }
    std::cout<<std::endl<<buff;
}

void pruebaImago2Fractio() {
    fractio frac = imago2fractio('K');
    std::cout<<frac.numerador<<std::endl<<frac.denominador;
}
void pruebaImago2Dualis() {
    int16_t mybool = imago2dualis('v');
    if (mybool)
        std::cout<<"YES" ;
    else
        std::cout<<"NO" ;

}
void pruebaImago2Numerus() {
    std::cout<<imago2numerus('A');
}
void pruebaImago2Catena(){
    char buff[32];
    imago2catena('A', &buff[0]);
    //trimcatena(&buff[0]);
    for (char i : buff) {
        std::cout<< i;
    }
    std::cout<<std::endl<<buff;
}

void pruebaNumerus2Fractio() {
    fractio frac = numerus2fractio(-321);
    std::cout<<frac.numerador<<std::endl<<frac.denominador;
}
void pruebaNumerus2Dualis() {
    int16_t  mybool = numerus2dualis(3);
    if (mybool)
        std::cout<<"YES" ;
    else
        std::cout<<"NO" ;

}
void pruebaNumerus2Imago() {
    char buff = numerus2imago(321); //imprime una A
    std::cout<<std::endl<<buff;
}
void pruebaNumerus2Catena(){
    char buff[32];
    numerus2catena(1234, &buff[0]);
    //trimcatena(&buff[0]);
    for (char i : buff) {
        std::cout<< i;
    }
    std::cout<<std::endl<<buff;
}