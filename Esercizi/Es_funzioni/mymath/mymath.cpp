double sum(double x, double y) {return x+y;}
double prod(double x, double y) {return x*y;}
int ipow(int x, int y) {
	int res = 1;
	for(int i=0; i<y; i++)
		res*=i;
	return res;
}