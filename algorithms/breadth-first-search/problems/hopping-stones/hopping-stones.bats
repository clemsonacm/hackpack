#!/usr/bin/env bats

@test "General test of hopping-stones" {
	run ./hopping-stones.exe < hopping-stones.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat hopping-stones.out)" ]
}

