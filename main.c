#include "gfx.h"
#include <stdio.h>
#include <stdlib.h>
//Cauê Mendonça Magela do Ó
//rgm : 43558

struct Pilha{
    int valor;
    struct Pilha *prox;
};

void inserir(int x, struct Pilha **topo){
    struct Pilha *pt = malloc(sizeof(struct Pilha));
    pt->valor = x;
    pt->prox = *topo;
    *topo = pt;
}

int main() {
    char string[50];
    int valor, resp, width, height, textwidth, textheight;
    struct Pilha *topo = NULL;
    struct Pilha *pt = NULL;
    struct Pilha *desalocar = NULL;
    gfx_init(1280, 720, "Pilha");
    gfx_set_color(255, 255, 255);
    do{
        printf("1-insercao\n2-remocao\n3-sair\n");
        scanf("%d", &resp);
        switch (resp) {
            case 1:
                printf("Informe o numero que sera inserido\n");
                scanf("%d", &valor);
                inserir(valor, &topo);
                break;
            case 2:
                if(topo != NULL){
                    pt = topo;
                    topo = topo->prox;
                    printf("O valor retirado foi = %d\n", pt->valor);
                    free(pt);
                }else{
                    printf("A pilha esta vazia\n");
                }
                break;
        }
        gfx_clear();
        width = 0;
        height = 0;
        pt = topo;
        sprintf(string, " topo ");
        gfx_get_text_size(string, &textwidth, &textheight);
        gfx_text(width, height, string);
    	width += textwidth;
        while (pt != NULL){
            if(pt->prox != NULL){
    	        sprintf(string, "%d -> ", pt->valor);
    	    }else{
    	        sprintf(string, "%d ", pt->valor);
    	    }
    	    gfx_get_text_size(string, &textwidth, &textheight);
    	    if(width+textwidth <= 1280){
    	        gfx_text(width, height, string);
    	        width += textwidth;
    	    }else{
    	        height += textheight;
    	        gfx_text(0, height, string);
    	        width = textwidth;
    	    }
            pt = pt->prox;
        }
        gfx_paint();
    } while (resp != 3);
    pt = topo;
    while (pt != NULL){
        desalocar = pt;
        pt = pt->prox;
        free(desalocar);
    }
    gfx_quit();
    return 0;
}
