#!/usr/bin/env bats

@test "36 to binary 100100" {
    result="$(bin/Debug/base 36 2)"
    [ ${result} == "100100" ]
}

@test "128 to octal 200" {
    result="$(bin/Debug/base 128 8)"
    [ ${result} == "200" ]
}

@test "1024 to hex 400" {
    result="$(bin/Debug/base 1024 16)"
    [ ${result} == "400" ]
}

@test "Binary 100100 to decimal 36" {
    result="$(bin/Debug/base 100100 2 10)"
    [ ${result} == "36" ]
}

@test "Binary 100100 to octal 44" {
    result="$(bin/Debug/base 100100 2 8)"
    [ ${result} == "44" ]
}

@test "Hex ff to decimal 255" {
    result="$(bin/Debug/base ff 16 10)"
    [ ${result} == "255" ]
}

@test "Hex ff to octal 173" {
    result="$(bin/Debug/base ff 16 8)"
    [ ${result} == "377" ]
}