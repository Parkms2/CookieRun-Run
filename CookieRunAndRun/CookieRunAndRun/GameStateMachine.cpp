#include"GameStateMachine.h"

void GameStateMachine::firstState() {
	m_gameStates.push_back(MenuState::Instance());
	m_gameStates.back()->onEnter();
	m_currentState = MenuState::Instance();
}
void GameStateMachine::pushState(GameState *pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	changeState(m_prevState);
}
void GameStateMachine::changeState(GameState *pState)
{
	if (pState != NULL)
	{
		if (m_currentState != NULL) {
			m_prevState = m_currentState;
			m_currentState->onExit();
		}
		m_currentState = pState;
		m_currentState->onEnter();
	}
}
void GameStateMachine::PopupState(GameState *pState)	{
	if (pState != NULL)	{
		pState->onEnter();
	}
}
void GameStateMachine::finishPopupState(GameState *pState) {
	if (pState != NULL) {
		pState->onExit();
	}
}
void GameStateMachine::update()
{
	if (m_currentState != NULL)
		m_currentState->update();
}

void GameStateMachine::render()
{
	if (m_currentState != NULL)
		m_currentState->render();
}