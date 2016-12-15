#pragma once

#include <GL/glew.h>

class Texture {
        friend class ScopeBindTexture;
    public:
        Texture(const char* path);
        Texture(const Texture& t) = delete;
        Texture(Texture&& t);
        Texture& operator=(const Texture& t) = delete;
        ~Texture();

        friend void swap(Texture& lhs, Texture& rhs);

        GLuint get_id() const;
    private:
        static int index;
        Texture();

        GLuint texture;
        GLuint texture_id;
};
