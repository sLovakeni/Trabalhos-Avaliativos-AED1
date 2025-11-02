#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
*/
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

int main(){
    //main para definir tamanho, quantidade e quantas flores
    int tamanho = 7;
    int potes[tamanho];
    potes[0] = 1;
    potes[1] = 0;
    potes[2] = 0;
    potes[3] = 0;
    potes[4] = 1;
    potes[5] = 0;
    potes[6] = 0;
    int flores = 2;
    int i = canPlaceFlowers(potes, tamanho, flores);
    printf("%d", i);

}
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int atual;
    int proximo;
    int counter = 0;
    int copia[flowerbedSize];
    for(int k = 0; k < flowerbedSize; k++){
        copia[k] = flowerbed[k];
    }
    //checa para ver se não tem pote ou não tem flor para adicionar
    if(flowerbedSize == 0 || n == 0){
        return true;
    }
    //checa para ver se tem apenas um pote e este pote está vazio(como ja foi testado antes se não há flores para adicionar ele só será verdadeiro caso esteja vazio
    if(flowerbedSize == 1 && flowerbed[0] == 0){
        return true;
    }
    //entra apenas quando for possivel checar ao menos dois potes
    if(flowerbedSize >= 2){
    for(int i = 0; i < n; i++){ //checa uma vez por flor
        for(int j = 1; j < flowerbedSize; j++){ //verifica todos os potes
            int current = j-1;
            int next = j;
            if(current == 0 && copia[current] == 0 && copia[next] == 0){ //verifica se os dois primeiros estão vazios
                copia[current] = 1;
                counter++;
            }else if(next == flowerbedSize - 1 && copia[current] == 0 && copia[next] == 0){ //verifica se os dois ultimos estão vazios
                copia[next] = 1;
                counter++;
            }else if(proximo < flowerbedSize - 2 && copia[current] == 0 && copia[next] == 0 && copia[next + 1] == 0){ //verifica 3 casas consecutivas e transforma a do meio em 1
                copia[next] = 1;
                counter++;
            }
        }
    }
    }
    if(counter < n){ //se o contador for menor que o numero de flores que quero adicionar então não há como adicionar as flores, logo falso
        return false;
    }
    return true; //passou pelo teste e é posso adicionar as flores
}


