#include <stdio.h>

//SEGUNDA SOLUÇÃO, USANDO MATRIZ

int main() {
	
    int num_cidade;
    printf("==== IBGE ==== \n \n");
    printf("Digite a quantidade de cidades a serem cadastradas: ");
    scanf("%d", &num_cidade); // numero de cidades a ser cadastradas
    
    /** A matriz terá a quantidade de cidadas cadastras, e 3 colunas fixas, 
        a primeira coluna [0] representa o código da cidade, 
        a segunda coluna [1] a quantidade de veiculos 
        e a terceira coluna [2] a quantidade de vítimas*/
    printf("\n\nAgora digite os dados da cidade: \n\n");
    int cidades[num_cidade][3]; 
    
     // o looping deverá ser apenas nas linhas da matriz já que sabemos que as colunas são fixas e representam uma informação específica
    for (int i = 0; i < num_cidade; i++) { //usaremos sempre o num_cidade para varrer a matriz.
        printf("------------------------------");
        printf("\n\nCadastro da cidade: %d", i+1);
        
        printf("\nDigite o código da cidade: ");
        scanf("%d", &cidades[i][0]);
        
        printf("Digite o número de veiculos de passeio da cidade:");
        scanf("%d", &cidades[i][1]);
        
        printf("Digite o número de acidentes de trânsito com vítimas:");
        scanf("%d", &cidades[i][2]);
    }
    
    printf("\n\nRELATÓRIOS: \n\n");
    printf("\n\n-------------------\n\n");
    /**
     Aqui faremos uma lógica de maior, 
     pegamos as informações da priemira posições da matriz e comparamos com as sbsequentes da mesma
     se o volor da variável for menor que a comparada, ela recebe o valor da comparada, 
     assim no final a variável ficará com o maior valor de todo o array.
    */
    int maior_n_acidente = cidades[0][2];  //variável para guardar o valor do maior numero de acidentes
    int cod_cid_maior_acid = cidades[0][0]; //variável para guardar o valor o código da cidade
    for (int i = 0; i < num_cidade; i++) {
        if(maior_n_acidente < cidades[i][2]){ // compara com a posições [2] da matriz que corresponde ao dados de acidentes
            maior_n_acidente = cidades[i][2];
            cod_cid_maior_acid = cidades[i][0];
        }
     }
    printf("A cidade com maior indíce de acidentes é: %d", cod_cid_maior_acid);
    printf("\nE o número de acidentes é: %d", maior_n_acidente);
    
    
    printf("\n\n-------------------\n\n");
     /**
     Aqui faremos uma lógica de menor, 
     pegamos as informações da priemira posições da matriz e comparamos com as sbsequentes da mesma
     se o volor da variável for maior que a comparada, ela recebe o valor da comparada, 
     assim no final a variável ficará com o menor valor de todo o array.
    */
    int menor_n_acidente = cidades[0][2]; //variável para guardar o valor do menor numero de acidentes
    int cod_cid_menor_acid = cidades[0][0]; //variável para guardar o valor o código da cidade
    for (int i = 0; i < num_cidade; i++) {
        if(menor_n_acidente > cidades[i][2]) { // compara com a posições [2] da matriz que corresponde ao dados de acidentes
            menor_n_acidente = cidades[i][2];
            cod_cid_menor_acid = cidades[i][0];
        }
     }
    printf("A cidade com  menor indíce de acidentes é: %d", cod_cid_menor_acid);
    printf("\nE o número de acidentes é: %d", menor_n_acidente);
    
    printf("\n\n-------------------\n\n");
     /**
        Lógica de média de veiculos, somamos todos os veiculos do array,
        e no fim dividimos pela quantiade de cidades.
    */
    int total_veiculos = 0;
    for (int i = 0; i < num_cidade; i++) {
        total_veiculos = total_veiculos + cidades[i][1]; // soma com a posição [1] já que corresponde ao dados de numeros de veiculos.
    }
    
    float media_veiculo = total_veiculos / num_cidade;
    printf("A méida de veiculos nas cidades juntas é: %.1f", media_veiculo);
    
    printf("\n\n-------------------\n\n");
    /**
        Lógica de média de acidentes de trânsito, 
        desde que a cidade tenha menos que 2000 veiculos.
    */
    int total_acident_transito = 0; //variável para somar os acidentes de trânsito
    int count_cidades_menor_2000 = 0; //varável que irá contar quntas cidade tem menos que 2000, necessária para média, já que não faremos desta vez com a quantiade de cidades.
    for (int i = 0; i < num_cidade; i++) {
        if(cidades[i][1] < 2000){  // compara com a posição [1] já que corresponde ao dados de numeros de veiculos.
            total_acident_transito = total_acident_transito + cidades[i][2];
            count_cidades_menor_2000++;
        }
    }
    
     float media_acidente_transito = total_acident_transito / count_cidades_menor_2000;
     printf("A méida de acidentes de trânsito em cidades com menos de 2000 veículos é: %.1f", media_acidente_transito);
    
        

    return 0;
}