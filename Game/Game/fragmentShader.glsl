#version 410 

out vec4 color;

in vec3 col;

void main()
{
	color = vec4(col + 0.25, 1);
}