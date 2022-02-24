#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

//EXEMPLO:
/*
struct horario agora, depois*;
Foram criadas duas variaveis do tipo "struct agora", assim como poderia ser int, char, etc. Ao se crar variavel do tipo struct agora elas est�o relacionadas, pertencentes ao struct chamdo agora.
Como sao variaveis do tipo struct, quando vc associa um valor � elas, esta relacionando valore as variaveis dentro da struct horario:

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
N�o funciona!
pois existem regras de coloca��o de caracteres no c e o ponto � lido primeiro que *, fazendo com que perca coerencia.
pois quando o ponteiro � acompanhado por * este esta trabalhando com endere�os de mem�ria e n�o d� pra alterar simplesmente com =. Tem que usar fun��o MALLOC.

ENt�o, para adcionar valor � variavel hora, do struct original struct horario, atrav�s da variavel de tipo struct horario(struct origem), ent�o temos que escrever:

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
    struct No *proximo;//ponteiro *proximo � uma variavel do tipo struct no, consequentemente, ele aponta para strauct no.(<tipo de variavel do PONTEIRO: neste caso, o tipo de variavel � variavel da struct No> * <nome do PONTEIRO = neste caso, o nome do ponteiro � pr�ximo>)  =& <vari�vel, fun��o ou vetor j� declarado no c�digo e que voc� quer utilizar no PONTEIRO> 
};

struct Lista {
    struct No *inicio; //ponteiro *inicio � uma variavel do tipo struct no, consequentemente, ele aponta para strauct no. Sintzxe(tipo de variavel do PONTEIRO: neste caso, o tipo de variavel � variavel da struct No> * <nome do PONTEIRO = neste caso, inicio>)  =& <vari�vel, fun��o ou vetor j� declarado no c�digo e que voc� quer utilizar no PONTEIRO> 
    int tamanho;
};

//FUN��O CRIAR COM TIPO DE VARIAVEL RETORNO: STRUCT lista, nome:*criar, e criar � um ponteiro. 
//FUN��O SINTAXE: <tipo_de_retorno> <nome_da_fun��o> (PAR�METROS){ instru��es;  retorno_da_fun��o;}
struct Lista *criar() {  
//o ponteiro *criar aponta para a [(struct Lista*) malloc(sizeof(struct Lista))].
    struct Lista *nova_lista = (struct Lista *) malloc(sizeof(struct Lista)); //o ponteiro declarado *nova_lista, de tipo de variavel struct lista, tem seu endere�o de mem�ria aletrado pela fun��o malloc: Int *memoria = (int*) malloc(sizeof(int));    char *nome = (char *) malloc(21*sizeof(char));  A fun��o malloc() pode retornar dois valores: NULL ou um ponteiro gen�rico (ponteiro gen�rico � do tipo�void*). 
    if (nova_lista != NULL){nova_lista->inicio = NULL; nova_lista->tamanho = 0;}//*=->... nova_lista sponta para inicio, que � igual a null. nova lista tem tamanho 0;
    return nova_lista;//retorno desta fun��o � nova lista =0
}

//FUN��O VAZIA COM TIPO DE VARIAVEL RETORNO: bool.
//FUN��O SINTAXE: <tipo_de_retorno> <nome_da_fun��o> (PAR�METROS){ instru��es;  retorno_da_fun��o;}
bool vazia(struct Lista *li) { //ponteiro li de tipo de variavel struct lista aponta para esta
    assert(li != NULL);     
    if (li->inicio == NULL) {//ponteiro li que aponta para variavel inicio, tem valor null - retorna verdadeiro
        return true;
    } else {
        return false;
    }
}


int main() {
   struct Lista *minha_lista = criar(); // da se primeiro valor a variavel ponteiro *minha_lista//ponteiro *minha_lista, de tipo de variavel struct lista, tem valor igual a fun��o criar, que em si � um ponteiro.
   //fun��o criar retorna valor da lista = 0.
   if (vazia(minha_lista) == true) {// se a fun��o vazia, com parametro(variavel): minha_lista, tem valor 0, ent�o � true e imprime lista vazia!
       printf("\nOK, lista vazia!");
   } else {
       printf("\nOps... algo deu errado!");
   } 
   return 0;
}

