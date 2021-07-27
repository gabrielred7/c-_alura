#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

//Variaveis Globais
const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

// Funcao Auxiliar para Verificar Palpites
bool letra_existe(char chute){
    for(char letra : PALAVRA_SECRETA){ // For do C++11
        if(chute == letra){
            return true;
        }
    }
    return false;
}

//Fun��o Auxiliar para Verificar se o Usuario chutou todas as letras
bool nao_acertou(){
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

//Fun��o Auxiliar para Verificar se o Usuario enforcou
bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

// Cabe�alho Refatorado
void imprime_cabecalho(){
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

//Imprime os chutes errados
void imprime_erros(){
    cout << "Chutes errados: ";
    for(char letra : chutes_errados){
        cout << letra << " ";
    }
    cout << endl;
}

//Imprime o status atual da palavra do jogo da forca
void imprime_palavra(){
    for(char letra : PALAVRA_SECRETA){
        if (chutou [letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}

int main(){
    setlocale(LC_ALL,"");
    imprime_cabecalho();
    //Palpites de Letras
    while(nao_acertou() && nao_enforcou()){

        // Apresentando a lista de chutes errados
        imprime_erros();

        // Escrevendo as palavras secretas
        imprime_palavra();

        //Analisando os chutes de letras
        cout << "Seu chute: ";
        char chute;
        cin >> chute;
        chutou[chute] = true;

        //Verificando Palpites
        if(letra_existe(chute)){
            cout << "Voc� acertou! Seu chute est� na palavra." << endl;
        }
        else{
            cout << "Voc� errou! Seu chute n�o est� na palavra." << endl;
            //Inserindo uma nova letra na lista de chutes errados
            chutes_errados.push_back(chute);
        }
        cout << endl;
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta �: " << PALAVRA_SECRETA << endl;
    if(nao_acertou()){
        cout << "Voc� Perdeu! Tente Novamente!" << endl;
    }
    else{
        cout << "Parab�ns! Voc� acertou a palavra secreta!" << endl;
    }
}
