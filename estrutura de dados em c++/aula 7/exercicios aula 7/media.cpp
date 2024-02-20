#include <iostream>

struct Student {
    int registrationNumber;
    float average;
};

int main() {
    Student* students = nullptr;
    int numberOfStudents = 0;

    while (true) {
        std::cout << "\nEscolha uma operacao:\n";
        std::cout << "1. Inserir media de um estudante\n";
        std::cout << "2. Consultar media de um estudante\n";
        std::cout << "3. Alterar media de um estudante\n";
        std::cout << "4. Remover media de um estudante\n";
        std::cout << "5. Encerrar o programa\n";

        int choice;
        std::cout << "Escolha: ";
        std::cin >> choice;

        if (choice == 1) {
            int registration;
            float average;
            std::cout << "Digite o numero de matricula: ";
            std::cin >> registration;

            // Verifica se a matrícula já está cadastrada
            bool found = false;
            for (int i = 0; i < numberOfStudents; ++i) {
                if (students[i].registrationNumber == registration) {
                    std::cout << "Matricula ja cadastrada. Insercao falhou.\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                Student* temp = new Student[numberOfStudents *2];
                for (int i = 0; i < numberOfStudents; ++i) {
                    temp[i] = students[i];
                }
                temp[numberOfStudents].registrationNumber = registration;
                std::cout << "Digite a media: ";
                std::cin >> average;
                temp[numberOfStudents].average = average;

                delete[] students;
                students = temp;
                numberOfStudents++;
                std::cout << "Media inserida com sucesso!\n";
            }
        } else if (choice == 2) {
            int registration;
            std::cout << "Digite o numero de matricula: ";
            std::cin >> registration;

            bool found = false;
            for (int i = 0; i < numberOfStudents; ++i) {
                if (students[i].registrationNumber == registration) {
                    std::cout << "Media do estudante: " << students[i].average << "\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "Matricula nao encontrada. Consulta falhou.\n";
            }
        } else if (choice == 3) {
            int registration;
            float newAverage;
            std::cout << "Digite o numero de matricula: ";
            std::cin >> registration;

            bool found = false;
            for (int i = 0; i < numberOfStudents; ++i) {
                if (students[i].registrationNumber == registration) {
                    std::cout << "Digite a nova media: ";
                    std::cin >> newAverage;
                    students[i].average = newAverage;
                    std::cout << "Media alterada com sucesso!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "Matricula nao encontrada. Alteracao falhou.\n";
            }
        } else if (choice == 4) {
            int registration;
            std::cout << "Digite o numero de matricula a ser removida: ";
            std::cin >> registration;

            int indexToRemove = -1;
            for (int i = 0; i < numberOfStudents; ++i) {
                if (students[i].registrationNumber == registration) {
                    indexToRemove = i;
                    break;
                }
            }

            if (indexToRemove != -1) {
                Student* temp = new Student[numberOfStudents - 1];
                for (int i = 0, j = 0; i < numberOfStudents; ++i) {
                    if (i != indexToRemove) {
                        temp[j] = students[i];
                        j++;
                    }
                }

                delete[] students;
                students = temp;
                numberOfStudents--;
                std::cout << "Media removida com sucesso!\n";
            } else {
                std::cout << "Matricula nao encontrada. Remocao falhou.\n";
            }
        } else if (choice == 5) {
            // Encerrar o programa
            break;
        } else {
            std::cout << "Escolha invalida. Tente novamente.\n";
        }
    }

    // Liberar a memória alocada
    delete[] students;

    return 0;
}
