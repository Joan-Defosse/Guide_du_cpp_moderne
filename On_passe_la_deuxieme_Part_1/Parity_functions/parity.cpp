bool is_odd(int i);

bool is_even(int i)
{
	if (i == 0)
	{
		return true;
	}
	else if (i < 0)
	{
		return is_even(-i);
	}
	else
	{
		return is_odd(i - 1);
	}
}

bool is_odd(int i)
{
	if (i == 0)
	{
		return false;
	}
	else if (i < 0)
	{
		return is_odd(-i);
	}
	else
	{
		return is_even(i - 1);
	}
}