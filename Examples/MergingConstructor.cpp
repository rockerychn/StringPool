#include <cassert>
#include <string>
#include <string_view>
#include <vector>
#include <iostream>
#include <zlib.h>
#include <map>
#include "../StringPool.h"

using namespace std;
int main()
{
    if (0){
        StringPool<char> pool1, pool2, pool3, pool4;
        std::map<std::string_view, std::string_view> map;

        std::string_view s1;

        for (int i = 0; i < 1000; i++)
        {
            s1 = pool1.add("string Heading Like A new stop when i = " + std::to_string(i));
            map.insert(std::make_pair(std::to_string(i), s1));
            cout << map[std::to_string(i)] << endl;
        }
        pool1.getPoolInfo();
        pool1.compress();


        // Merging constructor can be used to combine multiple StringPool objects into one
        // It is useful when multiple pools are filled across threads then the results can be stored in a single object
    }
    // StringPool of null-terminated strings
    if (0){
        StringPool<char, true> pool;

        std::vector<std::string_view> strings;
        strings.push_back(pool.add("one"));

        // string views passed to StringPool<>::add() don't have to point to a null-terminated string
        constexpr std::string_view s{ "two three" };
        strings.push_back(pool.add(s.substr(0, 3)));
        strings.push_back(pool.add(s.substr(4)));

        // strings added to a null-terminated pool can be used with C API
        assert(std::strcmp(strings[0].data(), "one") == 0);
        assert(std::strcmp(strings[1].data(), "two") == 0);
        assert(std::strcmp(strings[2].data(), "three") == 0);

        // string_view can be skipped, and a raw const char* can be used
        const char* str = pool.add("just a pointer").data();
        assert(std::strcmp(str, "just a pointer") == 0);
    }

    // StringPool of not null-terminated strings, uses less memory (1 byte per string) by dropping C compatibility
    if (0) {
        StringPool<char, false> pool;

        std::vector<std::string_view> strings;

        // string views passed to StringPool<>::add() don't have to point to a null-terminated string
        constexpr std::string_view s1{ "In C++, a type parameter, also known as a template parameter, is a way to create generic code that can work with different types. It allows you to write code that is independent of a specific type and can be reused with multiple types.Type parameters are used in C++ templates, which are a powerful feature of the language. Templates allow you to define generic classes, functions, and data structures that can operate on different types without sacrificing type safety.To define a type parameter in C++, you use the template keyword followed by the parameter list enclosed in angle brackets (<>). Here's an example of a simple template class that takes a type parameter" };
        constexpr std::string_view s2{ "one" };
        std::string_view s3;
        strings.push_back(pool.add(s1));
        strings.push_back(pool.add(s2));

        cout << strings.size() << endl;
        //pool.getPoolInfo();
        bool ret = pool.compress();
        ret = pool.decompress();
        //s3 = pool.get(s2);
        //cout << s3 << "   " << s2 << endl;
    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool(static_cast<size_t>(32768));
        std::vector<std::string_view> strings;
        FILE* fp = fopen("../meta.txt", "r");
        if (fp == NULL)
        {
            cout << "open file failed" << endl;
            return -1;
        }
        char buf[1024];
        while (fgets(buf, 1024, fp) != NULL)
        {
            strings.push_back(pool.add(buf));
        }
        fclose(fp);

        cout << "pool cache size:" << pool.standardBlockCapacity << endl;
        bool ret = pool.compress();
        pool.getPoolInfo();
    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool(static_cast<size_t>(16384));
        std::vector<std::string_view> strings;
        FILE* fp = fopen("../meta.txt", "r");
        if (fp == NULL)
        {
            cout << "open file failed" << endl;
            return -1;
        }
        char buf[1024];
        while (fgets(buf, 1024, fp) != NULL)
        {
            strings.push_back(pool.add(buf));
        }
        fclose(fp);

        cout << "pool cache size:" << pool.standardBlockCapacity << endl;
        bool ret = pool.compress();
        pool.getPoolInfo();
    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool;
        std::vector<std::string_view> strings;
        FILE* fp = fopen("../meta.txt", "r");
        if (fp == NULL)
        {
            cout << "open file failed" << endl;
            return -1;
        }
        char buf[1024];
        while (fgets(buf, 1024, fp) != NULL)
        {
            strings.push_back(pool.add(buf));
        }
        fclose(fp);

        cout << "pool cache size:" << pool.standardBlockCapacity << endl;
        bool ret = pool.compress();
        pool.getPoolInfo();
    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool(static_cast<size_t>(4096));
        std::vector<std::string_view> strings;
        FILE* fp = fopen("../meta.txt", "r");
        if (fp == NULL)
        {
            cout << "open file failed" << endl;
            return -1;
        }
        char buf[1024];
        while (fgets(buf, 1024, fp) != NULL)
        {
            strings.push_back(pool.add(buf));
        }
        fclose(fp);

        cout << "pool cache size:" << pool.standardBlockCapacity << endl;
        bool ret = pool.compress();
        pool.getPoolInfo();
    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool(static_cast<size_t>(2048));
        std::vector<std::string_view> strings;
        FILE* fp = fopen("../meta.txt", "r");
        if (fp == NULL)
        {
            cout << "open file failed" << endl;
            return -1;
        }
        char buf[1024];
        while (fgets(buf, 1024, fp) != NULL)
        {
            strings.push_back(pool.add(buf));
        }
        fclose(fp);

        cout << "pool cache size:" << pool.standardBlockCapacity << endl;
        bool ret = pool.compress();
        pool.getPoolInfo();
    }

    // StringPool uses default block capacity of 8192 characters, but a custom value can be specified
    if (0){
        constexpr auto myCustomCapacity = 1'000'000;
        StringPool<wchar_t, false> bigPool{ myCustomCapacity };

        const auto something = bigPool.add(L"something");
        StringPool<wchar_t, false> tooSmallPool{ something.length() / 2 };

        // if you try to add a string exceeding default block capacity, StringPool will allocate a new block capable of storing the string
        const auto stillAdded = tooSmallPool.add(something);
        assert(stillAdded == L"something");
    }
    if (0){
        //在当前目录下写入100个1kb大小的文件，文件名为1.txt,2.txt,...,100.txt
        FILE* fp;
        char buf[1024];
        for (int i = 0; i < 100; i++)
        {
            sprintf(buf, "test/%d.txt", i);
            fp = fopen(buf, "w");
            if (fp == NULL)
            {
                cout << "open file failed" << endl;
                return -1;
            }
            for (int j = 0; j < 1024; j++)
            {
                fputc('a', fp);
            }
            fclose(fp);
        }
    }
        
}
