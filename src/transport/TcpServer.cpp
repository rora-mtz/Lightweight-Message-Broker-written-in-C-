/**
 * @file TcpServer.cpp
 * @brief TCPサーバ（接続受付）の実装
 *
 * @details
 * 本モジュールはTCPサーバとしてクライアント接続を受け付ける機能を提供する。
 *
 * 設計方針:
 * - 通信処理はtransport層に集約する
 * - 最小構成として同期処理で実装する
 * - 将来的にセッション管理へ拡張する前提
 */

#include "TcpServer.h"
#include "../core/log.h"
#include <winsock2.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

namespace transport
{

    /**
     * @brief TCPサーバを起動し接続を待ち受ける
     *
     * @param port 待ち受けポート番号
     *
     * @details
     * 指定ポートでソケットをバインドし、
     * クライアントからの接続をacceptで待ち受ける。
     */
    void startServer(int port) 
    {

        WSADATA wsaData;

        // Winsock初期化
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) 
        {
            core::logError("WSAStartup failed");
            return;
        }

        // ソケット作成
        SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (serverSocket == INVALID_SOCKET) 
        {
            core::logError("Socket creation failed");
            WSACleanup();
            return;
        }

        sockaddr_in serverAddr{};
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        serverAddr.sin_addr.s_addr = INADDR_ANY;

        // bind
        if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) 
        {
            core::logError("Bind failed");
            closesocket(serverSocket);
            WSACleanup();
            return;
        }

        // listen
        if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) 
        {
            core::logError("Listen failed");
            closesocket(serverSocket);
            WSACleanup();
            return;
        }

        core::logDebug("Server listening on port " + std::to_string(port));

        // accept（1接続）
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) 
        {
            core::logError("Accept failed");
        }
        else 
        {
            core::logInfo("Client connected");
            closesocket(clientSocket);
        }

        closesocket(serverSocket);
        WSACleanup();
    }

}