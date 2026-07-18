# Light Message Broker Roadmap

## プロジェクト概要

Light Message BrokerはC++20で開発する軽量メッセージブローカー（Light Message Broker）です。

TCPチャットサーバーから開発を開始し、段階的にPub/Sub、永続化、Consumer Group、IOCP対応を追加することで、KafkaやRabbitMQの設計思想を学習できるプロジェクトとして成長させます。

本プロジェクトの目的は単なる動作するソフトウェアの作成ではなく、以下のスキルを体系的に学習・実践することです。

- C++20
- ネットワークプログラミング
- 並行処理
- OS理解
- ソフトウェア設計
- パフォーマンスチューニング
- GitHubを利用した開発プロセス運用

---

# プロジェクト目標

最終的に以下の機能を持つLight Message Brokerを実装する。

- TCP Server
- Pub/Sub
- Topic
- Queue
- Thread Pool
- Binary Protocol
- Persistence
- ACK
- Consumer Group
- IOCP
- Metrics
- Benchmark

---

# 技術スタック

## Language

- C++20

## IDE

- Visual Studio 2022

## Build System

- Visual Studio Solution (.sln)
- MSBuild

## Testing

- GoogleTest

## CI/CD

- GitHub Actions

## Platform

- Windows 11
- Winsock2
- IOCP

## Version Control

- Git
- GitHub
- GitHub Projects

---

# 開発フェーズ

---

# Phase 1 : TCP Chat Server

## 目的

TCP通信の基礎を学ぶ。

## 機能

- [ ] TCP Listener
- [ ] Accept
- [ ] Client Session
- [ ] Connection Manager
- [ ] Broadcast
- [ ] Chat Client
- [ ] Integration Test

## アーキテクチャ

```text
Client
   │
   ▼
TCP Server
   │
   ▼
Connection Manager
   │
   ▼
Broadcast
```

## 学習内容

- Winsock2
- TCP/IP
- select
- WSAEventSelect
- Thread
- Visual Studio Debugger

## 成果物

chat-server-v1

## リリース

v0.1.0

---

# Phase 2 : Pub/Sub Broker

## 目的

チャットサーバーをLight Message Brokerへ進化させる。

## 機能

- [ ] Topic Manager
- [ ] Subscriber
- [ ] Publisher
- [ ] Message Routing
- [ ] Subscription Management

## 利用例

```text
SUB sports

PUB sports hello world
```

## アーキテクチャ

```text
Publisher
    │
    ▼
Topic Router
    │
    ▼
Subscriber
```

## 学習内容

- Observer Pattern
- Event Routing
- Message Distribution

## 成果物

broker-v1

## リリース

v0.2.0

---

# Phase 3 : Multi Thread Architecture

## 目的

シングルスレッドの性能限界を改善する。

## 機能

- [ ] Thread Pool
- [ ] Task Queue
- [ ] Worker Threads
- [ ] Job Scheduling

## アーキテクチャ

```text
Network Thread
      │
      ▼
Task Queue
      │
      ▼
Worker Pool
```

## 学習内容

- std::thread
- std::mutex
- std::atomic
- condition_variable
- Concurrent Programming

## 成果物

broker-v2

## リリース

v0.3.0

---

# Phase 4 : Binary Protocol

## 目的

JSONベース通信から独自バイナリプロトコルに移行する。

## 機能

- [ ] Packet Header
- [ ] Version
- [ ] Message Type
- [ ] Payload Length
- [ ] Checksum

## プロトコル構造

```text
+----------+---------+----------+
| Header   | Topic   | Payload  |
+----------+---------+----------+
```

## 学習内容

- Binary Protocol
- Serialization
- Protocol Design

## 成果物

broker-v3

## リリース

v0.4.0

---

# Phase 5 : Persistence

## 目的

メッセージの永続化を実装する。

## 機能

- [ ] Append Only Log
- [ ] Segment File
- [ ] Message Recovery
- [ ] Startup Recovery

## ストレージ構造

```text
topic1/

000001.log
000002.log
000003.log
```

## 学習内容

- File I/O
- WAL
- Storage Design
- Crash Recovery

## 成果物

broker-v4

## リリース

v0.5.0

---

# Phase 6 : Reliability

## 目的

メッセージ消失を防止する。

## 機能

- [ ] ACK
- [ ] Retry
- [ ] Timeout
- [ ] Dead Letter Queue

## アーキテクチャ

```text
Producer
    │
    ▼
Broker
    │
    ▼
Consumer

ACK
```

## 学習内容

- Reliable Messaging
- Timeout Management
- Retry Strategy

## 成果物

broker-v5

## リリース

v0.6.0

---

# Phase 7 : Consumer Group

## 目的

メッセージを複数Consumerへ分散する。

## 機能

- [ ] Consumer Group
- [ ] Partition Assignment
- [ ] Group Join
- [ ] Rebalance

## アーキテクチャ

```text
Group A

Consumer1
Consumer2
Consumer3
```

## 学習内容

- Partition
- Load Balancing
- Distributed Consumption

## 成果物

broker-v6

## リリース

v0.7.0

---

# Phase 8 : IOCP

## 目的

Windowsネイティブの高性能通信へ移行する。

## 機能

- [ ] Overlapped IO
- [ ] Completion Port
- [ ] Async I/O

## アーキテクチャ

```text
IOCP

Accept
Read
Write

Completion Queue
```

## 学習内容

- Windows Internals
- IOCP
- High Performance Networking

## 成果物

broker-v7

## リリース

v0.8.0

---

# Phase 9 : Metrics

## 目的

サービスの状態を可視化する。

## 機能

- [ ] Connection Count
- [ ] Topic Count
- [ ] Queue Size
- [ ] Throughput
- [ ] Latency

## 出力例

```text
Connections : 105
Topics      : 16
Queue Size  : 23
Throughput  : 3400 msg/sec
Latency     : 2.1 ms
```

## 学習内容

- Monitoring
- Benchmark
- Performance Analysis

## 成果物

broker-v8

## リリース

v0.9.0

---

# Phase 10 : リファクタリング & 1.0

## 目的

製品として整理する。

## 機能

- [ ] コード整理
- [ ] API整理
- [ ] ドキュメント整備
- [ ] ベンチマーク整備
- [ ] CI安定化

## 成果物

Light Message Broker 1.0

## リリース

v1.0.0

---

# 非機能要件

## パフォーマンス目標

- 同時接続数 1,000
- 10,000 messages/sec
- メモリリーク 0

## 品質目標

- Unit Test
- Integration Test
- GitHub Actions
- 静的解析

## ドキュメント目標

- Architecture
- ADR
- Protocol Specification
- Storage Design
- Benchmark Report

---

# 将来拡張

## Cluster Mode

- [ ] Broker Discovery
- [ ] Replication
- [ ] Leader Election

## 学習テーマ

- Raft
- Consensus Algorithm
- Distributed Systems

---

# リリース計画

v0.1.0 Chat Server

v0.2.0 Pub/Sub

v0.3.0 Thread Pool

v0.4.0 Binary Protocol

v0.5.0 Persistence

v0.6.0 ACK

v0.7.0 Consumer Group

v0.8.0 IOCP

v0.9.0 Metrics

v1.0.0 Light Message Broker

---

# 成長マップ

```text
Echo Server
      ↓
Chat Server
      ↓
Pub/Sub Broker
      ↓
Thread Pool
      ↓
Binary Protocol
      ↓
Persistence
      ↓
ACK
      ↓
Consumer Group
      ↓
IOCP
      ↓
Metrics
      ↓
Light Message Broker 1.0
```