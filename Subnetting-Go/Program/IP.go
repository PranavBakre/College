package Program

import (
	"errors"
	"strconv"
	"strings"
	"subnetting-Go/Program/Utilities"
	//Uncomment below line for Linux- Commenting the above line
	//"./Utilities"
)

type IpAddress struct {
	Octet       []byte
	DefaultMask []byte
	MaskInt     int
	Class       rune
}

//Function Name :	Init
//Purpose		:   Initializes the structure IpAddress for operations
//Call			:	IpAddress_Object.Init()
func (Ip *IpAddress) Init() {
	Ip.Octet = make([]byte, 4)
	Ip.DefaultMask = make([]byte, 4)

}

//Function Name :	AcceptIpAddress
//Purpose		:	Accept IP Address from argument and checks for constraints
//Argument		:	ipstring ===> IP Address
//Return Type	:	Error ===> Returns error if constraints are proven false
//Call			: 	IpAddress_Object.AcceptIpAddress(IP Address)
func (Ip *IpAddress) AcceptIpAddress(ipstring string) error {
	var ipOctets = strings.Split(ipstring, ".")
	if len(ipOctets) > 4 {
		return errors.New("error: IP Address size should not exceed 4")
	}
	for i, oct := range ipOctets {
		oc, _ := strconv.Atoi(oct)
		if !Utilities.Myint(oc).InRange(0, 254) {
			txt := "Error: IP Octet "
			txt += strconv.Itoa(i)
			txt += " is out of range"
			return errors.New(txt)
		}
		Ip.Octet[i] = byte(oc)
	}
	return nil
}

func (Ip *IpAddress) CalculateIPClass() error {
	var firstOctet = Utilities.Myint(Ip.Octet[0])
	if firstOctet.InRange(0, 126) {
		Ip.Class = 'A'
	} else if firstOctet == 127 {
		Ip.Class = 'L'
	} else if firstOctet.InRange(128, 191) {
		Ip.Class = 'B'
	} else if firstOctet.InRange(192, 223) {
		Ip.Class = 'C'
	} else if firstOctet.InRange(224, 239) {
		Ip.Class = 'D'
	} else if firstOctet.InRange(240, 255) {
		Ip.Class = 'E'
	} else {
		return errors.New("error. Error in IP Address. Not of any class")
	}
	return nil
}

func (Ip *IpAddress) CalculateDmask() error {
	switch Ip.Class {

	case 'A':
		Ip.DefaultMask = []byte{255, 0, 0, 0}
		Ip.MaskInt = 8
	case 'B':
		Ip.DefaultMask = []byte{255, 255, 0, 0}
		Ip.MaskInt = 16
	case 'C':
		Ip.DefaultMask = []byte{255, 255, 255, 0}
		Ip.MaskInt = 24
	case 'D', 'E':
		return errors.New("Error.Class D and E dont have masking")
	}
	return nil
}
