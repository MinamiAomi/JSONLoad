#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // std::setwのため
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
    //// ファイルネーム
    //std::string jsonFileName = "data.json";
    //// Jsonクラスのインスタンス
    //Json j1;

    //// 読み込み専用ファイルを開く
    //std::ifstream jsonInFile(jsonFileName);
    //// 開けたらファイルを開いた数を増やす
    //if (jsonInFile) {
    //    std::cout << "ファイルを開けました。" << std::endl;

    //    // Jsonクラスに読み込み
    //    jsonInFile >> j1;
    //    // ファイルを閉じる
    //    jsonInFile.close();
   
    //    // 変更前のJsonオブジェクトを出力
    //    std::cout << j1 << std::endl << std::endl;
    //
    //    // Jsonオブジェクトから値を取り出し
    //    size_t openCount = j1["OpenCount"];
    //    // ファイルを開いた数を増やす
    //    openCount++;
    //    // Jsonオブジェクトの値を上書き
    //    j["OpenCount"] = openCount;
   
    //}
    
       /* std::cout << "ファイルを開けませんでした。" << std::endl;
        std::cout << "新しくファイルを生成します" << std::endl;*/

        // 開けなかったら新しく生成
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


    //// Jsonオブジェクトを出力
    //std::string jstr = j.dump();
    //std::cout << jstr << std::endl;


    //std::cout << std::endl << std::endl << j["stage"].dump() << std::endl;

    //// 書き込み専用ファイルを開く
    //std::ofstream jsonOutFile(jsonFileName);
    //// Jsonクラスに書き込み(setwでインデント数幅を指定)
    //jsonOutFile << std::setw(4) << j << std::endl;
    //// ファイルを閉じる
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



    // Jsonオブジェクトを出力
    std::string jstr = j.dump();


    for (const auto& it : j.at("stage").at(0).at("blocks")) {
        for (const auto& it2 : it) {
            std::cout << it2.dump() << std::endl;
        }
    }

    Block tb = { 100,222,2,2,2 };

    j.at("stage").at(0).at("blocks").push_back(tb);

    // 書き込み専用ファイルを開く
    std::ofstream jsonOutFile(jsonFileName);
    // Jsonクラスに書き込み(setwでインデント数幅を指定)
    jsonOutFile << std::setw(4) << j << std::endl;
    // ファイルを閉じる
    jsonOutFile.close();


    End();
    return 0;
}

void End() {
    constexpr int ESC = 27;
    printf("\n\n\nESCで終了\n");
    while (!_kbhit() && _getch() != ESC);
}