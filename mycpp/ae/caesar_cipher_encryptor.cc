using namespace std;

string caesarCypherEncryptor(string str, int key)
{
	unordered_map<int,char> nlm;
	int num;
	string ns="";

	for(int i=0;i<str.length();i++)
	{
		num = (int)str[i] - 97;
		num = 97+((num+key)%26);
		ns+=((char)num);
	}
	return ns;
}

