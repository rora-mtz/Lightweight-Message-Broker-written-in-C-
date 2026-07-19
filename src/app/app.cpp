/**
 * @file app.cpp
 * @brief アプリケーションエントリポイント
 */

#include "../transport/TcpServer.h"

int main() {

		// TCPサーバ起動
		transport::startServer(8080);
		
		return 0;
}