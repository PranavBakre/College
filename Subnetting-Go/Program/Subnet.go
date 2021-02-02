package Program

import (
	"errors"
	"fmt"
	"math"
	"strconv"
	"subnetting-Go/Program/Utilities"
	//Uncomment below line for Linux- Commenting the above line
	//"./Utilities"
)

type Subnetworks struct {
	Ip         *IpAddress //Provied IP Address
	SubnetMask []byte     //Subnet Mask for the SubNetworks
	NSubnets   int        //Number of Subnets Created
	NHosts     int        //Number of Hosts per subnet
	THosts     int        //Total Number of Hosts in the Network
	FIp        [][4]byte  //Array storing first IP of every Subnet
	LIp        [][4]byte  //Array Storing Last IP of every ubnet
}

//Function Name :	Init
//Purpose		:   Initializes the structure Subnetworks for operations
//Call			:	Subnetworks_Object.Init()
func (sp *Subnetworks) Init(ip *IpAddress) {
	sp.SubnetMask = make([]byte, 4)
	sp.Ip = ip
	sp.THosts = 1
	sp.NHosts = 1

}

//Function Name :	CalculateTHosts
//Purpose		:	Calculates the total number of hosts in the network
//Call			: 	Subnetworks_Object.CalculateTHosts()
func (sp *Subnetworks) CalculateTHosts() {
	for _, mask := range sp.Ip.DefaultMask {
		if mask != 255 {
			sp.THosts *= int(^mask) + 1
		}
	}
}

//Function Name :	CalculateNHosts
//Purpose		:	Calculates the total number of hosts per subnet in the network
//Call			: 	Subnetworks_Object.CalculateNHosts()
func (sp *Subnetworks) CalculateNHosts() {
	for _, mask := range sp.SubnetMask {
		if mask != 255 {
			sp.NHosts *= int(^mask) + 1
		}
	}
}

//Function Name :	CalculateSubnetMask
//Purpose		:	Calculates the subnet mask and the number of subnetworks generated for the argument-noSubnet
//Argument		:	noSubet ===> Number of Subnets Required
//Return Type	:	Error	===> Returned when requeste number of subnets exceeds the total number of hosts in the network,i.e. impossibility of creation of required subnets
//Call			:	Subnetworks_Object.CalculateSubnetMask(RequiredNumberOfSubnets)
func (sp *Subnetworks) CalculateSubnetMask(noSubnet int) error {
	var i int
	if noSubnet > sp.THosts {
		return errors.New("error: Number of Subnets greater than number of hosts")
	}
	for i = 0; int(math.Pow(2, float64(i))) < noSubnet; i++ {

	}
	sp.NSubnets = int(math.Pow(2, float64(i)))
	sp.FIp = make([][4]byte, sp.NSubnets, sp.NSubnets)
	sp.LIp = make([][4]byte, sp.NSubnets, sp.NSubnets)
	//	for j:=0;j<sp.NSubnets;j++ {
	//		sp.FIp[i]=make([]byte,4)
	//		sp.LIp[i]=make([]byte,4)
	//	}

	var subnetbitslength = len(strconv.FormatInt(int64(sp.NSubnets-1), 2))
	var tsubnet = (sp.NSubnets - 1) << (32 - sp.Ip.MaskInt - subnetbitslength)
	var subnetbits = strconv.FormatInt(int64(tsubnet), 2)
	//var tempoctet =make([]string,subnetbitslength/8)
	/*for i=0;i<subnetbitslength;i+=8 {
		tempoctet[i/8]=subnetbits[i:i+8]
	}*/
	var count int
	var sum int
	for j, oct := range sp.Ip.DefaultMask {

		if oct == 255 {
			sp.SubnetMask[j] = oct
		} else {
			var andoctet string
			tempoct := strconv.FormatInt(int64(^oct), 2)
			if count == 0 {
				andoctet = subnetbits[0:len(tempoct)]
			} else {
				a := len(subnetbits[sum:])
				if a < 8 {
					andoctet = subnetbits[sum:]
				} else {
					andoctet = subnetbits[sum : sum+len(tempoct)]
				}
			}
			count++
			sum = sum + len(tempoct)
			orOct, _ := strconv.ParseInt(andoctet, 2, 16)
			sp.SubnetMask[j] = oct ^ byte(orOct)

		}
	}

	return nil
}

//Function Name :	CalculateIPs
//Purpose		:	Calculate the first and last IP Addresses for the given subnet number passed as argument
//Arguments		:	subnetno ===> The subnet number for which IP Addresses are to be found
//Return Type	:	Error	 ===> Returns error when subnetno argument exceeds the number of subnets in the network
//Call			:	Subnetworks_Object.CalculateIPs(Subnet Number for which IP addresses are to be generated)
func (sp *Subnetworks) CalculateIPs(subnetno int) error {
	if subnetno >= sp.NSubnets {
		return errors.New("error: Subnet number exceeds the maximum number of subnets")
	}
	var tempIP [4]byte
	var adjustedsubnetno = subnetno

	for i := 3; i >= 0; i-- {
		if sp.SubnetMask[i] != 255 {
			adjustedsubnetno = adjustedsubnetno << len(strconv.FormatInt(int64(^sp.SubnetMask[i]), 2))

		}
	}
	avar := Utilities.IntToByteArray(adjustedsubnetno)

	//Get Network ID
	for i := 0; i < 4; i++ {
		tempIP[i] = sp.Ip.DefaultMask[i] & sp.Ip.Octet[i]
	}
	fmt.Println(tempIP)
	fmt.Println(avar)
	for i := 0; i < 4; i++ {
		tempIP[i] |= avar[i]
	}
	fmt.Println(tempIP)
	sp.FIp[subnetno] = tempIP
	for i := 0; i < 4; i++ {
		if sp.SubnetMask[i] != 255 {
			tempIP[i] |= ^sp.SubnetMask[i]

		}
	}
	sp.LIp[subnetno] = tempIP
	return nil
}

//Function Name :	CalcAllIP
//Purpose		:	Calculate IP Addresses ranges of all Subnets
//Call			: 	Subnetworks_Object.calcAllIP()
func (sp *Subnetworks) CalcAllIP() {
	for i := 0; i < sp.NSubnets; i++ {
		sp.CalculateIPs(i)
	}
}
