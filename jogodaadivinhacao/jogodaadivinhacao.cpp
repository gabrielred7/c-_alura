#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    setlocale(LC_ALL,"");
    cout << "*****************************************" << endl;
    cout << "*** Bem-vindos ao jogo da adivinhação! **" << endl;
    cout << "*****************************************" << endl;

    // Escolhendo a dificuldade
    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;
    char dificuldade;
    cin >> dificuldade;
    int n_tentativas;

    if (dificuldade == 'F'){
        n_tentativas = 15;
    }
    else if (dificuldade == 'M'){
        n_tentativas = 10;
    }
    else {
        n_tentativas = 5;
    }
    // Sorteando um numero aleatorio
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    int tentativas = 0;
    bool nao_acertou = true;
    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= n_tentativas; tentativas++){
        cout << "Tentativa de numero " << tentativas << endl;
        int chute;
        cout << "Qual o seu chute? ";
        cin >> chute;
        cout << "O valor do seu chute e: " << chute << "." << endl;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/(double) 2;
        pontos = pontos - pontos_perdidos;

        bool maior = chute > NUMERO_SECRETO;
        bool menor = chute < NUMERO_SECRETO;

        if (maior){
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        }
        else if (menor){
            cout << "Seu chute foi menor que o numero secreto!" << endl;
        }
        else {
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
        }
        cout << " " << endl;
    }
    cout << "Fim de Jogo!" << endl;

    if (nao_acertou){
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
    }
}
