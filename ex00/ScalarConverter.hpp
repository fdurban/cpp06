

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		const ScalarConverter&	operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void	convert(std::string data);
};
