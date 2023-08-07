package src

import (
	"fmt"
	"log"
	"regexp"
)

const (
	TOKEN_LPAREN = iota
	TOKEN_RPAREN
	TOKEN_NEWLINE

	TOKEN_PRINTLN

	TOKEN_ID

	TOKEN_STR

	TOKEN_WS
)

type Token struct {
	kind int
	text string
	line int
	col  int
	len  int
}

type FindFunc func([]byte) []byte

var find []FindFunc = []FindFunc{
	regexp.MustCompile("^[(]").Find,
	regexp.MustCompile("^[)]").Find,
	regexp.MustCompile("^[\n]").Find,
	regexp.MustCompile("^[a-zA-Z][a-zA-Z0-9_]*").Find,
	regexp.MustCompile("^\".*\"").Find,
	regexp.MustCompile("^println").Find,
	regexp.MustCompile("^[ \t]+").Find,
}

func Tokenize(buf []byte, lc []LineCol) []Token {
	i := 0
	l := len(lc)

	find_l := len(find)
	suc := false

	var match []byte
	var tokens []Token

	for i < l {
		for find_i := 0; find_i < find_l; find_i++ {
			match = find[find_i](buf[i:])
			if match != nil {
				match_l := len(match)
				if find_i != TOKEN_WS {
					tokens = append(tokens, Token{
						kind: find_i,
						text: string(match),
						line: lc[i].line,
						col:  lc[i].col,
						len:  match_l,
					})
				}
				i += match_l
				suc = true
				break
			}
		}

		if !suc {
			log.Fatal("Failed to tokenize!")
		}
		suc = false
	}

	return tokens
}

func PrintlnTokens(tokens []Token) {
	fmt.Print("[")
	if len(tokens) > 0 {
		fmt.Printf("'%s' (%d:%d:%d)", tokens[0].text, tokens[0].line, tokens[0].col, tokens[0].len)
	}
	for _, t := range tokens[1:] {
		fmt.Printf(", '%s' (%d:%d:%d)", t.text, t.line, t.col, t.len)
	}
	fmt.Print("]\n")
}

func PrintlnSource(tokens []Token) {
	for _, t := range tokens[:] {
		fmt.Printf("%s", t.text)
	}
	fmt.Print("\n")
}