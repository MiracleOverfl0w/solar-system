#ifndef OBJECT_MODULE_H //OBJECT_MODULE_H
#define OBJECT_MODULE_H

#include "glad.h"
#include "khrplatform.h"
#include <GLFW/glfw3.h>
#include <bits/stdc++.h>

using   std::cout,
        std::cerr,
        std::endl;

using   std::string;

std::pair<uint32_t,uint32_t> createTriangle(const GLfloat* vertices, size_t __size__);
#endif //OBJECT_MODULE_H
