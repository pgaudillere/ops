
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "Topic.h"
#include "ConfigLoader.h"
#include "xmlParser.h"



using namespace std;

namespace ops
{
    using namespace xml;
    
    ConfigLoader::ConfigLoader(string fileName)
    {
        
        
        XMLNode xMainNode = XMLNode::openFileHelper(fileName.c_str(), _T("config"));
        
        XMLNode xNode = xMainNode.getChildNode(_T("manager"));
        
        //char* baseAddressChars;
        //wcstombs(baseAddressChars, xNode.getAttribute(L"baseAddress"), 100);
        
        domainAddress = string(xNode.getAttribute(_T("domainAddress")));
        
        //fultratt = stringDup(xNode.getAttribute("baseAddress"));
        int i = 0;
        xNode = xMainNode.getChildNode(_T("topic"), i);
        while(!xNode.isEmpty())
        {
            int portID = 0;
            sscanf(stringDup(xNode.getAttribute(_T("portID"))), "%i", &portID);
            topics.push_back(new Topic(
            string(xNode.getAttribute(_T("name"))),
                    portID,
                    string(xNode.getAttribute(_T("type"))),
                    domainAddress
            ));
            i++;
            xNode = xMainNode.getChildNode(_T("topic"), i);
            
        }
        
        
        
        /*ifstream inS;
    inS.open(fileName.c_str());
     
    while(true)
    {
        string lineString;
     
        getline(inS, lineString);
        if(lineString.empty())
            break;
     
        if(lineString.find("topic") != string::npos)
            topics.push_back(loadTopic(lineString));
     
    }
     
    inS.close();
     
    return topics;*/
        
    }
//Topic * ConfigLoader::loadTopic(string lineString)
//{
//    string topic = getAttribute("name", lineString);
//    int ip = atoi(getAttribute("portID", lineString).c_str());
//    string typeID = getAttribute("type", lineString);
//
//    return new Topic(topic, ip, typeID);
//}
//
//string ConfigLoader::getAttribute(string attributeString, string lineString)
//{
//    int attributLength = attributeString.size();
//    int valueStartIndex = int(lineString.find(attributeString)) + attributLength + 2;
//    string value = lineString.substr(valueStartIndex, int(lineString.find("\"", valueStartIndex) - valueStartIndex));
//    return value;
//}
}