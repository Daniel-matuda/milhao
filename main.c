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
        {"print", "echo", "printf", "cout", "System.out.println"},
        'C'
    },
    {
        "Qual e o tipo de dado usado para numeros inteiros em C?",
        {"float", "int", "string", "char", "boolean"},
        'B'
    },
    {
        "Qual simbolo e usado para comentarios de uma linha em C?",
        {"//", "#", "--", "/*", "*/"},
        'A'
    },
    {
        "Qual funcao e usada para ler um caractere do teclado em C?",
        {"scanf", "getchar", "read", "input", "fgets"},
        'B'
    },
    {
        "Qual e o operador para comparar se dois valores sao iguais em C?",
        {"=", "==", "===", "equals", "!="},
        'B'
    }
};

Pergunta perguntas10k[5] = {
    {
        "Qual e a funcao usada para alocar memoria dinamicamente em C?",
        {"new", "malloc", "alloc", "create", "memory"},
        'B'
    },
    {
        "Como declaramos um ponteiro para inteiro em C?",
        {"int ptr", "int* ptr", "ptr int", "pointer int", "int &ptr"},
        'B'
    },
    {
        "Qual e o valor retornado pela funcao main em caso de sucesso?",
        {"1", "0", "-1", "true", "void"},
        'B'
    },
    {
        "Qual biblioteca contem a funcao printf em C?",
        {"math.h", "stdlib.h", "stdio.h", "string.h", "conio.h"},
        'C'
    },
    {
        "Qual e o operador para acessar o valor apontado por um ponteiro?",
        {"&", "*", "->", ".", "#"},
        'B'
    }
};

Pergunta perguntas100k[5] = {
    {
        "Qual e a diferenca entre ++i e i++ em C?",
        {"Nenhuma, sao equivalentes", "++i incrementa antes de usar, i++ depois", "i++ e mais rapido", "++i nao existe", "i++ so funciona em loops"},
        'B'
    },
    {
        "Como declaramos uma constante em C?",
        {"const", "#define", "Ambas as opcoes", "let", "final"},
        'C'
    },
    {
        "Qual e o tamanho em bytes do tipo 'double' na maioria dos sistemas?",
        {"2", "4", "8", "16", "Depende do sistema"},
        'C'
    },
    {
        "Qual e a funcao usada para comparar duas strings em C?",
        {"strcmp", "strcompare", "compare", "stringcmp", "=="},
        'A'
    },
    {
        "O que a funcao 'strcpy' faz?",
        {"Compara strings", "Copia strings", "Concatena strings", "Conta caracteres", "Divide strings"},
        'B'
    }
};

Pergunta perguntas500k[5] = {
    {
        "Qual e o comportamento de um ponteiro NULL quando dereferenciado?",
        {"Retorna 0", "Cria um novo ponteiro", "Causa comportamento indefinido", "Retorna um valor aleatorio", "Nada acontece"},
        'C'
    },
    {
        "O que e uma 'struct' em C?",
        {"Uma funcao", "Um tipo de dado composto", "Um ponteiro", "Um operador", "Uma macro"},
        'B'
    },
    {
        "Como alocar memoria para um array de 10 inteiros dinamicamente?",
        {"int arr[10]", "int arr = new int[10]", "int* arr = malloc(10)", "int* arr = malloc(10*sizeof(int))", "int arr = alloc(10)"},
        'D'
    },
    {
        "Qual e a diferenca entre 'malloc' e 'calloc'?",
        {"Nenhuma", "calloc inicializa com 0", "malloc e mais rapido", "calloc nao existe", "malloc so aloca, calloc aloca e executa"},
        'B'
    },
    {
        "O que a palavra-chave 'volatile' indica em C?",
        {"Que a variavel e constante", "Que a variavel pode mudar inesperadamente", "Que a variavel e otimizada", "Que a variavel e temporaria", "Que a variavel e global"},
        'B'
    }
};

Pergunta perguntas1kk[5] = {
    {
        "Qual e a diferenca entre 'char* const' e 'const char*'?",
        {"Nenhuma", "char* const e um ponteiro constante, const char* e um ponteiro para constante", "const char* e um ponteiro constante, char* const e um ponteiro para constante", "Ambos sao ponteiros constantes", "Ambos sao ponteiros para constantes"},
        'B'
    },
    {
        "O que e um 'ponteiro para funcao' em C?",
        {"Uma funcao que retorna um ponteiro", "Uma variavel que armazena um endereco de funcao", "Um tipo especial de array", "Um ponteiro que aponta para si mesmo", "Um conceito que nao existe em C"},
        'B'
    },
    {
        "Como implementar polimorfismo em C?",
        {"Nao e possivel", "Usando classes", "Usando structs com ponteiros para funcoes", "Usando templates", "Usando heranca"},
        'C'
    },
    {
        "O que e 'strict aliasing' em C?",
        {"Uma tecnica de otimizacao", "Uma regra que proibe acessar o mesmo dado com tipos diferentes", "Um tipo de ponteiro", "Uma forma de casting", "Um recurso de depuracao"},
        'B'
    },
    {
        "Qual e o proposito da palavra-chave 'restrict' em C?",
        {"Indicar que um ponteiro e o unico acesso a um objeto", "Restringir o escopo de uma variavel", "Criar constantes", "Otimizar loops", "Substituir const"},
        'A'
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