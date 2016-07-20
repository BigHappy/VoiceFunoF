#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include <string>
//template <typename List>



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    string getWord();
    
    ofxTCPClient tcpClient;
    bool connected;
    string str;
    //string sList[10];
    //string tList[10];
    
    
    string msgTx, msgRx;
    
    ofTrueTypeFont  mono;
    ofTrueTypeFont  monosm;
    
    
    float counter;
    int connectTime;
    int deltaTime;
    
    int size;
    string word;
    string voice;
    
    
    //void split(const std::string& s, const std::string& delim, List& result);

		
};
