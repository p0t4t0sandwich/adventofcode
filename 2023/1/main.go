package main

import (
	"errors"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func getFirstInt(str string) (string, error) {
	for i := 0; i < len(str); i++ {
		var char string = string(str[i])
		if _, err := strconv.Atoi(char); err == nil {
			return char, nil
		}
	}
	return "", errors.New("no integer found")
}

func getLastInt(str string) (string, error) {
	var revStr string
	for _, i := range str {
		revStr = string(i) + revStr
	}
	return getFirstInt(revStr)
}

func readLines(filename string) ([]string, error) {
	var lines []string
	content, err := os.ReadFile(filename)
	if err != nil {
		return lines, err
	}
	lines = strings.Split(string(content), "\n")
	return lines, err
}

func firstHalf(filename string) {
	lines, err := readLines(filename)
	if err != nil {
		log.Fatal(err)
	}

	var result int
	for _, line := range lines {
		first, _ := getFirstInt(line)
		last, _ := getLastInt(line)
		i, _ := strconv.Atoi(first + last)
		result = result + i
	}

	fmt.Printf("%d", result)
}

func secondHalf(filename string) {}

func main() {
	var part string
	var filename string
	if len(os.Args) > 2 {
		part = os.Args[1]
		filename = os.Args[2]
	} else {
		log.Fatal(errors.New("no filename provided"))
	}

	if part == "1" {
		firstHalf(filename)
	} else if part == "2" {
		secondHalf(filename)
	}
}
