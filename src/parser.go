package src

import (
	"errors"
	"log"
)

const (
	TREE_TERM = iota
	TREE_PRINTLN
)

type ParseTree struct {
	kind     int
	token    Token
	children []ParseTree
}

type Parser struct {
	curr   Token
	prev   Token
	tokens []Token
	index  int
	len    int
}

func (p *Parser) getNextToken() {
	p.index += 1
	p.prev = p.curr
	p.curr = p.tokens[p.index]
}

func (p *Parser) parsePrintln() (ParseTree, error) {
	tree := ParseTree{
		kind:     TREE_PRINTLN,
		token:    p.curr,
		children: make([]ParseTree, 0),
	}

	// Eat println, (
	p.getNextToken()
	p.getNextToken()

	if p.curr.kind != TOKEN_STR {
		return ParseTree{}, errors.New("expected STRING at PRINTLN")
	}
	tree.children = append(tree.children, ParseTree{
		kind:     TREE_TERM,
		token:    p.curr,
		children: nil,
	})

	// Eat STR, ), NEWLINE
	p.getNextToken()
	p.getNextToken()
	p.getNextToken()

	return tree, nil
}

func (p *Parser) Parse(tokens []Token) []ParseTree {
	p.curr = tokens[0]
	p.prev = tokens[0]
	p.tokens = tokens
	p.index = 0
	p.len = len(tokens)

	trees := make([]ParseTree, 0)

	running := true
	for running {
		switch p.curr.kind {
		case TOKEN_PRINTLN:
			tree, err := p.parsePrintln()
			if err != nil {
				log.Fatal(err)
			}
			trees = append(trees, tree)
		case TOKEN_EOF:
			running = false
		default:
			log.Fatal("Oh snap!")
		}
	}

	return trees
}
