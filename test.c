#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned createMask(unsigned a, unsigned b)
{
	unsigned r = 0;
	unsigned i = a;
	while (i <= b)
	{
		r |= 1 << i;
		i++;
	}
	return (r);
}
int main(void)
{
	printf("%d,\n", create_trgb(0,66,30,15));
	printf("%d,\n", create_trgb(0,25,7,26));
	printf("%d,\n", create_trgb(0,9,1,47));
	printf("%d,\n", create_trgb(0,4,4,73));
	printf("%d,\n", create_trgb(0,0,7,100));
	printf("%d,\n", create_trgb(0,12,44,138));
	printf("%d,\n", create_trgb(0,24,82,177));
	printf("%d,\n", create_trgb(0,57,125,209));
	printf("%d,\n", create_trgb(0,134,181,229));
	printf("%d,\n", create_trgb(0,211,236,248));
	printf("%d,\n", create_trgb(0,248,201,95));
	printf("%d,\n", create_trgb(0,255,170,0));
	printf("%d,\n", create_trgb(0,204,128,0));
	printf("%d,\n", create_trgb(0,153,87,0));
	printf("%d\n", create_trgb(0,106,52,3));


	unsigned x = 3905810;
	unsigned b = createMask(0,7);
	unsigned bbits = (b & x);
	unsigned g = createMask(8,15);
	unsigned gbits = (g & x) >> 8;
	unsigned r = createMask(16,23);
	unsigned rbits = (r & x) >> 16;

	// unsigned bits;
	// bits = x & mask;
	printf("Color:\nr:%d\ng:%d\nb:%d\n",rbits,gbits,bbits);
}