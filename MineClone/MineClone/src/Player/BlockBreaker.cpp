#include "BlockBreaker.h"

#include "PlayerInfo.h"

#include <iostream>

BlockBreaker::BlockBreaker()
	: m_playerIsBreaking(false),
	m_blockPostion{-1, -1, -1},
	m_heldItemId(BlockId::Air)
{
}

bool BlockBreaker::_break(BlockId heldItemId, glm::ivec3 blockPosition, float hardness)
{
	if (heldItemId != m_heldItemId) {
		m_playerIsBreaking = true;
		m_heldItemId = heldItemId;
		m_startBreakingTimer.restart();
	}
	else if (blockPosition != m_blockPostion) {
		m_playerIsBreaking = true;
		m_blockPostion = blockPosition;
		m_startBreakingTimer.restart();
	}
	else {
		bool animationChanged = false;
		for (int i = 1; i < 12; ++i) {
			if (m_startBreakingTimer.getElapsedTime().asSeconds() < 0.1 * i * hardness) {
				g_PlayerInfo.breakingStage = i;
				animationChanged = true;
				break;
			}
		}
		if (!animationChanged) {
			stopBreaking();
			return true;
		}
	}

	return false;
}

void BlockBreaker::stopBreaking()
{
	m_playerIsBreaking = false;
	m_blockPostion = { -1, -1, -1 };
	g_PlayerInfo.breakingStage = 0;
}