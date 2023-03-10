////绘制三角形
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include"Shader.h"
//#include<iostream>
//
//void framebuffer_size_callback(GLFWwindow* widnow, int width, int height);
//void processInput(GLFWwindow* window);
//
////setting
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
////const char* vertexShaderSource = "#version 330 core\n"
////"layout (location=0) in vec3 aPos;\n"
////"void main()\n"
////"{\n"
////"gl_Position=vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
////"}\n";
////"layout(location=0) in vec3 aPos;\n"
////"layout(location=1) in vec3 aColor;\n"
////"out vec3 ourColor;\n"
////"void main()\n"
////"{\n"
////"gl_Position=vec4(aPos,1.0);\n"
////"ourColor=aColor;\n"
////"}\n";
////
////const char* fragmentShaderSource = "#version 330 core\n"
////最初片元着色器
////"out vec4 FragColor;\n"
////"void main()\n"
////"{\n"
////"FragColor=vec4(1.0f,0.5f,0.2f,1.0f);\n"
////"}\n";
//
////渐变色片元着色器
////"out vec4 fragColor;\n;"
////"uniform vec4 ourColor;\n;"
////"void main()\n"
////"{\n"
////"fragColor=ourColor;\n"
////"}\n";
////"out vec4 FragColor;\n"
////"in vec3 ourColor;\n"
////"void main()\n"
////"{\n"
////"FragColor=vec4(ourColor,1.0);\n"
////"}\n";
//
//int main()
//{
//	//glfw:初始化和配置
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	
//
//	//glfw窗口创建
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to Create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	//glad:加载所有的OpenGL函数指针
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "failed to initialize glad" << std::endl;
//		return -1;
//	}
//
//	//构建和编译着色器
//	//----------------
//
//	Shader ourShader("./src/vertexshader.vert", "./src/fragmentshader.frag");
//
//	
//	////顶点shader
//	//unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	//glCompileShader(vertexShader);
//	////检查顶点着色器编译错误
//	//int success;
//	//char infoLog[512];
//	//glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	//if (!success)
//	//{
//	//	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\N" << infoLog << std::endl;
//	//}
//
//	////片元着色器
//	//unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	//glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	//glCompileShader(fragmentShader);
//	////检查片云着色器错误
//	//glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	//if (!success)
//	//{
//	//	glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	//}
//
//	////将着色器链接起来
//	//unsigned int shaderProgram = glCreateProgram();
//	//glAttachShader(shaderProgram, vertexShader);
//	//glAttachShader(shaderProgram, fragmentShader);
//	//glLinkProgram(shaderProgram);
//	////检查着色器链接错误
//	//glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	//if (!success)
//	//{
//	//	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
//	//}
//	//glDeleteShader(vertexShader);
//	//glDeleteShader(fragmentShader);
//
//
//	//设置顶点数据和配置顶点属性
//	//---------------------------
//	float vertices[] = {
//		-0.5f,-0.5f,0.0f, 1.0f,0.0f,0.0f,//left
//		0.5f,-0.5f,0.0f,  0.0f,1.0f,0.0f,//right
//		0.0f,0.5f,0.0f,   0.0f,0.0f,1.0f,//top
//	};
//
//	//float vertices[] = {
//	//0.5f,0.5f,0.0f,  1.0f,0.0f,0.0f,//右上
//	//-0.5f,0.5f,0.0f, 0.0f,1.0f,0.0f//左上
//	//-0.5f,-0.5f,0.0f,0.0f,0.0f,1.0f,//左下
//	//0.5f,-0.5f,0.0f  //右下
//	//};
//
//	unsigned int indices[]
//	{
//		0,1,3,//第一个三角形
//		1,2,3//第二个三角形
//	};
//
//	unsigned int VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	//glGenBuffers(1, &EBO);
//
//	/// <summary>
//	/// 以上为初始化代码
//	/// 最终的代码流程为：
//	/// </summary>
//	/// <returns></returns>
//	//1.绑定顶点数组对象
//	glBindVertexArray(VAO);
//	//2.把我们的顶点数组赋值到一个顶点缓冲中，供OpenGL使用
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	//3.复制我们的索引数组到一个索引缓冲中，供OpenGL使用
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	//4.设定顶点属性指针
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	
//		//颜色属性
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	//glBindBuffer(GL_ARRAY_BUFFER, 0);
//	//glBindVertexArray(0);
//
//	//5.绘制代码
//	//渲染循环
//	while (!glfwWindowShouldClose(window))
//	{
//		//输入
//		processInput(window);
//
//		//渲染
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		//记得激活着色器
//		//glUseProgram(shaderProgram);
//
//		//更新uniform的颜色
//		//float timeValue = glfwGetTime();
//		//float greenValue = sin(timeValue) / 2.0f + 0.5f;
//		//int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//
//		//绘制第一个三角形
//		//glUseProgram(shaderProgram);
//		ourShader.use();
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//
//		//glfw：缓冲区交换（双缓冲）和I/O事件(键盘的按下和释放以及鼠标事件)
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	//可选：一旦资源超出其用途，就取消分配所以资源
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	//glDeleteProgram(shaderProgram);
//
//
//	//glfw：终止、清除所有的GLFW资源分配
//	glfwTerminate();
//	return 0;
//
//
//}
//
//void framebuffer_size_callback(GLFWwindow* widnow, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}

