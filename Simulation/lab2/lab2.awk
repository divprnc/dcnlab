BEGIN{

	tcp = 0;
	udp = 0;
}
{
	if($1 == "r" && $3 == "2" && $4 == "3" && $5 == "tcp")
		tcp++;
	
	if($1 == "r" && $3 == "2" && $4 == "3" && $5 == "cbr")
		udp++;
}
END{
	printf("\nTotal Number of packets sent by TCP %d\n",tcp);
	printf("\nTotal Number of packets sent by UDP %d\n",udp);
}
