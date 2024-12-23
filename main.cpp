#include <Novice.h>
#include <unordered_map>
#include <functional>

const char kWindowTitle[] = "LE2B_21_ミヤザキ_ヤマト";

class Command {
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
};

class Player {
private:
    int x;
    int y;
public:
    Player() : x(100), y(100) {}

    void MoveLeft() {
        x -= 10;
    }

    void MoveRight() {
        x += 10;
    }

    void Draw() {
        Novice::DrawBox(x, y, 30, 30, 0.0f, WHITE, kFillModeSolid);
    }
};

class MoveLeftCommand : public Command {
private:
    Player& player;
public:
    explicit MoveLeftCommand(Player& p) : player(p) {}
    void Execute() override {
        player.MoveLeft();
    }
};

class MoveRightCommand : public Command {
private:
    Player& player;
public:
    explicit MoveRightCommand(Player& p) : player(p) {}
    void Execute() override {
        player.MoveRight();
    }
};

class InputHandler {
private:
    std::unordered_map<int, Command*> commandMap;
public:
    void BindCommand(int key, Command* command) {
        commandMap[key] = command;
    }

    void HandleInput(int key) {
        if (commandMap.find(key) != commandMap.end()) {
            commandMap[key]->Execute();
        }
    }
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    Player player;
    InputHandler inputHandler;

    // Create commands
    MoveLeftCommand moveLeft(player);
    MoveRightCommand moveRight(player);
    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        ///
        /// ↓更新処理ここから
        ///
         // Bind keys to commands
        inputHandler.BindCommand(DIK_A, &moveLeft);
        inputHandler.BindCommand(DIK_D, &moveRight);

        if (keys[DIK_A]) {
            inputHandler.HandleInput(DIK_A);
        }
        if (keys[DIK_D]) {
            inputHandler.HandleInput(DIK_D);
        }
        ///
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///
        player.Draw();
        ///
        /// ↑描画処理ここまで
        ///

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}