#include "common.h"
#include "bgfx_utils.h"
#include "imgui/imgui.h"
#include "Shaders.h"

namespace App
{
	
struct PosNormalVertex
{
	float m_x;
	float m_y;
	float m_z;
	uint32_t m_normal;

	static void init()
	{
		ms_layout
			.begin()
			.add(bgfx::Attrib::Position,  3, bgfx::AttribType::Float)
			.add(bgfx::Attrib::Normal,    4, bgfx::AttribType::Uint8, true, true)
			.end();
	}

	static bgfx::VertexLayout ms_layout;
};

bgfx::VertexLayout PosNormalVertex::ms_layout;

static PosNormalVertex s_cubeVertices[24] =
{
	{-1.0f,  1.0f,  1.0f, encodeNormalRgba8( 0.0f,  0.0f,  1.0f) },
	{ 1.0f,  1.0f,  1.0f, encodeNormalRgba8( 0.0f,  0.0f,  1.0f) },
	{-1.0f, -1.0f,  1.0f, encodeNormalRgba8( 0.0f,  0.0f,  1.0f) },
	{ 1.0f, -1.0f,  1.0f, encodeNormalRgba8( 0.0f,  0.0f,  1.0f) },
	{-1.0f,  1.0f, -1.0f, encodeNormalRgba8( 0.0f,  0.0f, -1.0f) },
	{ 1.0f,  1.0f, -1.0f, encodeNormalRgba8( 0.0f,  0.0f, -1.0f) },
	{-1.0f, -1.0f, -1.0f, encodeNormalRgba8( 0.0f,  0.0f, -1.0f) },
	{ 1.0f, -1.0f, -1.0f, encodeNormalRgba8( 0.0f,  0.0f, -1.0f) },
	{-1.0f,  1.0f,  1.0f, encodeNormalRgba8( 0.0f,  1.0f,  0.0f) },
	{ 1.0f,  1.0f,  1.0f, encodeNormalRgba8( 0.0f,  1.0f,  0.0f) },
	{-1.0f,  1.0f, -1.0f, encodeNormalRgba8( 0.0f,  1.0f,  0.0f) },
	{ 1.0f,  1.0f, -1.0f, encodeNormalRgba8( 0.0f,  1.0f,  0.0f) },
	{-1.0f, -1.0f,  1.0f, encodeNormalRgba8( 0.0f, -1.0f,  0.0f) },
	{ 1.0f, -1.0f,  1.0f, encodeNormalRgba8( 0.0f, -1.0f,  0.0f) },
	{-1.0f, -1.0f, -1.0f, encodeNormalRgba8( 0.0f, -1.0f,  0.0f) },
	{ 1.0f, -1.0f, -1.0f, encodeNormalRgba8( 0.0f, -1.0f,  0.0f) },
	{ 1.0f, -1.0f,  1.0f, encodeNormalRgba8( 1.0f,  0.0f,  0.0f) },
	{ 1.0f,  1.0f,  1.0f, encodeNormalRgba8( 1.0f,  0.0f,  0.0f) },
	{ 1.0f, -1.0f, -1.0f, encodeNormalRgba8( 1.0f,  0.0f,  0.0f) },
	{ 1.0f,  1.0f, -1.0f, encodeNormalRgba8( 1.0f,  0.0f,  0.0f) },
	{-1.0f, -1.0f,  1.0f, encodeNormalRgba8(-1.0f,  0.0f,  0.0f) },
	{-1.0f,  1.0f,  1.0f, encodeNormalRgba8(-1.0f,  0.0f,  0.0f) },
	{-1.0f, -1.0f, -1.0f, encodeNormalRgba8(-1.0f,  0.0f,  0.0f) },
	{-1.0f,  1.0f, -1.0f, encodeNormalRgba8(-1.0f,  0.0f,  0.0f) },
};

static const uint16_t s_cubeIndices[36] =
{
	 0,  2,  1,
	 1,  2,  3,
	 4,  5,  6,
	 5,  7,  6,

	 8, 10,  9,
	 9, 10, 11,
	12, 13, 14,
	13, 15, 14,

	16, 18, 17,
	17, 18, 19,
	20, 21, 22,
	21, 23, 22,
};


#ifdef __EMSCRIPTEN__
#include <emscripten.h>
EM_JS(void, HideLoader, (), { document.getElementById("loader").style.display = "none"; });
#else
void HideLoader() {}
#endif


class App : public entry::AppI
{
public:
	App(const char* _name, const char* _description, const char* _url)
		: entry::AppI(_name, _description, _url)
	{
	}

