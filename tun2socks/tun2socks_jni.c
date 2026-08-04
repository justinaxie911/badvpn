#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include <android/log.h>

extern int tun2socks_main(int argc, char **argv);

#define LOG_TAG "Tun2SocksJNI"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

JNIEXPORT jint JNICALL
Java_kpn_soft_dev_kpnrevolution_natives_Tun2Socks_runTun2Socks(JNIEnv *env, jobject thiz, jobjectArray args) {
    // Menghitung jumlah argumen
    int argc = (*env)->GetArrayLength(env, args);
    char **argv = (char **) malloc(sizeof(char *) * (argc + 1));
    
    // Konversi Java String Array ke C char**
    for (int i = 0; i < argc; i++) {
        jstring string = (jstring) (*env)->GetObjectArrayElement(env, args, i);
        const char *rawString = (*env)->GetStringUTFChars(env, string, 0);
        argv[i] = strdup(rawString);
        (*env)->ReleaseStringUTFChars(env, string, rawString);
    }
    argv[argc] = NULL; // Null terminator

    // Panggil fungsi tun2socks
    int result = tun2socks_main(argc, argv);

    // Bersihkan memory
    for (int i = 0; i < argc; i++) {
        free(argv[i]);
    }
    free(argv);

    return result;
}
