--- main.cpp	2017-08-12 12:08:42.455862735 +0200
+++ main2.cpp	2017-08-12 12:06:23.362018000 +0200
@@ -1,78 +1,70 @@
+// rtti1.cpp -- używanie operatora dynamic_cast
 #include <iostream>
-#include <ctime>
 #include <cstdlib>
+#include <ctime>
 
-using namespace std;
-
+using std::cout;
 
 class Grand
 {
-private:
-    int hold;
-public:    
-    Grand(int h = 0) : hold(h) {}
-    virtual void Speak() const { cout << "Jestem z klasy grand!\n"; };
-    virtual int Value() const { return hold; }
+    private:
+        int hold;
+    public:
+        Grand(int h = 0) : hold(h) {}
+        virtual void Speak() const { cout << "Jestem klasa Grand!\n"; }
+        virtual int Value() const { return hold; }
 };
 
-
 class Superb : public Grand
 {
-public:
-    Superb(int h = 0) : Grand(h) {}
-    void Speak() const { cout << "Jestem z klasy superb!\n"; };
-    virtual void Say() const { cout << "Przechowuje wartość klasy Superb, która wynosi " << Value() << " !\n"; }   
+    public:
+        Superb(int h = 0) : Grand(h) {}
+        void Speak() const { cout << "Jestem klasa Superb!!\n"; }
+        virtual void Say() const
+        { cout << "Przechowuję wartość klasy Superb, która wynosi " << Value() << "!\n";}
 };
 
-
 class Magnificent : public Superb
 {
-public:
-    Magnificent(int h = 0) : Superb(h) {}
-    void Speak() const { cout << "Jestem z klasy magnificent!\n"; };
-    void Say() const { cout << "Przechowuje wartość klasy Magnificent, która wynosi " << Value()<<" !\n"; }
+    private:
+        char ch;
+    public:
+        Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
+        void Speak() const { cout << "Jestem klasa Magnificent!!!\n"; }
+        void Say() const { cout << "Przechowuję znak " << ch <<
+            " oraz liczbę " << Value() << "!\n"; }
 };
 
 Grand * GetOne();
 
 int main()
 {
-    std::srand(std::time(0));    
-    
-    Grand * pg = nullptr;
-    
-    Superb * ps = nullptr;
-
+    std::srand(std::time(0));
+    Grand * pg;
+    Superb * ps;
     for (int i = 0; i < 5; i++)
     {
         pg = GetOne();
         pg->Speak();
-        
         if (ps = dynamic_cast<Superb *>(pg))
-        {
             ps->Say();
-        }
-        delete pg;
     }
-
     return 0;
 }
 
-
-Grand * GetOne()
+Grand * GetOne() // generuje losowo jeden z trzech rodzajów obiektów
 {
     Grand * p;
-
     switch (std::rand() % 3)
     {
         case 0: p = new Grand(std::rand() % 100);
                 break;
         case 1: p = new Superb(std::rand() % 100);
                 break;
-        case 2: p = new Magnificent(std::rand() % 100);
+        case 2: p = new Magnificent(std::rand() % 100,
+                        'A' + std::rand() % 26);
                 break;
     }
-
     return p;
 }
 
