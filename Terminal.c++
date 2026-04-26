#include <cstdio>
#include <string>
#include <map>
#include <functional>
#include <iostream>
#include <windows.h>

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

    // 🔥 HELP
    comandos["help"] = []() {
        printf("\nComandos disponiveis:\n");
        printf("help    - mostrar comandos\n");
        printf("info    - informacoes\n");
        printf("ver - versao do sistema\n");
        printf("clear   - limpar tela\n");
        printf("calc    - calculadora\n");
        printf("user    - criar/alterar usuario\n");
        printf("exit    - sair\n");
    };

    // 🔥 USER
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
  
    comandos["ver"] =[]{
 printf("Terminal-simulado v1.0");
    };


    // 🔥 VERSION
comandos["info"] = []() {
    const std::string cor_amarela = "\033[1;33m";
    const std::string reset_cor = "\033[0m";

    std::cout << cor_amarela;

    std::cout <<
"\nTerminal-simulado v1.0\n"
"----------------------------------------\n"
"Kernel:Terminal-simulado (simulado)\n"
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
    //  CLEAR
    comandos["clear"] = []() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printDD();
    };

    //  CALCULADORA
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

    // 🔁 LOOP
    while (true)
    {
        std::cout << "\n" << user << "@kernel> ";
        std::getline(std::cin, comando);

        if (comando == "exit")
            break;

        if (comandos.find(comando) != comandos.end())
        {
            comandos[comando]();
        }
        else
        {
            printf("Comando desconhecido\n");
        }
    }

    return 0;
}