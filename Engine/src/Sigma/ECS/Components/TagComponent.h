#pragma once

#include <string>

namespace Sigma
{
    struct TagComponent
    {
        std::string Name = "";

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& name);
    };
}