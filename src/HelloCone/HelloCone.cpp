// COPYRIGHT_BEGIN
//
// The MIT License (MIT)
//
// Copyright (c) 2018 Wizzer Works
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//  For information concerning this header file, contact Mark S. Millard,
//  of Wizzer Works at msm@wizzerworks.com.
//
//  More information concerning Wizzer Works may be found at
//
//      http://www.wizzerworks.com
//
// COPYRIGHT_END

// Include Open Inventor header files.
#include <Inventor/Xt/SoXt.h>
#include <Inventor/Xt/SoXtRenderArea.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/nodes/SoSeparator.h>

int main(int argc, char **argv)
{
    // Initialize SoXt (and implicitly Coin). This returns a main window to use.
    // If unsuccessful, exit.
    Widget window = SoXt::init(argv[0]);  // Pass the application name.
    if (window == NULL)
        return 1;

    // Make a scene graph containing a red cone.
    SoSeparator *root = new SoSeparator;
    SoPerspectiveCamera *camera = new SoPerspectiveCamera;
    SoMaterial *material = new SoMaterial;
    root->ref();
    root->addChild(camera);
    root->addChild(new SoDirectionalLight);

    material->diffuseColor.setValue(1.0, 0.0, 0.0);  // Set red color.
    root->addChild(material);
    root->addChild(new SoCone);

    // Create a render area in which to see our scene graph.
    // The render area will appear within the main window.
    SoXtRenderArea *renderArea = new SoXtRenderArea(window);

    // Make the camera see everything.
    camera->viewAll(root, renderArea->getViewportRegion());

    // Put the scene into renderArea, change the title of the renderArea.
    renderArea->setSceneGraph(root);
    renderArea->setTitle("Hello Cone");
    renderArea->show();

    SoXt::show(window);  // Display main window.
    SoXt::mainLoop();    // Main Inventor event loop.

    root->unref();
    return 0;
}
