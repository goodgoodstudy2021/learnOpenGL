////����������
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
////���ƬԪ��ɫ��
////"out vec4 FragColor;\n"
////"void main()\n"
////"{\n"
////"FragColor=vec4(1.0f,0.5f,0.2f,1.0f);\n"
////"}\n";
//
////����ɫƬԪ��ɫ��
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
//	//glfw:��ʼ��������
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	
//
//	//glfw���ڴ���
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
//	//glad:�������е�OpenGL����ָ��
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "failed to initialize glad" << std::endl;
//		return -1;
//	}
//
//	//�����ͱ�����ɫ��
//	//----------------
//
//	Shader ourShader("./src/vertexshader.vert", "./src/fragmentshader.frag");
//
//	
//	////����shader
//	//unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	//glCompileShader(vertexShader);
//	////��鶥����ɫ���������
//	//int success;
//	//char infoLog[512];
//	//glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	//if (!success)
//	//{
//	//	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\N" << infoLog << std::endl;
//	//}
//
//	////ƬԪ��ɫ��
//	//unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	//glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	//glCompileShader(fragmentShader);
//	////���Ƭ����ɫ������
//	//glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	//if (!success)
//	//{
//	//	glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	//}
//
//	////����ɫ����������
//	//unsigned int shaderProgram = glCreateProgram();
//	//glAttachShader(shaderProgram, vertexShader);
//	//glAttachShader(shaderProgram, fragmentShader);
//	//glLinkProgram(shaderProgram);
//	////�����ɫ�����Ӵ���
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
//	//���ö������ݺ����ö�������
//	//---------------------------
//	float vertices[] = {
//		-0.5f,-0.5f,0.0f, 1.0f,0.0f,0.0f,//left
//		0.5f,-0.5f,0.0f,  0.0f,1.0f,0.0f,//right
//		0.0f,0.5f,0.0f,   0.0f,0.0f,1.0f,//top
//	};
//
//	//float vertices[] = {
//	//0.5f,0.5f,0.0f,  1.0f,0.0f,0.0f,//����
//	//-0.5f,0.5f,0.0f, 0.0f,1.0f,0.0f//����
//	//-0.5f,-0.5f,0.0f,0.0f,0.0f,1.0f,//����
//	//0.5f,-0.5f,0.0f  //����
//	//};
//
//	unsigned int indices[]
//	{
//		0,1,3,//��һ��������
//		1,2,3//�ڶ���������
//	};
//
//	unsigned int VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	//glGenBuffers(1, &EBO);
//
//	/// <summary>
//	/// ����Ϊ��ʼ������
//	/// ���յĴ�������Ϊ��
//	/// </summary>
//	/// <returns></returns>
//	//1.�󶨶����������
//	glBindVertexArray(VAO);
//	//2.�����ǵĶ������鸳ֵ��һ�����㻺���У���OpenGLʹ��
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	//3.�������ǵ��������鵽һ�����������У���OpenGLʹ��
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	//4.�趨��������ָ��
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	
//		//��ɫ����
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	//glBindBuffer(GL_ARRAY_BUFFER, 0);
//	//glBindVertexArray(0);
//
//	//5.���ƴ���
//	//��Ⱦѭ��
//	while (!glfwWindowShouldClose(window))
//	{
//		//����
//		processInput(window);
//
//		//��Ⱦ
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		//�ǵü�����ɫ��
//		//glUseProgram(shaderProgram);
//
//		//����uniform����ɫ
//		//float timeValue = glfwGetTime();
//		//float greenValue = sin(timeValue) / 2.0f + 0.5f;
//		//int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//
//		//���Ƶ�һ��������
//		//glUseProgram(shaderProgram);
//		ourShader.use();
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//
//		//glfw��������������˫���壩��I/O�¼�(���̵İ��º��ͷ��Լ�����¼�)
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	//��ѡ��һ����Դ��������;����ȡ������������Դ
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	//glDeleteProgram(shaderProgram);
//
//
//	//glfw����ֹ��������е�GLFW��Դ����
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
//	//��ʼ��������2
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	//����glfw����
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
//	//glad�������еĺ���ָ��
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initlize GLAD" << std::endl;
//		return -1;
//	}
//
//	//�����ͱ�����ɫ������
//	Shader ourShader("./src/vertexshader.vert","./src/fragmentshader.frag");
//
//	//���ö������ݲ����ö������
//	float vertices[] = {
//		// positions         // colors       //texture coords
//	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   0.0f,0.0f,// bottom right
//	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f,0.0f,// bottom left
//	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.5f,1.0f// top 
//	};
//
//
//	//float texcoords[] =
//	//{
//	//	0.0f,0.0f,//���½�
//	//	1.0f,0.0f,//���½�
//	//	0.5f,1.0f//����
//	//};
//
//	unsigned int indices[] =
//	{
//		0,1,3,//��һ��������
//		1,2,3//�ڶ���������
//	};
//
//
//	unsigned int VAO, VBO,EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	//�Ȱ󶨶����������VAO�����ٰ󶨲����ö��㻺������VBO���������ö�������
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//λ�ò���
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	//��ɫ����
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	//��ͼ����
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//
//	//���غʹ�����ͼ
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);//���м���������GL_TEXTURE_2D�������ڶ��Ը����������Ч
//	//��������Ļ��ƣ�wraping������
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	//����������˲���
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//����ͼƬ��������ͼ������mipmap
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
//	//��Ⱦѭ��
//	while (!glfwWindowShouldClose(window))
//	{
//		//input
//		processInput(window);
//
//		//��Ⱦ
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//		//����ͼ
//		glBindTexture(GL_TEXTURE_2D, texture);
//
//		//��Ⱦ����
//		ourShader.use();
//		glBindVertexArray(VAO);
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		//glfw ��������������ȡ�������
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

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Shader.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("./src/vertexshader.vert", "./src/fragmentshader.frag");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
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

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    // load and create a texture 
    // -------------------------
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
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


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);

        // render container
        ourShader.use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}