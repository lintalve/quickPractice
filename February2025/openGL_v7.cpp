// The view matrix and the projection matrix are constant
// across a draw
uniform mat4 view_matrix;
uniform mat4 projection_matrix;
// The output of the vertex shader (matched to the
// fragment shader)
out VERTEX { vec3 vec4 } vertex;
// Ok, go!
normal; color;
void main(void) {
    // Construct a model-view matrix from the uniform view matrix
    // and the per-instance model matrix.
    mat4 model_view_matrix = view_matrix * model_matrix;
    // Transform position by the model-view matrix, then by the
    // projection matrix.
    gl_Position = projection_matrix * (model_view_matrix * position);
    // Transform the normal by the upper-left-3x3-submatrix of the
    // model-view matrix vertex.
    normal = mat3(model_view_matrix) * normal;
    // Pass the per-instance color through to the fragment shader.
    vertex.color = color;
}
