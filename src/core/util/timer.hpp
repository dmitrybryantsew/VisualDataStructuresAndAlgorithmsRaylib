#ifndef TIMER_HPP
#define TIMER_HPP
#include <chrono>
namespace Simple2DEngine{
		class Timer
		{
		public:
			static Timer* GetInstance();
			static void FreeTimer();

			void ResetTimer();
			float GetDeltaTime();
			void SetTimeScale(float t = 1.0f);
			float GetTimeScale();
			void Tick();

		private:
			static Timer* s_instance;
			std::chrono::system_clock::time_point m_startTime;
			std::chrono::duration<float> m_deltaTime;
			float m_timeScale;

			Timer();
			~Timer();
		};
	}

#endif TIMER_HPP