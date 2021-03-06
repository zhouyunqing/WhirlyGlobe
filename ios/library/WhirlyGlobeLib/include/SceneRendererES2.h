/*
 *  SceneRendererES2.h
 *  WhirlyGlobeLib
 *
 *  Created by Steve Gifford on 10/23/12.
 *  Copyright 2011-2017 mousebird consulting
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#import "SceneRendererES.h"
#import "Lighting.h"

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>


@class WhirlyKitSceneRendererES1;
@class WhirlyKitSceneRendererES2;


/** This message is sent out by the renderer right
    before it does its thing.  We use it to loosely
    sync other threads to the render.
  */
@interface WhirlyKitFrameMessage : NSObject

/// When the message is sent, basically
@property (nonatomic) NSTimeInterval frameStart;

/// The interval between frames
@property (nonatomic) NSTimeInterval frameInterval;

/// The message is coming from this renderer
@property (nonatomic,weak) WhirlyKitSceneRendererES2 *renderer;

@end

/// Protocol for frame boundary observers
@protocol WhirlyKitFrameBoundaryObserver

/// Fill this in to get a call on the rendering (probably main) thread as the frame starts.
/// Don't do anything expensive
- (void)frameStart:(WhirlyKitFrameMessage *)msg;

@end

/// Fill this in to get a view snapshot on the next draw
@protocol WhirlyKitSnapshot
/// Called when the snapshot is take.  Use the UIImage.
- (void)snapshot:(UIImage *)image;
@end

/** Scene Renderer for OpenGL ES2.
     This implements the actual rendering.  In theory it's
     somewhat composable, but in reality not all that much.
     Just set this up as in the examples and let it run.
 */
@interface WhirlyKitSceneRendererES2 : WhirlyKitSceneRendererES

/// Add a light to the existing set
- (void)addLight:(WhirlyKitDirectionalLight *)light;

/// Replace all the lights at once. nil turns off lighting
- (void)replaceLights:(NSArray *)lights;

/// Set the default material
- (void)setDefaultMaterial:(WhirlyKitMaterial *)mat;

/// The next time through we'll redo the render setup.
/// We might need this if the view has switched away and then back.
- (void)forceRenderSetup;

/// Add a frame boundary observer
- (void)addFrameObserver:(NSObject<WhirlyKitFrameBoundaryObserver> *)observer;

/// Remove a frame boundary observer
- (void)removeFrameObserver:(NSObject<WhirlyKitFrameBoundaryObserver> *)observer;

/// If set, we'll let the render run on a dispatch queue.
/// This lets the UI run in the main thread without interference,
///  but it does mean you can't mess with the rendering context.
@property (nonatomic,assign) bool dispatchRendering;

/// Set if we want a screenshot on the next draw
@property (nonatomic,weak) NSObject<WhirlyKitSnapshot> *snapshotDelegate;

// Used by a subclass
- (id) initWithVersion:(EAGLRenderingAPI)apiVersion size:(CGSize)size;

@end
