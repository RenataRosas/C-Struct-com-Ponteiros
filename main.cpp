#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

//EXEMPLO:
/*
struct horario agora, depois*;
Foram criadas duas variaveis do tipo "struct agora", assim como poderia ser int, char, etc. Ao se crar variavel do tipo struct agora elas estão relacionadas, pertencentes ao struct chamdo agora.
Como sao variaveis do tipo struct, quando vc associa um valor à elas, esta relacionando valore as variaveis dentro da struct horario:

struct horario{ ou struct horario{ int hora, minuto, segundo;}- nenhuma dessas variaveis tiveram valor declarado.
int hora
int minuto
int segundo}

struct horario agora, *depois; -> criadas 2 variaveis do tipo struct horario (horario e *depois) e ao receberem valores, passam eles para as variaveis do proprio struct!
Por enquanto, nenhuma dessas variaveis possui um valor declarado. Elas foram apenas criadas como nome e tipo struct horario.
como fazer o ponteiro *depois apontar para agora:

*depois = &agora

printf("%i; %i;%i", agora.hora, agora.minuto, agora.segundo) - para imprimir estes dados podemos usar a variavel agora, relacionada a struct horario. Para relacionar elementos da struct original e imprimi-los no momento definido
agora, variavel agora, basta usar "nome da variavel definida para struct original"."nome da variavel da struct original"

MASSSS E SE:

*depois.hora = 20;
*(depois.hora) = 20;
Não funciona!
pois existem regras de colocação de caracteres no c e o ponto é lido primeiro que *, fazendo com que perca coerencia.
pois quando o ponteiro é acompanhado por * este esta trabalhando com endereços de memória e não dá pra alterar simplesmente com =. Tem que usar função MALLOC.

ENtão, para adcionar valor à variavel hora, do struct original struct horario, através da variavel de tipo struct horario(struct origem), então temos que escrever:

(*depois).hora = 20;
(*depois).minuto = 20;
(*depois).segundo = 20;
...
fica assim:
struct horario{ int hora, minuto, segundo;}
struct horario agora, *depois;
*depois = &agora
(*depois).hora = 20;
(*depois).minuto = 20;
(*depois).segundo = 20;

printf("%i; %i;%i", agora.hora, agora.minuto, agora.segundo);

O resultado no console fica 20 20 20

MAS! PODEMOS FAZER O PROCEDIMENTO DE COLOCAR VALORES A VARIAVEL PONTEIRO( DE TIPO STRUCT ORIGEM, QUE APONTA PARA OS ELEMENTOS, VARIAVEIS DA STRUCT ORIGEM) SEM PRECISA DE * E ():

(*depois).hora = 20;          DEPOIS->HORA = 20;
(*depois).minuto = 20;        DEPOIS->MINUTO = 20;
(*depois).segundo = 20;       DEPOIS->SEGUNDO = 20;


*/

struct No {
    int info;
    struct No *proximo;//ponteiro *proximo é uma variavel do tipo struct no, consequentemente, ele aponta para strauct no.(<tipo de variavel do PONTEIRO: neste caso, o tipo de variavel é variavel da struct No> * <nome do PONTEIRO = neste caso, o nome do ponteiro é próximo>)  =& <variável, função ou vetor já declarado no código e que você quer utilizar no PONTEIRO> 
};

struct Lista {
    struct No *inicio; //ponteiro *inicio é uma variavel do tipo struct no, consequentemente, ele aponta para strauct no. Sintzxe(tipo de variavel do PONTEIRO: neste caso, o tipo de variavel é variavel da struct No> * <nome do PONTEIRO = neste caso, inicio>)  =& <variável, função ou vetor já declarado no código e que você quer utilizar no PONTEIRO> 
    int tamanho;
};

//FUNÇÃO CRIAR COM TIPO DE VARIAVEL RETORNO: STRUCT lista, nome:*criar, e criar é um ponteiro. 
//FUNÇÃO SINTAXE: <tipo_de_retorno> <nome_da_função> (PARÂMETROS){ instruções;  retorno_da_função;}
struct Lista *criar() {  
//o ponteiro *criar aponta para a [(struct Lista*) malloc(sizeof(struct Lista))].
    struct Lista *nova_lista = (struct Lista *) malloc(sizeof(struct Lista)); //o ponteiro declarado *nova_lista, de tipo de variavel struct lista, tem seu endereço de memória aletrado pela função malloc: Int *memoria = (int*) malloc(sizeof(int));    char *nome = (char *) malloc(21*sizeof(char));  A função malloc() pode retornar dois valores: NULL ou um ponteiro genérico (ponteiro genérico é do tipo void*). 
    if (nova_lista != NULL){nova_lista->inicio = NULL; nova_lista->tamanho = 0;}//*=->... nova_lista sponta para inicio, que é igual a null. nova lista tem tamanho 0;
    return nova_lista;//retorno desta função é nova lista =0
}

//FUNÇÃO VAZIA COM TIPO DE VARIAVEL RETORNO: bool.
//FUNÇÃO SINTAXE: <tipo_de_retorno> <nome_da_função> (PARÂMETROS){ instruções;  retorno_da_função;}
bool vazia(struct Lista *li) { //ponteiro li de tipo de variavel struct lista aponta para esta
    assert(li != NULL);     
    if (li->inicio == NULL) {//ponteiro li que aponta para variavel inicio, tem valor null - retorna verdadeiro
        return true;
    } else {
        return false;
    }
}


int main() {
   struct Lista *minha_lista = criar(); // da se primeiro valor a variavel ponteiro *minha_lista//ponteiro *minha_lista, de tipo de variavel struct lista, tem valor igual a função criar, que em si é um ponteiro.
   //função criar retorna valor da lista = 0.
   if (vazia(minha_lista) == true) {// se a função vazia, com parametro(variavel): minha_lista, tem valor 0, então é true e imprime lista vazia!
       printf("\nOK, lista vazia!");
   } else {
       printf("\nOps... algo deu errado!");
   } 
   return 0;
}

