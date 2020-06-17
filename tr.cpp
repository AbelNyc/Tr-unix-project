/*
 * CSc103 Project 3: unix utilities
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 #geeksforgeeks
 #csc103 tutoring
 #total hours==20 hours
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:
 */
#include <iterator>
#include <map>
using std::map;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <string.h> // for c-string functions.
#include <getopt.h> // to parse long arguments.

static const char* usage =
"Usage: %s [OPTIONS] SET1 [SET2]\n"
"Limited clone of tr.  Supported options:\n\n"
"   -c,--complement     Use the complement of SET1.\n"
"   -d,--delete         Delete characters in SET1 rather than translate.\n"
"   --help          show this message and exit.\n";

void escape(string& s) {
	/* NOTE: the normal tr command seems to handle invalid escape
	 * sequences by simply removing the backslash (silently) and
	 * continuing with the translation as if it never appeared. */
	/* TODO: write me... */
	for(int i=0;i<s.length();i++){
	if(s[i]=='\\') {
		if(s[i+1]=='n')
			s[i+1]='\n';
		else if(s[i+1]=='t')
			s[i+1]='\t';
		else if(s[i+1]=='\\')
			s[i+1]='\\';
		s.erase(s.begin()+i);
}
}
}

int main(int argc, char *argv[])
{
	// define long options
	static int comp=0, del=0;
	static struct option long_opts[] = {
		{"complement",      no_argument,   0, 'c'},
		{"delete",          no_argument,   0, 'd'},
		{"help",            no_argument,   0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "cdh", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'c':
				comp = 1;
				break;
			case 'd':
				del = 1;
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}
	if (del) {
		if (optind != argc-1) {
			fprintf(stderr, "wrong number of arguments.\n");
			return 1;
		}
	} else if (optind != argc-2) {
		fprintf(stderr,
				"Exactly two strings must be given when translating.\n");
		return 1;
	}
	string s1 = argv[optind++];
	string s2 = (optind < argc)?argv[optind]:"";
	/* process any escape characters: */
	escape(s1);
	escape(s2);

	/* TODO: finish this... */

map<char,char>m;

	if(s1.length()>s2.length()) {

		for (int i=0;i<s2.length();i++) {
       m[s1[i]]=s2[i];
		}

   for (int i=s1.length()-s2.length();i<s1.length();i++) {
		   m[s1[i]]=s2.back();
		}
	}

	else if(s1.length()==s2.length()){
			for (int i=0;i<s2.length();i++) {
        m[s1[i]]=s2[i];
	}
}


string USER_INPUT;
string OUTPUT;
char chr;


while(fread(&chr,1,1,stdin)){
	USER_INPUT.push_back(chr);
	}
map<char,char>::iterator itr2;

	for(int i=0;i<USER_INPUT.length();i++) {
		itr2=m.find(USER_INPUT[i]);
		if(comp==0&&del==0)
			if(itr2!=m.end())
				OUTPUT.push_back(itr2->second);
		else
			  OUTPUT.push_back(USER_INPUT[i]);
	}


	if(comp==0 && del==1){
		for (int i=0;i<USER_INPUT.length();i++) {
			if(s1.find(USER_INPUT[i])==string::npos)
				OUTPUT.push_back(USER_INPUT[i]);
			}
		}

	if(comp==1 && del==0){
		for (int i=0;i<USER_INPUT.length();i++) {
			if(s1.find(USER_INPUT[i])!=string::npos)
			   OUTPUT.push_back(USER_INPUT[i]);
			else
				 OUTPUT.push_back(s2.back());
			}
		}
	if(comp==1 && del==1){
		for (int i=0;i<USER_INPUT.length();i++) {
			if(s1.find(USER_INPUT[i])!=string::npos){
				 OUTPUT.push_back(USER_INPUT[i]);
			}
		}
	}

	cout<<OUTPUT;
}