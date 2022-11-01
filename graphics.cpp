#include "designerHeader.h"

GLuint getShaderProgramId (const char *vertexFile, const char *fragmentFile);
GLuint compileShader (const GLchar *source, GLuint shaderType);
GLuint shaderProgramId, vao, vbo, ubo, textureId;

//To stop sending information to shaders, screen resolution is hard coded (half per dimension)
const char* vertexShader =
    "#version 330\n"
    "layout (location = 0) in vec2 vert;\n"
    "layout (location = 1) in vec2 _uv;\n"
    "out vec2 uv;\n"
    "void main () {\n"
    "    uv = _uv;\n"
    "    gl_Position = vec4 (vert.x / 960.0 - 1.0, vert.y / 540.0 - 1.0, 0.0, 1.0);\n"
    "}\n";

const char* fragmentShader =
    "#version 330\n"
    "out vec4 color;\n"
    "in vec2 uv;\n"
    "uniform sampler2D tex;\n"
    "void main () {\n"
    "    color = texture(tex, uv);\n"
    "}\n";

//For corners, (u1, v1) is the top left and (u2, v2) is bottom right. (0, 0) is top left corner
Texture notGate = {200, 100, 0.0f, 0.0f, 1.0f, 0.3268f};
Texture andGate = {200, 100, 0.0f, 0.3268f, 1.0f, 0.6437f};
Texture manualInputOff = {200, 53, 0.0f, 0.647f, 1.0f, 0.8202f};
Texture manualInputOn = {200, 53, 0.0f, 0.8235f, 1.0f, 0.9967f};

Texture textures[4] = {notGate, andGate, manualInputOff, manualInputOn};



