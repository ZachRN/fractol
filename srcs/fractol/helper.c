long double	dpow(long double base, int times)
{
	long double ret;

	ret = 1.0;
	while (times > 1)
	{
		ret = ret * base;
		times--;	
	}
	return (base);
}
