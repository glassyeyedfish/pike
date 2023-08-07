package src

type LineCol struct {
	line int
	col  int
}

func GenLineCol(buf []byte) []LineCol {
	buf_l := len(buf)
	col := 1
	line := 1
	var lc []LineCol

	for buf_i := 0; buf_i < buf_l; buf_i++ {
		lc = append(lc, LineCol{
			line: line,
			col:  col,
		})
		if buf[buf_i] == '\n' {
			col = 1
			line++
		} else {
			col++
		}
	}

	return lc
}
