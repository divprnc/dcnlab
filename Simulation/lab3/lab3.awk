BEGIN{
	packet = 0;
	time = 0;
}
{
	if($1 == "r" && $9 == "1.0" && $10 == "5.0")
	{
		packet = packet + $6;
		time = $2;
	}
}
END{
	printf("\nThroughput : %f Mbps \n\n",(packet*time)*(8/1000000));
}
