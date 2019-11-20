set ns [new Simulator]
set tf [open lab2.tr w]
$ns trace-all $tf
set nf [open lab2.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
$ns color 1 "red"
$ns color 2 "orange"

$n0 label "Source/TCP"
$n1 label "Source/UDP"
$n2 label "Router"
$n3 label "Destination"

$ns duplex-link $n0 $n2 100Kb 100ms DropTail
$ns duplex-link $n1 $n2 100Kb 100ms DropTail
$ns duplex-link $n2 $n3 100Kb 100ms DropTail 



$ns duplex-link-op $n0 $n2 color "green"
$ns duplex-link-op $n1 $n2 color "blue"
$ns duplex-link-op $n2 $n3 color "black"


$ns duplex-link-op $n0 $n2 label "from 0-2"
$ns duplex-link-op $n1 $n2 label "from 1-2"
$ns duplex-link-op $n2 $n3 label "from 2-3"

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$tcp0 set class_ 1
$ftp0 set packetSize 100Mb
$ftp0 set interval_ 0.01

set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0
$udp0 set class_ 2
$cbr0 set packetSize 100Mb
$cbr0 set interval_ 0.01



set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0
set null0 [new Agent/Null]
$ns attach-agent $n3 $null0
$ns connect $tcp0 $sink0
$ns connect $udp0 $null0

proc finish {} {
	global ns nf tf
	$ns flush-trace
	exec nam lab2.nam &
	close $nf
	close $tf
	exit 0
}

$ns at 0.1 "$cbr0 start"
$ns at 0.2 "$ftp0 start"
$ns at 5.0 "finish"
$ns run


