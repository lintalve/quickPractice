// Vertex positions
static const GLfloat positions[] = {-1.0f,-1.0f, 0.0f, 1.0f, 1.0f,-1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,-1.0f, 1.0f, 0.0f, 1.0f };
// Vertex colors
static const GLfloat colors[] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, };
// The buffer object
GLuint buffer;
// Reserve a name for the buffer object.
glGenBuffers(1, &buffer);
// Bind it to the GL_ARRAY_BUFFER target.
glBindBuffer(GL_ARRAY_BUFFER, buffer);
// Allocate space for it (sizeof(positions) + sizeof(colors)).
glBufferData(GL_ARRAY_BUFFER, sizeof(positions) + sizeof(colors), NULL, GL_STATIC_DRAW);
// Put "positions" at offset zero in the buffer.
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(positions), positions);
// target // total size // no data // usage // target // offset // size // data // Put "colors" at an offset in the buffer equal to the filled size of // the buffer so far- i.e., sizeof(positions).
glBufferSubData(GL_ARRAY_BUFFER, sizeof(positions), sizeof(colors), colors);
// target // offset // size // data // Now "positions" is at offset 0 and "colors" is directly after it // in the same buffer.
