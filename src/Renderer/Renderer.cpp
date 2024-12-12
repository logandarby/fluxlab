#include "Renderer.h"

#include "Model/Model.h"
#include "core/Core.h"
#include "core/GLCore.h"

void Renderer::clear() { GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)); }

void Renderer::draw(const VertexArray& vao, const IndexBuffer& ib, const Shader& shader) {
    shader.bind();
    vao.bind();
    ib.bind();
    GL_CALL(
        glDrawElements(GL_TRIANGLES, static_cast<int>(ib.getCount()), GL_UNSIGNED_INT, nullptr));
}

void Renderer::getViewport(int x, int y, int width, int height) {
    GL_CALL(glViewport(x, y, width, height));
}
void Renderer::setDepthTest(bool enabled) {
    if (enabled) {
        GL_CALL(glEnable(GL_DEPTH_TEST));
    } else {
        GL_CALL(glDisable(GL_DEPTH_TEST));
    }
}

unsigned int Renderer::getMaxTextureSlots() {
    int maxTextureSlots;
    GL_CALL(glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureSlots));
    return static_cast<unsigned int>(maxTextureSlots);
}