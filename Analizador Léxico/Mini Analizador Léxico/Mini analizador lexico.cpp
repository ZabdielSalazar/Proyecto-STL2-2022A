#include<iostream>
#include<map>
#include<string>
#include<vector>
int main(){
    std::map<std::string,int> dict{{"for",1},{"if",2},{"then",3},{"else",4},{"while",5},{"do",6},{"+",13},{"-",14},{"*",15},{"/",16},{"until",29},{"input",31},{":",17},{":=",18},{"<",20},{"<>",21},{"<=",22},{">",23},{">=",24},{"=",25},{";",26},{"(",27},{")",28},{"#",0},{"int",30},{"output",32}};
    std::vector<std::pair<int, std::string>> seqOut;
    std::string buffer;
    std::string s;
    getline(std::cin,s);
    s.push_back('\0');
    bool isNum;
    for(auto c=s.begin();c!=s.end();++c){
        if(!buffer.empty()){//donde existe num o cadena
            if(isNum and (*c<'0' or *c>'9')){
                seqOut.emplace_back(11,buffer);
                buffer.clear();
                --c;
            }
            else if(not('a'<=*c and *c<='z' or *c >= 'A' and *c <= 'Z' or '0' <= *c and *c <= '9')){  //no cadena o num
                if(dict[buffer]!=0){
                    seqOut.emplace_back(dict[buffer],buffer);
                }
                else{
                    seqOut.emplace_back(10,buffer);
                }
                buffer.clear();
                --c;
            }
            else{
                buffer+=*c;
            }
        }
        else{//donde es el primero de todos
            if(*c==' ') continue;
            buffer+=*c;
            int fir = dict[buffer];
            buffer+=*(c+1);
            int sec = dict[buffer];
            if(0<fir and fir<sec){//double longitud ch
                seqOut.emplace_back(sec,buffer);
                buffer.clear();
                ++c;
            }
            else if(fir>0 and sec==0){  //single longitud ch
                buffer.pop_back();
                seqOut.emplace_back(fir,buffer);
                buffer.clear();
            }
            else if(fir==0){ //num o palabra
                buffer.pop_back();
                isNum = '0' <= *c and *c <= '9';
            }
        }
    }

    //Salida
    for(auto word:seqOut){
        std::cout<<"("<<word.first<<","<<word.second<<")"<<std::endl;
    }
}
