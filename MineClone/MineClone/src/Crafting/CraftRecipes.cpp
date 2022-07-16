#include "CraftRecipes.h"

#include "World/Block/BlockDatabase.h"

const BlockId EMPTY = BlockId::Air;

Recipe::Recipe(ItemStack output)
	: output(output)
{
}

Recipe4::Recipe4(std::array<CraftingElement, 4>&& input, ItemStack output)
	: Recipe(output),
	input(input)
{
}

Recipe9::Recipe9(std::array<CraftingElement, 9>&& input, ItemStack output)
	: Recipe(output),
	input(input)
{
}

bool operator==(const CraftingElement & element1, const BlockId & element2)
{
	if (element1.id == element2) {
		return true;
	}
	else if (BlockDatabase::get().isWoodPlanks(element1.id) && BlockDatabase::get().isWoodPlanks(element2)) {
		return true;
	}
	else {
		return false;
	}
}

bool operator==(const BlockId & element2, const CraftingElement & element1)
{
	return element1 == element2;
}

const std::vector<const Recipe4*> Recipe4::ALL_RESIPES
{
	&Recipe4::OAK_PLANKS, &Recipe4::BIRCH_PLANKS, &Recipe4::PALM_PLANKS, &Recipe4::SPRUCE_PLANKS,
	&Recipe4::STICK, &Recipe4::CRAFTING_TABLE, &Recipe4::TORCHES
};

const Recipe4 Recipe4::OAK_PLANKS(
	{ BlockId::OakBark, EMPTY,
	EMPTY, EMPTY },
	// result
	{ BlockId::OakPlanks, 4 }
);
const Recipe4 Recipe4::BIRCH_PLANKS(
	{ BlockId::BirchBark, EMPTY,
	EMPTY, EMPTY },
	// result
	{ BlockId::BirchPlanks, 4 }
);
const Recipe4 Recipe4::PALM_PLANKS(
	{ BlockId::PalmBark, EMPTY,
	EMPTY, EMPTY },
	// result
	{ BlockId::PalmPlanks, 4 }
);
const Recipe4 Recipe4::SPRUCE_PLANKS(
	{ BlockId::SpruceBark, EMPTY,
	EMPTY, EMPTY },
	// result
	{ BlockId::SprucePlanks, 4 }
);
