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

const Recipe4 Recipe4::STICK(
	{ BlockId::OakPlanks, BlockId::OakPlanks,
	EMPTY, EMPTY },
	// result
	{ BlockId::Stick, 4 }
);

const Recipe4 Recipe4::CRAFTING_TABLE(
	{ BlockId::OakPlanks, BlockId::OakPlanks,
	BlockId::OakPlanks, BlockId::OakPlanks },
	// result
	{ BlockId::CraftingTable, 1 }
);

const Recipe4 Recipe4::TORCHES(
	{ BlockId::Coal, BlockId::Air,
	BlockId::Stick, BlockId::Air },
	// result
	{ BlockId::Glowstone, 4 }
);


const std::vector<const Recipe9*> Recipe9::ALL_RESIPES
{
	&Recipe9::WOODEN_SWORD, &Recipe9::WOODEN_PICKAXE, &Recipe9::WOODEN_SHOVEL, &Recipe9::WOODEN_AXE1, &Recipe9::WOODEN_AXE2,
	&Recipe9::STONE_SWORD, &Recipe9::STONE_PICKAXE, &Recipe9::STONE_SHOVEL, &Recipe9::STONE_AXE1, &Recipe9::STONE_AXE2,
	&Recipe9::IRON_SWORD, &Recipe9::IRON_PICKAXE, &Recipe9::IRON_SHOVEL, &Recipe9::IRON_AXE1, &Recipe9::IRON_AXE2,
	&Recipe9::GOLD_SWORD, &Recipe9::GOLD_PICKAXE, &Recipe9::GOLD_SHOVEL, &Recipe9::GOLD_AXE1, &Recipe9::GOLD_AXE2,
	&Recipe9::DIAMOND_SWORD, &Recipe9::DIAMOND_PICKAXE, &Recipe9::DIAMOND_SHOVEL, &Recipe9::DIAMOND_AXE1, &Recipe9::DIAMOND_AXE2
};

const Recipe9 Recipe9::WOODEN_SWORD(
	{ EMPTY, BlockId::OakPlanks, EMPTY,
	EMPTY, BlockId::OakPlanks, EMPTY,
	EMPTY, BlockId::Stick, EMPTY, },
	// result
	{ BlockId::WoodenSword, 1 }
);
const Recipe9 Recipe9::WOODEN_PICKAXE(
	{ BlockId::OakPlanks, BlockId::OakPlanks, BlockId::OakPlanks,
	EMPTY, BlockId::Stick, EMPTY,
	EMPTY, BlockId::Stick, EMPTY, },
	// result
	{ BlockId::WoodenPickaxe, 1 }
);
const Recipe9 Recipe9::WOODEN_SHOVEL(
	{ EMPTY, BlockId::OakPlanks, EMPTY,
	EMPTY, BlockId::Stick, EMPTY,
	EMPTY, BlockId::Stick, EMPTY, },
	// result
	{ BlockId::WoodenShovel, 1 }
);
const Recipe9 Recipe9::WOODEN_AXE1(
	{ BlockId::OakPlanks, BlockId::OakPlanks, EMPTY,
	BlockId::OakPlanks, BlockId::Stick, EMPTY,
	EMPTY, BlockId::Stick, EMPTY, },
	// result
	{ BlockId::WoodenAxe, 1 }
);
const Recipe9 Recipe9::WOODEN_AXE2(
	{ EMPTY, BlockId::OakPlanks, BlockId::OakPlanks,
	EMPTY, BlockId::Stick, BlockId::OakPlanks,
	EMPTY, BlockId::Stick, EMPTY, },
	// result
	{ BlockId::WoodenAxe, 1 }
);
const Recipe9 Recipe9::STONE_SWORD(
	{ EMPTY, BlockId::Cobblestone, EMPTY,
	EMPTY, BlockId::Cobblestone, EMPTY,
	EMPTY, BlockId::Stick, EMPTY, },
	// result
	{ BlockId::StoneSword, 1 }
);
const Recipe9 Recipe9::STONE_PICKAXE(
	{ BlockId::Cobblestone, BlockId::Cobblestone, BlockId::Cobblestone,
	EMPTY, BlockId::Stick, EMPTY,
	EMPTY, BlockId::Stick, EMPTY, },
	// result
	{ BlockId::StonePickaxe, 1 }
);
const Recipe9 Recipe9::STONE_SHOVEL(
	{ EMPTY, BlockId::Cobblestone, EMPTY,
	EMPTY, BlockId::Stick, EMPTY,
	EMPTY, BlockId::Stick, EMPTY, },
	// result
	{ BlockId::StoneShovel, 1 }
);
const Recipe9 Recipe9::STONE_AXE1(
	{ BlockId::Cobblestone, BlockId::Cobblestone, EMPTY,
	BlockId::Cobblestone, BlockId::Stick, EMPTY,
	EMPTY, BlockId::Stick, EMPTY, },
	// result
	{ BlockId::StoneAxe, 1 }
);
const Recipe9 Recipe9::STONE_AXE2(
	{ EMPTY, BlockId::Cobblestone, BlockId::Cobblestone,
	EMPTY, BlockId::Stick, BlockId::Cobblestone,
	EMPTY, BlockId::Stick, EMPTY, },
	// result
	{ BlockId::StoneAxe, 1 }
);
