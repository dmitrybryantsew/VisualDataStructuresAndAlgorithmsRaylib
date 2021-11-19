#include "timer.hpp"
namespace Simple2DEngine{
		Timer* Timer::s_instance = nullptr;

		Timer* Timer::GetInstance()
		{
			if (s_instance == nullptr)
			{
				s_instance = new Timer();
			}
			return s_instance;
		}

		void Timer::FreeTimer() {
			delete s_instance;
			s_instance = nullptr;
		}

		Timer::Timer()
		{
			ResetTimer();
			m_timeScale = 1.0f;
			m_deltaTime = std::chrono::duration<float>(0.0f);
		}
		Timer::~Timer()
		{
            FreeTimer();
		}

		void Timer::ResetTimer() {
			m_startTime = std::chrono::system_clock::now();
		}

		float Timer::GetDeltaTime()
		{
			return m_deltaTime.count();
		}

		void Timer::SetTimeScale(float t /*= 1.0f*/)
		{
			m_timeScale = t;
		}
		float Timer::GetTimeScale()
		{
			return m_timeScale;
		}

		void Timer::Tick()
		{
			m_deltaTime = std::chrono::system_clock::now() - m_startTime;
		}

}
