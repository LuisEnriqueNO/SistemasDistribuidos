    #include<stdio.h>
    #include<conio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<time.h>
    
/* Se definen las constantes, numero de filas y numero de columnas
Se define el porcentaje de poblacion como constante para modificarlo en cualquier momento */
    #define noFil 20
    #define noCol 20
    #define NORMAL 25
     
    void Imprimir(int Matriz[noFil][noCol]){
        int i,j;
        
        //Recorremos la matriz
        for(i=0 ; i<noFil ; i++){
            for(j=0 ; j<noCol ; j++){
                //Si es 0 la celula está muerta, por lo que se imprime un guión
                if(Matriz[i][j]==0){
                    printf(" ~");
                }
                //Si no, está viva, por lo que se imprime un gato
                else{
                    printf(" #");
                }
            }
            //Salto de linea al llegar al final de la fila
            printf("\n");
        }
    }
    void Duplicar(int ori[noFil][noCol], int dest[noFil][noCol]){
    	
        //Recorremos la matriz
        for(int i=0 ; i<noFil ; i++)
            for(int j=0 ; j<noCol ; j++)
                //Copiamos la matriz origen en destino
                dest[i][j]=ori[i][j];
    }
    
    void Refrescar(int Matriz[noFil][noCol]){
        int copiamatriz[noFil][noCol];
        int NUMcelulasvivas=0,i,j;
        
        //Copiamos la matriz en una copia auxiliar
        Duplicar(Matriz, copiamatriz);
        for(i=0 ; i<noFil ; i++){
            for(j=0;j<noCol;j++){
            	
                //Control de las celulas vecinas vivas
                if(i>0 && j>0 && Matriz[i-1][j-1]==1){
                    NUMcelulasvivas++;
                }
                if(i>0 && Matriz[i-1][j]==1){
                    NUMcelulasvivas++;
                }
                if(i>0 && j<noCol && Matriz[i-1][j+1]==1){
                    NUMcelulasvivas++;
                }
                if(j>0 && Matriz[i][j-1]==1){
                    NUMcelulasvivas++;
                }
                if(j<noCol && Matriz[i][j+1]==1){
                    NUMcelulasvivas++;
                }
                if(i<noFil && j>0 && Matriz[i+1][j-1]==1){
                    NUMcelulasvivas++;
                }
                if(i<noFil && Matriz[i+1][j]==1){
                    NUMcelulasvivas++;
                }
                if(i<noFil && j<noCol && Matriz[i+1][j+1]==1){
                    NUMcelulasvivas++;
                }
     
                //Actuamos sobre las celulas en la copia de la matriz
                if(Matriz[i][j]==1){
                    //La celulas vivas con 2 o 3 celulas vivas pegadas, se mantiene vivas.
                    if(NUMcelulasvivas==2 || NUMcelulasvivas==3){
                        copiamatriz[i][j]=1;
                    }
                    //Si no se cumple la condicion, mueren.
                    else{
                        copiamatriz[i][j]=0;
                    }
                }
                else{
                    //Las celulas muertas con 3 celulas vivas pegadas, resucitan.
                    if(NUMcelulasvivas==3){
                        copiamatriz[i][j]=1;
                    }
                }
                //Ponemos a 0 el contador
                NUMcelulasvivas=0;
            }
        }
        //Devolvemos los nuevos datos a la matriz original
        Duplicar(copiamatriz, Matriz);
    }
    
    void Resucitar(int Matriz[noFil][noCol]){
        int i,j,a,b;
        
        do{
            printf("Ingrese la fila <1-%d>: ", noFil);
            i=getche()-48;
            fflush(stdin);
        }while(i<1 || i>noFil);
        
        do{
            printf("\nIngrese la columna <1-%d>: ", noCol);
            j=getche()-48;
            fflush(stdin);
        }while(j<1 || j>noCol);
        
        //Copiamos la el valor de la celula, para poder revertir el cambio
        a=Matriz[i-1][j-1];
        
        //Resucitamos la celula seleccionada
        Matriz[i-1][j-1]=1;
        system("cls");
        Imprimir(Matriz);
        
        //Preguntamos si se desea mantener la seleccion
        printf("\n Su eleccion es correcta? [s/n]");
        b=getch();
        
        //Limpiamos el buffer
        fflush(stdin);
        
        //Si no se mantiene, se devuelve el valor de la celula copiada anteriormente
        if(b=='n') Matriz[i-1][j-1]=a;
    }
    
    void Patron(int Matriz[noFil][noCol]){
     
    //Las posiciones se interpretan: Primer numero--> Fila, Segundo numero-->Columna
     
        Matriz[noFil-(noFil/2+1)][noCol-(noCol/2+1)]=1; //1 Posicion (1,1) del patron
        Matriz[noFil-(noFil/2+1)][noCol-(noCol/2)]=1;   //2 Posicion (1,2) del patron
        Matriz[noFil-(noFil/2+1)][noCol-(noCol/2-1)]=0; //3 Posicion (1,3) del patron
        Matriz[noFil-noFil/2][noCol-(noCol/2+1)]=1;     //4 Posicion (2,1) del patron
        Matriz[noFil-(noFil/2)][noCol-(noCol/2)]=0;     //5 Posicion (2,2) del patron
        Matriz[noFil-(noFil/2)][noCol-(noCol/2-1)]=1;   //6 Posicion (2,3) del patron
        Matriz[noFil-(noFil/2-1)][noCol-(noCol/2+1)]=0; //7 Posicion (3,1) del patron
        Matriz[noFil-(noFil/2-1)][noCol-(noCol/2)]=1;   //8 Posicion (3,2) del patron
        Matriz[noFil-(noFil/2-1)][noCol-(noCol/2-1)]=0; //9 Posicion (3,3) del patron
     
     
     
    }
    void Juego(){
        int poblacion,i,j,filas,columnas,repetir,confirmar;
        int Matriz [noFil][noCol];
        
        //Menu inicial
        do{
            system("cls");
            do{
                printf("\n\t Bienvenid@ al Juego de la Vida\n");
                printf("\n\tPresione 1 para iniciar\n");
                poblacion=getch();

                fflush(stdin);
                system ("cls");
            }
            while(!(poblacion=='1'));
            
            //Ponemos todas las celulas muertas inicialmente
            for(i=0;i<noFil;i++){
                for(j=0;j<noCol;j++){
                    Matriz [i][j]=0;
                }
            }
            //Aplicamos los porcentajes de poblacion sobre el total de celulas
            if(poblacion=='1'){
                poblacion=(((noFil*noCol)/100)*NORMAL);
            }

            else poblacion=(((noFil*noCol)/100)*20);
     
     
            //Modo aleatorio
            srand(time(0));
            for(i=0;i<poblacion;i++){
                filas=rand()%20;
                columnas=rand()%20;
                
                //Si la celula esta muerta, la resucita
                if(Matriz [filas][columnas]==0){
                    Matriz[filas][columnas]=1;
                }
                /*NOTA: 
				Si ya estaba viva se mantiene, y no lo contamos como una posicion añadida, asi aseguramos que 
				se impriman el numero de celulas vivas seleccionado. Por ello restamos uno al contador*/
     
                else
                    i--;
            }
            char letra;
            do{
                do
                {
                    system("cls");
                    Imprimir(Matriz);
                    printf("\n Presione cualquier tecla para que el juego avance \n\n");
                    printf("\n O bien, ingrese una letra para: \n\n [s] Salir \n [r] Revivir celula \n [f] Formar matriz");
     
                    //Opciones en el juego
                    letra=getch();
                    fflush(stdin);
                    
                    if(letra=='s'){
                        system("cls");
                        Imprimir(Matriz);
                        printf("\n Fin del juego");
                    }
                    else if(letra=='f'){
                        Patron(Matriz);
                    }
                    else if(letra=='r'){
                        system("cls");
                        Imprimir(Matriz);
                        Resucitar(Matriz);
                    }
                    else{
                        Refrescar(Matriz);
                    }
                }while(letra!='s');
     
                //Confirmacion de salida, para prevenir equivocaciones
                system("cls");
                printf("\n\n\n\n%20cQuieres salir? [s/n]", ' ');
                confirmar=getch();
                fflush(stdin);
     
            }while(confirmar=='n');
            system("cls");
     
            //Opcion para volver a empezar, asi no hace falta salir del programa y volver a ejecutar
            printf("\n\n\n\n%20c Reiniciar el juego? [s/n]", ' ');
            repetir=getch();
            //Limpiamos el buffer
            fflush(stdin);
     
        }while(repetir=='s');
     
     
    }
    int main(){
        //Iniciamos el juego
        Juego();
    }