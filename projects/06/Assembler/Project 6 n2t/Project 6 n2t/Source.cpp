#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;


string C_com2bin(string c_com)    // Chuyen tu A - instruction sang binary
{
	c_com = c_com.substr(0, c_com.find(" ", 0));	// Lay ra chuoi ki tu
	string out = "111";								// Op-code and not-use
	string comp;
	string dest;
	string jump;
	// Finding comp
	int equalSign = c_com.find("=", 0);				// Tim vi tri dau "="
	if (equalSign > -1 && equalSign < c_com.length())			// Truong hop co "dest"
	{
		if (c_com.substr(equalSign + 1, 3) == "D|M")			// a, c1 -> c6
			comp = "1010101";
		else if (c_com.substr(equalSign + 1, 3) == "D|A")
			comp = "0010101";
		else if (c_com.substr(equalSign + 1, 3) == "D&A")
			comp = "0000000";
		else if (c_com.substr(equalSign + 1, 3) == "D&M")
			comp = "1000000";
		else if (c_com.substr(equalSign + 1, 3) == "A-D")
			comp = "0000111";
		else if (c_com.substr(equalSign + 1, 3) == "M-D")
			comp = "1000111";
		else if (c_com.substr(equalSign + 1, 3) == "D+1")
			comp = "0011111";
		else if (c_com.substr(equalSign + 1, 3) == "A+1")
			comp = "0110111";
		else if (c_com.substr(equalSign + 1, 3) == "M+1")
			comp = "1110111";
		else if (c_com.substr(equalSign + 1, 3) == "D-1")
			comp = "0001110";
		else if (c_com.substr(equalSign + 1, 3) == "A-1")
			comp = "0110010";
		else if (c_com.substr(equalSign + 1, 3) == "M-1")
			comp = "1110010";
		else if (c_com.substr(equalSign + 1, 3) == "D+A")
			comp = "0000010";
		else if (c_com.substr(equalSign + 1, 3) == "D+M")
			comp = "1000010";
		else if (c_com.substr(equalSign + 1, 3) == "D-A")
			comp = "0010011";
		else if (c_com.substr(equalSign + 1, 3) == "D-M")
			comp = "1010011";
		else if (c_com.substr(equalSign + 1, 2) == "-1")
			comp = "0111010";
		else if (c_com.substr(equalSign + 1, 2) == "!D")
			comp = "0001101";
		else if (c_com.substr(equalSign + 1, 2) == "!A")
			comp = "0110001";
		else if (c_com.substr(equalSign + 1, 2) == "!M")
			comp = "1110001";
		else if (c_com.substr(equalSign + 1, 2) == "-D")
			comp = "0001111";
		else if (c_com.substr(equalSign + 1, 2) == "-A")
			comp = "0110011";
		else if (c_com.substr(equalSign + 1, 2) == "-M")
			comp = "1110011";
		else if (c_com.substr(equalSign + 1, 1) == "0")
			comp = "0101010";
		else if (c_com.substr(equalSign + 1, 1) == "1")
			comp = "0111111";
		else if (c_com.substr(equalSign + 1, 1) == "D")
			comp = "0001100";
		else if (c_com.substr(equalSign + 1, 1) == "A")
			comp = "0110000";
		else if (c_com.substr(equalSign + 1, 1) == "M")
			comp = "1110000";
	}
	else		// Truong hop k co "dest"
	{
		if (c_com.find("D|M", 0) >= 0 && c_com.find("D|M", 0) < c_com.length())
			comp = "1010101";
		else if (c_com.find("D|A", 0) >= 0 && c_com.find("D|A", 0) < c_com.length())
			comp = "0010101";
		else if (c_com.find("D&A", 0) >= 0 && c_com.find("D&A", 0) < c_com.length())
			comp = "0000000";
		else if (c_com.find("D&M", 0) >= 0 && c_com.find("D&M", 0) < c_com.length())
			comp = "1000000";
		else if (c_com.find("A-D", 0) >= 0 && c_com.find("A-D", 0) < c_com.length())
			comp = "0000111";
		else if (c_com.find("M-D", 0) >= 0 && c_com.find("M-D", 0) < c_com.length())
			comp = "1000111";
		else if (c_com.find("D+1", 0) >= 0 && c_com.find("D+1", 0) < c_com.length())
			comp = "0011111";
		else if (c_com.find("A+1", 0) >= 0 && c_com.find("A+1", 0) < c_com.length())
			comp = "0110111";
		else if (c_com.find("M+1", 0) >= 0 && c_com.find("M+1", 0) < c_com.length())
			comp = "1110111";
		else if (c_com.find("D-1", 0) >= 0 && c_com.find("D-1", 0) < c_com.length())
			comp = "0001110";
		else if (c_com.find("A-1", 0) >= 0 && c_com.find("A-1", 0) < c_com.length())
			comp = "0110010";
		else if (c_com.find("M-1", 0) >= 0 && c_com.find("M-1", 0) < c_com.length())
			comp = "1110010";
		else if (c_com.find("D+A", 0) >= 0 && c_com.find("D+A", 0) < c_com.length())
			comp = "0000010";
		else if (c_com.find("D+M", 0) >= 0 && c_com.find("D+M", 0) < c_com.length())
			comp = "1000010";
		else if (c_com.find("D-A", 0) >= 0 && c_com.find("D-A", 0) < c_com.length())
			comp = "0010011";
		else if (c_com.find("D-M", 0) >= 0 && c_com.find("D-M", 0) < c_com.length())
			comp = "1010011";
		else if (c_com.find("-1", 0) >= 0 && c_com.find("-1", 0) < c_com.length())
			comp = "0111010";
		else if (c_com.find("!D", 0) >= 0 && c_com.find("!D", 0) < c_com.length())
			comp = "0001101";
		else if (c_com.find("!A", 0) >= 0 && c_com.find("!A", 0) < c_com.length())
			comp = "0110001";
		else if (c_com.find("!M", 0) >= 0 && c_com.find("!M", 0) < c_com.length())
			comp = "1110001";
		else if (c_com.find("-D", 0) >= 0 && c_com.find("-D", 0) < c_com.length())
			comp = "0001111";
		else if (c_com.find("-A", 0) >= 0 && c_com.find("-A", 0) < c_com.length())
			comp = "0110011";
		else if (c_com.find("-M", 0) >= 0 && c_com.find("-M", 0) < c_com.length())
			comp = "1110011";
		else if (c_com.find("0", 0) >= 0 && c_com.find("0", 0) < c_com.length())
			comp = "0101010";
		else if (c_com.find("1", 0) >= 0 && c_com.find("1", 0) < c_com.length())
			comp = "0111111";
		else if (c_com.find("D", 0) >= 0 && c_com.find("D", 0) < c_com.length())
			comp = "0001100";
		else if (c_com.find("A", 0) >= 0 && c_com.find("A", 0) < c_com.length())
			comp = "0110000";
		else if (c_com.find("M", 0) >= 0 && c_com.find("M", 0) < c_com.length())
			comp = "1110000";
	}
	// Finding jump
	int semi = c_com.find(";", 0);			// Tim vi tri dau ";"
	if (c_com.substr(semi + 1, 3) == "JGT")		// j1, j2, j3
		jump = "001";
	else if (c_com.substr(semi + 1, 3) == "JEQ")
		jump = "010";
	else if (c_com.substr(semi + 1, 3) == "JGE")
		jump = "011";
	else if (c_com.substr(semi + 1, 3) == "JLT")
		jump = "100";
	else if (c_com.substr(semi + 1, 3) == "JNE")
		jump = "101";
	else if (c_com.substr(semi + 1, 3) == "JLE")
		jump = "110";
	else if (c_com.substr(semi + 1, 3) == "JMP")
		jump = "111";
	else
		jump = "000";
	// Finding dest
	if (equalSign > -1 && equalSign < c_com.length())
	{
		string d3, d2, d1;
		int findM = c_com.find("M", 0);
		if (findM > -1 && findM < equalSign)
		{
			d3 = "1";
		}
		else
		{
			d3 = "0";
		}
		int findD = c_com.find("D", 0);
		if (findD > -1 && findD < equalSign)
		{
			d2 = "1";
		}
		else
		{
			d2 = "0";
		}
		int findA = c_com.find("A", 0);
		if (findA > -1 && findA < equalSign)
		{
			d1 = "1";
		}
		else
		{
			d1 = "0";
		}
		dest = d1 + d2 + d3;
	}
	else
		dest = "000"; // Khong co dau "="
	out = out + comp + dest + jump;		//  connection
	return out;
}


