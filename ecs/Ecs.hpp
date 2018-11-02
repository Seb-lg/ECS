//
// Created by seble on 01/11/2018.
//

#ifndef ECS_ECS_HPP
#define ECS_ECS_HPP

#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include "ListComponent.hpp"

namespace ecs{
    class Ecs {
    public:

        Ecs() {}

        static Ecs &get() {
        	static Ecs ecs;

        	return ecs;
        }

        template <typename T>
        static hidden::ListComponent<T> &get() {
		return hidden::ListComponent<T>::get();
        }

        template<typename T, typename ...Args>
        void addComponent(ID id, Args... args){
            _deleteIds[id].emplace_back(hidden::ListComponent<T>::get().addComponent(id, args...));
        }

        template <typename T>
        std::vector<T> &getComponentList(){
            return hidden::ListComponent<T>::get().getComponentList();
        }

        void deleteId(ID id) {
            for (auto &deleting : _deleteIds[id])
                deleting();
            _deleteIds[id].clear();
        }

        template <typename ...Args>
        std::vector<ID> getFilter() {
        	std::vector<ID> valableId;
		for (auto it = _deleteIds.begin(); it != _deleteIds.end(); ++it)
		{
        		if (idHasComponent<Args...>(it->first))
				valableId.emplace_back(it->first);
		}
		return (valableId);
        }

	template <typename ...Args>
	bool idHasComponent(ID id) {
	    isIn<Args...> isin;
	    return (isin(id));
	}

    private:
        std::unordered_map<ID, std::vector<std::function<void()>>>  _deleteIds;

        template <typename ...Ts>
        struct isIn {
        	bool operator() (ID id);
        };

        template <typename T>
	struct isIn<T> {
		bool operator() (ID id) {
			auto &vec = hidden::ListComponent<T>::get().getIdsList();
			return ((std::find(vec.begin(), vec.end(), id) != vec.end()));
		}
	};

	template <typename T, typename ...Args>
	struct isIn<T, Args...> {
		bool operator() (ID id) {
			isIn<Args...> isin;
			auto &vec = hidden::ListComponent<T>::get().getIdsList();
			return ((std::find(vec.begin(), vec.end(), id) != vec.end()) && isin(id));
		}
	};

    };
}


#endif //ECS_ECS_HPP
