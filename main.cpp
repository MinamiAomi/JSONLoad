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

struct Block {
    int px = 100;
    int py = 100;
    int ro = 2;
    int wi = 5;
    int he = 2;
};

void to_json(Json& j, const Block& b) {
    j = Json{ b.px,b.py,b.ro,b.wi,b.he };
}


struct Camera {
    int px = 0;
    int py = 0;
};

void to_json(Json& j, const Camera& c) {
    j = Json{ {"px",c.px},{"py",c.py} };
}

struct Stage {
    std::vector<Block> blocks;
    Camera camera;
};

void to_json(Json& j, const Stage& s) {
    j = Json{ {"blocks",s.blocks},{"camera",s.camera} };
}

int main()
{
    //// �t�@�C���l�[��
    //std::string jsonFileName = "data.json";
    //// Json�N���X�̃C���X�^���X
    //Json j1;

    //// �ǂݍ��ݐ�p�t�@�C�����J��
    //std::ifstream jsonInFile(jsonFileName);
    //// �J������t�@�C�����J�������𑝂₷
    //if (jsonInFile) {
    //    std::cout << "�t�@�C�����J���܂����B" << std::endl;

    //    // Json�N���X�ɓǂݍ���
    //    jsonInFile >> j1;
    //    // �t�@�C�������
    //    jsonInFile.close();
   
    //    // �ύX�O��Json�I�u�W�F�N�g���o��
    //    std::cout << j1 << std::endl << std::endl;
    //
    //    // Json�I�u�W�F�N�g����l�����o��
    //    size_t openCount = j1["OpenCount"];
    //    // �t�@�C�����J�������𑝂₷
    //    openCount++;
    //    // Json�I�u�W�F�N�g�̒l���㏑��
    //    j["OpenCount"] = openCount;
   
    //}
    
       /* std::cout << "�t�@�C�����J���܂���ł����B" << std::endl;
        std::cout << "�V�����t�@�C���𐶐����܂�" << std::endl;*/

        // �J���Ȃ�������V��������
    //Json j = {
    //        { "OpenCount", 0 },
    //        { "pi", 3.141592 },
    //        { "happy", true },
    //        { "name", "Niels" },
    //        { "nothing", nullptr },
    //        { "answer", {
    //            { "everything",42 }
    //                    }
    //        },
    //        { "list", { 1, 0, 2 } },
    //        { "object", {
    //            { "currency", "USD" },
    //            { "value", 42.99 }
    //                    }
    //        },
    //    };
    //


    //// Json�I�u�W�F�N�g���o��
    //std::string jstr = j.dump();
    //std::cout << jstr << std::endl;


    //std::cout << std::endl << std::endl << j["stage"].dump() << std::endl;

    //// �������ݐ�p�t�@�C�����J��
    //std::ofstream jsonOutFile(jsonFileName);
    //// Json�N���X�ɏ�������(setw�ŃC���f���g�������w��)
    //jsonOutFile << std::setw(4) << j << std::endl;
    //// �t�@�C�������
    //jsonOutFile.close();

    std::vector<Stage> stages = {};

    stages.emplace_back();
    stages[0].blocks.emplace_back();
    stages[0].blocks.emplace_back();

    stages.emplace_back();
    stages[1].blocks.emplace_back();

    std::string jsonFileName = "stageData.json";

    Json j = {
        {"stage", stages}
    };



    // Json�I�u�W�F�N�g���o��
    std::string jstr = j.dump();


    for (const auto& it : j.at("stage").at(0).at("blocks")) {
        for (const auto& it2 : it) {
            std::cout << it2.dump() << std::endl;
        }
    }

    Block tb = { 100,222,2,2,2 };

    j.at("stage").at(0).at("blocks").push_back(tb);

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