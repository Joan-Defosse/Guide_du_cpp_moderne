template <typename Collection>
void afficher(Collection const& iterable)
{
	for (auto const& e : iterable)
	{
		std::cout << e << std::endl;
	}
}