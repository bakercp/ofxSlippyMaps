//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


void ofApp::setup()
{
    Geo::Coordinate dresden(51.0530, 13.7337);
    Geo::Coordinate saic(41.880645, -87.624415);
    Geo::Coordinate bean(41.882672, -87.62336);
    Geo::Coordinate ts(40.758895, -73.985131);

    cout << Gd(18, 41.89155578613281, -87.63175964355469) << endl;


//    ofExit();

    ofSetFrameRate(60);
	ofSetVerticalSync(true);

    ofEnableAlphaBlending();

    Poco::ThreadPool::defaultPool().addCapacity(32);

    layers.push_back(std::make_shared<Maps::TileLayer>());
//    layers.push_back(std::make_shared<Maps::TileLayer>());
//    layers.push_back(std::make_shared<Maps::TileLayer>());

//    layers[0]->setup(std::make_shared<Maps::MicrosoftAerialStyleProvider>(),
//                     ofGetWidth(),
//                     ofGetHeight());

//    layers[1]->setup(std::make_shared<Maps::EsriSatelliteTileProvider>(),
//                     ofGetWidth(),
//                     ofGetHeight());
//
    layers[0]->setup(std::make_shared<Maps::GoogleAerialTileProvider>(),
                     ofGetWidth(),
                     ofGetHeight());
//

    for (std::size_t i = 0; i < layers.size(); ++i)
    {
        layers[i]->setCenter(saic, 19);
    }


   // layers[0]->
}


void ofApp::update()
{
    
}


void ofApp::draw()
{
    ofBackgroundGradient(ofColor(255), ofColor(0));

    ofDrawBitmapString(ofToString(layers[0]->getCenter()), ofVec2f(15, 15));

    ofFill();
    ofSetColor(255);

    ofPushMatrix();


    if (ofGetKeyPressed('0'))
    {
        layers[0]->draw(0, 0);
    }
    else if (ofGetKeyPressed('1'))
    {
        layers[1]->draw(0, 0);
    }
    else
    {
//        ofFill();
//        ofSetColor(255, 150);

//        for (std::size_t i = 0; i < layers.size(); ++i)
//        {
            layers[ofGetFrameNum() % layers.size()]->draw(0, 0);
//        }
    }



//    layers[0]->getProvider()->til


    ofPopMatrix();
}


void ofApp::keyPressed(int key)
{
    if (key == 'f' || key == 'F')
    {
		ofToggleFullscreen();
	}
    else if (key == '-')
    {
        for (std::size_t i = 0; i < layers.size(); ++i)
        {
            layers[i]->setCenter(layers[i]->getCenter().zoomBy(-0.5));
        }
    }
    else if (key == '=')
    {
        for (std::size_t i = 0; i < layers.size(); ++i)
        {
            layers[i]->setCenter(layers[i]->getCenter().zoomBy(0.5));
        }
    }
    else if (key == 'w')
    {
        for (std::size_t i = 0; i < layers.size(); ++i)
        {
            layers[i]->setCenter(layers[i]->getCenter().up(0.5));
        }
    }
    else if (key == 'a')
    {
        for (std::size_t i = 0; i < layers.size(); ++i)
        {
            layers[i]->setCenter(layers[i]->getCenter().left(0.5));
        }
    }
    else if (key == 's')
    {
        for (std::size_t i = 0; i < layers.size(); ++i)
        {
            layers[i]->setCenter(layers[i]->getCenter().down(0.5));
        }
    }
    else if (key == 'd')
    {
        for (std::size_t i = 0; i < layers.size(); ++i)
        {
            layers[i]->setCenter(layers[i]->getCenter().right(0.5));
        }
    }
}

