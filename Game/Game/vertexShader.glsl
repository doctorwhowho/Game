#version 410

uniform mat4 MVP;

layout(location =  0) in vec3 positions;

out vec3 col;

void main()
{
	gl_Position = MVP * vec4(positions, 1.0);
	col = vec3(positions.y) + 0.5f;
}