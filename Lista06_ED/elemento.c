#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elemento.h>

typedef struct elemento{
    struct tarefa dados;
    struct elemento *prox;
} Elem;

typedef struct elemento* ListaTarefas;

ListaTarefas* criar_lista(void){
    ListaTarefas* li = malloc(sizeof(ListaTarefas));
    if(li != NULL) li = NULL;
    return li;
}

void libera_lista(ListaTarefas* li){
    if(li != NULL) {
        Elem* no;
        while( (*li) != NULL){
        no = *li;
        *li = no->prox;
        free(no);
        }
    }
    free(li);
}

int tamanho_lista(ListaTarefas* li){
    if (li == NULL) return -1;
    if (*li == NULL) return 0;
    Elem* no = *li;
    int tam = 0;
    while(no != NULL){
        no = no->prox;
        tam += 1;
    }
    return tam;
}

int lista_vazia(ListaTarefas* li){
    if( li == NULL) return 1;
    if( *li == NULL) return 1;
    return 0;
}

int lista_cheia(ListaTarefas* li){
    (void) li;
    return 0;
}

int insere_tarefa_inicio(ListaTarefas* li, struct tarefa t){
    if( li == NULL) return 0;
    Elem* no = malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = t;
    no->prox = *li;
    *li = no;
    return 1;
}

int insere_tarefa_final(ListaTarefas* li, struct tarefa t){
    if (li == NULL) return 0;
    Elem* no = malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = t;
    no->prox = NULL;
    if(*li== NULL){
        *li = no;
        return 1;
    }
    Elem *prox = *li;
    while(prox->prox != NULL){;
        prox = prox->prox;
    }
    prox->prox = no;
    return 1;
}

int insere_tarefa_ordenada(ListaTarefas* li, struct tarefa t){
    if(li == NULL) return 0;
    Elem* no = malloc(sizeof(Elem));
    if( no == NULL) return 0;
    no->dados = t;
    if (*li == NULL){
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant = NULL, *prox = *li;
        while(prox != NULL && prox->dados.prioridade < no->dados.prioridade){
            ant = prox;
            prox = prox->prox;
        }
        if(prox == *li){
            no->prox = *li;
            *li = no;
            return 1;
        }
        else{
            ant->prox = no;
            no->prox = prox;
        }
        return 1;
    }
}

int remove_tarefa_inicio(ListaTarefas* li){
    if( li == NULL) return 0;
    if( *li == NULL) return 0;
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_tarefa_final(ListaTarefas* li){
    if( li == NULL || *li == NULL) return 0;
    Elem *ant = NULL, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if( no == *li){
        *li = NULL;
    }
    else{
     ant->prox = NULL;
    }
    free(no);
    return 1;   
}

int remove_tarefa(ListaTarefas* li, int codigo){
    if( li == NULL || *li == NULL) return 0;
    Elem *ant = NULL, *atual = *li;
    while(atual != NULL && atual->dados.codigo != codigo){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == NULL){
        return 0; // código ausente
    }
    if(atual == *li){
        *li = atual->prox;
    }
    else{
        ant->prox = atual->prox;
    }
    free(atual);
    return 1;
}

int busca_tarefa_pos(ListaTarefas* li, int pos, struct tarefa *t){
    if( li == NULL || *li == NULL || pos < 0) return 0;
    Elem *no = *li;
    int i = 0;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL){
        return 0;
    }
    else{
        *t = no->dados;
        return 1;
    }
}

int busca_tarefa_cod(ListaTarefas* li, int codigo, struct tarefa *t){
    if( li == NULL || *li == NULL || t == NULL) return 0;
    Elem *no = *li;
    while (no != NULL && no->dados.codigo != codigo){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    else{
        *t = no->dados;
        return 1;
    }
}
#include <stdlib.h>
#include <string.h>

int conta_tarefas_prioridade(ListaTarefas* li, int prioridade){
    if (li == NULL) return -1;
    Elem *no = *li;
    int soma = 0;
    while (no != NULL){
        if (no->dados.prioridade == prioridade){
            soma += 1;
        }
        no = no->prox;
    }
    return soma;
}


int tarefa_mais_urgente(ListaTarefas* li, struct tarefa *t){
    if (li == NULL || *li == NULL || t == NULL) return 0;
    Elem *no = (*li)->prox;
    *t = (*li)->dados;              /* o primeiro nó é o candidato inicial */
    while (no != NULL){
        if (no->dados.prioridade < t->prioridade){   /* '<' mantém a primeira no empate */
            *t = no->dados;
        }
        no = no->prox;
    }
    return 1;
}

int busca_tarefa_desc(ListaTarefas* li, char *texto, struct tarefa *t){
    if (li == NULL || *li == NULL || texto == NULL || t == NULL) return 0;
    Elem *no = *li;
    while (no != NULL){
        if (strstr(no->dados.descricao, texto) != NULL){
            *t = no->dados;
            return 1;
        }
        no = no->prox;
    }
    return 0;
}

int insere_tarefa_final_prioridade(ListaTarefas* li, struct tarefa t){
    if (li == NULL) return 0;
    Elem *atual = *li, *ant = NULL, *ult = NULL;
    while (atual != NULL){
        if (atual->dados.prioridade == t.prioridade){
            ult = atual;            /* última ocorrência da prioridade */
        }
        ant = atual;                /* ao final, é o último nó da lista */
        atual = atual->prox;
    }
    Elem *no = malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = t;
    no->prox = NULL;
    if (*li == NULL){               /* lista vazia */
        *li = no;
        return 1;
    }
    if (ult == NULL){               /* prioridade ausente: insere no final */
        ant->prox = no;
        return 1;
    }
    no->prox = ult->prox;           /* prioridade existente: insere após ult */
    ult->prox = no;
    return 1;
}


int remove_tarefas_prioridade(ListaTarefas* li, int prioridade){
    if (li == NULL) return -1;
    int removidas = 0;
    Elem *ant = NULL, *atual = *li;
    while (atual != NULL) {
        if (atual->dados.prioridade == prioridade) {
            Elem *no = atual;
            if (ant == NULL)
                *li = atual->prox;
            else
                ant->prox = atual->prox;
            atual = atual->prox;
            free(no);
            removidas++;            /* ant fica parado ao remover */
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }
    return removidas;
}

int mescla_tarefas(ListaTarefas* dst, ListaTarefas* src){
    if(dst == NULL || src == NULL) return 0;
    if( *src = NULL){
        free(src);
        return 1;
    }
    if( *dst == NULL){
        *dst = *src;
        Elem *no = *src
        
    }
    Elem *fim_dst = *dst;
    while(fim_dst->prox != NULL){
        fim_dst = fim_dst->prox;
    }
    
    
}