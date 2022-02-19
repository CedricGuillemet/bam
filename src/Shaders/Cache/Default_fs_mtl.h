static const uint8_t Default_fs_mtl[551] =
{
	0x46, 0x53, 0x48, 0x0b, 0xe3, 0xc2, 0x5c, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x02, // FSH....e........
	0x00, 0x00, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x3c, 0x6d, 0x65, 0x74, 0x61, // ..#include <meta
	0x6c, 0x5f, 0x73, 0x74, 0x64, 0x6c, 0x69, 0x62, 0x3e, 0x0a, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, // l_stdlib>.#inclu
	0x64, 0x65, 0x20, 0x3c, 0x73, 0x69, 0x6d, 0x64, 0x2f, 0x73, 0x69, 0x6d, 0x64, 0x2e, 0x68, 0x3e, // de <simd/simd.h>
	0x0a, 0x0a, 0x75, 0x73, 0x69, 0x6e, 0x67, 0x20, 0x6e, 0x61, 0x6d, 0x65, 0x73, 0x70, 0x61, 0x63, // ..using namespac
	0x65, 0x20, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, // e metal;..struct
	0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, //  xlatMtlMain_out
	0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x62, 0x67, // .{.    float4 bg
	0x66, 0x78, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30, 0x20, 0x5b, 0x5b, 0x63, // fx_FragData0 [[c
	0x6f, 0x6c, 0x6f, 0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x73, // olor(0)]];.};..s
	0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, // truct xlatMtlMai
	0x6e, 0x5f, 0x69, 0x6e, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, // n_in.{.    float
	0x33, 0x20, 0x76, 0x5f, 0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x20, 0x5b, 0x5b, 0x75, 0x73, 0x65, // 3 v_normal [[use
	0x72, 0x28, 0x6c, 0x6f, 0x63, 0x6e, 0x30, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, // r(locn0)]];.};..
	0x66, 0x72, 0x61, 0x67, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, // fragment xlatMtl
	0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, // Main_out xlatMtl
	0x4d, 0x61, 0x69, 0x6e, 0x28, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, // Main(xlatMtlMain
	0x5f, 0x69, 0x6e, 0x20, 0x69, 0x6e, 0x20, 0x5b, 0x5b, 0x73, 0x74, 0x61, 0x67, 0x65, 0x5f, 0x69, // _in in [[stage_i
	0x6e, 0x5d, 0x5d, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, // n]]).{.    xlatM
	0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, 0x6f, 0x75, 0x74, 0x20, 0x3d, // tlMain_out out =
	0x20, 0x7b, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x5f, //  {};.    float _
	0x31, 0x30, 0x31, 0x20, 0x3d, 0x20, 0x28, 0x64, 0x6f, 0x74, 0x28, 0x66, 0x61, 0x73, 0x74, 0x3a, // 101 = (dot(fast:
	0x3a, 0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x69, 0x7a, 0x65, 0x28, 0x69, 0x6e, 0x2e, 0x76, 0x5f, // :normalize(in.v_
	0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x29, 0x2c, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x33, 0x28, // normal), float3(
	0x30, 0x2e, 0x38, 0x31, 0x33, 0x37, 0x33, 0x33, 0x34, 0x35, 0x38, 0x35, 0x31, 0x38, 0x39, 0x38, // 0.81373345851898
	0x31, 0x39, 0x33, 0x33, 0x35, 0x39, 0x33, 0x37, 0x35, 0x2c, 0x20, 0x30, 0x2e, 0x34, 0x36, 0x34, // 193359375, 0.464
	0x39, 0x39, 0x30, 0x35, 0x35, 0x36, 0x32, 0x34, 0x30, 0x30, 0x38, 0x31, 0x37, 0x38, 0x37, 0x31, // 9905562400817871
	0x30, 0x39, 0x33, 0x37, 0x35, 0x2c, 0x20, 0x30, 0x2e, 0x33, 0x34, 0x38, 0x37, 0x34, 0x32, 0x39, // 09375, 0.3487429
	0x30, 0x32, 0x32, 0x37, 0x38, 0x39, 0x30, 0x30, 0x31, 0x34, 0x36, 0x34, 0x38, 0x34, 0x33, 0x37, // 0227890014648437
	0x35, 0x29, 0x29, 0x20, 0x2a, 0x20, 0x30, 0x2e, 0x35, 0x29, 0x20, 0x2b, 0x20, 0x30, 0x2e, 0x35, // 5)) * 0.5) + 0.5
	0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75, 0x74, 0x2e, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46, // ;.    out.bgfx_F
	0x72, 0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30, 0x20, 0x3d, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, // ragData0 = float
	0x34, 0x28, 0x5f, 0x31, 0x30, 0x31, 0x20, 0x2a, 0x20, 0x5f, 0x31, 0x30, 0x31, 0x29, 0x3b, 0x0a, // 4(_101 * _101);.
	0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x6f, 0x75, 0x74, 0x3b, 0x0a, //     return out;.
	0x7d, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00,                                                       // }......
};
