#include "UserInterface.h"
#include <cinder/app/AppBase.h>

UserInterface::UserInterface(EventManager& p_eventManager, GameInfo& p_gameInfo, GameScene& p_gameScene)
	: Manager(), m_eventManager(p_eventManager), m_gameInfo(p_gameInfo), m_gameScene(p_gameScene)
{
	m_gameInfoColor = cinder::ColorA(1, 1, 1, 1);
	m_gameInfoFont = cinder::Font(cinder::app::loadAsset(NORMAL_FONT_PATH), NORMAL_FONT_SIZE);
}


void UserInterface::Update()
{
}

void UserInterface::Draw() const
{
	if (SHOW_GAME_INFO)
		ShowGameInfo();
}

void UserInterface::ShowGameInfo() const
{
	cinder::gl::drawString("MOUSEX : " + std::to_string(GetEventManager().GetMousePosition().x), glm::vec2(10, 10), m_gameInfoColor, m_gameInfoFont);
	cinder::gl::drawString("MOUSEY : " + std::to_string(GetEventManager().GetMousePosition().y), glm::vec2(10, 30), m_gameInfoColor, m_gameInfoFont);


	cinder::gl::drawString("GAME_OBJECTS : " + std::to_string(GameObject::GetGameObjectCounter()) + "/" + std::to_string(GameObject::GetGameObjectTotalCounter()), glm::vec2(10, 50), m_gameInfoColor, m_gameInfoFont);
	cinder::gl::drawString("Delta time : " + std::to_string(GetGameInfo().m_deltaTime), glm::vec2(10, 70), m_gameInfoColor, m_gameInfoFont);

	const bool mouseLeft = GetEventManager().GetEvent("MOUSE_LEFT_DOWN").GetState();
	const bool mouseRight = GetEventManager().GetEvent("MOUSE_RIGHT_DOWN").GetState();
	cinder::gl::drawString("MOUSE_LEFT_DOWN : " + std::to_string(int(mouseLeft)), glm::vec2(10, 90), m_gameInfoColor, m_gameInfoFont);
	cinder::gl::drawString("MOUSE_RIGHT_DOWN : " + std::to_string(int(mouseRight)), glm::vec2(10, 110), m_gameInfoColor, m_gameInfoFont);

	const bool moveUp = GetEventManager().GetEvent("JUMP").GetState();
	const bool moveLeft = GetEventManager().GetEvent("MOVE_LEFT").GetState();
	const bool moveDown = GetEventManager().GetEvent("MOVE_DOWN").GetState();
	const bool moveRight = GetEventManager().GetEvent("MOVE_RIGHT").GetState();
	cinder::gl::drawString("JUMP : " + std::to_string(int(moveUp)), glm::vec2(10, 130), m_gameInfoColor, m_gameInfoFont);
	cinder::gl::drawString("MOVE_LEFT : " + std::to_string(int(moveLeft)), glm::vec2(10, 150), m_gameInfoColor, m_gameInfoFont);
	cinder::gl::drawString("MOVE_DOWN : " + std::to_string(int(moveDown)), glm::vec2(10, 170), m_gameInfoColor, m_gameInfoFont);
	cinder::gl::drawString("MOVE_RIGHT : " + std::to_string(int(moveRight)), glm::vec2(10, 190), m_gameInfoColor, m_gameInfoFont);
}
