namespace Imog3n {
    bgfx::ProgramHandle LoadProgram(const char* vertexShaderName, const char* fragmentShaderName)
    {
        auto& caps = *bgfx::getCaps();
        bgfx::ShaderHandle vsh = createEmbeddedShader(embeddedNodeShaders, caps.rendererType, vertexShaderName);
        bgfx::ShaderHandle fsh = createEmbeddedShader(embeddedNodeShaders, caps.rendererType, fragmentShaderName);

        BX_ASSERT(isValid(vsh) && isValid(fsh), "Failed to create Embedded Node shaders");

        return createProgram(vsh, fsh, true);
    }
}