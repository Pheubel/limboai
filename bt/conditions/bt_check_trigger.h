/**
 * bt_check_trigger.h
 * =============================================================================
 * Copyright 2021-2023 Serhii Snitsaruk
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 * =============================================================================
 */

/* bt_check_trigger.h */

#ifndef BT_CHECK_TRIGGER_H
#define BT_CHECK_TRIGGER_H

#include "bt_condition.h"

#include "core/object/object.h"
#include "core/string/ustring.h"

#include "core/object/class_db.h"

class BTCheckTrigger : public BTCondition {
	GDCLASS(BTCheckTrigger, BTCondition);

private:
	String variable;

protected:
	static void _bind_methods();

	virtual String _generate_name() const override;
	virtual int _tick(double p_delta) override;

public:
	void set_variable(String p_variable);
	String get_variable() const { return variable; }

	virtual PackedStringArray get_configuration_warnings() const override;
};

#endif // BT_CHECK_TRIGGER