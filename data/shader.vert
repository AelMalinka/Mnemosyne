#version 130

in vec3 in_position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	gl_Position = model * view * projection * vec4(in_position, 1.0);
}
