void printAllPermutations(string s, int l, int h) 
{
	if(l>h)	return;
	if(l == h)
	{
		cout<<s<<endl;
		return;
	}

	for(int i=l; i<=h; i++) 
	{
		swap(s[l], s[i]);
		printAllPermutations(s, l+1, h);
		swap(s[l], s[i]);
	}
}
