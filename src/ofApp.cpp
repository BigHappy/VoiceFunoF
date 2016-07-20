#include "ofApp.h"
#include <string>
#include <vector>
#include <iostream>

template <typename List>
void split(const std::string& s, const std::string& delim, List& result)
{
    result.clear();
    
    using string = std::string;
    string::size_type pos = 0;
    
    while(pos != string::npos )
    {
        string::size_type p = s.find(delim, pos);
        
        if(p == string::npos)
        {
            result.push_back(s.substr(pos));
            break;
        }
        else {
            result.push_back(s.substr(pos, p - pos));
        }
        
        pos = p + delim.size();
    }
}


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    connected = tcpClient.setup("localhost", 10500);
}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0);
    ofDrawBitmapString(voice,100, 200 );
    voice = getWord();
    cout << voice << " / ";
}

string ofApp::getWord(){
    word = "";
    if(tcpClient.isConnected()) {
        string dataIn2 = tcpClient.receiveRaw();
        std::vector<string> sList;
        split(dataIn2, "WORD", sList);
        for(int i=1;i<sList.size();i++){
            string tmp = sList[i];
            std::vector<string> tList;
            split(tmp, "\"", tList);
            word += tList[1];
            //cout << word << " / ";

        }
        
        return word;
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}