void DrawSprites (std::vector<Object>& objects, std::vector<short>& vertices, std::vector<float>& uvs, std::vector<Gate>& gateData, float scaleFactor) {
    for (int i = 0; i < gateData.size (); i++) {
        Texture t;
        if (gateData[i].gateType == OUTPUTGATE) {
            t = textures[2];
        } else if (gateData[i].gateType == OUTPUTGATEON) {
            t = textures[3];
        } else {
            t = textures[gateData[i].gateType];
        }
        objects[i] = {gateData[i].position.x, gateData[i].position.y, t};

        //Vertices
        //Top right
        vertices[i * 12] = objects[i].x + objects[i].texture.width * scaleFactor;
        vertices[i * 12 + 1] = objects[i].y;

        //Bottom right
        vertices[i * 12 + 2] = objects[i].x + objects[i].texture.width * scaleFactor;
        vertices[i * 12 + 3] = objects[i].y + objects[i].texture.height * scaleFactor;

        //Top left
        vertices[i * 12 + 4] = objects[i].x;
        vertices[i * 12 + 5] = objects[i].y;

        //Bottom right
        vertices[i * 12 + 6] = objects[i].x + objects[i].texture.width * scaleFactor;
        vertices[i * 12 + 7] = objects[i].y + objects[i].texture.height * scaleFactor;

        //Bottom left
        vertices[i * 12 + 8] = objects[i].x;
        vertices[i * 12 + 9] = objects[i].y + objects[i].texture.height * scaleFactor;

        //Top left
        vertices[i * 12 + 10] = objects[i].x;
        vertices[i * 12 + 11] = objects[i].y;

        //UVs
        //First check if sprite should be flipped
        if (gateData[i].gateType == OUTPUTGATE || gateData[i].gateType == OUTPUTGATEON) {
            //Top right
            uvs[i * 12] = objects[i].texture.u1;
            uvs[i * 12 + 1] = objects[i].texture.v1;

            //Bottom right
            uvs[i * 12 + 2] = objects[i].texture.u1;
            uvs[i * 12 + 3] = objects[i].texture.v2;

            //Top left
            uvs[i * 12 + 4] = objects[i].texture.u2;
            uvs[i * 12 + 5] = objects[i].texture.v1;

            //Bottom right
            uvs[i * 12 + 6] = objects[i].texture.u1;
            uvs[i * 12 + 7] = objects[i].texture.v2;

            //Bottom left
            uvs[i * 12 + 8] = objects[i].texture.u2;
            uvs[i * 12 + 9] = objects[i].texture.v2;

            //Top left
            uvs[i * 12 + 10] = objects[i].texture.u2;
            uvs[i * 12 + 11] = objects[i].texture.v1;
        } else {
            //Top right
            uvs[i * 12] = objects[i].texture.u2;
            uvs[i * 12 + 1] = objects[i].texture.v2;

            //Bottom right
            uvs[i * 12 + 2] = objects[i].texture.u2;
            uvs[i * 12 + 3] = objects[i].texture.v1;

            //Top left
            uvs[i * 12 + 4] = objects[i].texture.u1;
            uvs[i * 12 + 5] = objects[i].texture.v2;

            //Bottom right
            uvs[i * 12 + 6] = objects[i].texture.u2;
            uvs[i * 12 + 7] = objects[i].texture.v1;

            //Bottom left
            uvs[i * 12 + 8] = objects[i].texture.u1;
            uvs[i * 12 + 9] = objects[i].texture.v1;

            //Top left
            uvs[i * 12 + 10] = objects[i].texture.u1;
            uvs[i * 12 + 11] = objects[i].texture.v2;
        }
    }

    //Init OpenGL buffers
    glGenVertexArrays (1, &vao);
    glGenBuffers (1, &vbo);
    glGenBuffers (1, &ubo);
    glBindVertexArray (vao);

    glBindBuffer (GL_ARRAY_BUFFER, vbo);
    glBufferData (GL_ARRAY_BUFFER, vertices.size () * sizeof (short), &vertices[0], GL_DYNAMIC_DRAW);
    glVertexAttribPointer (0, 2, GL_SHORT, GL_FALSE, 2 * sizeof (short), 0);

    glBindBuffer (GL_ARRAY_BUFFER, ubo);
    glBufferData (GL_ARRAY_BUFFER, uvs.size () * sizeof (float), &uvs[0], GL_STATIC_DRAW);
    glVertexAttribPointer (1, 2, GL_FLOAT, GL_TRUE, 2 * sizeof (GLfloat), 0);
    
    glEnableVertexAttribArray (0);
    glEnableVertexAttribArray (1);

    glBindBuffer (GL_ARRAY_BUFFER, 0);
    glBindVertexArray (0);

    //Set OpenGL shader and VAO
    glUseProgram (shaderProgramId);
    glActiveTexture (GL_TEXTURE0);
    glBindTexture (GL_TEXTURE_2D, textureId);
    glBindVertexArray (vao);
}



//Turn on specific output gate
void TurnOnOutputGate (std::vector<Gate>& gateData, bool& redrawSprites, int gateIndex) {
    gateData[gateIndex].gateType = OUTPUTGATEON;
    gateData[gateIndex].isOn = true;
    redrawSprites = true;
}



GLuint getShaderProgramId (const char *vertexFile, const char *fragmentFile) {
    GLuint programId, vertexHandler, fragmentHandler;

    vertexHandler = compileShader (vertexFile, GL_VERTEX_SHADER);
    fragmentHandler = compileShader (fragmentFile, GL_FRAGMENT_SHADER);

    programId = glCreateProgram ();
    glAttachShader (programId, vertexHandler);
    glAttachShader (programId, fragmentHandler);
    glLinkProgram (programId);

    GLint success;
    GLchar infoLog[512];
    glGetProgramiv (programId, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog (programId, 512, 0, infoLog);
        exit (1);
    }

    glDeleteShader (vertexHandler);
    glDeleteShader (fragmentHandler);

    return programId;
}



GLuint compileShader (const GLchar *source, GLuint shaderType) {
    GLuint shaderHandler;

    shaderHandler = glCreateShader (shaderType);
    glShaderSource (shaderHandler, 1, &source, 0);
    glCompileShader (shaderHandler);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv (shaderHandler, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog (shaderHandler, 512, 0, infoLog);
        exit (1);
    };

    return shaderHandler;
}