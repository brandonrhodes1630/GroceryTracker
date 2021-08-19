using namespace std;



void menuDisplay() { //Simple C++ function to display menu
	cout << "************* Main Menu **************" << endl;
	cout << "*     1: View Purchased Products     *" << endl;
	cout << "*     2: Specific Product Search     *" << endl;
	cout << "*     3: View Products Histogram     *" << endl;
	cout << "*     4: Exit Program                *" << endl;
	cout << "**************************************" << endl;
	cout << "Selection: ";
}

void itemFrequencyMenu() {//Simple menu for specific product input
	cout << "*************** Product Frequency ***************" << endl;
	cout << "*                                               *" << endl;
	cout << "*Enter a product to find it's purchase frequency*" << endl;
	cout << "*                                               *" << endl;
	cout << "*************************************************" << endl;
	cout << "Product: ";
}

void itemFrequency(string product, int freq) { //Function to display specific product frequency
	cout << "--------------- Product Frequency ---------------" << endl;
	cout << endl;
	cout << "                " << product << ": ";
	cout << freq << endl;
	cout << endl;
	cout << "-------------------------------------------------" << endl;
	cout << endl;
}



void histogram(ifstream & f) { //Function for histogram logic
	vector<string> fileArr;
	vector<string> products;
	vector<string> productFrequency;
	string product;
	unsigned int i;
	unsigned int j;
	

	while (f >> product) { //Reads the file and places information into a vector, product and the corresponding frequency
		                   
		fileArr.push_back(product);	
	}

	for (i = 0; i < fileArr.size(); ++i) { //Fills the products vector with the products bought
		products.push_back(fileArr.at(i));
		i = i + 1;
	}
	for (j = 1; j < fileArr.size(); ++j) { //Fills the productFrequency array with the number of products bought per day
		int num = stoi(fileArr.at(j));//Turns string into int in order to produce special character n times
		string x = string(num, '$');//Performs the action to produce special character n times
		productFrequency.push_back(x); //Adds the frequency in form of special characters to array
		j = j + 1; //Skips one index in order to only grab numbers
	}
	cout << "************* Histogram *************" << endl;
	cout << endl;
	for (i = 0; i < products.size() && i < productFrequency.size(); ++i) {
		cout << "            -" << products[i]; cout << " " << productFrequency[i] << endl;
	}/*Loop outputs products array at index followed by products
	   corresponding frequency in form of special characters*/
	cout << endl;
}
