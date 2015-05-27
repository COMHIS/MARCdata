#include "MARCdata.hpp"

void MARCdata::csvOutput(const std::string filename){
	constructSubfields();
	ogzstream table(filename.c_str());
	table << "008lang|100a|100d|240a|245a|245b|260a|260b|260c|300a|300b|300c|300e|310a|362a|500a|502a|502c|502d|510a|510c|650a|651a|710a|720a|785t|852a\n";
	for (auto& book : books){
		int langIdx = book["008"]['#'].length()-5;
		table << book["008"]['#'].substr(langIdx,3) << "|";
		table << book["100"]['a'] << "|";
		table << book["100"]['d'] << "|";
		table << book["240"]['a'] << "|";
		table << book["245"]['a'] << "|";
		table << book["245"]['b'] << "|";
		table << book["260"]['a'] << "|";
		table << book["260"]['b'] << "|";
		table << book["260"]['c'] << "|";
		table << book["300"]['a'] << "|";
		table << book["300"]['b'] << "|";
		table << book["300"]['c'] << "|";
		table << book["300"]['e'] << "|";
		table << book["310"]['a'] << "|";
		table << book["362"]['a'] << "|";
		table << book["500"]['a'] << "|";
		table << book["502"]['a'] << "|";
		table << book["502"]['c'] << "|";
		table << book["502"]['d'] << "|";
		table << book["510"]['a'] << "|";
		table << book["510"]['c'] << "|";
		table << book["650"]['a'] << "|";
		table << book["651"]['a'] << "|";
		table << book["710"]['a'] << "|";
		table << book["720"]['a'] << "|";
		table << book["785"]['t'] << "|";
		table << book["852"]['a'] << "\n";
	}
}

int main()
{
	MARCdata kungliga;
	fennica.xmlInput("data/kungliga_pt1.xml");
	fennica.csvOutput("data/kungliga.csv.gz");
	return 0;
}
