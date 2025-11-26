#include "Sistema.h"
#include "Cardio.h"
#include "Forca.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>

Sistema::Sistema() {
    carregarDados();
}

Sistema::~Sistema() {
    salvarDados();
    // Deletar ponteiros de exercicios e fichas
    for (auto p : exercicios){
        delete p;
    }
    for (auto f : fichas){
        delete f;
    }
}

// Carregar dados dos arquivos
void Sistema::carregarDados() {
    // Carregar exercicios.txt
    // Carregar fichas.txt
    historico.carregarDeArquivo();
}

// Salvar dados nos arquivos
void Sistema::salvarDados() {
    // Salvar exercicios.txt
    // Salvar fichas.txt
    historico.salvarEmArquivo();
}

// Buscar exercício por ID
Exercicio* Sistema::buscarExercicioPorId(int id) {
    return nullptr; // Implementar
}

// Buscar ficha por ID
Ficha* Sistema::buscarFichaPorId(int id) {
    return nullptr; // Implementar
}

// Cadastrar novo exercício
void Sistema::cadastrarExercicio() {
    int tipo;

    std::cout << "Tipo (1 - Cardio;  2 - Força): ";
    std::cin >> tipo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (tipo == 1){
        std::string nome;
        double duracao;
        double calorias;

        std::cout << "Nome do exercicio: ";
        getline(std::cin, nome);

        std::cout << "Duração do exercício: ";
        std::cin >> duracao;

        std::cout << "Calorias por minuto: ";
        std::cin >> calorias;

        exercicios.push_back(new Cardio(nome, duracao, calorias));

    }else if (tipo == 2){
        std::string nome;
        double carga;
        int series;
        int repeticoes;
        int tempoDescanso;

        std::cout << "Nome do exercicio: ";
        getline(std::cin, nome);

        std::cout << "Carga do exercício: ";
        std::cin >> carga;

        std::cout << "Quantidade de séries: ";
        std::cin >> series;

        std::cout << "Quantidade de repetições: ";
        std::cin >> repeticoes;

        std::cout << "Tempo de descanso entre séries (em segundos): ";
        std::cin >> tempoDescanso;

        exercicios.push_back(new Forca(nome, carga, series, repeticoes, tempoDescanso));
    }else{
        std::cout << "Valor informado não coresponde a um tipo de exercício!" << std::endl;
    }
    

}

// Listar exercícios ativos
void Sistema::listarExercicios() {
    
    for (const auto e : exercicios){
        if(e->isAtivo()){
            e->exibirDetalhes();
        }
    }
}

// Desativar exercício
void Sistema::excluirExercicio() {
    // Implementar
}

// Criar nova ficha
void Sistema::criarFicha() {
    // Implementar
}

// Adicionar exercício à ficha
void Sistema::adicionarExercicioFicha() {
    // Implementar
}

// Listar todas as fichas
void Sistema::listarFichas() {
    // Implementar
}

// Registrar treino realizado
void Sistema::registrarTreino() {
    // Implementar
}

// Exibir histórico de treinos
void Sistema::exibirHistorico() {
    // Implementar
}
