package src

import (
	"fmt"
	"log"
	"os"
)

func Pike() {
	// 1. Copy the contents of the file into a byte buffer.
	if len(os.Args) != 2 {
		fmt.Printf("Usage: %s [SOURCE FILE]\n", os.Args[0])
		os.Exit(1)
	}

	src, err := os.Open(os.Args[1])
	if err != nil {
		log.Fatal(err)
	}
	defer src.Close()

	var info os.FileInfo
	info, err = src.Stat()
	if err != nil {
		log.Fatal(err)
	}

	l := info.Size()
	buf := make([]byte, l)
	_, err = src.Read(buf)
	if err != nil {
		log.Fatal(err)
	}

	// 2. Generate the line-col data for each byte
	lc := GenLineCol(buf)

	// 3. Convert the byte buffer and line-col data into tokens
	tokens := Tokenize(buf, lc)

	// PrintlnSource(tokens)
	PrintlnTokens(tokens)
}
