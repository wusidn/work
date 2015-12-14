#include "EnginePortal.h"
#include "ShaderElement.h"
#include "ShaderProgram.h"

#include <gl\glew.h>
#include <gl\freeglut.h>

#pragma comment(lib, "glew32.lib")

#include <iostream>
#include <string>
using namespace std;

GLuint vertexArrayObject;
GLuint vertexBufferObject;
GLuint indiesBufferObject;


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(700, 300);
	string title = "Hello Engine For Windows And VS2015";
	glutCreateWindow(title.c_str());

	if (glewInit()) {
		cout << "glewInit Error" << endl;
		exit(EXIT_FAILURE);
	}

	engine_portal_init();

	glutDisplayFunc(engine_portal_display);


	glutMainLoop();
	return 0;
}


void engine_portal_init(void)
{
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

	const GLfloat vertices[6][2] =
	{
		{ -0.50,  -0.50 },
		{ 0.50,   -0.50 },
		{ 0.50,   0.50 },
		{ -0.50,  0.50 }
	};

	const GLfloat colors[] = {
		1.0, 0.0, 0.0, 1.0,
		0.0, 1.0, 0.0, 1.0,
		0.0, 0.0, 1.0, 1.0,
		1.0, 1.0, 0.0, 1.0,
	};

	const GLushort vertex_indies[] = {
		0, 1, 2, 0, 2, 3
	};


	glGenBuffers(1, &indiesBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiesBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertex_indies), vertex_indies, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	glGenBuffers(1, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), nullptr, GL_STATIC_DRAW);


	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);


	string a = ShaderElement::getShaderSource("../Shader/triangles.vert");


	ShaderElement * shaderVert = ShaderElement::createWithShaderCode(GL_VERTEX_SHADER, ShaderElement::getShaderSource("../Shader/triangles.vert"));
	if (!shaderVert->compile()) {
		cout << shaderVert->getError() << endl;
		cout << "Vertex Shader Compile Error" << endl;
	}

	ShaderElement * shaderFrag = ShaderElement::createWithShaderCode(GL_FRAGMENT_SHADER, ShaderElement::getShaderSource("../Shader/triangles.frag"));
	if (!shaderFrag->compile()) {
		cout << "Fragment Shader Compile Error" << endl;
	}

	ShaderProgram * shaderProgram = ShaderProgram::create();
	shaderProgram->attachShader(*shaderVert);
	shaderProgram->attachShader(*shaderFrag);

	if (!shaderProgram->linkProgram()) {
		cout << "ShaderProgram Linking Error" << endl;
	}

	GLint uboSize;
	GLuint uboIndex = glGetUniformBlockIndex(shaderProgram->programId(), "Uniforms");
	GLvoid * uboData;
	GLuint ubo;
	if (uboIndex == GL_INVALID_INDEX) {
		cout << "Uniforms Is Not Uniform Block Name" << endl;
	}

	glGetActiveUniformBlockiv(shaderProgram->programId(), uboIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &uboSize);
	uboData = (GLvoid *)malloc(uboSize);
	if (uboData == nullptr) {
		cout << "uboData Malloc Error" << endl;
	}

	enum { vTranslation, vRotation, vScale, numUniforms };

	const char* uniformsNames[numUniforms] = {
			"vTranslation",
			"vRotation",
			"vScale"
	};

	GLuint indices[numUniforms];
	GLint sizes[numUniforms];
	GLint offsets[numUniforms];
	GLint types[numUniforms];

	glGetUniformIndices(shaderProgram->programId(), numUniforms, uniformsNames, indices);

	glGetActiveUniformsiv(shaderProgram->programId(), numUniforms, indices, GL_UNIFORM_SIZE, sizes);
	glGetActiveUniformsiv(shaderProgram->programId(), numUniforms, indices, GL_UNIFORM_OFFSET, offsets);
	glGetActiveUniformsiv(shaderProgram->programId(), numUniforms, indices, GL_UNIFORM_TYPE, types);

	//data
	GLfloat translation[3] = { 0.3f, 0.3f, 0.0f};
	GLfloat rotation[3] = { 0.0f, 0.0f, 90.0f};
	GLfloat scale[3] = { 0.5f, 0.8f, 0.0f};

	memcpy((void *)((GLint)uboData + offsets[vTranslation]), translation, sizes[vTranslation] * ShaderProgram::TypeSize(types[vTranslation]));
	memcpy((void *)((GLint)uboData + offsets[vRotation]), rotation, sizes[vRotation] * ShaderProgram::TypeSize(types[vRotation]));
	memcpy((void *)((GLint)uboData + offsets[vScale]), scale, sizes[vScale] * ShaderProgram::TypeSize(types[vScale]));


	glGenBuffers(1, &ubo);
	glBindBuffer(GL_UNIFORM_BUFFER, ubo);
	glBufferData(GL_UNIFORM_BUFFER, uboSize, uboData, GL_STATIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, uboIndex, ubo);


	glUseProgram(shaderProgram->programId());

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (const void *)sizeof(vertices));
	glEnableVertexAttribArray(1);

}

void engine_portal_display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(vertexArrayObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiesBufferObject);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);

	glFinish();
}

void engine_portal_idle(void)
{
	engine_portal_display();
	//static int  
}
