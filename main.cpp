#include <cassert>
#include <string>
#include <string_view>
#include <vector>
#include <iostream>
#include <zlib.h>
#include <map>
#include "meta_pool.h"

using namespace std;
int main()
{
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool(static_cast<size_t>(32768));
        std::vector<std::string_view> strings;
        FILE* fp = fopen("meta.txt", "r");
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

        cout << "pool cache size: " << pool.standardBlockCapacity << endl;
        
        auto start = std::chrono::high_resolution_clock::now();
        bool ret = pool.compress();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        pool.getPoolInfo();
        cout << "compress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        ret = pool.decompress();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "decompress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl << std::endl;
    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool(static_cast<size_t>(16384));
        std::vector<std::string_view> strings;
        FILE* fp = fopen("meta.txt", "r");
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

        cout << "pool cache size: " << pool.standardBlockCapacity << endl;
        auto start = std::chrono::high_resolution_clock::now();
        bool ret = pool.compress();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        pool.getPoolInfo();
        cout << "compress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        ret = pool.decompress();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "decompress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl << std::endl;

    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool;
        std::vector<std::string_view> strings;
        FILE* fp = fopen("meta.txt", "r");
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

        cout << "pool cache size: " << pool.standardBlockCapacity << endl;
        auto start = std::chrono::high_resolution_clock::now();
        bool ret = pool.compress();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        pool.getPoolInfo();
        cout << "compress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        ret = pool.decompress();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "decompress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl << std::endl;
    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool(static_cast<size_t>(4096));
        std::vector<std::string_view> strings;
        FILE* fp = fopen("meta.txt", "r");
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

        cout << "pool cache size: " << pool.standardBlockCapacity << endl;
        auto start = std::chrono::high_resolution_clock::now();
        bool ret = pool.compress();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        pool.getPoolInfo();
        cout << "compress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        ret = pool.decompress();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "decompress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl << std::endl;
    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool(static_cast<size_t>(2048));
        std::vector<std::string_view> strings;
        FILE* fp = fopen("meta.txt", "r");
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

        cout << "pool cache size: " << pool.standardBlockCapacity << endl;
        auto start = std::chrono::high_resolution_clock::now();
        bool ret = pool.compress();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        pool.getPoolInfo();
        cout << "compress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        ret = pool.decompress();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "decompress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl << std::endl;
    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool(static_cast<size_t>(1024));
        std::vector<std::string_view> strings;
        FILE* fp = fopen("meta.txt", "r");
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

        cout << "pool cache size: " << pool.standardBlockCapacity << endl;
        auto start = std::chrono::high_resolution_clock::now();
        bool ret = pool.compress();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        pool.getPoolInfo();
        cout << "compress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        ret = pool.decompress();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "decompress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl << std::endl;
    }
    {
        //读取文件meta.txt，将每一行作为一个字符串存入StringPool
        StringPool<char, false> pool(static_cast<size_t>(512));
        std::vector<std::string_view> strings;
        FILE* fp = fopen("meta.txt", "r");
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

        cout << "pool cache size: " << pool.standardBlockCapacity << endl;
        auto start = std::chrono::high_resolution_clock::now();
        bool ret = pool.compress();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        pool.getPoolInfo();
        cout << "compress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        ret = pool.decompress();
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "decompress time: " << duration.count() << " us" << " , per block: " << duration.count()/pool.blocks.size() << " us" << std::endl << std::endl;
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
