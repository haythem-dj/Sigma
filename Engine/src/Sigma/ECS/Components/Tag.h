#pragma once

#include <string>

namespace Sigma
{
    struct Tag
    {
        std::string Name = "";

        Tag() = default;
        Tag(const Tag&) = default;
        Tag(const std::string& name);
    };
}