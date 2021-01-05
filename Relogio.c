#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

int executar;
int hora;
int minutos;
int segundos;
int cronometro;
int aux;
int alarme;
int horalarme;
int minutoalarme;

void Relogio(){
    hora=0;
    minutos=0;
    segundos=0;
    while(executar != 0){
        _sleep(1000);
        segundos++;
        if(segundos == 60){
            minutos++;
            segundos = 0;
        }
        if(minutos == 60){
            hora++;
            minutos = 0;
        }
        if(hora == 23){
            hora = 0;
        }
    }
}

void Cronometro(){
    while(aux != 0){
        _sleep(1000);
        cronometro++;
    }
}

void Alarme(){
    while(alarme != 0){
        _sleep(1000);
        if(horalarme == hora && minutoalarme == minutos){
            Beep(523,500);
            printf("ALARME!");
        }
    }
}

int main(){
    int op;

    executar = 1;
    _beginthread(Relogio, 0, NULL);

    menu:
        printf("\n+==================================+\n");
        printf("|[1]Ver Hora;                      |\n");
        printf("|[2]Alterar Hora;                  |\n");
        printf("|[3]Iniciar Cronometro;            |\n");
        printf("|[4]Parar Cronometro;              |\n");
        printf("|[5]Zerar Cronometro;              |\n");
        printf("|[6]Definir Alarme;                |\n");
        printf("|[7]Parar Alarme;                  |\n");
        printf("|[8]Sair.                          |\n");
        printf("+==================================+\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                system("cls");
                printf("\n %d : %d : %d \n\n", hora, minutos, segundos);
                goto menu;
            break;

            case 2:
                system("cls");
                printf("\nHora: ");
                scanf("%d", &hora);
                printf("Minutos: ");
                scanf("%d", &minutos);
                goto menu;
            break;

            case 3:
                system("cls");
                aux = 1;
                _beginthread(Cronometro, 0, NULL);
                goto menu;
            break;

            case 4:
                system("cls");
                aux = 0;
                printf("\nCronometro: %d\n", cronometro);
                goto menu;
            break;

            case 5:
                system("cls");
                cronometro = 0;
                goto menu;
            break;

            case 6:
                system("cls");
                printf("\nHora: ");
                scanf("%d", &horalarme);
                printf("Minutos: ");
                scanf("%d", &minutoalarme);
                alarme = 1;
                _beginthread(Alarme, 0, NULL);
                goto menu;
            break;

            case 7:
                alarme = 0;
                system("cls");
                goto menu;
            break;

            case 8:
                system("cls");
                return 0;
            break;
        }

    system("PAUSE");
}
