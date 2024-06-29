#pragma once

class Display {
public:
    static Display& getInstance();

    Display(Display const&) = delete;
    void operator=(Display const&) = delete;

private:
    Display();
    ~Display();

    static Display instance;
};