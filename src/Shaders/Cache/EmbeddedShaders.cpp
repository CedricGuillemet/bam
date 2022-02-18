#include "EmbeddedShaders.h"
#include "bgfx_utils.h"
static const bgfx::EmbeddedShader embeddedShaders[] =
{
BGFX_EMBEDDED_SHADER(Default_vs),
BGFX_EMBEDDED_SHADER(Default_fs),
BGFX_EMBEDDED_SHADER_END()
};
#include "ShaderHelper.h"
