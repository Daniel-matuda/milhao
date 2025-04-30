#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char pergunta[500];
    char opcoes[5][200];
    char resposta;
} Pergunta;

Pergunta perguntas1k[5] = {
    {
        "Qual e o comando usado para imprimir algo na tela em C?",
        {"printf", "echo", "print", "System.out.println", "cout"},
        'A'
    },
    {
        "Qual e o tipo de dado usado para numeros inteiros em C?",
        {"float", "char", "boolean", "int", "string"},
        'D'
    },
    {
        "Qual simbolo e usado para comentarios de uma linha em C?",
        {"/*", "--", "#", "//", "*/"},
        'D'
    },
    {
        "Qual funcao e usada para ler um caractere do teclado em C?",
        {"scanf", "getchar", "fgets", "read", "input"},
        'B'
    },
    {
        "Qual e o operador para comparar se dois valores sao iguais em C?",
        {"=", "==", "!=", "===", "equals"},
        'B'
    }
};

Pergunta perguntas10k[5] = {
    {
        "Qual e a funcao usada para alocar memoria dinamicamente em C?",
        {"new", "create", "malloc", "memory", "alloc"},
        'C'
    },
    {
        "Como declaramos um ponteiro para inteiro em C?",
        {"pointer int", "int ptr", "int &ptr", "int* ptr", "ptr int"},
        'D'
    },
    {
        "Qual e o valor retornado pela funcao main em caso de sucesso?",
        {"1", "0", "-1", "true", "void"},
        'B'
    },
    {
        "Qual biblioteca contem a funcao printf em C?",
        {"math.h", "conio.h", "string.h", "stdio.h", "stdlib.h"},
        'D'
    },
    {
        "Qual e o operador para acessar o valor apontado por um ponteiro?",
        {"->", "*", "#", "&", "."},
        'B'
    }
};

Pergunta perguntas100k[5] = {
    {
        "Qual e a diferenca entre ++i e i++ em C?",
        {"i++ e mais rapido", "++i incrementa antes de usar, i++ depois", "Nenhuma", "++i nao existe", "i++ so funciona em loops"},
        'B'
    },
    {
        "Qual das opcoes melhor descreve o uso do operador 'sizeof' em C?",
        {"Multiplica tamanhos", "Retorna o valor da variavel", "Retorna o tamanho da variavel ou tipo em bytes", "Retorna a quantidade de elementos", "Capacidade maxima"},
        'C'
    },
    {
        "Qual e o tamanho em bytes do tipo 'double' na maioria dos sistemas?",
        {"4", "16", "8", "Depende do sistema", "2"},
        'C'
    },
    {
        "Qual e a funcao usada para comparar duas strings em C?",
        {"==", "strcompare", "stringcmp", "strcmp", "compare"},
        'D'
    },
    {
        "O que a funcao 'strcpy' faz?",
        {"Compara strings", "Concatena strings", "Copia strings", "Conta caracteres", "Divide strings"},
        'C'
    }
};

Pergunta perguntas500k[5] = {
    {
        "Qual e o comportamento de um ponteiro NULL quando dereferenciado?",
        {"Valor aleatorio", "Retorna 0", "Aponta para um valor indefinido", "Cria um novo ponteiro", "Nada acontece"},
        'C'
    },
    {
        "O que e uma 'struct' em C?",
        {"Uma funcao", "Um tipo de dado composto", "Um operador", "Um ponteiro", "Uma macro"},
        'B'
    },
    {
        "Como alocar memoria para um array de 10 inteiros dinamicamente?",
        {"int* arr = malloc(10)", "int arr[10]", "int* arr = malloc(10*sizeof(int))", "int arr = new int[10]", "int arr = alloc(10)"},
        'C'
    },
    {
        "Qual e a diferenca entre 'malloc' e 'calloc'?",
        {"calloc inicializa com 0", "malloc e mais rapido", "calloc aloca e executa", "Nenhuma", "calloc nao existe"},
        'A'
    },
    {
        "O que a palavra-chave 'volatile' indica em C?",
        {"E otimizada", "E constante", "A variavel pode mudar inesperadamente", "E temporaria", "E global"},
        'C'
    }
};