	void init(int32_t _argc, const char* const* _argv, uint32_t _width, uint32_t _height) override
	{
		Args args(_argc, _argv);

		m_width  = _width;
		m_height = _height;
		m_debug  = BGFX_DEBUG_NONE;
		m_reset  = BGFX_RESET_VSYNC;

		bgfx::Init init;
		init.type     = args.m_type;
		init.vendorId = args.m_pciId;
		init.resolution.width  = m_width;
		init.resolution.height = m_height;
		init.resolution.reset  = m_reset;
		bgfx::init(init);

		// Enable debug text.
		bgfx::setDebug(m_debug);

		// Set view 0 clear state.
		bgfx::setViewClear(0
			, BGFX_CLEAR_COLOR|BGFX_CLEAR_DEPTH
			, 0
			, 1.0f
			, 0
			);

		m_timeOffset = bx::getHPCounter();

		imguiCreate();
        
		// Create vertex stream declaration.
		PosNormalVertex::init();

        // Create static vertex buffer.
		m_vbh = bgfx::createVertexBuffer(
					  bgfx::makeRef(s_cubeVertices, sizeof(s_cubeVertices) )
					, PosNormalVertex::ms_layout
					);

        bx::mtxIdentity(m_world);
        
		// Create static index buffer.
		m_ibh = bgfx::createIndexBuffer(bgfx::makeRef(s_cubeIndices, sizeof(s_cubeIndices) ) );

        m_worldUniform = bgfx::createUniform("u_world", bgfx::UniformType::Mat4);
        m_viewProjectionUniform = bgfx::createUniform("u_viewProjection", bgfx::UniformType::Mat4);

		// Create program from shaders.
		m_program = LoadProgram("Default_vs", "Default_fs");

		HideLoader();
	}

	virtual int shutdown() override
	{
		imguiDestroy();

		// Shutdown bgfx.
		bgfx::shutdown();

		return 0;
	}

