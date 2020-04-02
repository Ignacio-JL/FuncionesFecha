#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int dia,mes,anio;
    }tFecha;

    int controlFecha(tFecha,int[]);
    void diaSiguiente(tFecha,int[]);
    void sumarDias(tFecha,int[]);
    void restarDias(tFecha,int[]);
    void diferenciaDias();
    void diaFecha();


int main()
{
    int dias[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    int confirmacion=NULL;

    tFecha Fecha;
    printf("\n ingrese dia: ");
    scanf("%i",&Fecha.dia);
    printf("\n ingrese mes: ");
    scanf("%i",&Fecha.mes);
    printf("\n ingrese a%co: ",164);
    scanf("%i",&Fecha.anio);

    confirmacion=controlFecha(Fecha,dias);



    if(confirmacion==0){//SI CUMPLE FECHA ES VERDADERO EJ 14+
        printf("\n fecha bien ingresada");
        diaSiguiente(Fecha,dias);//FUNCION DIA SIGUIENTE SOLO SI ES FECHA CORRECTAEJ 15+
        sumarDias(Fecha,dias);//FUNCION SUMAR DIAS EJ 16+
        restarDias(Fecha,dias);//FUNCION RESTAR DIAS EJ 17+

    }
    else
        {
        printf("\n fecha mal ingresada");
        }
        diferenciaDias(); //FUNCION DIFERENCIA DIAS EJ 18+
        diaFecha(); //FUNCION ENCONTRAR DIA DE UNA FECHA EJ 19+


    return 0;
}       //FIN MAIN

///
int controlFecha(tFecha Pfecha,int Pdias[]){
    if((Pfecha.anio%4==0&&Pfecha.anio%100!=0)||(Pfecha.anio&&400==0)){
        Pdias[1]=29;
    }
    else {
        Pdias[1]=28;
    }
        if(Pfecha.dia>Pdias[Pfecha.mes-1]||Pfecha.dia<1){
            return 1;
        }

        if(Pfecha.dia>Pdias[Pfecha.mes-1]||Pfecha.mes<1){
            return 1;
        }
        if(Pfecha.anio<1){
            return 1;
        }

    return 0;

}
///
void diaSiguiente(tFecha Pfecha,int Pdias[]){

    if((Pfecha.anio%4==0&&Pfecha.anio%100!=0)||(Pfecha.anio&&400==0)){
        Pdias[1]=29;
    }
    else {
        Pdias[1]=28;
    }
    Pfecha.dia+=1;
    if(Pfecha.dia>Pdias[Pfecha.mes-1]){
        Pfecha.dia=1;
        Pfecha.mes+=1;
        if(Pfecha.mes>12)
            Pfecha.anio+=1;
    }
    printf("\n la fecha siguiente es %i/%i/%i",Pfecha.dia,Pfecha.mes,Pfecha.anio);


}
///
void sumarDias(tFecha Pfecha,int Pvec[]){

        int suma;
        printf("\n ingrese la cantidad de dias a sumar: ");
        scanf("%i",&suma);
        Pfecha.dia+=suma;
        while((Pfecha.dia>Pvec[Pfecha.mes-1])){
            if((Pfecha.anio%4==0&&Pfecha.anio%100!=0)||(Pfecha.anio&&400==0)){
            Pvec[1]=29;
                }
            else
            {
            Pvec[1]=28;
            }

            Pfecha.dia-=Pvec[Pfecha.mes-1];
            if(Pfecha.mes>11)
                {
                Pfecha.mes=1;
                Pfecha.anio++;
                }
            else
                {

                Pfecha.mes++;
                }


    }


        printf("\n sumado los dias la fecha es %i/%i/%i\n\n",Pfecha.dia,Pfecha.mes,Pfecha.anio);


}
///
void restarDias(tFecha Pfecha,int Pdias[]){
   int resta;

   printf("\n ingrese cantidad de dias a restar a la fecha%i/%i/%i  : ",Pfecha.dia,Pfecha.mes,Pfecha.anio);
   scanf("%i",&resta);
   Pfecha.dia-=resta;
   while((Pfecha.dia<1))
    {
            if((Pfecha.anio%4==0&&Pfecha.anio%100!=0)||(Pfecha.anio&&400==0)){
            Pdias[1]=29;
                }
            else
            {
            Pdias[1]=28;
            }

            if(Pfecha.mes==1){
                Pfecha.dia+=Pdias[11];
                Pfecha.mes--;
            }
            else{
            Pfecha.dia+=Pdias[Pfecha.mes-2];//-2 REFIERE A LA POSICION DEL VECTOR DONDE ESTA EL MES ANTERIOR INGRESADO
            Pfecha.mes--;
            }
            if(Pfecha.mes<1){
                Pfecha.mes=12;
                Pfecha.anio--;
            }

    }

   printf("\n la fecha restada es %i/%i/%i",Pfecha.dia,Pfecha.mes,Pfecha.anio);

}
//
void diferenciaDias(){
    tFecha fecha1,fecha2,fechamenor,fechamayor;
    int igual=0,meses[12]={31,28,31,30,31,30,31,31,30,31,30,31},contador=0;

    printf("\nINGRESE 2 FECHAS A COMPARAR DIFERENCIA DE DIAS:\n FECHA 1");
    printf("\n ingrese dia: ");
    scanf("%i",&fecha1.dia);
    printf("\n ingrese mes: ");
    scanf("%i",&fecha1.mes);
    printf("\n ingrese a%co: ",164);
    scanf("%i",&fecha1.anio);
    printf("\n FECHA 2");
    printf("\n ingrese dia: ");
    scanf("%i",&fecha2.dia);
    printf("\n ingrese mes: ");
    scanf("%i",&fecha2.mes);
    printf("\n ingrese a%co: ",164);
    scanf("%i",&fecha2.anio);
//EMPEZAMOS COMPARANDO DIAS MUCHO MUY IMPORTANTE :v - FUNCION PARA COMPARAR FECHA MENOR;
            if(fecha1.dia>fecha2.dia){
        fechamenor=fecha2;
        fechamayor=fecha1;
        }
        else{
            if(fecha1.dia<fecha2.dia){
                fechamenor=fecha1;
                fechamayor=fecha2;
            }
            else
                igual++;
        }

            if(fecha1.mes>fecha2.mes){
        fechamenor=fecha2;
        fechamayor=fecha1;
       }
        else{
            if(fecha1.mes<fecha2.mes){
                fechamenor=fecha1;
                fechamayor=fecha2;
            }
            else
                igual++;
        }



    if(fecha1.anio>fecha2.anio){
        fechamenor=fecha2;
        fechamayor=fecha1;
        }
        else{
            if(fecha1.anio<fecha2.anio){
                fechamenor=fecha1;
                fechamayor=fecha2;
            }
            else
                igual++;
        }

        if(igual!=3)

            {


                while((fechamenor.dia!=fechamayor.dia)||(fechamenor.mes!=fechamayor.mes)||(fechamenor.anio!=fechamayor.anio)){

                if((fechamenor.anio%4==0&&fechamenor.anio%100!=0)||(fechamenor.anio&&400==0)){
                meses[1]=29;
                }
                else{
                    meses[1]=28;
                }

                  if(fechamenor.dia==meses[fechamenor.mes-1]){
                    fechamenor.dia=1;
                    fechamenor.mes++;
                    contador++; //◄ ◄
                    if(fechamenor.mes==13){
                        fechamenor.anio++;
                        fechamenor.mes=1;
                        }
                    }
                    else{
                  contador++;
                  fechamenor.dia++;
                    }

                    }


            printf("\n la diferencia de dia es %i",contador);




        }
        else
            printf("\n las fechas son iguales");


}
void diaFecha(){ //FORMULA D=[N+M+A+(A/4)+Ks]%7
    /*
    1600►6
    1700►4
    1800►2
    1900►0
    2000►6
    2100►4
    */

    int mes[12]={0,3,3,6,1,4,6,2,5,0,3,5},ks,resultado; //SI ES BISIESTO {6,2,...........}
    char dia[7][15]={"domingo","lunes","martes","miercoles","jueves","viernes","sabado"};
    tFecha fecha;
    printf("INGRESE FECHA A SABER DIA");
    printf("\n dia: "); scanf("%i",&fecha.dia);
    printf("\n mes: "); scanf("%i",&fecha.mes);
    printf("\n a%co: ",164); scanf("%i",&fecha.anio);
    if(fecha.anio>1599&&fecha.anio<1701)
        ks=6;
    if(fecha.anio>1699&&fecha.anio<1801)
        ks=4;
    if(fecha.anio>1799&&fecha.anio<1901)
        ks=2;
    if(fecha.anio>1899&&fecha.anio<2001)
        ks=0;
    if(fecha.anio>1999&&fecha.anio<2101)
        ks=6;
    if(fecha.anio>2099&&fecha.anio<2201)
        ks=4;

    if((fecha.anio%4==0&&fecha.anio%100!=0)||(fecha.anio&&400==0)){
                mes[0]=6;
                mes[1]=2;
                }
        resultado=(fecha.dia+mes[fecha.mes-1]+(fecha.anio%100)+(((fecha.anio%100))/4)+ks)%7;

printf("\n el dia de la fecha es : %s",dia[resultado]);


}



