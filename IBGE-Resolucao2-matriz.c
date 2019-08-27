#include <stdio.h>

//SEGUNDA SOLU��O, USANDO MATRIZ

int main() {
	
    int num_cidade;
    printf("==== IBGE ==== \n \n");
    printf("Digite a quantidade de cidades a serem cadastradas: ");
    scanf("%d", &num_cidade); // numero de cidades a ser cadastradas
    
    /** A matriz ter� a quantidade de cidadas cadastras, e 3 colunas fixas, 
        a primeira coluna [0] representa o c�digo da cidade, 
        a segunda coluna [1] a quantidade de veiculos 
        e a terceira coluna [2] a quantidade de v�timas*/
    printf("\n\nAgora digite os dados da cidade: \n\n");
    int cidades[num_cidade][3]; 
    
     // o looping dever� ser apenas nas linhas da matriz j� que sabemos que as colunas s�o fixas e representam uma informa��o espec�fica
    for (int i = 0; i < num_cidade; i++) { //usaremos sempre o num_cidade para varrer a matriz.
        printf("------------------------------");
        printf("\n\nCadastro da cidade: %d", i+1);
        
        printf("\nDigite o c�digo da cidade: ");
        scanf("%d", &cidades[i][0]);
        
        printf("Digite o n�mero de veiculos de passeio da cidade:");
        scanf("%d", &cidades[i][1]);
        
        printf("Digite o n�mero de acidentes de tr�nsito com v�timas:");
        scanf("%d", &cidades[i][2]);
    }
    
    printf("\n\nRELAT�RIOS: \n\n");
    printf("\n\n-------------------\n\n");
    /**
     Aqui faremos uma l�gica de maior, 
     pegamos as informa��es da priemira posi��es da matriz e comparamos com as sbsequentes da mesma
     se o volor da vari�vel for menor que a comparada, ela recebe o valor da comparada, 
     assim no final a vari�vel ficar� com o maior valor de todo o array.
    */
    int maior_n_acidente = cidades[0][2];  //vari�vel para guardar o valor do maior numero de acidentes
    int cod_cid_maior_acid = cidades[0][0]; //vari�vel para guardar o valor o c�digo da cidade
    for (int i = 0; i < num_cidade; i++) {
        if(maior_n_acidente < cidades[i][2]){ // compara com a posi��es [2] da matriz que corresponde ao dados de acidentes
            maior_n_acidente = cidades[i][2];
            cod_cid_maior_acid = cidades[i][0];
        }
     }
    printf("A cidade com maior ind�ce de acidentes �: %d", cod_cid_maior_acid);
    printf("\nE o n�mero de acidentes �: %d", maior_n_acidente);
    
    
    printf("\n\n-------------------\n\n");
     /**
     Aqui faremos uma l�gica de menor, 
     pegamos as informa��es da priemira posi��es da matriz e comparamos com as sbsequentes da mesma
     se o volor da vari�vel for maior que a comparada, ela recebe o valor da comparada, 
     assim no final a vari�vel ficar� com o menor valor de todo o array.
    */
    int menor_n_acidente = cidades[0][2]; //vari�vel para guardar o valor do menor numero de acidentes
    int cod_cid_menor_acid = cidades[0][0]; //vari�vel para guardar o valor o c�digo da cidade
    for (int i = 0; i < num_cidade; i++) {
        if(menor_n_acidente > cidades[i][2]) { // compara com a posi��es [2] da matriz que corresponde ao dados de acidentes
            menor_n_acidente = cidades[i][2];
            cod_cid_menor_acid = cidades[i][0];
        }
     }
    printf("A cidade com  menor ind�ce de acidentes �: %d", cod_cid_menor_acid);
    printf("\nE o n�mero de acidentes �: %d", menor_n_acidente);
    
    printf("\n\n-------------------\n\n");
     /**
        L�gica de m�dia de veiculos, somamos todos os veiculos do array,
        e no fim dividimos pela quantiade de cidades.
    */
    int total_veiculos = 0;
    for (int i = 0; i < num_cidade; i++) {
        total_veiculos = total_veiculos + cidades[i][1]; // soma com a posi��o [1] j� que corresponde ao dados de numeros de veiculos.
    }
    
    float media_veiculo = total_veiculos / num_cidade;
    printf("A m�ida de veiculos nas cidades juntas �: %.1f", media_veiculo);
    
    printf("\n\n-------------------\n\n");
    /**
        L�gica de m�dia de acidentes de tr�nsito, 
        desde que a cidade tenha menos que 2000 veiculos.
    */
    int total_acident_transito = 0; //vari�vel para somar os acidentes de tr�nsito
    int count_cidades_menor_2000 = 0; //var�vel que ir� contar quntas cidade tem menos que 2000, necess�ria para m�dia, j� que n�o faremos desta vez com a quantiade de cidades.
    for (int i = 0; i < num_cidade; i++) {
        if(cidades[i][1] < 2000){  // compara com a posi��o [1] j� que corresponde ao dados de numeros de veiculos.
            total_acident_transito = total_acident_transito + cidades[i][2];
            count_cidades_menor_2000++;
        }
    }
    
     float media_acidente_transito = total_acident_transito / count_cidades_menor_2000;
     printf("A m�ida de acidentes de tr�nsito em cidades com menos de 2000 ve�culos �: %.1f", media_acidente_transito);
    
        

    return 0;
}