string A_dec2bin(string a_com) // Chuyen tu A-instruction sang binary
{
	int val = stoi(a_com);		// chuyen tu string -> int
	string out = "0";			// Op-code cua A-instruction
	if ((val - 16384) >= 0)		// Bat dau translate
	{
		val -= 16384;
		out += "1";
	}
	else
		out += "0";
	if ((val - 8192) >= 0)
	{
		val -= 8192;
		out += "1";
	}
	else
		out += "0";
	if ((val - 4096) >= 0)
	{
		val -= 4096;
		out += "1";
	}
	else
		out += "0";
	if ((val - 2048) >= 0)
	{
		val -= 2048;
		out += "1";
	}
	else
		out += "0";
	if ((val - 1024) >= 0)
	{
		val -= 1024;
		out += "1";
	}
	else
		out += "0";
	if ((val - 512) >= 0)
	{
		val -= 512;
		out += "1";
	}
	else
		out += "0";
	if ((val - 256) >= 0)
	{
		val -= 256;
		out += "1";
	}
	else
		out += "0";
	if ((val - 128) >= 0)
	{
		val -= 128;
		out += "1";
	}
	else
		out += "0";
	if ((val - 64) >= 0)
	{
		val -= 64;
		out += "1";
	}
	else
		out += "0";
	if ((val - 32) >= 0)
	{
		val -= 32;
		out += "1";
	}
	else
		out += "0";
	if ((val - 16) >= 0)
	{
		val -= 16;
		out += "1";
	}
	else
		out += "0";
	if ((val - 8) >= 0)
	{
		val -= 8;
		out += "1";
	}
	else
		out += "0";
	if ((val - 4) >= 0)
	{
		val -= 4;
		out += "1";
	}
	else
		out += "0";
	if ((val - 2) >= 0)
	{
		val -= 2;
		out += "1";
	}
	else
		out += "0";
	if ((val - 1) >= 0)
	{
		val -= 1;
		out += "1";
	}
	else
		out += "0";
	return out;
}


