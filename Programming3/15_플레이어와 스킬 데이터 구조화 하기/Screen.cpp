#include "Screen.h"

Screen::Screen(int width, int height)
    : m_nScreenIndex(0), m_width(width), m_height(height) {

    CONSOLE_CURSOR_INFO cci;

    // 1. 화면 버퍼 2개 생성
    m_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    m_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // 2. 커서 숨기기 (렌더링 시 깜빡임 방지)
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(m_hScreen[0], &cci);
    SetConsoleCursorInfo(m_hScreen[1], &cci);
}

Screen::~Screen() {
    // 할당된 핸들 리소스 해제
    CloseHandle(m_hScreen[0]);
    CloseHandle(m_hScreen[1]);
}

void Screen::flipping() {
    // 현재 인덱스의 버퍼를 화면에 활성화
    SetConsoleActiveScreenBuffer(m_hScreen[m_nScreenIndex]);
    // 다음 프레임을 그릴 버퍼 인덱스로 전환 (0->1, 1->0)
    m_nScreenIndex = !m_nScreenIndex;
}

void Screen::clear() {
    COORD coor = { 0, 0 };
    DWORD dw;
    // 현재 그리고 있는 버퍼를 공백(' ')으로 채움
    FillConsoleOutputCharacter(m_hScreen[m_nScreenIndex], ' ', m_width * m_height, coor, &dw);
}

void Screen::print(int x, int y, const std::string& str) {
    DWORD dw;
    COORD cursorPosition = { static_cast<SHORT>(x), static_cast<SHORT>(y) };

    // 출력할 위치로 커서 이동
    SetConsoleCursorPosition(m_hScreen[m_nScreenIndex], cursorPosition);

    // 데이터 쓰기
    WriteFile(m_hScreen[m_nScreenIndex], str.c_str(), static_cast<DWORD>(str.length()), &dw, NULL);
}