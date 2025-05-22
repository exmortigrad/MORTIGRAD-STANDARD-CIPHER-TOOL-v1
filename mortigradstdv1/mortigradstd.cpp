#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

//DECODING FUNCTION
string decode(const vector <int> & numbers) 
{
    string DecodedOutput;
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        int num = numbers[i];
        char letter = '\0';
        if (num >= 1 && num <= 9)
        {
            letter = 'A' + num - 1; 
        }
        else if (num == 0)
        {
            DecodedOutput += ' ';
            continue;
        }
        else
        {
            switch (num)
            {
            case 80: letter = 'J'; break;
            case 88: letter = 'K'; break;
            case 96: letter = 'L'; break;
            case 104: letter = 'M'; break;
            case 112: letter = 'N'; break;
            case 120: letter = 'O'; break;
            case 128: letter = 'P'; break;
            case 136: letter = 'Q'; break;
            case 144: letter = 'R'; break;
            case 152: letter = 'S'; break;
            case 180: letter = 'T'; break;
            case 189: letter = 'U'; break;
            case 198: letter = 'V'; break;
            case 207: letter = 'W'; break;
            case 216: letter = 'X'; break;
            case 225: letter = 'Y'; break;
            case 234: letter = 'Z'; break;
            }
        }
        DecodedOutput += letter;
    }
    return DecodedOutput;
}

//ENCODING FUNCTION
string encode(const string & input)
{
    string EncodedOutput;
    for (char letter : input)
    {
        if (letter == ' ')
        {
            EncodedOutput += " ";
            continue;
        }

        letter = toupper(letter);

        if (letter >= 'A' && letter <= 'I')
        {
            EncodedOutput += to_string(letter - 'A' + 1);
        }
        else
        {
            switch (letter)
            {
            case 'J': EncodedOutput += "80"; break;
            case 'K': EncodedOutput += "88"; break;
            case 'L': EncodedOutput += "96"; break;
            case 'M': EncodedOutput += "104"; break;
            case 'N': EncodedOutput += "112"; break;
            case 'O': EncodedOutput += "120"; break;
            case 'P': EncodedOutput += "128"; break;
            case 'Q': EncodedOutput += "136"; break;
            case 'R': EncodedOutput += "144"; break;
            case 'S': EncodedOutput += "152"; break;
            case 'T': EncodedOutput += "180"; break;
            case 'U': EncodedOutput += "189"; break;
            case 'V': EncodedOutput += "198"; break;
            case 'W': EncodedOutput += "207"; break;
            case 'X': EncodedOutput += "216"; break;
            case 'Y': EncodedOutput += "225"; break;
            case 'Z': EncodedOutput += "234"; break;
            default: return " ***Invalid characters*** ";
            }
        }
        EncodedOutput += " ";
    }
    return EncodedOutput;
}

int main()
{
	string option;
    string input;

    cout << R"(


  __  __  ____  _____ _______ _____ _____ _____            _____     _____ _____ _____  _    _ ______ _____    _______ ____   ____  _       __      ____ 
 |  \/  |/ __ \|  __ \__   __|_   _/ ____|  __ \     /\   |  __ \   / ____|_   _|  __ \| |  | |  ____|  __ \  |__   __/ __ \ / __ \| |      \ \    / /_ |
 | \  / | |  | | |__) | | |    | || |  __| |__) |   /  \  | |  | | | |      | | | |__) | |__| | |__  | |__) |    | | | |  | | |  | | |       \ \  / / | |
 | |\/| | |  | |  _  /  | |    | || | |_ |  _  /   / /\ \ | |  | | | |      | | |  ___/|  __  |  __| |  _  /     | | | |  | | |  | | |        \ \/ /  | |
 | |  | | |__| | | \ \  | |   _| || |__| | | \ \  / ____ \| |__| | | |____ _| |_| |    | |  | | |____| | \ \     | | | |__| | |__| | |____     \  /   | |
 |_|  |_|\____/|_|  \_\ |_|  |_____\_____|_|  \_\/_/    \_\_____/   \_____|_____|_|    |_|  |_|______|_|  \_\    |_|  \____/ \____/|______|     \/    |_|
                                                                                                                                                         
                                                                                                                                                         

     
)" << '\n';

    while (true)
    {
        cout << "--MORTIGRAD Standard Encode/Decode Tool--" << endl;
        cout << "(Type 'Q' to quit) or (Type 'G' to see guide)" << endl << endl;
        cout << "Decode" << endl;
        cout << "OR" << endl;
        cout << "Encode" << endl << endl;
        cout << "Please select an option: ";

        getline(cin, input);
        cout << endl << endl;

        istringstream iss(input);
        iss >> option;

        //DECODING OUTPUT
        vector<int> numbers;
        if (option == "Decode" || option == "decode" || option == "DECODE")
        {
            cout << "Enter a cipher to decode: ";
            getline(cin, input);

            istringstream iss(input);
            int num;
            while (iss >> num)
            {
                if (num < 1 || num > 234) 
                {
                    cout << "***Invalid numerical values***" << endl << endl;
                }
                numbers.push_back(num);
            }

            if (numbers.empty()) 
            {
                cout << "***No valid numbers provided***" << endl << endl;
            }
            else
            {
                string translation = decode(numbers);
                cout << "Decoded Message: " << translation << endl << endl;
            }
        }

        //ENCODING OUTPUT
        else if (option == "Encode" || option == "encode" || option == "ENCODE")
        {
            cout << "Enter a message to encode: ";
            getline(cin, input);

            string EncodedMessage = encode(input);
            if (EncodedMessage.substr(0, 3) == "***")
            {
                cout << EncodedMessage << endl << endl;
            }
            else
            {
                cout << "Encoded Message: " << EncodedMessage << endl << endl;
            }
        }

        else if (option == "Q" || option == "q")
        {
            break;
        }
        else if (option == "G" || option == "g")
        {
            cout << "Select an option to encode or decode a MORTIGRAD cipher from the menu." << endl << endl;
            cout << "A few things to note:" << endl;
            cout << "1. For decoding, most invalid numbers (78, 86, 70, 62, etc.) will create a blank space in the output." << endl;
            cout << "2. Encoding cannot handle punctuation, please stick with valid letters." << endl;
            cout << "3. Ciphers must contain spaces between each new number when decoding. Not doing so will result in an error." << endl << endl;
        }
        else
        {
            cout << "***Invalid entry***" << endl << endl;
        }
    }
}
