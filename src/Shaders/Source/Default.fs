$input v_normal

#include "bgfx_shader.sh"
#include "CommonFS.shader"
#include "Common.shader"

void main()
{
	float halfNormal = dot(normalize(v_normal.xyz), normalize(vec3(0.7, 0.4, 0.3))) * 0.5 + 0.5;
    float light = halfNormal * halfNormal;
    gl_FragColor = vec4(0.9, 0.6, 0.4, 1.0) * light;
}
