/**
 * @file log.cpp
 * @brief 共通ログ機能の実装
 *
 * @details
 * 本モジュールはアプリケーション全体で使用するログ出力機能を提供する。
 *
 * 設計方針:
 * - ログは共通機能としてcore層に配置する
 * - アプリケーション層との依存は一方向（app → core）
 * - 現段階では最小構成を優先しシンプルな関数として実装
 *
 * 拡張方針:
 * - ログレベル（INFO / ERROR）
 * - 出力先の変更（ファイル / ネットワーク）
 * - 非同期ログ対応
 */

#include "log.h"
#include <iostream>

namespace core {

    /**
     * @brief ログレベル文字列取得用関数
     *
     * @param level ログレベル
     *
     * @details
     * 受け取ったログレベルに応じた文字列を返す。
     *
     */
    std::string levelToString(LogLevel level) {

        switch (level) {
        case LogLevel::Debug:
            return "DEBUG";
        case LogLevel::Info:
            return "INFO";
        case LogLevel::Warn:
            return "WARN";
        case LogLevel::Error: 
            return "ERROR";
        default: 
            return "UNKNOWN";
        }
    }

    /**
     * @brief ログメッセージを出力する
     *
     * @param level ログレベル
     * @param msg   出力するメッセージ
     *
     * @details
     * 取得したログレベルに応じてログを出力する。
     *
     * なぜこの設計か:
     * - ログ機能は全体で利用されるためcore層に配置
     * - 初期段階では過剰設計を避け関数として実装
     * - 将来的にはクラス化や非同期化に拡張可能
     *
     * 制約:
     * - スレッドセーフではない
     * - 出力先は固定（std::cout）
     */
    void log(LogLevel level, const std::string& msg) {
        std::cout << "[" << levelToString(level) << "] " << msg << std::endl;
    }

    /**
     * @brief ログメッセージ出力ラッパー関数
     *
     * @param msg   出力するメッセージ
     *
     * @details
     * ログを出力する関数のラッパー関数。
     * 
     */
    void logDebug(const std::string & msg) {
        log(LogLevel::Debug, msg);
    }

    void logInfo(const std::string & msg) {
        log(LogLevel::Info, msg);
    }

    void logWarn(const std::string & msg) {
        log(LogLevel::Warn, msg);
    }

    void logError(const std::string & msg) {
        log(LogLevel::Error, msg);
    }

}