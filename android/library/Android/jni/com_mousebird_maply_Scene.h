/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_mousebird_maply_Scene */

#ifndef _Included_com_mousebird_maply_Scene
#define _Included_com_mousebird_maply_Scene
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_mousebird_maply_Scene
 * Method:    addShaderProgram
 * Signature: (Lcom/mousebird/maply/Shader;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Scene_addShaderProgram
  (JNIEnv *, jobject, jobject, jstring);

/*
 * Class:     com_mousebird_maply_Scene
 * Method:    addRenderTargetNative
 * Signature: (JIIJ)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Scene_addRenderTargetNative
  (JNIEnv *, jobject, jlong, jint, jint, jlong);

/*
 * Class:     com_mousebird_maply_Scene
 * Method:    removeRenderTargetNative
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Scene_removeRenderTargetNative
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_mousebird_maply_Scene
 * Method:    teardownGL
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Scene_teardownGL
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_Scene
 * Method:    getProgramIDBySceneName
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_mousebird_maply_Scene_getProgramIDBySceneName
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_mousebird_maply_Scene
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Scene_nativeInit
  (JNIEnv *, jclass);

/*
 * Class:     com_mousebird_maply_Scene
 * Method:    addChangesNative
 * Signature: (Lcom/mousebird/maply/ChangeSet;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Scene_addChangesNative
  (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
