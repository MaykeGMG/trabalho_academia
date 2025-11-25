#include "Historico.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

// Adicionar registro ao histórico
void Historico::adicionarRegistro(const RegistroTreino& registro) {
    // Implementar
}

// Exibir histórico completo
void Historico::exibirHistorico() const {
    std::cout << "histórico de treino: " << std::endl;
    for (const auto& registro : registros){
        std::cout << registro.dataHora << " - " << registro.nomeFicha << "\nCalorias Gastas: " << registro.caloriasTotal << "KCal; Tempo: " << registro.tempoTotal << " minutos" << std::endl; 
    }
}

// Getter de registros
const std::vector<RegistroTreino>& Historico::getRegistros() const {
    static std::vector<RegistroTreino> vazio; // Placeholder para compilar

    for(const auto& registro : registros){
        vazio.push_back(registro);
    }

    return vazio;
}

// Carregar histórico do arquivo
void Historico::carregarDeArquivo() {
    // Implementar
}

// Salvar histórico no arquivo
void Historico::salvarEmArquivo() const {
    // Implementar
}
