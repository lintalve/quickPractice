GLuint buffer;
FILE * f;
size_t filesize;
// Open a file and find its size
f = fopen("data.dat", "rb");
fseek(f, 0, SEEK_END);
filesize = ftell(f);
fseek(f, 0, SEEK_SET);
// Create a buffer by generating a name and binding it to a buffer
// binding point- GL_COPY_WRITE_BUFFER here (because the binding means
// nothing in this example).
glGenBuffers(1, &buffer);
glBindBuffer(GL_COPY_WRITE_BUFFER, buffer);
// Allocate the data store for the buffer by passing NULL for the
// data parameter.
glBufferData(GL_COPY_WRITE_BUFFER, (GLsizei)filesize, NULL, GL_STATIC_DRAW);
// Map the buffer...
void* data = glMapBuffer(GL_COPY_WRITE_BUFFER, GL_WRITE_ONLY);
// Read the file into the buffer.
fread(data, 1, filesize, f);
// Okay, done, unmap the buffer and close the file.
glUnmapBuffer(GL_COPY_WRITE_BUFFER);
fclose(f);
