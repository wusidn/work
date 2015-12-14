#version 430 core

layout( location = 0 ) in vec4 vPosition;
layout( location = 1 ) in vec4 vColor;

out vec4 color;

uniform  Uniforms {
	vec3 vTranslation;
    vec3 vRotation;
	vec3 vScale;
};

void main()
{
    color = vColor;

	float pi = 3.1415926535898;

	mat4 translation = mat4(
		1.0, 0.0, 0.0, vTranslation.x,
		0.0, 1.0, 0.0, vTranslation.y,
		0.0, 0.0, 1.0, vTranslation.z,
		0.0, 0.0, 0.0, 1.0
	);

	mat4 rotation = mat4(
		cos(vRotation.z / 180 * pi), 0 - sin(vRotation.z / 180 * pi), 0.0, 0.0,
		sin(vRotation.z / 180 * pi),  cos(vRotation.z / 180 * pi), 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	);

	mat4 scale = mat4(
		vScale.x, 0.0, 0.0, 0.0,
		0.0, vScale.y, 0.0, 0.0,
		0.0, 0.0, vScale.z, 0.0,
		0.0, 0.0, 0.0, 1.0
	);

    gl_Position = vPosition * scale * rotation * translation;
}