//Since I'd like to use and apply what I've written
//here is the method to convert my math objects into
//OpenGL standard math objects

#include <glm/glm.hpp>  // GLM library for OpenGL math

struct Vector2 {
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {}

    // Method to convert to OpenGL vector (glm::vec2)
    glm::vec2 toGLM() const {
        return glm::vec2(x, y);
    }
};

int main() {
    Vector2 myVec(1.0f, 2.0f);
    
    // Convert to OpenGL-compatible glm::vec2
    glm::vec2 glmVec = myVec.toGLM();
    
    // Now you can use glmVec in OpenGL calls
}

