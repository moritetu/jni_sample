package sample;

class JNISample {
    static {
        System.loadLibrary("jnisample");
    }

    public JNISample() {
        System.out.println("Called JNISample Constructor");
    }

    // C側のプログラムを呼び出すインターフェース
    public native void hello(String message);
    //    public native static void hello2(String message);
    public native void newJNISample();

    public void callInstanceMethod(String message) {
        System.out.println("callInstanceMethod:" + message);
    }

    public static void callStaticMethod(String message) {
        System.out.println("callStaticMethod:" + message);
    }

    // java -classpath path sample.JNISample message
    public static void main(String[] args) {
        JNISample hello = new JNISample();
        hello.hello(args[0]);
        hello.newJNISample();
    }
}
