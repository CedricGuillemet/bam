$input a_position, a_normal
$output v_normal

#include "bgfx_shader.sh"
#include "Common.shader"

void main()
{
    mat4 mvp = mul(u_viewProjection, u_world);
	gl_Position = mul(mvp, vec4(a_position, 1.0) );
	v_normal = mul(u_world, vec4(a_normal, 0.0)).xyz;
}