Pergunta perguntas1kk[5] = {
    {
        "Qual e a diferenca entre 'char* const' e 'const char*'?",
        {"Ambos sao ponteiros para constantes", "Ambos sao ponteiros constantes", "const char* e um ponteiro constante, char* const e um ponteiro para constante", "Nenhuma", "char* const e um ponteiro constante, const char* e um ponteiro para constante"},
        'E'
    },
    {
        "O que e um 'ponteiro para funcao' em C?",
        {"Uma variavel que armazena um endereco de funcao", "Um array especial", "Uma funcao que retorna um ponteiro", "Um ponteiro para si mesmo", "Um conceito que nao existe"},
        'A'
    },
    {
        "Como implementar polimorfismo em C?",
        {"Heranca", "Usando structs com ponteiros para funcoes", "Usando templates", "Nao e possivel", "Usando classes"},
        'B'
    },
    {
        "O que e 'strict aliasing' em C?",
        {"Uma regra que proibe acessar o mesmo dado com tipos diferentes", "Casting", "Um ponteiro especial", "Depuracao", "Uma tecnica de otimizacao"},
        'A'
    },
    {
        "Qual e o proposito da palavra-chave 'restrict' em C?",
        {"Criar constantes", "Indicar que um ponteiro e o unico acesso a um objeto", "Restringir escopo", "Substituir const", "Otimizar loops"},
        'B'
    }
};

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char obterResposta() {
    char resposta;
    printf("\nSua resposta: ");
    scanf(" %c", &resposta);
    limparBuffer();
    return toupper(resposta);
}

void mostrarPontuacao(int pontos) {
    printf("\nPontuacao atual: %d pontos\n", pontos);
}

Pergunta selecionarPerguntaAleatoria(Pergunta perguntas[], int totalPerguntas) {
    return perguntas[rand() % totalPerguntas];
}

int jogarRodada(Pergunta p, int valorRodada) {
    printf("\nRodada de %d pontos\n", valorRodada);
    printf("Pergunta: %s\n", p.pergunta);
    for (int i = 0; i < 5; i++) {
        printf("%c) %s\n", 'A' + i, p.opcoes[i]);
    }
    
    char resposta = obterResposta();
    
    if (resposta == p.resposta) {
        printf("\nResposta correta! Voce ganhou %d pontos!\n", valorRodada);
        return valorRodada;
    } else {
        printf("\nResposta incorreta! A resposta correta era %c.\n", p.resposta);
        return -1;
    }
}

int main() {
    srand(time(NULL));
    int pontos = 0;
    int rodada = 1;
    int valoresRodadas[] = {1000, 10000, 100000, 500000, 1000000};
    char continuar;
    
    printf("Bem-vindo ao Jogo de Perguntas e Respostas sobre Linguagem C!\n");
    printf("Voce comecara com 0 pontos e tera que responder perguntas de dificuldade crescente.\n");
    printf("Voce pode parar a qualquer momento (a partir da segunda pergunta) e ficar com metade dos pontos acumulados.\n");
    printf("Mas cuidado! Se errar, perde tudo!\n\n");
    
    Pergunta p1k = selecionarPerguntaAleatoria(perguntas1k, 5);
    pontos += jogarRodada(p1k, valoresRodadas[0]);
    
    if (pontos == -1) {
        printf("\nGame Over! Voce perdeu tudo.\n");
        return 0;
    }
    
    mostrarPontuacao(pontos);
    
    for (rodada = 2; rodada <= 5; rodada++) {
        printf("\nVoce esta na rodada %d (%d pontos). Deseja continuar? (S/N): ", rodada, valoresRodadas[rodada-1]);
        scanf(" %c", &continuar);
        limparBuffer();
        
        if (toupper(continuar) != 'S') {
            pontos = pontos / 2;
            printf("\nVoce desistiu e ficou com metade dos pontos: %d\n", pontos);
            break;
        }
        
        Pergunta p;
        switch(rodada) {
            case 2: p = selecionarPerguntaAleatoria(perguntas10k, 5); break;
            case 3: p = selecionarPerguntaAleatoria(perguntas100k, 5); break;
            case 4: p = selecionarPerguntaAleatoria(perguntas500k, 5); break;
            case 5: p = selecionarPerguntaAleatoria(perguntas1kk, 5); break;
        }
        
        int resultado = jogarRodada(p, valoresRodadas[rodada-1]);
        
        if (resultado == -1) {
            pontos = 0;
            printf("\nGame Over! Voce perdeu tudo.\n");
            break;
        } else {
            pontos += resultado;
            mostrarPontuacao(pontos);
            
            if (rodada == 5) {
                printf("\nParabens! Voce completou todas as rodadas e ganhou %d pontos!\n", pontos);
            }
        }
    }
    
    return 0;
}