#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // std::setw�̂���
#include <cassert>

#include <conio.h>
#include <memory>

#include "json.hpp"

using Json = nlohmann::json;

void End();

int main()
{
    // �t�@�C���l�[��
    std::string jsonFileName = "data.json";
    // Json�N���X�̃C���X�^���X
    Json j;

    // �ǂݍ��ݐ�p�t�@�C�����J��
    std::ifstream jsonInFile(jsonFileName);
    // �J������t�@�C�����J�������𑝂₷
    if (jsonInFile) {
        std::cout << "�t�@�C�����J���܂����B" << std::endl;

        // Json�N���X�ɓǂݍ���
        jsonInFile >> j;
        // �t�@�C�������
        jsonInFile.close();
   
        // �ύX�O��Json�I�u�W�F�N�g���o��
        std::cout << j << std::endl << std::endl;
    
        size_t openCount = 0;
        // Json�I�u�W�F�N�g����l�����o��
        openCount = j["OpenCount"];
        // �t�@�C�����J�������𑝂₷
        openCount++;
        // Json�I�u�W�F�N�g����l���㏑��
        j["OpenCount"] = openCount;
   
    }
    else {
        std::cout << "�t�@�C�����J���܂���ł����B" << std::endl;
        std::cout << "�V�����t�@�C���𐶐����܂�" << std::endl;

        // �J���Ȃ�������V��������
        j = {
            { "OpenCount", 0 },
            { "pi", 3.141592 },
            { "happy", true },
            { "name", "Niels" },
            { "nothing", nullptr },
            { "answer", {
                { "everything",42 }
                        }
            },
            { "list", { 1, 0, 2 } },
            { "object", {
                { "currency", "USD" },
                { "value", 42.99 }
                        }
            }
        };
    }


    // Json�I�u�W�F�N�g���o��
    std::cout << j << std::endl;

    // �������ݐ�p�t�@�C�����J��
    std::ofstream jsonOutFile(jsonFileName);
    // Json�N���X�ɏ�������(setw�ŃC���f���g�������w��)
    jsonOutFile << std::setw(4) << j << std::endl;
    // �t�@�C�������
    jsonOutFile.close();

    End();
    return 0;
}

void End() {
    constexpr int ESC = 27;
    printf("\n\n\nESC�ŏI��\n");
    while (!_kbhit() && _getch() != ESC);
}