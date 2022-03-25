#include <stdio.h>
#include <stdlib.h>

//------------ESTRUTURAS ----------------

struct Registro
 {
  int chave;
  //Outros Campos
 } ;


typedef struct Nodo
 {
  struct Registro Reg;
  struct Nodo* Dir;
  struct Nodo* Esq;
 }Nodo;

typedef struct Arvore {
    struct Nodo* Raiz;
}Arvore;

//*************************************************************
//---------------INICIALIZAÇÃO DE ÁRVORE----------------------

void inicializa(Arvore* arv)
{
    arv->Raiz = NULL;
}


//************************************************************
//------------------INSERÇÃO EM ÁRVORE-----------------------

void insere(Arvore *arv)
{
    struct Nodo *p;

    if (arv->Raiz == NULL)
    {
        arv->Raiz = (struct Nodo*)malloc(sizeof(struct Nodo));
        arv->Raiz->Reg.chave = 2;
    }

    p = arv->Raiz;

    p->Esq = (struct Nodo*)malloc(sizeof(struct Nodo));
    p->Dir = (struct Nodo*)malloc(sizeof(struct Nodo));

    p->Dir->Reg.chave = 1;
    p->Dir->Esq=NULL;
    p->Dir->Dir=NULL;

    p->Esq->Reg.chave = 3;
    p->Esq->Dir=NULL;
    p->Esq->Esq=NULL;

    p = p->Esq;

    p->Esq = (struct Nodo*)malloc(sizeof(struct Nodo));
    p->Esq->Reg.chave = 4;
    p->Esq->Dir=NULL;
    p->Esq->Esq=NULL;


}
//*************************************************************
//-----------------INSERE 2------------------------------------

void insere2(Arvore *arv)
{
    struct Nodo *p;

    if (arv->Raiz == NULL)
    {
        arv->Raiz = (struct Nodo*)malloc(sizeof(struct Nodo));
        arv->Raiz->Reg.chave = 2;
    }

    p = arv->Raiz;

    p->Esq = (struct Nodo*)malloc(sizeof(struct Nodo));
    p->Dir = (struct Nodo*)malloc(sizeof(struct Nodo));

    p->Dir->Reg.chave = 1;
    p->Dir->Esq=NULL;
    p->Dir->Dir=NULL;

    p->Esq->Reg.chave = 7;
    p->Esq->Dir=NULL;
    p->Esq->Esq=NULL;

    p = p->Esq;

    p->Esq = (struct Nodo*)malloc(sizeof(struct Nodo));
    p->Esq->Reg.chave = 4;
    p->Esq->Dir=NULL;
    p->Esq->Esq=NULL;


}


//*************************************************************
// ----------------IMPRESSÃO DE FOLHAS-------------------------

void folhas(Nodo* p){


    if (p!=NULL){
        folhas(p->Esq);

        if ((p->Dir==NULL)&&(p->Esq==NULL))
            printf("Codigo: %d\n",p->Reg.chave);

        folhas(p->Dir);

    }
}

//*****************************************************************
//-------------------QUANTIDADE DE NODOS---------------------------

int conta(struct Nodo* arv,int x){
if (arv!=NULL){
    x = conta(arv->Esq,x);
    x = conta(arv->Dir,x);
    x++;

}
return x;

}

//******************************************************************
//---------------------ALTURA ÁRVORE--------------------------------





//******************************************************************
//---------------------IMPRESSÃO DE DADOS---------------------------

void impressao(Nodo* arv){
    if (arv!=NULL){
        impressao(arv->Esq);
        printf("nodo: %d\n", arv->Reg.chave);
        impressao(arv->Dir);
    }

}

//******************************************************************
//--------------------IGUALDADE DE ARVORES--------------------------
void igualdade(Nodo* arv1, Nodo* arv2, int* x){
    if (arv1 != NULL && arv2 != NULL){
        
        if (arv1->Reg.chave != arv2->Reg.chave && x != 0){
            *x = 0;
        }

        igualdade(arv1->Esq, arv2->Esq, x);
        igualdade(arv1->Dir, arv2->Dir, x);
    }

    printf("%d", *x);
}

//******************************************************************

void main()
{

    Arvore arv, arv2;
    int x, a=0, y=1;

    inicializa(&arv);

    insere(&arv);

    inicializa(&arv2);

    insere2(&arv2);

    folhas(arv.Raiz);

    impressao(arv.Raiz);

    x = conta(arv.Raiz,a);

    printf("Qtd de nodos: %d\n",x);

    igualdade(arv.Raiz, arv2.Raiz, &y);

}
