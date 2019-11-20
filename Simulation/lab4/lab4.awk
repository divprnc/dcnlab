BEGIN{
	count = 0;
}

{
	if($1 == "c")
	{
		count++;
	}
}
END{
	printf("\nTotal Packets Collision : %d \n",count);

}
