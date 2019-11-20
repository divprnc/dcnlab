BEGIN{
	count = 0;
}
{

	if($1 == "d")
	{
		count++;
	}
}
END{
	printf("\nPackets Dropped are :",count);
}

