void generate_parenthesis(int n, int close, int open, string tmp) 
{
	if(open == close && close == n)
	{
		cout<<tmp<<endl;
		return;
	}

	if(open > close) 
	{
		// closing parenthesis
		tmp.push_back(')');
		generate_parenthesis(n, close+1, open, tmp);
		tmp.pop_back();
		
		if(open < n) 
		{
			// apply opening parenthesis
			tmp.push_back('(');
			generate_parenthesis(n, close, open+1, tmp);
			tmp.pop_back();
		}
	}

	else if(open == close)
	{
		if(open < n) 
		{
			// apply opening parenthesis
			tmp.push_back('(');
			generate_parenthesis(n, close, open+1, tmp);
			tmp.pop_back();
		}
	}
}