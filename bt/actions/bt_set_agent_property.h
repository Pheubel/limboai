/**
 * bt_set_agent_property.h
 * =============================================================================
 * Copyright 2021-2023 Serhii Snitsaruk
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 * =============================================================================
 */

#ifndef BT_SET_AGENT_PROPERTY_H
#define BT_SET_AGENT_PROPERTY_H

#include "modules/limboai/bt/actions/bt_action.h"

#include "modules/limboai/blackboard/bb_param/bb_variant.h"

#include "core/object/class_db.h"
#include "core/object/object.h"

class BTSetAgentProperty : public BTAction {
	GDCLASS(BTSetAgentProperty, BTAction);

private:
	StringName property;
	Ref<BBVariant> value;

protected:
	static void _bind_methods();

	virtual String _generate_name() const override;
	virtual int _tick(double p_delta) override;

public:
	virtual PackedStringArray get_configuration_warnings() const override;

	void set_property(StringName p_prop);
	StringName get_property() const { return property; }

	void set_value(Ref<BBVariant> p_value);
	Ref<BBVariant> get_value() const { return value; }
};

#endif // BT_SET_AGENT_PROPERTY