 /*
  * WindowListner.h
  *
  * 3.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include <GL/glew.h>
#include <GL/gl.h> 
#include <GLFW/glfw3.h>

struct WindowListener {
    GLFWkeyfun key_callback;
    GLFWmousebuttonfun mouse_button_callback;
    GLFWcursorposfun cursor_pos_callback;
    GLFWcursorenterfun cursor_enter_callback;
};
