// NaputseGE-Test project main.go
package main

import "fmt"

var xAxis int
var yAxis int
var characterPosition = []int{1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9}

func callArea() {
	y := 0
	for y <= yAxis {
		x := 0
		for x <= xAxis {
			i := 0
			for i < int(len(characterPosition)) {
				if (x == characterPosition[i]) && (y == characterPosition[i+1]) {
					fmt.Print("X")
				} else {
					fmt.Print("_")
				}
				i += 2
			}
			x++
		}
		fmt.Print("\n")
		y++
	}
}
func main() {
	var userInput int
	fmt.Print("Length?: ")
	fmt.Scan(&userInput)
	xAxis = userInput
	fmt.Print("Width?: ")
	fmt.Scan(&userInput)
	yAxis = userInput
	fmt.Println(xAxis, yAxis)
	callArea()
}
