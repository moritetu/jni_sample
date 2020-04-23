#include "JNISample.h"

JNIEXPORT void JNICALL
Java_sample_JNISample_hello(JNIEnv *env, jobject obj, jstring jmsg)
{
  jboolean isCopy;
  const char *msg = (*env)->GetStringUTFChars(env, jmsg, &isCopy);

  if (msg == NULL)
    return;

  printf("Hello, %s\n", msg);

  (*env)->ReleaseStringUTFChars(env, jmsg, msg);
}


JNIEXPORT void JNICALL
Java_sample_JNISample_newJNISample(JNIEnv *env, jobject thisObj)
{
  jclass clazz = (*env)->GetObjectClass(env, thisObj);
  jmethodID mid = (*env)->GetMethodID(env,
                                      clazz,
                                      "<init>",
                                      "()V");

  jstring msg = (*env)->NewStringUTF(env, "New Object");
  jobject obj = (*env)->NewObject(env, clazz, mid);
  jmethodID imid = (*env)->GetMethodID(env,
                                       clazz,
                                       "callInstanceMethod",
                                       "(Ljava/lang/String;)V");
  (*env)->CallVoidMethod(env, obj, imid, msg);

  jmethodID smid = (*env)->GetStaticMethodID(env,
                                             clazz,
                                             "callStaticMethod",
                                             "(Ljava/lang/String;)V");

  (*env)->CallStaticVoidMethod(env, clazz, smid, msg);
}
