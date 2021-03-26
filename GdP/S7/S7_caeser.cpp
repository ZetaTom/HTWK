#include <iostream>
#include <string>

std::string caeser( std::string text, int n) {
	for( size_t i = 0; i < text.length(); ++i ) {
		int zeichen = text[i];
		if(zeichen >= 'A' && zeichen <= 'Z') {
			zeichen = 'A' + ( (zeichen - 'A' + n) ) % 26;
		} else if ( zeichen >= 'a' && zeichen <= 'z' ) {
			zeichen = 'a' + ( (zeichen - 'a' + n) ) % 26;
		}
		text[i] = static_cast< char >(zeichen);
	}
	return text;
}

int main() {
	std::string text;
	int n;
	std::cout << "Eingabe: ";
	std::getline( std::cin, text );
	std::cout << "Verschiebung: ";
	std::cin >> n;
	std::string verschluesselt = caeser(text, n);
	std::cout << verschluesselt << std::endl;
}
