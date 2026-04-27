#include <cstdio>
#include <string>
#include <map>
#include <functional>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

void printDD()
{
    const std::string cor_vermelha = "\033[1;31m";
    const std::string reset_cor = "\033[0m";
    std::cout << cor_vermelha;

    printf("\n            ____________________________________________");
    printf("\n            |                                          |");
    printf("\n            |                 HELLO                    |");
    printf("\n            |                                          |");
    printf("\n            |  SEJA BEM-VINDO AO Terminal-simulado     |");
    printf("\n            |                                          |");
    printf("\n            |   OBS: ESTE NAO E UM SISTEMA REAL        |");
    printf("\n            |                SE DIVIRTA!               |");
    printf("\n            |        Para iniciar digite: help         |");
    printf("\n            |__________________________________________|\n\n");

    std::cout << reset_cor;
}

void lodboot()
{
    printf("Booting Terminal-simulado...\n");
    Sleep(800);
    printf("[ OK ] Loading lib\n");
    Sleep(800);
    printf("[ OK ] Loading terminal\n");
    Sleep(600);
    printf("[ OK ] Starting services\n");
    Sleep(600);
    printf("[ OK ] Mounting filesystem\n");
    Sleep(600);
    printf("[ OK ] System ready\n\n");
}

int main()
{
    std::string comando;
    std::string user;

    lodboot();
    printDD();

    std::cout << "User name: ";
    std::getline(std::cin, user);
    std::cout << "Hello, " << user << "\n";

    std::map<std::string, std::function<void()>> comandos;

    comandos["help"] = []() {
        printf("\nComandos disponiveis:\n");
        printf("help    - mostrar comandos\n");
        printf("note    - cria uma anotacao\n");
        printf("notes   -  ver notas criadas\n");
        printf("edit    -  edita notas criadas \n");
        printf("info    - informacoes\n");
        printf("ver     - versao do sistema\n");
        printf("clear   - limpar tela\n");
        printf("calc    - calculadora\n");
        printf("user    - criar/alterar usuario\n");
        printf("exit    - sair\n");
    };

    comandos["user"] = [&user]() {
        std::string novoUser;

        std::cout << "Digite o nome do novo usuario: ";
        std::getline(std::cin, novoUser);

        if (!novoUser.empty()) {
            user = novoUser;
            std::cout << "Usuario alterado com sucesso!\n";
        } else {
            std::cout << "Nome invalido!\n";
        }
    };

    comandos["ver"] = []() {
        printf("Terminal-simulado v1.0\n");
    };

    comandos["info"] = []() {
        const std::string cor_amarela = "\033[1;33m";
        const std::string reset_cor = "\033[0m";

        std::cout << cor_amarela;

        std::cout <<
"\nTerminal-simulado v1.0\n"
"----------------------------------------\n"
"Kernel: Terminal-simulado (simulado)\n"
"Arquitetura: x86_64\n"
"Build: 2026.01\n"
"Shell: terminal-simulado\n"
"Desenvolvedor: devfrances\n"
"----------------------------------------\n\n";

        std::cout <<
"  |\\---/|  \n"
"  | o_o |  \n"
"   \\_^_/  \n";

        std::cout << reset_cor;
    };

    // ✔ NOTE CORRIGIDO
    comandos["note"] = []() {
        std::string texto;

        std::cout << "Digite sua nota: ";
        std::getline(std::cin, texto);

        if (texto.empty()) {
            std::cout << "Nota vazia!\n";
            return;
        }

        std::string cmd = "python ../../py/nota.py \"" + texto + "\"";
        system(cmd.c_str());

        std::cout << " Nota enviada ao sistema!\n";
    };

    comandos["clear"] = []() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printDD();
    };

    comandos["calc"] = []() {
        double a, b;
        char op;

        std::cout << "Ex: 5 + 5\n";
        std::cout << "Conta: ";
        std::cin >> a >> op >> b;
        std::cin.ignore();

        switch(op) {
            case '+': std::cout << "Resultado: " << a + b << "\n"; break;
            case '-': std::cout << "Resultado: " << a - b << "\n"; break;
            case '*': std::cout << "Resultado: " << a * b << "\n"; break;
            case '/':
                if (b != 0)
                    std::cout << "Resultado: " << a / b << "\n";
                else
                    std::cout << "Erro: divisao por zero\n";
                break;
            default:
                std::cout << "Operador invalido\n";
        }
    };

comandos["notes"] = []() {
    std::ifstream file("../../data/notas/notas.txt");

    if (!file.is_open()) {
        std::cout << "Nenhuma nota encontrada!\n";
        return;
    }

    std::string linha;
    int i = 1;

    std::cout << "\n===== SUAS NOTAS =====\n";

    while (std::getline(file, linha)) {
        std::cout << i << " - " << linha << "\n";
        i++;
    }

    std::cout << "======================\n";
};
comandos["edit"] = []() {
    std::ifstream file("../../data/notas/notas.txt");

    if (!file.is_open()) {
        std::cout << "Nenhuma nota para editar!\n";
        return;
    }

    std::vector<std::string> notas;
    std::string linha;

    while (std::getline(file, linha)) {
        notas.push_back(linha);
    }
    file.close();

    if (notas.empty()) {
        std::cout << "Nenhuma nota disponivel!\n";
        return;
    }

    // listar notas
    for (size_t i = 0; i < notas.size(); i++) {
        std::cout << i + 1 << " - " << notas[i] << "\n";
    }

    int id;
    std::cout << "Qual nota deseja editar? ";
    std::cin >> id;
    std::cin.ignore();

    if (id < 1 || static_cast<size_t>(id) > notas.size()) {
        std::cout << "Indice invalido!\n";
        return;
    }

    std::string novoTexto;
    std::cout << "Novo texto: ";
    std::getline(std::cin, novoTexto);

    notas[id - 1] = novoTexto;

    std::ofstream out("../../data/notas/notas.txt");

    for (const auto &n : notas) {
        out << n << "\n";
    }

    std::cout << "Nota editada com sucesso!\n";
};


    while (true)
    {
        std::cout << "\n" << user << "@kernel> ";
        std::getline(std::cin, comando);

        if (comando == "exit")
            break;

        if (comandos.find(comando) != comandos.end())
            comandos[comando]();
        else
            printf("Comando desconhecido\n");
    }

    return 0;
}