#pragma once

#include "../../Core/Base.h"

#include <string>

namespace Sigma
{
    struct SIGMA_API Tag
    {
        std::string Name = "";

        Tag() = default;
        Tag(const Tag&) = default;
        Tag(const std::string& name);
    };
}