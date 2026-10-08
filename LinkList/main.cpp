#include <iostream>
#include <limits>
#include "LinkList.h"
using namespace std;

// 读取整数；如果输入了字母等内容，就提示重新输入
int ReadInt()
{
    int value;
    while (!(cin >> value))
    {
        if (cin.eof())
            exit(0);

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "请输入整数：";
    }
    return value;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    LinkList<int> list(a, 5);
    int choice;

    do
    {
        cout << "\n====== 单链表操作菜单 ======\n";
        cout << "1. 显示链表\n";
        cout << "2. 查看链表长度\n";
        cout << "3. 获取指定位置的元素\n";
        cout << "4. 查找元素的位置\n";
        cout << "5. 插入元素\n";
        cout << "6. 删除元素\n";
        cout << "0. 退出\n";
        cout << "请选择：";
        choice = ReadInt();

        switch (choice)
        {
        case 1:
            if (list.ListLength() == 0)
                cout << "链表为空\n";
            else
            {
                cout << "链表元素：";
                list.PrintLinkList();
                cout << endl;
            }
            break;

        case 2:
            cout << "链表长度：" << list.ListLength() << endl;
            break;

        case 3:
        {
            cout << "请输入位置（从1开始）：";
            int pos = ReadInt();

            if (pos < 1 || pos > list.ListLength())
                cout << "位置不合法\n";
            else
                cout << "该位置的元素：" << list.Get(pos) << endl;

            break;
        }

        case 4:
        {
            cout << "请输入要查找的元素：";
            int item = ReadInt();
            int pos = list.Locate(item);

            if (pos == 0)
                cout << "没有找到该元素\n";
            else
                cout << "该元素首次出现的位置：" << pos << endl;

            break;
        }

        case 5:
        {
            cout << "请输入插入位置（1到"
                 << list.ListLength() + 1 << "）：";
            int pos = ReadInt();

            if (pos < 1 || pos > list.ListLength() + 1)
            {
                cout << "插入位置不合法\n";
                break;
            }

            cout << "请输入插入的元素：";
            int item = ReadInt();

            list.Insert(pos, item);
            cout << "插入成功\n";
            break;
        }

        case 6:
        {
            cout << "请输入删除位置（从1开始）：";
            int pos = ReadInt();

            if (pos < 1 || pos > list.ListLength())
                cout << "删除位置不合法\n";
            else
                cout << "已删除元素：" << list.Delete(pos) << endl;

            break;
        }
        case 7:
        {
            list.Invert();
            cout << "逆置后的链表：";
            list.PrintLinkList();
            cout << endl;
            break;
        }

        case 8:
        {
            // 检查当前链表是否按升序排列
            bool sorted = true;
            int len = list.ListLength();

            for (int i = 1; i < len; i++)
            {
                if (list.Get(i) > list.Get(i + 1))
                {
                    sorted = false;
                    break;
                }
            }

            if (!sorted)
            {
                cout << "当前链表不是升序，不能进行有序合并\n";
                break;
            }

            LinkList<int> other;

            cout << "请输入第二个链表的元素个数：";
            int n = ReadInt();

            if (n < 0)
            {
                cout << "元素个数不能为负\n";
                break;
            }

            cout << "请按从小到大的顺序输入元素\n";

            for (int i = 1; i <= n; i++)
            {
                cout << "第" << i << "个元素：";
                int item = ReadInt();

                if (i > 1 && item < other.Get(i - 1))
                    sorted = false;

                other.Insert(i, item);
            }

            if (!sorted)
            {
                cout << "第二个链表不是升序，合并取消\n";
                break;
            }

            // 用独立的空链表接收合并结果
            LinkList<int> result;
            result.Merge(list, other);

            // 将结果的节点转交回 list，方便继续使用菜单操作
            list.Merge(result, other);

            cout << "合并后的链表：";
            list.PrintLinkList();
            cout << endl;
            break;
        }
        case 0:
            cout << "程序已退出\n";
            break;

        default:
            cout << "选项不合法，请重新选择\n";
        }
    } while (choice != 0);

    return 0;
}