#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <windows.h>
#include <string>

class Screen {
private:
    HANDLE m_hScreen[2];     // 두 개의 화면 버퍼 핸들
    int m_nScreenIndex;      // 현재 사용 중인 버퍼 인덱스
    int m_width;             // 화면 가로 너비
    int m_height;            // 화면 세로 높이

public:
    // 생성자 및 소멸자
    Screen(int width = 160, int height = 50);
    ~Screen();

    // 주요 기능 함수
    void flipping();                                   // 버퍼 교체 및 출력
    void clear();                                      // 버퍼 지우기
    void print(int x, int y, const std::string& str);  // 문자열 출력
};

#endif
