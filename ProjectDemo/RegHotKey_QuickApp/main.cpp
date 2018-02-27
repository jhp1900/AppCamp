#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <windows.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    HWND hConsole = GetActiveWindow();

    MSG msg = {0};
    RegisterHotKey(hConsole,1,MOD_CONTROL | MOD_SHIFT,'D');

    while (GetMessage(&msg, NULL, 0, 0) != 0){
        if (msg.message == WM_HOTKEY){
            if(msg.wParam == 1)
                OutputDebugString(L"jfkdsjkfdas\n");
        }
    }

    return app.exec();
}
