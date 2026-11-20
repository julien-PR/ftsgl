#version 460 core

layout(location = 0) in vec2	position;
layout(location = 1) in vec4	in_color;

out vec4	color;

uniform vec2	resolution;
uniform vec2	new_resolution;

vec2 scale_to_screen(vec2 pos)
{
	return (pos * (resolution / new_resolution));
}

void main()
{
	color = in_color;
	gl_Position = vec4(scale_to_screen(position), 0.0, 1.0);
}
