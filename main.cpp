#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // std::setwのため
#include <cassert>

#include "json.hpp"

using Json = nlohmann::json;

int main()
{
    // ファイルネーム
    std::string jsonFileName = "data2.json";
    // Jsonクラスのインスタンス
    Json j;

    // 読み込み専用ファイルを開く
    std::ifstream jsonInFile(jsonFileName);
    // 開けなかったらエラー
    assert(jsonInFile);
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

    // 変更後のJsonオブジェクトを出力
    std::cout << j << std::endl;


    // 書き込み専用ファイルを開く
    std::ofstream jsonOutFile(jsonFileName);
    // Jsonクラスに書き込み(setwでインデント数幅を指定)
    jsonOutFile << std::setw(4) << j << std::endl;
    // ファイルを閉じる
    jsonOutFile.close();


    return 0;
}