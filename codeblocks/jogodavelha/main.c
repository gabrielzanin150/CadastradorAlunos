#include <stdio.h>
#include <stdlib.h>

int main()
{

    int matriz[3][3],i,j,linha1,coluna1,linha2,coluna2,vitoria=0,cont=0,contdiagonal1=0,contdiagonal2=0,jogadas=0;

        for(i=0;i<3;i++){
            for (j=0;j<3;j++){

                matriz[i][j]=-1;
          }
        }
          for(i=0;i<3;i++){

            for (j=0;j<3;j++){
                printf("\t%d |",matriz[i][j]);
            }
              printf("\n");
          }
                while(vitoria==0 && jogadas<9){

                printf("Vez do Jogador 1: Linha e coluna");
                scanf("%d  %d",&linha1,&coluna1);
                 while (matriz[linha1-1][coluna1-1]!=-1){
                   printf("Linha ocupada,digite novamente ");
                   scanf("%d  %d", &linha1,&coluna1);
                   }
                   matriz[linha1-1][coluna1-1]=0;
                   jogadas++;

                for(i=0;i<3;i++){
                    for (j=0;j<3;j++){
                printf("\t%d",matriz[i][j]);
                  }
                   printf("\n");
                }

                for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(matriz[i][j]==0){
                        cont++;
                    }
                }
                if(cont==3){
                   vitoria=1;
                }
                  else{
                    cont=0;
                  }
                }
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
                        if(matriz[j][i]==0){
                            cont++;
                        }
                      }
                    if(cont==3){
                         vitoria=1;
                    }
                    else{
                        cont=0;
                    }
                }
                for(i=0;i<3;i++){
                  for(j=0;j<3;j++){
                    if(matriz[0][0]==0 && matriz[1][1]==0 && matriz[2][2]==0){
                            contdiagonal1=3;

                  }
                  if(matriz[0][2]==0 && matriz[1][1]==0 && matriz[2][0]==0){
                        contdiagonal2=3;
                  }
                 }
                    if(contdiagonal1==3 || contdiagonal2==3){
                         vitoria=1;
                    }
                      else {
                        contdiagonal1=contdiagonal2=0;}
                    if(vitoria==1)
                        break;

                  printf("Vez do Jogador 2: Linha e coluna");
                  scanf("%d  %d",&linha2,&coluna2);
                while (matriz[linha2-1][coluna2-1]!=-1){
                   printf("Linha ocupada,digite novamente ");
                   scanf("%d  %d", &linha2,&coluna2);
                   }

                   matriz[linha2-1][coluna2-1]=1;
                   jogadas++;

                for(i=0;i<3;i++){
                    for (j=0;j<3;j++){
                printf("\t%d",matriz[i][j]);
                  }
                   printf("\n");
                }
            // logica de verificaçao da vitoria do jogador 2
              for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(matriz[i][j]==1){
                        cont++;
                    }
                }
                if(cont==3){
                   vitoria=2;
                }
                  else{
                    cont=0;
                  }
                }
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
                        if(matriz[j][i]==1){
                            cont++;
                        }
                      }
                    if(cont==3){
                         vitoria=2;
                    }
                    else{
                        cont=0;
                    }
                }
                for(i=0;i<3;i++){
                  for(j=0;j<3;j++){
                    if(matriz[0][0]==1 && matriz[1][1]==1 && matriz[2][2]==1){
                            contdiagonal1=3;

                  }
                  if(matriz[0][2]==1 && matriz[1][1]==1 && matriz[2][0]==1){
                        contdiagonal2=3;
                  }
                 }
                    if(contdiagonal1==3 || contdiagonal2==3){
                         vitoria=2;
                    }
                  }
                }
               }
                // Fim da verificaçao da vitoria

                if(vitoria==1){
                    printf("Vitoria do jogador 1");
                    }
                    else
                     if (vitoria==2){
                        printf("Vitoria do Jogador 2");
                    }
                    else
                        printf("velha");
                    return 0;
}
