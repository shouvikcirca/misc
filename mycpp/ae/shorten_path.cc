using namespace std;
string shortenPath(string path)
{

	vector<string> folders;
	string ns = "";

	for(int i=0;i<path.length();i++)
	{
		if(path.at(i) != '/')
			ns+=path.at(i);
		else
		{
			ns = i==0?("/"+ns):(ns);
			folders.push_back(ns);
			ns = "";
		}

	}
	folders.push_back(ns);

	vector<string> shortenedpath;
	int i = (folders[0] == "/")?1:0;
	if(i==1)
		shortenedpath.push_back("/");

	for(;i<folders.size();i++)
	{
		if(folders[i] == "..")
		{
			if(shortenedpath.empty())
				shortenedpath.push_back(folders[i]+"/");
			else if(shortenedpath.back() == "/" && shortenedpath.size()==1)
				continue;
			else if(shortenedpath.back() == "../")
				shortenedpath.push_back("../");

			else
				shortenedpath.pop_back();

		}		
		else if(folders[i] == "." || folders[i] == "")
			continue;
		else
			shortenedpath.push_back(folders[i]+'/');
	}

	ns="";
	while(!shortenedpath.empty())
	{
		ns = shortenedpath.back()+ns;
		shortenedpath.pop_back();
	}

	return ns=="/"?ns:ns.substr(0,ns.length()-1);
}
