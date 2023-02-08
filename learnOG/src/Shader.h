////#pragma once
////
////#include<glad/glad.h>
////
////#include<string>
////#include<fstream>
////#include<sstream>
////#include<iostream>
////
////class Shader
////{
////public:
////	//程序ID
////	unsigned int ID;
////
////	//构造器读取并构建着色器
////	Shader(const char* vertexPath, const char* fragmentPath)
////	{
////		//1.从文件路径中获取顶点、片元着色器
////		std::string vertexCode;
////		std::string fragmentCode;
////		std::ifstream vShaderFile;
////		std::ifstream fShaderFile;
////		//保证ifstream对象可以抛出异常
////		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
////		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
////		try
////		{
////			//打开文件
////			vShaderFile.open(vertexPath);
////			fShaderFile.open(fragmentPath);
////			std::stringstream vShaderStream, fShaderStream;
////			//读取文件的缓冲内容到数据流中
////			vShaderStream << vShaderFile.rdbuf();
////			fShaderStream << fShaderFile.rdbuf();
////			//关闭文件处理器
////			vShaderFile.close();
////			fShaderFile.close();
////			//转换数据流到string
////			vertexCode = vShaderStream.str();
////			fragmentCode = fShaderStream.str();
////		}
////		catch (std::ifstream::failure e)
////		{
////			std::cout << "ERROR::SHADER::FAILED_NOT_SUCCESFULLY_READ" << std::endl;
////		}
////		const char* vShaderCode = vertexCode.c_str();
////		const char* fShaderCode = fragmentCode.c_str();
////
////		//2.编译着色器
////		unsigned int vertex, fragment;
////		int success;
////		char infoLog[512];
////
////		//顶点着色器
////		vertex = glCreateShader(GL_VERTEX_SHADER);
////		glShaderSource(vertex, 1, &vShaderCode, NULL);
////		glCompileShader(vertex);
////		//打印编译错误
////		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
////		if (!success)
////		{
////			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
////			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////		}
////
////		//片元着色器
////		fragment = glCreateShader(GL_FRAGMENT_SHADER);
////		glShaderSource(fragment, 1, &fShaderCode, NULL);
////		glCompileShader(fragment);
////		//打印编译错误
////		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
////		if (!success)
////		{
////			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
////			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
////		}
////
////
////		//着色器程序
////		ID = glCreateProgram();
////		glAttachShader(ID, vertex);
////		glAttachShader(ID, fragment);
////		glLinkProgram(ID);
////		//打印连接错误
////		glGetProgramiv(ID, GL_LINK_STATUS, &success);
////		if (!success)
////		{
////			glGetProgramInfoLog(ID, 512, NULL, infoLog);
////			std::cout << "ERROR::SHADER::PROGRAM::LINKED_FAILED\n" << infoLog << std::endl;
////		}
////
////		glDeleteShader(vertex);
////		glDeleteShader(fragment);
////	}
////	//使用、激活程序
////	void use()
////	{
////		glUseProgram(ID);
////	}
////	//uniform工具函数
////	void setBool(const std::string& name, bool value)const
////	{
////		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
////	}
////	void setInt(const std::string& name, int value)const
////	{
////		glUniform1i(glGetUniformLocation(ID, name.c_str()),value);
////	}
////	void setFloat(const std::string& name, float value)const
////	{
////		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
////	}
////};
////
//
//
//#ifndef SHADER_H
//#define SHADER_H
//
//#include <glad/glad.h>
//
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <iostream>
//
//class Shader
//{
//public:
//    unsigned int ID;
//    // constructor generates the shader on the fly
//    // ------------------------------------------------------------------------
//    Shader(const char* vertexPath, const char* fragmentPath)
//    {
//        // 1. retrieve the vertex/fragment source code from filePath
//        std::string vertexCode;
//        std::string fragmentCode;
//        std::ifstream vShaderFile;
//        std::ifstream fShaderFile;
//        // ensure ifstream objects can throw exceptions:
//        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//        try
//        {
//            // open files
//            vShaderFile.open(vertexPath);
//            fShaderFile.open(fragmentPath);
//            std::stringstream vShaderStream, fShaderStream;
//            // read file's buffer contents into streams
//            vShaderStream << vShaderFile.rdbuf();
//            fShaderStream << fShaderFile.rdbuf();
//            // close file handlers
//            vShaderFile.close();
//            fShaderFile.close();
//            // convert stream into string
//            vertexCode = vShaderStream.str();
//            fragmentCode = fShaderStream.str();
//        }
//        catch (std::ifstream::failure& e)
//        {
//            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
//        }
//        const char* vShaderCode = vertexCode.c_str();
//        const char* fShaderCode = fragmentCode.c_str();
//        // 2. compile shaders
//        unsigned int vertex, fragment;
//        // vertex shader
//        vertex = glCreateShader(GL_VERTEX_SHADER);
//        glShaderSource(vertex, 1, &vShaderCode, NULL);
//        glCompileShader(vertex);
//        checkCompileErrors(vertex, "VERTEX");
//        // fragment Shader
//        fragment = glCreateShader(GL_FRAGMENT_SHADER);
//        glShaderSource(fragment, 1, &fShaderCode, NULL);
//        glCompileShader(fragment);
//        checkCompileErrors(fragment, "FRAGMENT");
//        // shader Program
//        ID = glCreateProgram();
//        glAttachShader(ID, vertex);
//        glAttachShader(ID, fragment);
//        glLinkProgram(ID);
//        checkCompileErrors(ID, "PROGRAM");
//        // delete the shaders as they're linked into our program now and no longer necessary
//        glDeleteShader(vertex);
//        glDeleteShader(fragment);
//    }
//    // activate the shader
//    // ------------------------------------------------------------------------
//    void use()
//    {
//        glUseProgram(ID);
//    }
//    // utility uniform functions
//    // ------------------------------------------------------------------------
//    void setBool(const std::string& name, bool value) const
//    {
//        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
//    }
//    // ------------------------------------------------------------------------
//    void setInt(const std::string& name, int value) const
//    {
//        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
//    }
//    // ------------------------------------------------------------------------
//    void setFloat(const std::string& name, float value) const
//    {
//        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
//    }
//
//private:
//    // utility function for checking shader compilation/linking errors.
//    // ------------------------------------------------------------------------
//    void checkCompileErrors(unsigned int shader, std::string type)
//    {
//        int success;
//        char infoLog[1024];
//        if (type != "PROGRAM")
//        {
//            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
//            if (!success)
//            {
//                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
//                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
//            }
//        }
//        else
//        {
//            glGetProgramiv(shader, GL_LINK_STATUS, &success);
//            if (!success)
//            {
//                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
//                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
//            }
//        }
//    }
//};
//#endif

