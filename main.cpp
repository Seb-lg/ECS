#include <iostream>
#include <Time.hpp>
#include <thread>
#include <list>
#include <cmath>
#include "ecs/Ecs.hpp"
#include "Workers/ThreadPool.hpp"

int main() {
	std::cout << "Hello, World!" << std::endl;
	ID id;

	long time;
	auto &ecs = ecs::Ecs::get();

	for (int i = 0; i < 1000; i++) {
		id = ecs::entity::Entity::getId();
		ecs.addComponent<int>(id, i);
	}

	int x = 0;

	auto ids = ecs.filter<int>();
	auto ints = ecs.getComponentMap<int>();
	time = ecs::Time::get(TimeUnit::MilliSeconds);

	for (auto id : ids) {
		for (auto od : ids) {
			std::this_thread::sleep_for(std::chrono::nanoseconds(100));
		}
	}

	std::cout << ecs::Time::get(TimeUnit::MilliSeconds) - time << " " << x << std::endl;
	x = 0;

	time = ecs::Time::get(TimeUnit::MilliSeconds);

	ThreadPool<std::pair<ID,ID>> pool([&x, &ints](std::pair<ID, ID> check) {
		std::this_thread::sleep_for(std::chrono::nanoseconds(100));
	}, 4);

	for (auto id : ids) {
		pool.lockWork();
		for (auto od : ids) {
			pool.addTask(std::pair<ID, ID>(id, od));
			//x++;
		}
		pool.unlockWork();
		while (!pool.isDone());
	}
	std::cout << ecs::Time::get(TimeUnit::MilliSeconds) - time << " " << x << std::endl;

	return 0;
}