int isSymbol(vector<string>& symbols, string s)		// Kiem tra xem trong danh sach ki hieu "symbols" co chua ki hieu "s" khong ?
{
	for (int i = 0; i < symbols.size(); i++) // linear search for the string, return 1 if it exists, return 0 if it doesn't
	{
		if (symbols[i] == s)
			return 1;
	}
	return 0;
}

string itos(int i) // integer -> string
{
	ostringstream s;
	s << i;
	return s.str();
}

int isNum(string num) // Kiem tra xem ki tu dau tien cua 1 chuoi co phai la so hay khong ?
{
	if (num == "0" || num == "1" || num == "2" || num == "3" || num == "4" || num == "5" || num == "6" || num == "7" || num == "8" || num == "9")
		return 1;
	else
		return 0;
}


int main(int argc, char* argv[])
{

	vector<string> symbols;		// Danh sach cac symbols de check
	symbols.push_back("R0");
	symbols.push_back("R1");
	symbols.push_back("R2");
	symbols.push_back("R3");
	symbols.push_back("R4");
	symbols.push_back("R5");
	symbols.push_back("R6");
	symbols.push_back("R7");
	symbols.push_back("R8");
	symbols.push_back("R9");
	symbols.push_back("R10");
	symbols.push_back("R11");
	symbols.push_back("R12");
	symbols.push_back("R13");
	symbols.push_back("R14");
	symbols.push_back("R15");
	symbols.push_back("SCREEN");
	symbols.push_back("KBD");
	symbols.push_back("SP");
	symbols.push_back("LCL");
	symbols.push_back("ARG");
	symbols.push_back("THIS");
	symbols.push_back("THAT");
	int symSize = 23;

	// Dien vao symbol table
	map<string, int> SymbolTable;
	SymbolTable["R0"] = 0;
	SymbolTable["R1"] = 1;
	SymbolTable["R2"] = 2;
	SymbolTable["R3"] = 3;
	SymbolTable["R4"] = 4;
	SymbolTable["R5"] = 5;
	SymbolTable["R6"] = 6;
	SymbolTable["R7"] = 7;
	SymbolTable["R8"] = 8;
	SymbolTable["R9"] = 9;
	SymbolTable["R10"] = 10;
	SymbolTable["R11"] = 11;
	SymbolTable["R12"] = 12;
	SymbolTable["R13"] = 13;
	SymbolTable["R14"] = 14;
	SymbolTable["R15"] = 15;
	SymbolTable["SCREEN"] = 16384;
	SymbolTable["KBD"] = 24576;
	SymbolTable["SP"] = 0;
	SymbolTable["LCL"] = 1;
	SymbolTable["ARG"] = 2;
	SymbolTable["THIS"] = 3;
	SymbolTable["THAT"] = 4;


	// Opening ".asm file" to read and ".hack file" to write with the same name
	ifstream fin(argv[argc - 1]);
	string file = argv[argc - 1];
	int dotLocation = file.find(".", 0);
	string hackFile = file.substr(0, dotLocation) + ".hack";	// Them duoi .hack
	ofstream fout(hackFile.c_str());   // .c_str() chuyen std::string thanh char* (CharT*) 

	// Chay qua file dau vao 1 lan de dien cac ki hieu "user defined jump" vao symbol table
	int PC = 0;
	int RAMLocation = 16;
	string sym;
	while (getline(fin, sym))		// getline se return so ki tu dc doc vao
	{
		if ((sym.substr(0, 1) == "(") && !(isSymbol(symbols, sym.substr(1, sym.find(")", 0) - 1))))
		{
			SymbolTable[sym.substr(1, sym.find(")", 0) - 1)] = PC;
			symbols.push_back(sym.substr(1, sym.find(")", 0) - 1));
			symSize++;
		}
		if (sym.substr(0, 1) != "/" && sym.substr(0, 1) != "(" && sym.substr(0, 1) != "")
			PC++;
	}
	fin.close();

	// Chay lai file dau vao 1 lan nua de dien cac ki hieu "user defined variable symbols" vao symbol table
	fin.open(argv[argc - 1]);
	while (getline(fin, sym))
	{
		if (sym.substr(0, 1) == "@")
		{
			if (!(isNum(sym.substr(1, 1))) && !(isSymbol(symbols, sym.substr(1, sym.find(" ", 0) - 1))))
			{
				SymbolTable[sym.substr(1, sym.length() - 1)] = RAMLocation;
				RAMLocation++;
				symbols.push_back(sym.substr(1, sym.length() - 1));
				symSize++;
			}
		}
	}
	fin.close();

	// Bat dau phan tich cu phap
	string command, hack_command;
	fin.open(argv[argc - 1]); // open file
	while (getline(fin, command))
	{
		if (command.substr(0, 1) == "/" || command.substr(0, 1) == "" || command.substr(0, 1) == "(") // comments, blank line, or labels do nothing
		{
			;
		}
		else if (command.substr(0, 1) == "@") // A command, call the A translation function
		{
			if (isNum(command.substr(1, 1)))
			{
				hack_command = A_dec2bin(command.substr(1, command.length() - 1));
				fout << hack_command << endl;
			}
			else // it is a user defined symbol located in the SymbolTable
			{
				hack_command = A_dec2bin(itos(SymbolTable[command.substr(1, command.length() - 1)]));
				fout << hack_command << endl;
			}
		}
		else // C command, call the C translation function
		{
			hack_command = C_com2bin(command);
			fout << hack_command << endl;
		}
	}

	// Closing files
	fin.close();
	fout.close();

	// Kiem tra xem file .hack dau ra co dam bao 16bit o moi dong hay khong
	fin.open(hackFile.c_str());
	string hackLine;
	int line = 0;
	while (getline(fin, hackLine))
	{
		if (hackLine.length() != 16)
			cout << "Error in line " << line << "Please correct your syntax in .asm file." << endl;
		line++;
	}
	fin.close();
	return 0;
}