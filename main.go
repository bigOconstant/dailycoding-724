package main

import (
	"fmt"
	"strconv"
)

type Btree struct {
	Val   string
	Left  *Btree
	Right *Btree
}

func newBtree(val string) *Btree {
	retVal := new(Btree)
	retVal.Val = val
	retVal.Left = nil
	retVal.Right = nil
	return retVal
}

func (t *Btree) evaluate() int {
	var retVal int
	switch t.Val {
	case "*":
		retVal = t.Left.evaluate() * t.Right.evaluate()
		break
	case "+":
		retVal = t.Left.evaluate() + t.Right.evaluate()
		break

	case "-":
		retVal = t.Left.evaluate() - t.Right.evaluate()
		break
	case "/":
		retVal = t.Left.evaluate() / t.Right.evaluate()
		break

	default:
		i, _ := strconv.Atoi(t.Val)
		retVal = i
		break
	}

	return retVal

}

func main() {
	var root = newBtree("*")
	root.Left = newBtree("+")
	root.Right = newBtree("+")
	root.Left.Left = newBtree("3")
	root.Left.Right = newBtree("2")
	root.Right.Right = newBtree("5")
	root.Right.Left = newBtree("4")

	fmt.Println("answer:", root.evaluate())
}
