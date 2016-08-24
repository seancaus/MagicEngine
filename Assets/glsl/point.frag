#version 410 core

/**

.vert：顶点着色器(Vertex Shader)
.frag：片段着色器(Fragment Shader)
.geom：几何着色器(Geometry Shader)
.tesc：细分控制着色器(Tessellation Control Shader)
.tese：细分评估着色器(Tessellation Evaluation Shader)
.comp：计算着色器(Compute Shader)

*/

out vec4 fragColor;

void main() {
	fragColor = vec4(1.0, .5, .5, 1.0);
}
