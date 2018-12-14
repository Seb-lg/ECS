//
// Created by seble on 01/11/2018.
//

#pragma once

#include <vector>
#include <unordered_map>
#include <functional>
#include "Entity.hpp"

namespace hidden {
	template <typename T>
	class ListComponent {
	public:
		static ListComponent<T> &get() {
			thread_local static ListComponent<T> listComponent;

			return listComponent;
		}

		template <typename ...Args>
		std::function<void()> addComponent(ID id, Args... args) {
			_map.try_emplace(id, args...);
			_ids.push_back(id);
			std::sort(_ids.begin(), _ids.end());
			return ([id](){
				hidden::ListComponent<T>::get().getComponentMap().erase(id);
				std::remove_if(hidden::ListComponent<T>::get().getIds().begin(), hidden::ListComponent<T>::get().getIds().end(), [id](ID const &d) {
					return 	d == id;
				});
			});
		}

		std::vector<ID> getIdForComponent(std::function<bool(T&)> function) {
			std::vector<ID> ids;

			for (auto map : _map) {
				if (function(*map.second))
					ids.push_back(*map.first);
			}
			return ids;
		}


		std::unordered_map<ID, T> &getComponentMap() {
			return _map;
		}

		std::vector<ID> &getIds() {
			return _ids;
		}

		T &operator[] (ID id) {
			return _map[id];
		}

	private:
		std::unordered_map<ID, T>	_map;
		std::vector<ID>			_ids;
	};
}
