//ofDxSharedTexture example written by Philippe Laulheret for Second Story
//Simple example to use nv_interop extension
//Based on microsoft dx sdk sample
//MIT Licensing

#pragma once

#include "ofMain.h"

#include "dxThread.h"

class testApp : public ofBaseApp{


	public:

		ofTexture sharedTexture;
		HANDLE gl_device;
		HANDLE handle_shared_texture;

		myDxThread *dxThread;

		void cleanUp();

		void setup();
		void update();
		void draw();
		void exit(ofEventArgs & args);
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
