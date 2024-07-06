#pragma once

#include "PrimitiveTypes.h"

namespace Sigma
{
	namespace id
	{
		using id_type = u32;

		constexpr u32 generation_bits = 8;
		constexpr u32 index_bits = (sizeof(id_type)*8 - generation_bits);
		constexpr id_type generation_mask = (id_type(1) << generation_bits) - 1;
		constexpr id_type index_mask = (id_type(1) << index_bits) - 1;
		constexpr id_type id_mask = id_type(-1);
	
		constexpr id_type is_valid(id_type id)
		{
			return id != id_mask;
		}

		constexpr id_type index(id_type id)
		{
			return id_mask & id;
		}

		constexpr id_type generation(id_type id)
		{
			return (id >> index_bits) & generation_mask;
		}

		constexpr id_type new_generation(id_type id)
		{
			const id_type generation = id::generation(id) + 1;
			return index(id) | (generation << index_bits);
		}

	}
}
