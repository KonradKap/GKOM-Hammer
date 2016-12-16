#include "Texture.h"

#include <stdexcept>
#include <memory>

#include <SOIL/SOIL.h>

#include "commons/ScopeBind.h"

Texture::Texture() : 
        texture() {
}

Texture::Texture(const char* path) :
        texture() {

    int width;
    int height;
    std::unique_ptr<unsigned char, decltype(&SOIL_free_image_data)> image{
        SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGBA), SOIL_free_image_data};
    if(image == nullptr)
        throw std::runtime_error("Texture load failed");

    glGenTextures(1, &texture);
    const auto guard = ScopeBind::guard(*this);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.get());
    glGenerateMipmap(GL_TEXTURE_2D);
    
}

Texture::Texture(Texture&& t) :
        Texture() {
    
    swap(*this, t);
}

Texture::~Texture() {
    glDeleteTextures(1, &texture);
}

void swap(Texture& lhs, Texture& rhs) {
    std::swap(lhs.texture, rhs.texture);
}

GLuint Texture::get_id() const {
    return GL_TEXTURE0;
}
