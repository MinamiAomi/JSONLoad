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

int main()
{
    // ファイルネーム
    std::string jsonFileName = "data.json";
    // Jsonクラスのインスタンス
    Json j;

    // 読み込み専用ファイルを開く
    std::ifstream jsonInFile(jsonFileName);
    // 開けたらファイルを開いた数を増やす
    if (jsonInFile) {
        std::cout << "ファイルを開けました。" << std::endl;

        // Jsonクラスに読み込み
        jsonInFile >> j;
        // ファイルを閉じる
        jsonInFile.close();
   
        // 変更前のJsonオブジェクトを出力
        std::cout << j << std::endl << std::endl;
    
        size_t openCount = 0;
        // Jsonオブジェクトから値を取り出し
        openCount = j["OpenCount"];
        // ファイルを開いた数を増やす
        openCount++;
        // Jsonオブジェクトから値を上書き
        j["OpenCount"] = openCount;
   
    }
    else {
        std::cout << "ファイルを開けませんでした。" << std::endl;
        std::cout << "新しくファイルを生成します" << std::endl;

        // 開けなかったら新しく生成
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


    // Jsonオブジェクトを出力
    std::cout << j << std::endl;

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