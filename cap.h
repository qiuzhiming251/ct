/**
 * A simple warpper for CvCapture in C++.
 *
 * @blackball
 */

#ifndef CV_CAP_H
#define CV_CAP_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>

class Capture {
public:
    Capture() : m_cap(0){}
    ~Capture() {
	_release();
    }
    
    void open(const char *vname) {
	_release();
	m_cap = cvCaptureFromFile(vname);
	if (!m_cap) {
	    fprintf(stderr, "Can not open video: %s!\n", vname);
	    exit(0);
	}
    }

    int grab() {
	return cvGrabFrame(m_cap);
    }
    
    IplImage * retrieve() {
	return cvRetrieveFrame(m_cap);
    }

    IplImage * queryFrame() {
	return cvQueryFrame(m_cap);
    }
    
private:
    void _release() {
	cvReleaseCapture( &m_cap );
    }
    
private:
    CvCapture *m_cap;    
};

#endif 
