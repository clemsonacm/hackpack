#!/usr/bin/env bats


@test "Set example code matches Sample Output" {
	run ./knapsack.exe < knapsack.in
	[ "$status" -eq 0 ]
	[ "$output" = "$(cat knapsack.out)" ]
}
