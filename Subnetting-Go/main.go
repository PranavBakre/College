package main

import (
	"Subnetting-Go/Program"
	//Uncomment below line for Linux- Commenting the above line
	//"./Program"
	"fmt"
	"os"
)

func main() {
	var ip Program.IpAddress
	var sp Program.Subnetworks
	ip.Init()
	ip.AcceptIpAddress("12.2.3.5")
	ip.CalculateIPClass()
	ip.CalculateDmask()
	sp.Init(&ip)
	sp.CalculateTHosts()
	err := sp.CalculateSubnetMask(102)
	if err != nil {
		fmt.Println(err.Error())
		os.Exit(1)
	}
	sp.CalculateNHosts()
	sp.CalcAllIP() //Calls CalculateIP for every subnet
	//sp.CalculateIPs(256)
	//ip.CalculateNoHosts()
	fmt.Printf("%v\n", ip)
	fmt.Printf("%v", sp)

	for i := 0; i < 8; i++ {
		fmt.Println(sp.FIp[i])
		fmt.Println(sp.LIp[i])
	}
	fmt.Println(sp.FIp[127])
	fmt.Println(sp.LIp[127])
}