//
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include"stb_image.h"
//#include"Shader.h"
//#include<iostream>
//#include<string>
//
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//void framebuffer_Size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* widnow);
//
//int main()
//{
//	//初始化和配置2
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	//创建glfw窗口
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to Create Window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_Size_callback);
//
//
//
//
//	//glad加载所有的函数指针
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initlize GLAD" << std::endl;
//		return -1;
//	}
//
//	//构建和编译着色器程序
//	Shader ourShader("./src/vertexshader.vert","./src/fragmentshader.frag");
//
//	//设置顶点数据并配置顶点参数
//	float vertices[] = {
//		// positions          // colors           // texture coords
//		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
//		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
//		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
//		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
//	};
//
//
//	//float texcoords[] =
//	//{
//	//	0.0f,0.0f,//左下角
//	//	1.0f,0.0f,//右下角
//	//	0.5f,1.0f//上中
//	//};
//
//	unsigned int indices[] =
//	{
//		0,1,3,//第一个三角形
//		1,2,3//第二个三角形
//	};
//
//
//	unsigned int VAO, VBO,EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	//先绑定顶点数组对象（VAO），再绑定并设置顶点缓冲区（VBO），再配置顶点属性
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//位置参数
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	//颜色参数
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	//贴图参数
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//
//	//加载和创建贴图
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);//所有即将到来的GL_TEXTURE_2D操作现在都对该纹理对象生效
//	//设置纹理的环绕（wraping）参数
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	//设置纹理过滤参数
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//加载图片，创建贴图并生成mipmap
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load("./src/container.jpg", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		std::cout << "Fail to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//
//	//渲染循环
//	while (!glfwWindowShouldClose(window))
//	{
//		//input
//		processInput(window);
//
//		//渲染
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//		//绑定贴图
//		glBindTexture(GL_TEXTURE_2D, texture);
//
//		//渲染内容
//		ourShader.use();
//		glBindVertexArray(VAO);
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		//glfw 交换缓冲区并读取输入输出
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//
//
//	glfwTerminate();
//	return 0;
//
//}
//
//void framebuffer_Size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}


#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"Shader.h"
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"
#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

float mixValue = 0.2f;

int main()
{
	//初始化
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	//创建窗口
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "MYOPENGL", NULL,NULL);
	if (window==NULL)
	{
		std::cout << "failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//glad 加载指针
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//构建和编译shader
	Shader ourShader("./src/vertexshader.vert", "./src/fragmentshader.frag");


	float vertices[] =
	{
		// positions          // colors           // texture coords
	   0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
	   0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
	  -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
	  -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
	};

	unsigned int indices[] =
	{
		0,1,3,
		1, 2, 3
	};
	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//位置配置
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//颜色配置
	glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),(void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//贴图配置
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//加载和创建贴图1
	unsigned int texture1;
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	//设置贴图的环绕参数
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//设置贴图的过滤参数
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//加载图片，创建贴图生成mipmap
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("./src/container.jpg", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else 
	{
	std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);
	//创建和设置贴图2
	unsigned int texture2;
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	//设置环绕参数
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//设置过滤参数
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//加载和创建贴图，生成mipmaps
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("./src/awesomeface.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	ourShader.use();
	ourShader.setInt("texture1", 0);
	ourShader.setInt("texture2", 1);

	//渲染循环
	while (!glfwWindowShouldClose(window))
	{
		//输入
		processInput(window);

		//渲染
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//绑定贴图
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);

		//创建变换矩阵
		glm::mat4 transform=glm::mat4(1.0f);
		transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));

		//获取uniform矩阵位置并设置矩阵
		ourShader.use();
		unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));



		//将mixValue设置到shader中
		ourShader.setFloat("mixValue", mixValue);

		//渲染内容
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		//GLFW 双缓冲
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//空间回收
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window,int width,int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		mixValue += 0.001f;
		if (mixValue >= 1.0f)
			mixValue = 1.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		mixValue -= 0.001f;
		if (mixValue <= 0.0f)
			mixValue = 0.0f;
	}
}

