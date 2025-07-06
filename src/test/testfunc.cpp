#include "testfunc.h"

std::pair<uint32_t,uint32_t> createTriangle(GLfloat* vertices, size_t __size__){

    //create Shader Vertex Source
    const char *vertexShaderSource = 
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    
    //create Fragment Shader Source
    const char *fragmentShaderSource =
        "#version 330 core"
        "out vec4 FragColor;"
        "void main()"
        "{"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
        "}" ;
    

//---------------  Create vertex Shader and compile --------------------
    uint32_t vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
//----------------------------------------------------------------------


//---------------  Create fragment Shader and compile ------------------
    uint32_t fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

//----------------------------------------------------------------------
    

//--------------  Create ProgramShader from Vertex-Shader and Fragment-Shader ----------------
    uint32_t shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
//--------------------------------------------------------------------------------------------

//----------- clear useless Shader ---------    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
//------------------------------------------


//  create refference containers for vertex array
    
    GLuint VAO,VBO;

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, __size__ , vertices , GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return make_pair(shaderProgram,VAO);
}


int main(){

}