package main

import (
	"io"
	"log"
	"os"
	"regexp"
	"strings"
)

const (
	TOKENIZING_CHAR = iota
	TOKENIZING_ID
)

func Tokenize(f *os.File) []string {
	buf := make([]byte, 1)
	var token strings.Builder
	var tokens []string
	curr_state := TOKENIZING_CHAR
	prev_state := TOKENIZING_CHAR

	isSpecial := regexp.MustCompile("=|:").Match
	isAlpha := regexp.MustCompile("[a-zA-Z]").Match
	isId := regexp.MustCompile("[a-zA-Z_]").Match

	_, err := f.Read(buf)
	for err != io.EOF {
		if err != nil {
			log.Fatal(err)
			os.Exit(1)
		}

		prev_state = curr_state

		switch curr_state {
		case TOKENIZING_CHAR:
			if isSpecial(buf) {
				token.WriteByte(buf[0])
				tokens = append(tokens, token.String())
				token.Reset()
			} else if isAlpha(buf) {
				curr_state = TOKENIZING_ID
			}
		case TOKENIZING_ID:
			if isId(buf) {
				token.WriteByte(buf[0])
			} else {
				tokens = append(tokens, token.String())
				token.Reset()
				curr_state = TOKENIZING_CHAR
			}
		}

		if prev_state == curr_state {
			_, err = f.Read(buf)
		}
	}

	return tokens
}