#pragma once

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

class Shader
{
public:
	unsigned int ID;
	//构造函数动态生成着色器
	Shader(const char* vertexPath, const char* fragmentPath)
	{
		//1.从文件中读取顶点和片元着色器
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		//确保ifstream对象可以抛出异常
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			//打开文件
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			//将文件的缓冲区内容读取到流
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			//关闭文件处理程序
			vShaderFile.close();
			fShaderFile.close();
			//将流转换到字符串
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure& e)
		{
			std::cout << "ERROR::SHADER:FAIL_NOT_SUCCESSFULLY_READ:" << e.what() << std::endl;
		}
		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();
		//2.编译着色器
		unsigned int vertex, fragment;
		//顶点着色器
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		checkCompileErrors(vertex, "VERTEX");
		//片元着色器
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		checkCompileErrors(fragment, "FRAGMENT");
		//着色器程序
		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);
		checkCompileErrors(ID, "PROGRAM");
		//删除着色器，着色器已经链接进了程序，不再需要
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	//激活着色器
	void use()
	{
		glUseProgram(ID);
	}
	//效用统一函数
	void setBool(const std::string& name, bool value)const 
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}
	void setInt(const std::string& name, int value)const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}
	void setFlaot(const std::string& name, float value)const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}


private:
	//用于检测着色器编译和链接错误
	void checkCompileErrors(unsigned int shader, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERRROR of type:" << type << "\n" << infoLog << "\n -- -------------------------------------" << std::endl;

			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM::LINKING_ERROR of type:" << type << "\n" << infoLog << "\n -- -----------------------------------" << std::endl;

			}
		}
	}

};
