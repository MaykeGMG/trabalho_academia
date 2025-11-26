#include "Ficha.h"
#include <iostream>
#include <iomanip>

int Ficha::proximoId = 1;

// Construtor para novos cadastros
Ficha::Ficha(std::string nome) : nome(nome) {
    this->id = proximoId++;
}

// Construtor para leitura de arquivo
Ficha::Ficha(int id, std::string nome) : nome(nome){
    this->id = id;

    if (id >= proximoId) {
        proximoId = id + 1;
    }
}

// Destrutor (não deletar exercícios, apenas limpar vector)
Ficha::~Ficha() {
    exercicios.clear();
}

// Adicionar exercício à ficha
void Ficha::adicionarExercicio(Exercicio* exercicio) {
    exercicios.push_back(exercicio);
    std::cout << "exercicio adicionado à ficha de treino: " << exercicio->getNome() << std::endl;
}

// Exibir ficha completa com exercícios e totais
void Ficha::exibirFicha() const {

    std::cout << nome << ":\n";

    for (const auto& exercicio : exercicios){
        std::cout << exercicio->getNome() << std::endl;
    }

    std::cout << "Tempo estimado de execução do treino: " << calcularTempoTotal() << " Estimativa de calorias totais gastas no treino: " << calcularCaloriasTotais() << std::endl;
}

// Calcular tempo total da ficha
double Ficha::calcularTempoTotal() const {

    double total = 0.0;

    for (const auto& exercicio : exercicios){
        total += exercicio->calcularTempoEstimado();
    }

    return total;
}

// Calcular calorias totais da ficha
double Ficha::calcularCaloriasTotais() const {

    double total = 0.0;

    for (const auto& exercicio : exercicios){
        total += exercicio->calcularCaloriasGastas();
    }

    return total;
}

// Getters
int Ficha::getId() const { 
    return id;
}

std::string Ficha::getNome() const { 
    return nome;
}

const std::vector<Exercicio*>& Ficha::getExercicios() const {
    static std::vector<Exercicio*> vazio; // Placeholder para compilar

    for (const auto& exercicio : exercicios){
        vazio.push_back(exercicio);
    }

    return vazio; // Implementar
}

// Atualizar próximo ID
void Ficha::atualizarProximoId(int maiorId) {
    // Implementar
}
