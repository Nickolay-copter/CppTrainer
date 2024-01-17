set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set<string> values;
	for (const auto& val : m)
	{
		values.insert(val.second);
	}
	return values;
}