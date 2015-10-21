#!/usr/bin/env bats

@test "test remove min with 2 element" {
	run ./heap.exe < heap1.in
	[ "$output" == '1, 2, ' ]
	[ $status -eq 0 ]
}
@test "test remove min with 2 elments reverse" {
	run ./heap.exe < heap2.in
	[ "$output" == '1, 2, ' ]
	[ $status -eq 0 ]
}
@test "test remove min 3 elements" {
	run ./heap.exe < heap3.in
	[ "$output" == '1, 2, 3, ' ]
	[ $status -eq 0 ]
}

@test "test remove min 3 elements out of order" {
	run ./heap.exe < heap7.in
	[ "$output" == '1, 2, 3, ' ]
	[ $status -eq 0 ]
}
@test "test remove min 6 elements in order" {
	run ./heap.exe < heap4.in
	[ "$output" == '1, 2, 3, 4, 5, 6, ' ]
	[ $status -eq 0 ]
}
@test "test remove min 6 elements in reverse" {
	run ./heap.exe < heap5.in
	[ "$output" == '1, 2, 3, 4, 5, 6, ' ]
	[ $status -eq 0 ]
}
@test "test remove min 6 elements in arbitary" {
	run ./heap.exe < heap6.in
	[ "$output" == '1, 2, 3, 4, 5, 6, ' ]
	[ $status -eq 0 ]
}
@test "large random test remove min" {
	run ./heap.exe < heap8.in
	[ "$output" == "$(cat heap8.out)" ]
	[ $status -eq 0 ]
}
