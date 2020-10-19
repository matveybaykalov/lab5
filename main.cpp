#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <iterator>
#include <set>

void print(std::pair<int, std::string> a){
    std::cout << a.first << ' ' << a.second << std::endl;
}
void printVec(int i){
    std::cout <<i << ' ';
}
bool ifNegative(std::pair<int, std::string> a){
    if (a.first<0) return true;
    else return false;
}
int insertFirst(std::pair<int, std::string> element){
    return element.first;
}
bool ifNegativeInVector(int i){
    if(i<0) return true;
    else return false;
}
bool comp(int a, int b)
{
    if (a>b) return true;
    else return false;
}

int main() {
    using std::cout;
    using std::endl;
    using std::unordered_multimap;
    using std::string;

    unordered_multimap<int, string> multiMap ( {
            {0,"zero"},
            {1, "one"},
            {2, "two"},
            {3, "three"},
            {1, "odin"},
            {2, "dva"}
    });

    std::for_each(multiMap.begin(), multiMap.end(), print);
    cout << endl;
    multiMap.insert ( std::pair<int, string>(-1, "minus one") );
    multiMap.insert ( std::pair<int, string>(-1, "minus odin") );
    multiMap.insert ( std::pair<int, string>(-1, "negative one") );
    std::for_each(multiMap.begin(), multiMap.end(), print);
    cout << endl;
    multiMap.erase(0);
    std::for_each(multiMap.begin(), multiMap.end(), print);
    cout << endl;

    std::map <int, string> Map;
    for (auto& i : multiMap){
        Map.insert(i);
    }
    std::for_each(Map.begin(), Map.end(), print);
    cout << endl;

    int count = count_if(Map.begin(), Map.end(), ifNegative);
    cout<<"count = " << count << endl;

    std::vector <int> myVec;
    std::transform(Map.begin(), Map.end(),std::back_inserter(myVec), insertFirst);
    for (auto& i:myVec){
        cout << i << ' ';
    }
    cout << endl;

    cout <<"posiition of -1 = " << std::distance(myVec.begin(), std::find(myVec.begin(), myVec.end(), -1)) << endl;

    std::replace_if(myVec.begin(), myVec.end(), ifNegativeInVector, 8);
    std::for_each(myVec.begin(), myVec.end(), printVec);
    cout << endl;

    std::sort(myVec.begin(), myVec.end(), comp);
    std::for_each(myVec.begin(), myVec.end(), printVec);
    cout << endl;

    std::set <int> mySet;
    for (auto& i:myVec){
        mySet.insert(i);
    }
    std::for_each(mySet.begin(), mySet.end(), printVec);
    cout << endl;
    return 0;
}