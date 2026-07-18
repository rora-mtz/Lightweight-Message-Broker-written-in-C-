#pragma once

// 共通ログ機能（インターフェース）
// 軽量なログ出力を提供する

#include <string>

namespace core {

    // ログ出力関数
    void log(const std::string& msg);

}