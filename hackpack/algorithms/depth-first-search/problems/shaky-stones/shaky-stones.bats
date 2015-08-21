#!/usr/bin/env bats

@test "General test of shaky-stones" {
	run ./shaky-stones.exe < shaky-stones.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat shaky-stones.out)" ]
}

