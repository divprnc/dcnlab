BEGIN {
	count = 0;
}
{
	if($1 == "d")
		count++;
}
END {
	printf("\nPackets dropped due to congestion are %d\n",count);
}
