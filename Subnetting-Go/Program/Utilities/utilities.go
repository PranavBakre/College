package Utilities

type Myint int

func (temp Myint) InRange(min, max Myint) bool {
	if temp >= min && temp <= max {
		return true
	}
	return false
}

func Size(temp []byte) int {
	var count = 0
	for _, oct := range temp {
		if oct != 0 {
			count++
		}
	}
	return count
}

func IntToByteArray(i int) []byte {

	var subnetnoBin = make([]byte, 0, 4)

	for i != 0 {
		n := len(subnetnoBin)
		subnetnoBin = subnetnoBin[0 : n+1]
		subnetnoBin[n] = byte(i % 256)
		i = i / 256
	}
	return Reverse(subnetnoBin)

}

func Reverse(temp []byte) []byte {
	rev := make([]byte, 4)
	var i = 0
	for _, octtemp := range temp {
		if octtemp != 0 {
			rev[3-i] = octtemp

		}
		i++
	}
	/*for i=0;i<4 && len(rev)>i;i++ {
		if rev[i]==0 {
			rev =rev[i+1:]

		}
	}*/
	return rev
}
