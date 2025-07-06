#include "../include/Solar.h"
#include "../include/Object_module.h"
#include <time.h>

// ----------- DEFINE MARCO DIRECTIVE -------------//

#define VIEW_X 0
#define VIEW_Y 0
#define WIDTH 800
#define HEIGHT 600

#define PROJECT_NAME "Simulation Solar System"
#define LOG_FILE_NAME "log.txt"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){ glViewport(VIEW_X , VIEW_Y , width , height); }
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);  // or gmtime(&now) for UTC
    string putMsg;

    cout << "Project Name : " << PROJECT_NAME << endl;
    cout << "Log File : " << LOG_FILE_NAME << endl;
    cout << "Time : " << ctime(&now) << endl;
    FILE* LOG = fopen(LOG_FILE_NAME, "w");
    if (LOG == NULL) {
        fprintf(LOG, "[x] Failed to open log file.\n");
        cerr << "[x] Failed to open log file." << endl;
        return -1;
    }
    
    fprintf(LOG, "[+] Log file opened successfully.\n");
    cout << "[+] Log file opened successfully." << endl;
    

    if(!glfwInit()){
            fprintf(LOG, "[x] The Initialization was failed\n");
            cerr << "[x] The Initialization was failed" << endl;
            glfwTerminate();
            return -1;
    }
        
    fprintf(LOG, "[+] The Initialization was successful\n");    
    cout << "[+] The Initialization was successful" << endl;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, PROJECT_NAME, NULL, NULL);
    
    if (!window){
        fprintf(LOG, "[x] Failed to create GLFW window\n");
        cerr << "[x] Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    fprintf(LOG, "[+] GLFW window created successfully\n");
    cout << "[+] GLFW window created successfully" << endl;
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        fprintf(LOG, "[x] Failed to initialize GLAD\n");
        cerr << "[x] Failed to initialize GLAD" << endl;
        return -1;
    }    

    glViewport(VIEW_X , VIEW_Y , WIDTH , HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



    GLfloat vert[] = 
    {
        -0.5f, -0.5f, 0.0f,  // Left  
        0.5f, -0.5f, 0.0f,  // Right 
        0.0f,  0.5f, 0.0f   // Top             
    };
    cout << "[+] OpenGL Version: " << glGetString(GL_VERSION) << endl;
    cout << "[+] OpenGL Vendor: " << glGetString(GL_VENDOR) << endl;
    cout << "[+] OpenGL Renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "[+] OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    
    fprintf(LOG, "[+] OpenGL Version: %s\n", glGetString(GL_VERSION));
    fprintf(LOG, "[+] OpenGL Vendor: %s\n", glGetString(GL_VENDOR));
    fprintf(LOG, "[+] OpenGL Renderer: %s\n", glGetString(GL_RENDERER));
    fprintf(LOG, "[+] OpenGL Shading Language Version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    
    while( !glfwWindowShouldClose(window) ){
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        auto [shader,vertArray] = createTriangle(vert,sizeof(vert));
        glUseProgram(shader);
        glBindVertexArray(vertArray);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    fprintf(LOG, "[+] The program is terminated successfully\n");
    cout << "[+] The program is terminated successfully" << endl;
    fclose(LOG);
    glfwDestroyWindow(window);
    fprintf(LOG, "[+] GLFW window destroyed successfully\n");
    cout << "[+] GLFW window destroyed successfully" << endl;
    glfwTerminate();
    return 0;
    
}