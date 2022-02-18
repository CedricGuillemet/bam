#pragma once

#include <bgfx/bgfx.h>

namespace App {
    bgfx::ProgramHandle LoadProgram(const char* vertexShaderName, const char* fragmentShaderName);
}
