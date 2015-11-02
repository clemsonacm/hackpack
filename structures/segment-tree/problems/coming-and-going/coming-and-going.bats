#!/usr/bin/env bats

@test "General test of coming-and-going" {
	run ./coming-and-going.exe < coming-and-going.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat coming-and-going.out)" ]
}
