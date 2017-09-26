#version 130

uniform vec3 in_color;
out vec4 out_color;

void main() {
	out_color = vec4(in_color, 1.0);
}
