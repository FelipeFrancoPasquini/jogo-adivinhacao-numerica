#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int gerar_numero_secreto(){
    int numero_secreto = (rand() % 100);
    cout << "O número secreto desta rodada é: " << numero_secreto << endl;
    
    return numero_secreto;
}

int solicitar_dificuldade(int dificuldade){
    do {
        cout << "Em qual nível de dificuldade deseja jogar?" << endl;
        cout << "Digite o número correspondente as dificuldades abaixo:" << endl;
        cout << "[1] - Fácil = 20 tentativas.\n[2] - Médio = 15 tentativas.\n[3] - Difícil = 10 tentativas" << endl;
        cin >> dificuldade;
    } while (dificuldade != 1 && dificuldade != 2 && dificuldade != 3);
    
    return dificuldade;
}

int configuracao_dificuldade(int dificuldade, int tentativas_disponiveis){
    switch (dificuldade) {
    case 1:
        tentativas_disponiveis = 20;
        break;
    case 2:
        tentativas_disponiveis = 15;
        break;
    case 3:
        tentativas_disponiveis = 10;
        break;
    default:
        break;
    }
    
    return tentativas_disponiveis;
}

void verificar_numero_chutado(int numero_chutado, int numero_secreto){
    if (numero_chutado > numero_secreto) cout << "O número " << numero_chutado << " é maior do que o número secreto. Tente novamente!" << endl;
    else cout << "O número " << numero_chutado << " é menor do que o número secreto.\nTente novamente!" << endl;
}

int evento_vitoria(int tentativas_utilizadas){
    cout << "Parabéns! Você adivinhou o número secreto utilizando " << tentativas_utilizadas << " tentativas." << endl;
    cout << "Fim de jogo." << endl;
    
    return 0;
}

int evento_derrota(int tentativas_disponiveis){
    cout << "Infelizmente, você não acertou o número secreto em " << tentativas_disponiveis << " tentativas." << endl;
    cout << "Fim de jogo." << endl;
    
    return 0;
}

int main(){
    srand(time(NULL));
    int dificuldade = 0, tentativas_disponiveis = 0, tentativas_utilizadas = 0, numero_chutado;
    bool partida_em_andamento = true;
    
    while (partida_em_andamento) {
        int numero_secreto = gerar_numero_secreto();
        
        dificuldade = solicitar_dificuldade(dificuldade);
        tentativas_disponiveis = configuracao_dificuldade(dificuldade,tentativas_disponiveis);
        
        for (tentativas_utilizadas = 1; tentativas_utilizadas <= tentativas_disponiveis; tentativas_utilizadas++){
            
            
            cout << "\nTentativa número: " << tentativas_utilizadas << "/" << tentativas_disponiveis << endl;
            cout << "Qual é o seu chute?" << endl;
            cin >> numero_chutado;
            
            if (numero_chutado == numero_secreto) break;
            
            verificar_numero_chutado(numero_chutado, numero_secreto);
        }
        
        if (numero_chutado == numero_secreto) {
            evento_vitoria(tentativas_utilizadas);
        } else {
            evento_derrota(tentativas_disponiveis);
        }
        
        partida_em_andamento = false;
    }

    return 0;
}