    void editTransform(const float* view, const float* projection, float* world)
    {
        static ImGuizmo::OPERATION mCurrentGizmoOperation(ImGuizmo::TRANSLATE);
        static ImGuizmo::MODE mCurrentGizmoMode(ImGuizmo::WORLD);
        if (ImGui::IsKeyPressed(90))
           mCurrentGizmoOperation = ImGuizmo::TRANSLATE;
        if (ImGui::IsKeyPressed(69))
           mCurrentGizmoOperation = ImGuizmo::ROTATE;
        if (ImGui::IsKeyPressed(82)) // r Key
           mCurrentGizmoOperation = ImGuizmo::SCALE;
        if (ImGui::RadioButton("Translate", mCurrentGizmoOperation == ImGuizmo::TRANSLATE))
          mCurrentGizmoOperation = ImGuizmo::TRANSLATE;
        ImGui::SameLine();
        if (ImGui::RadioButton("Rotate", mCurrentGizmoOperation == ImGuizmo::ROTATE))
           mCurrentGizmoOperation = ImGuizmo::ROTATE;
        ImGui::SameLine();
        if (ImGui::RadioButton("Scale", mCurrentGizmoOperation == ImGuizmo::SCALE))
          mCurrentGizmoOperation = ImGuizmo::SCALE;
        float matrixTranslation[3], matrixRotation[3], matrixScale[3];
        ImGuizmo::DecomposeMatrixToComponents(world, matrixTranslation, matrixRotation, matrixScale);
        ImGui::InputFloat3("Tr", matrixTranslation);
        ImGui::InputFloat3("Rt", matrixRotation);
        ImGui::InputFloat3("Sc", matrixScale);
        ImGuizmo::RecomposeMatrixFromComponents(matrixTranslation, matrixRotation, matrixScale, world);

        if (mCurrentGizmoOperation != ImGuizmo::SCALE)
        {
          if (ImGui::RadioButton("Local", mCurrentGizmoMode == ImGuizmo::LOCAL))
             mCurrentGizmoMode = ImGuizmo::LOCAL;
          ImGui::SameLine();
          if (ImGui::RadioButton("World", mCurrentGizmoMode == ImGuizmo::WORLD))
             mCurrentGizmoMode = ImGuizmo::WORLD;
        }
        static bool useSnap(false);
        if (ImGui::IsKeyPressed(83))
          useSnap = !useSnap;
        ImGui::Checkbox("Snap", &useSnap);
        ImGui::SameLine();
        static float snap[3] = {1, 1, 1};
        switch (mCurrentGizmoOperation)
        {
        case ImGuizmo::TRANSLATE:
           ImGui::InputFloat3("Snap", snap);
           break;
        case ImGuizmo::ROTATE:
           ImGui::InputFloat("Angle Snap", snap);
           break;
        case ImGuizmo::SCALE:
           ImGui::InputFloat("Scale Snap", snap);
           break;
        default:
            break;
        }
        ImGuiIO& io = ImGui::GetIO();
        ImGuizmo::SetRect(0, 0, io.DisplaySize.x, io.DisplaySize.y);
        ImGuizmo::Manipulate(view, projection, mCurrentGizmoOperation, mCurrentGizmoMode, world, NULL, useSnap ? snap : NULL);
    }
	bool update() override
	{
		if (!entry::processEvents(m_width, m_height, m_debug, m_reset, &m_mouseState) )
		{
			imguiBeginFrame(m_mouseState.m_mx
				,  m_mouseState.m_my
				, (m_mouseState.m_buttons[entry::MouseButton::Left  ] ? IMGUI_MBUT_LEFT   : 0)
				| (m_mouseState.m_buttons[entry::MouseButton::Right ] ? IMGUI_MBUT_RIGHT  : 0)
				| (m_mouseState.m_buttons[entry::MouseButton::Middle] ? IMGUI_MBUT_MIDDLE : 0)
				,  m_mouseState.m_mz
				, uint16_t(m_width)
				, uint16_t(m_height)
				);

            const bx::Vec3 at  = { 0.0f, 0.0f, 0.0f };
            const bx::Vec3 eye = { 3.0f, 4.0f, 5.0f };
            
            // Set view and projection matrix for view 0.
            float view[16];
            bx::mtxLookAt(view, eye, at, {0.f, 1.f, 0.f});

            float proj[16];
            bx::mtxProj(proj, 60.0f, float(m_width)/float(m_height), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);

            float viewProj[16];
            bx::mtxMul(viewProj, view, proj);
            
            bgfx::setUniform(m_worldUniform, m_world);
            bgfx::setUniform(m_viewProjectionUniform, viewProj);

            // Transform dialog
            ImGui::SetNextWindowPos(
                  ImVec2(10.0f, 10.0f)
                , ImGuiCond_FirstUseEver
                );
            ImGui::SetNextWindowSize(
                  ImVec2(m_width / 5.0f, m_height / 3.5f)
                , ImGuiCond_FirstUseEver
                );
			ImGui::Begin("Transform"
				, NULL
				, 0
				);

            editTransform(view, proj, m_world);
			ImGui::End();

			imguiEndFrame();

			float time = (float)( (bx::getHPCounter()-m_timeOffset)/double(bx::getHPFrequency() ) );

			bgfx::setViewRect(0, 0, 0, m_width, m_height);
			bgfx::setViewClear(0
				, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH
				, 0x20304030
				, 1.0f
				, 0
			);
			bgfx::discard();
            bgfx::touch(0);

            // Set view 0 default viewport.
            bgfx::setViewRect(0, 0, 0, uint16_t(m_width), uint16_t(m_height) );

			uint64_t state = BGFX_STATE_WRITE_MASK | BGFX_STATE_DEPTH_TEST_LESS;

			// Set vertex and index buffer.
			bgfx::setVertexBuffer(0, m_vbh);
			bgfx::setIndexBuffer(m_ibh);

			// Set render states.
			bgfx::setState(state);

			// Submit primitive for rendering to view 0.
			bgfx::submit(0, m_program);

			// Advance to next frame. Rendering thread will be kicked to
			// process submitted rendering primitives.
			bgfx::frame();

			return true;
		}

		return false;
	}

	entry::MouseState m_mouseState;

	uint32_t m_width;
	uint32_t m_height;
	uint32_t m_debug;
	uint32_t m_reset;
	int64_t m_timeOffset;
    float m_world[16];

	bgfx::VertexBufferHandle m_vbh;
	bgfx::IndexBufferHandle m_ibh;
	bgfx::ProgramHandle m_program;
    bgfx::UniformHandle m_worldUniform;
    bgfx::UniformHandle m_viewProjectionUniform;
};

} // namespace

ENTRY_IMPLEMENT_MAIN(
	  App::App
	, "App"
	, ""
	, ""
	);
