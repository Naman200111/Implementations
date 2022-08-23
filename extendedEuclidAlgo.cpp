int gcd,x,y; //global variables
void extendedEuclidAlgo(int a, int b) 
{
    // base case
    if(b==0) {
        gcd = a;
        x = 1;
        y = 0;
        return;
    }

    extendedEuclidAlgo(b, a%b);

    // curr x = ybelow
    // curr y = xbelow - (a/b)*ybelow
    int cx = y;
    int cy = x - (a/b)y;

    x = cx;
    y = cy;
}

// modulo inverse of a with respect to m
// (a*b)%m = 1 is satisified then b is the modulo inverse of a wrt m
int ModuloInv(int a, int m) 
{
    if(__gcd(a,m) != 1) {
        return -1; // modulo inverse does not exist
    }

    extendedEuclidAlgo(a, m);
    return (x+m)%m;
}