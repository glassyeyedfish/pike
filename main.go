package main

import (
	"fmt"
	"log"
	"os"
)

func main() {
	// Open the source file.
	f, err := os.Open("test.pk")
	if err != nil {
		log.Fatal(err)
		os.Exit(1)
	}

	tokens := Tokenize(f)

	fmt.Printf("%v\n", tokens)

	defer f.Close()
}
