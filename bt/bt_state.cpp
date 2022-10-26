/* bt_state.cpp */

#include "bt_state.h"
#include "core/class_db.h"
#include "core/variant.h"
#include "modules/limboai/bt/bt_task.h"
#include "modules/limboai/limbo_state.h"

void BTState::_setup() {
	root_task = behavior_tree->instance(get_agent(), get_blackboard());
}

void BTState::_exit() {
	root_task->cancel();
}

void BTState::_update(float p_delta) {
	int status = root_task->execute(p_delta);
	if (status == BTTask::SUCCESS) {
		get_root()->dispatch("success", Variant());
	} else if (status == BTTask::FAILURE) {
		get_root()->dispatch("failure", Variant());
	}
}

void BTState::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_behavior_tree", "p_value"), &BTState::set_behavior_tree);
	ClassDB::bind_method(D_METHOD("get_behavior_tree"), &BTState::get_behavior_tree);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "behavior_tree", PROPERTY_HINT_RESOURCE_TYPE, "BehaviorTree"), "set_behavior_tree", "get_behavior_tree");
}

BTState::BTState() {
}
