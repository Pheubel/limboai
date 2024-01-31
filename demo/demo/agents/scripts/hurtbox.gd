#*
#* hurtbox.gd
#* =============================================================================
#* Copyright 2021-2024 Serhii Snitsaruk
#*
#* Use of this source code is governed by an MIT-style
#* license that can be found in the LICENSE file or at
#* https://opensource.org/licenses/MIT.
#* =============================================================================
#*
class_name Hurtbox
extends Area2D
## Area that registers damage.


@export var health: Health


func _init() -> void:
	collision_layer = 4
	collision_mask = 0


func take_damage(amount: float, source: Area2D) -> void:
	if source.owner == owner:
		# Don't damage yourself.
		return
	health.take_damage(amount)