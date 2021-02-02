package main

import "fmt"


func facto (i int) int {
	if i==0 {
		return 1
	}
	return i*facto(i-1)
}



func main() {
	var n int
	fmt.Println("Enter the number")
	fmt.Scanln(&n)
	var factorial=facto(n)
	fmt.Println("Factorial of ",n," is ",factorial)

}