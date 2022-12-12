#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // std::setw�̂���
#include <cassert>

#include "json.hpp"

using Json = nlohmann::json;

int main()
{
    // �t�@�C���l�[��
    std::string jsonFileName = "data2.json";
    // Json�N���X�̃C���X�^���X
    Json j;

    // �ǂݍ��ݐ�p�t�@�C�����J��
    std::ifstream jsonInFile(jsonFileName);
    // �J���Ȃ�������G���[
    assert(jsonInFile);
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

    // �ύX���Json�I�u�W�F�N�g���o��
    std::cout << j << std::endl;


    // �������ݐ�p�t�@�C�����J��
    std::ofstream jsonOutFile(jsonFileName);
    // Json�N���X�ɏ�������(setw�ŃC���f���g�������w��)
    jsonOutFile << std::setw(4) << j << std::endl;
    // �t�@�C�������
    jsonOutFile.close();


    return 0;
}