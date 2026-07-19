#pragma once

// 共通ログ機能（インターフェース）
// 軽量なログ出力を提供する

#include <string>

namespace core {

    // ログレベル
    enum class LogLevel
    {
        Debug,
        Info,
        Warn,
        Error
    };

    // 基本ログ出力関数(内部用)
    void log(LogLevel level, const std::string& msg);

    // ラッパー関数（外部用）
    void logDebug(const std::string & msg);
    void logInfo(const std::string & msg);
    void logWarn(const std::string & msg);
    void logError(const std::string & msg);

}