//
// Created by GH on 2018/11/26.
//

#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <values.h>
#include "Interview.h"
using namespace swordToOffer;

namespace swordToOffer {

    BinaryTreeNode* createBinaryTreeNodebyPre() {
        BinaryTreeNode *pRoot = nullptr;
        char ch;
        scanf("%c", &ch);
        if (ch != '#') {
            pRoot = new BinaryTreeNode;
            pRoot->m_nValue = ch - 48;
            pRoot->m_pLeft = createBinaryTreeNodebyPre();
            pRoot->m_pRight = createBinaryTreeNodebyPre();
        }
        return pRoot;
    }


    BinaryTreeNode* createBinaryTreeNodebyPre(char *str) {
        if (str == nullptr)
            return nullptr;
        int index = 0;
        BinaryTreeNode *pRoot = createBinaryTreeNodebyPreCore(str, &index);
        return pRoot;
    }

    BinaryTreeNode* createBinaryTreeNodebyPreCore(char *str, int *index) {
        BinaryTreeNode *pRoot = nullptr;
        if (str[*index] == '\0' || str[*index] == '#') {
            *index+=1;
            return pRoot;
        }
        if (str[*index] != '#') {
            pRoot = new BinaryTreeNode;
            pRoot->m_nValue = str[*index] - 48;
            *index += 1;
            pRoot->m_pLeft = createBinaryTreeNodebyPreCore(str, index);
            pRoot->m_pRight = createBinaryTreeNodebyPreCore(str, index);
        }
        return pRoot;
    }

    void PreBinaryTree(BinaryTreeNode* pRoot) {
        if (pRoot) {
            gh::print(pRoot->m_nValue);
            PreBinaryTree(pRoot->m_pLeft);
            PreBinaryTree(pRoot->m_pRight);
        }
    }

    void addListNode(ListNode* head, ListNode* newlistNode) {
        if (head->m_pNext == nullptr) {
            head->m_pNext = newlistNode;
            return;
        }
        ListNode *listNodeTemp = head;
        while (listNodeTemp->m_pNext != nullptr)
            listNodeTemp = listNodeTemp->m_pNext;
        listNodeTemp->m_pNext = newlistNode;
    }

    ListNode* newListNode(int* numbers, int length) {
        if (numbers == nullptr || length <= 0)
            return nullptr;
        ListNode *pHead = new ListNode();
        ListNode *pNode = pHead;
        for (int i = 0; i < length; ++i) {
            pNode->m_nValue = numbers[i];
            if (i!=length-1)
                pNode->m_pNext = new ListNode;
            else
                pNode->m_pNext = nullptr;
            pNode = pNode->m_pNext;
        }
        return pHead;
    }

    void addListNode(ListNode** pHead, int value) {
        ListNode *newList = new ListNode();
        newList->m_pNext = nullptr;
        newList->m_nValue = value;
        if (*pHead == nullptr) {
            *pHead = new ListNode;
            *pHead = newList;
        } else {
            ListNode *pNode = *pHead;
            while (pNode->m_pNext != nullptr) {
                pNode = pNode->m_pNext;
            }
            pNode->m_pNext = newList;
        }
    }

    void printListNode(ListNode* head) {
        if (head == nullptr)
            return;
        ListNode *listNodeTemp = head;
        while (listNodeTemp != nullptr) {
            std::cout<<listNodeTemp->m_nValue<<" ";
            listNodeTemp = listNodeTemp->m_pNext;
        }
        std::cout<<std::endl;
    }

    void printListNode(ListNode** pHead) {
        if (*pHead == nullptr)
            return;
        ListNode *pNode = *pHead;
        while (pNode != nullptr) {
            std::cout<<pNode->m_nValue<<" ";
            pNode = pNode->m_pNext;
        }
        std::cout<<std::endl;
    }

    ListNode* newListNode(int value) {
        ListNode *p = new ListNode();
        p->m_nValue = value;
        p->m_pNext = nullptr;
        return p;
    }

    bool duplicate(int numbers[], int length, int *duplicate) {
        if (numbers == nullptr || length <= 0)
            return false;

        for (int i = 0; i < length; ++i) {
            if (numbers[i] < 0 || numbers[i] >= length)
                return false;
        }

        for (int i = 0; i < length; ++i) {
            while (numbers[i] != i) {
                if (numbers[i] == numbers[numbers[i]]) {
                    *duplicate = numbers[i];
                    return true;
                }
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;
    }

    int getDuplication(const int* numbers, int length) {
        if (numbers == nullptr || length <= 0)
            return -1;
        int start = 1;
        int end = length - 1;
        while(start <= end) {
            int middle = (end + start) / 2;
            int count = countRange(numbers, length, start, middle);
            if (end == start) {
                if (count > 1)
                    return start;
                else
                    break;
            }
            if (count > (middle - start + 1))
                end = middle;
            else
                start = middle + 1;
        }
        return -1;
    }

    int countRange(const int* numbers, int length, int start, int end) {
        if (numbers == nullptr || length <= 0)
            return 0;
        int count = 0;
        for (int i = 0; i < length; ++i) {
            if (numbers[i] <= end && numbers[i] >= start)
                ++count;
        }
        return count;
    }

    bool Find(int matrix[][4], int rows, int columns, int number) {
        if (matrix == nullptr || rows <= 0 || columns <= 0)
            return false;
        for (int i = columns - 1; i >= 0; --i) {
            for (int j = 0; j < rows; ++j) {
                if (matrix[j][i] == number)
                    return true;
                if (matrix[j][i] > number)
                    break;
                else
                    continue;
            }
            ++matrix;
        }
        return false;
    }

    bool Find(int *matrix, int rows, int columns, int number) {
        if (matrix == nullptr || rows <=0 || columns <= 0)
            return false;
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >= 0) {
            if (matrix[row * columns + column] == number)
                return true;
            if (matrix[row * columns + column] > number)
                --column;
            else
                ++row;
        }
        return false;
    }

    void ReplaceBlank(char string[], int length) {
        if (string == nullptr || length <= 0)
            return;
        int stringLength = 0;
        int blankCount = 0;
        while (string[stringLength] != '\0') {
            if (string[stringLength] == ' ')
                ++blankCount;
            ++stringLength;
        }
        int newLength = stringLength + blankCount * 2;
        if (newLength > length)
            return;
        int indexp2 = newLength;
        int indexp1 = stringLength;
        while (indexp1 != indexp2) {
            if (string[indexp1] != ' ') {
                string[indexp2--] = string[indexp1--];
            } else {
                string[indexp2--] = '0';
                string[indexp2--] = '2';
                string[indexp2--] = '%';
                --indexp1;
            }
        }
    }

    void MergeArray(int *numbers1, int length1, int *numbers2, int length2) {
        if (numbers1 == nullptr || numbers2 == nullptr || length2 <= 0)
            return;
        if (length1 <= 0) {
            int nb2 = length2 - 1;
            while (nb2 >= 0)
                numbers1[nb2] = numbers2[nb2--];
            return;
        }
        int newLength = length1 + length2 - 1;
        int nb1 = length1 - 1;
        int nb2 = length2 - 1;
        while (newLength >= 0 && nb1 >= 0 && nb2 >= 0) {
            if (numbers1[nb1] > numbers2[nb2])
                numbers1[newLength--] = numbers1[nb1--];
            else
                numbers1[newLength--] = numbers2[nb2--];
        }
    }

    BinaryTreeNode* ConstructByFM(int *preorder, int *inorder, int length) {
        if (preorder == nullptr || inorder == nullptr || length <= 0 )
            return nullptr;
        return  ConstructByFMCore(preorder, preorder + length - 1, inorder, preorder + length - 1);
    }

    BinaryTreeNode* ConstructByFMCore(int *startPreorder, int *endPreorder,
                                      int *startInorder, int *endInorder) {
        int rootValue = startPreorder[0];
        BinaryTreeNode* root = new BinaryTreeNode();
        root->m_nValue = rootValue;
        root->m_pLeft = root->m_pRight = nullptr;
        if (startPreorder == endPreorder) {
            if (startInorder == endInorder && *startPreorder == *startInorder)
                return root;
            else
                throw std::exception();
        }
        int *rootInorder = startPreorder;
        while (rootInorder <= endInorder && *rootInorder != rootValue )
            ++rootInorder;
        if (rootInorder == endInorder && *rootInorder != rootValue)
            throw std::exception();
        int leftLength = rootInorder - startInorder;
        int * leftPreorderEnd = startPreorder + leftLength;
        if (leftLength > 0) {
            root->m_pLeft = ConstructByFMCore(leftPreorderEnd + 1, leftPreorderEnd,
                                              startInorder, rootInorder - 1);
        }
        if (leftLength < endPreorder - startPreorder) {
            root->m_pRight = ConstructByFMCore(leftPreorderEnd + 1, endPreorder,
                                               rootInorder + 1, endInorder);
        }
        return root;
    }

    long long FibonacciByRecursion(unsigned int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        return FibonacciByRecursion(n - 1) + FibonacciByRecursion(n - 2);
    }

    long long Fibonacci(unsigned int n) {
        long long firstNumber = 0;
        long long secondNumber = 1;
        if (n == 0)
            return firstNumber;
        if (n == 1)
            return secondNumber;
        long long fibonacci = 0;
        for (int i = 2; i <= n; ++i) {
            fibonacci = firstNumber + secondNumber;
            firstNumber = secondNumber;
            secondNumber = fibonacci;
        }
        return fibonacci;
    }

    int RandomInRange(int start, int end) {
        if (end > start) {
            srand(time(NULL));
            return start + rand() % ((end - start));
        }
        return 0;
    }

    void swap_element(int *a, int *b) {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    int Partition(int data[], int length, int start, int end) {
        if (data == nullptr || length <= 0 || start < 0 || end >= length)
            gh::print("ERROR");
//            throw new std::exception();
        int index = RandomInRange(start, end);
//        gh::print("index: ", index, "index data: ", data[index]);
        std::swap(data[index], data[end]);
        int small = start - 1;
        for (index = start; index < end; ++index) {
            if (data[index] < data[end]) {
                ++small;
                if (small != index)
                    std::swap(data[index], data[small]);
            }
        }
        ++small;
        std::swap(data[small], data[end]);
        return small;
    }

    void QuickSort(int data[], int length, int start, int end) {
        if (start == end)
            return;
        int index = Partition(data, length, start, end);
        if (index > start)
            QuickSort(data, length, start, index - 1);
        if (index < end)
            QuickSort(data, length, index + 1, end);
    }

    void sortAges(int *ages, int length) {
        if (ages == nullptr || length < 0)
            gh::print("exception");
        int maxage = 99;
        int ageCount[maxage + 1];
        for (int i = 0; i < 100; ++i) {
            ageCount[i] = 0;
        }
        for (int i = 0; i < length; ++i) {
            int age = ages[i];
            if (age > 99 || age < 0)
                gh::print("exception");
            ++ageCount[age];
        }
        int k = 0;
        for (int i = 0; i <= maxage; ++i) {
            for (int j = 0; j < ageCount[i]; ++j) {
                ages[k++] = i;
            }
        }
    }

	int Min(int *numbers, int length) {
        if (numbers == nullptr || length <= 0)
            throw new std::exception();
        int indexP1 = 0;
        int indexP2 = length - 1;
        int indexMiddle;
        while (indexP2 - indexP1 > 1) {
            indexMiddle = (indexP1 + indexP2) / 2;
            //当三个值相等
            if (numbers[indexP1] == numbers[indexMiddle] and numbers[indexMiddle] == numbers[indexP2]) {
                int min = numbers[indexP2];
                for (int i = indexP1; i < indexP2; ++i) {
                    if (numbers[i] < min)
                        min = numbers[i];
                }
                return min;
            }

            if (numbers[indexP1] <= numbers[indexMiddle]) {
                indexP1 = indexMiddle;
                continue;
            }
            if (numbers[indexP2] >= numbers[indexMiddle]) {
                indexP2 = indexMiddle;
            }
        }
        return numbers[indexP1] < numbers[indexP2] ? numbers[indexP1] : numbers[indexP2];
    }

    bool hasPath(char *matrix, int rows, int cols, char *str) {
        if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
            return false;
        bool visit[rows * cols];
        for (int i = 0; i < cols * rows; ++i)
            visit[0] = false;

        int pathLength = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (hasPathCore(matrix, rows, cols, row, col, str, visit, pathLength))
                    return true;
            }
        }
        return false;
    }

    bool hasPathCore(char *matrix, int rows, int cols, int row, int col, char *str, bool *visited, int pathLength) {
        if (str[pathLength] == '\0')
            return true;
        bool hasPath = false;
        if (row >= 0 and col >= 0 and row < rows and col < cols and matrix[row * cols + col] == str[pathLength] and !visited[row * cols + col]) {
            ++pathLength;
            visited[row * cols + col] = true;
            hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, visited, pathLength) ||
                      hasPathCore(matrix, rows, cols, row, col - 1, str, visited, pathLength) ||
                      hasPathCore(matrix, rows, cols, row + 1, col, str, visited, pathLength) ||
                      hasPathCore(matrix, rows, cols, row, col + 1, str, visited, pathLength);
            if (!hasPath) {
                visited[row * cols + col] = false;
            }
        }
        return hasPath;
    }

    int robotMoveCount(int threshold, int rows, int cols) {
        if (rows < 0 || cols < 0)
            return 0;
        bool visited[rows * cols];
        for (int i = 0; i < cols * rows; ++i) {
            visited[i] = false;
        }
        return robotMoveCore(rows, cols, 0, 0, threshold, visited);
    }

    int robotMoveCore(int rows, int cols, int row, int col, int threshold, bool *visited) {
        int counts = 0;
        if (row < rows && col < cols && row >= 0 && col >= 0 && computeThreshold(row, col, threshold) && !visited[row * cols + col]) {
            visited[row * cols + col] = true;
            counts = 1 +
            robotMoveCore(rows, cols, row - 1, col, threshold, visited) +
            robotMoveCore(rows, cols, row, col - 1, threshold, visited) +
            robotMoveCore(rows, cols, row, col + 1, threshold, visited) +
            robotMoveCore(rows, cols, row + 1, col, threshold, visited);
        }
        return counts;
    }

    bool computeThreshold(int row, int col, int threshold) {
        if (row < 0 || col < 0 || threshold < 0 )
            return false;
        int thresholdTemp = 0;
        while (row % 10 != 0) {
            thresholdTemp += row % 10;
            row /= 10;
        }
        while (col % 10 != 0) {
            thresholdTemp += col % 10;
            col /= 10;
        }
        return thresholdTemp < threshold;
    }

    int maxProductAfterCutting_solution(int length) {
        if (length < 2)
            return 0;
        if (length == 2)
            return 2;
        if (length == 3)
            return 1;
        int *products = new int[length + 1];
        products[0] = 0;
        products[1] = 0;
        products[2] = 2;
        products[3] = 3;
        int max = 0;
        for(int i = 4; i <= length; ++i) {
            max = 0;
            for (int j = 1; j <= i/2; ++j) {
                int product = products[j] * products[i - j];
                if (product > max)
                    max = product;
            }
            products[i] = max;
        }
        max = products[length];
        delete[] products;
        return max;
    }

    int NumberOf1(int n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag) {
            if (flag & n)
                ++count;
            flag = flag << 1;
        }
        return count;
    }

    int NumberOf1_new(int n) {
        int count = 0;
        while (n) {
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }

    double Pow(double base, int exponent) {
        if (exponent == 0)
            return 1.0;
        if (base == 1)
            return base;
        if (fabs(base - 1.0) < 9E-10)
            return 0;
        bool isPositive = true;
        if (exponent < 0) {
            isPositive = false;
            exponent = -exponent;
        }
        double result;
        if (exponent % 2 == 0) {
            result = Pow(base, exponent / 2) * Pow(base, exponent / 2);
        } else {
            result = base * Pow(base, exponent / 2) * Pow(base, exponent / 2);
        }
        return isPositive ? result : 1/result;
    }

    void Print1ToMaxOfDigits(int n) {
        if (n < 0)
            return;
        char *number = new char[n + 1];
        number[n] = '\0';
        number[0] = '0';
        Print1ToMaxOfDigitsRecursively(number, n ,0);
        delete[] number;
    }

    void Print1ToMaxOfDigitsRecursively(char* number, int length, int index) {
        if (index == length) {
            printNumber(number);
            return;
        }
        for (int i = 0; i < 10; ++i) {
            number[index + 1] = static_cast<char>(i + '0');
            Print1ToMaxOfDigitsRecursively(number, length, index + 1);
        }
    }

    void printNumber(char *number) {
        if (number == nullptr)
            return;
        int index = 0;
        bool isFirst = false;
        while(number[index] != '\0') {
            if (!isFirst && number[index] != '0') {
                isFirst = true;
            }
            if (isFirst)
                printf("%c", number[index]);
            ++index;
        }
        printf("\t");
    }

    void DeleteNode(ListNode* pListHead, ListNode* pToBeDelete) {
        if (pListHead == nullptr || pToBeDelete == nullptr)
            return;
        if (pToBeDelete->m_pNext != nullptr) {
            ListNode *tempListNode = pToBeDelete->m_pNext;
            pToBeDelete->m_nValue = tempListNode->m_nValue;
            pToBeDelete->m_pNext = tempListNode->m_pNext;
            delete tempListNode;
            tempListNode = nullptr;
        } else if (pListHead == pToBeDelete) {
            delete pToBeDelete;
            pToBeDelete = nullptr;
            pListHead = nullptr;
        } else {
            ListNode *tempListNode = pListHead;
            while (tempListNode->m_pNext != pToBeDelete) {
                tempListNode = tempListNode->m_pNext;
            }
            tempListNode->m_pNext = nullptr;
            delete pToBeDelete;
            pToBeDelete = nullptr;
        }
    }

    void DeleteDuplication(ListNode **pHead) {
        if (pHead == nullptr || *pHead == nullptr)
            return;
        ListNode *preNode = nullptr;
        ListNode *pTempHead = *pHead;
        while (pTempHead != nullptr) {
            ListNode *pNext = pTempHead->m_pNext;
            if (pNext != nullptr && pTempHead->m_nValue == pNext->m_nValue) {
                int value = pTempHead->m_nValue;
                ListNode* toBeDelete = pTempHead;
                while (toBeDelete != nullptr && toBeDelete->m_nValue == value) {
                    pNext = toBeDelete->m_pNext;
                    delete toBeDelete;
                    toBeDelete = nullptr;
                    toBeDelete = pNext;
                }

                if (preNode == nullptr)
                    *pHead = pNext;
                else
                    preNode->m_pNext = pNext;
                pTempHead = pNext;

            } else {
                preNode = pTempHead;
                pTempHead = pTempHead->m_pNext;
            }
        }
    }

    bool match(char* str, char* pattern) {
        if (str == nullptr || pattern == nullptr)
            return false;
        return matchCore(str, pattern);
    }

    bool matchCore(char* str, char* pattern) {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        if ( *(pattern + 1) == '*') {
            if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
                return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
            } else {
                return matchCore(str, pattern + 2);
            }
        }
        if (*str == *pattern || (*pattern == '.' && *str != '\0'))
            return matchCore(str + 1, pattern + 1);
        return false;
    }

    void RecorderOddEven(int *pData, int length) {
        if (pData == 0 || length <= 0)
            return;
        int left = 0, right = length - 1;
        while (left < right) {
            while(left < right && pData[left] % 2 != 0)
                ++left;
            while(left < right && pData[right] % 2 == 0)
                --right;
            if (left < right) {
                int temp = pData[left];
                pData[left] = pData[right];
                pData[right] = temp;
                ++left;
            }
//            if (pData[left] % 2 != 0 && pData[right] % 2 != 0)
//                ++left;
//            if (pData[left] % 2 == 0 && pData[right] % 2 == 0)
//                --right;
//            if (pData[left] % 2 == 0 && pData[right] % 2 != 0) {
//                int temp = pData[left];
//                pData[left] = pData[right];
//                pData[right] = temp;
//                ++left;
//            }
//            if (pData[left] % 2 != 0 && pData[right] % 2 == 0) {
//                --right;
//            }
        }
    }

    bool isNumberic(const char* str) {
        if (str == nullptr)
            return false;
        scanInteger(&str);
        if (*str == '.') {
            ++str;
//            number = scanUnsignedInteger(&str) || number;
            scanUnsignedInteger(&str);
        }
        if (*str == 'e' || *str == 'E') {
            ++str;
//            number = scanInteger(&str) && number;
            scanInteger(&str);
        }
//        return number && *str == '\0';
        return *str == '\0';
    }

    bool scanInteger(const char** str) {
        if (**str == '+' || **str == '-')
            ++(*str);
        return scanUnsignedInteger(str);
    }

    bool scanUnsignedInteger(const char** str) {
        const char *before = *str;
        while (**str != '\0' && **str >= '0' && **str <= '9')
            ++(*str);
        return *str > before;
    }

    ListNode* FindKthToTail(ListNode* pListNode, unsigned int k) {
        if (pListNode == nullptr || k <= 0)
            return nullptr;
        int move = 0;
        ListNode *pNode = pListNode;
        ListNode *pHead = pListNode;

        while(pHead->m_pNext != nullptr) {
            pHead = pHead->m_pNext;
            ++move;
            if (move >= k)
                pNode = pNode->m_pNext;
        }
        return pNode;
    }

    ListNode* MeetNode(ListNode* pHead) {
        if (pHead == nullptr)
            return nullptr;
        ListNode* pSlow = pHead->m_pNext;
        if (pSlow == nullptr)
            return nullptr;

        ListNode* pFast = pSlow->m_pNext;
        while (pFast != pSlow && pFast->m_pNext != nullptr) {
            pFast = pFast->m_pNext->m_pNext;
            pSlow = pSlow->m_pNext;
        }
        if (pFast == nullptr)
            return nullptr;
        return pFast;
    }

    ListNode* EntryNodeLoop(ListNode* pHead) {
        if (pHead == nullptr)
            return nullptr;
        ListNode *pNode = MeetNode(pHead);
        if (pNode == nullptr)
            return nullptr;
        int LoopLength = 1;
        ListNode *pTemp = pNode;
        while(pNode->m_pNext != pTemp) {
            pNode = pNode->m_pNext;
            ++LoopLength;
        }
        ListNode *pFast = pHead;
        ListNode *pSlow = pHead;
        while(LoopLength > 0) {
            pFast = pFast->m_pNext;
            --LoopLength;
        }
        while (pFast != pSlow) {
            pFast = pFast->m_pNext;
            pSlow = pSlow->m_pNext;
        }
        return pFast;
    }

    ListNode* ReverseList(ListNode *pHead) {
        if (pHead == nullptr)
            return nullptr;
        ListNode *pPre = nullptr;
        if (pHead->m_pNext != nullptr) {
            pPre = pHead;
            pHead = pHead->m_pNext;
            pPre->m_pNext = nullptr;
        } else {
            return pHead;
        }

        ListNode *pNext = nullptr;
        while (pHead != nullptr) {
            pNext = pHead->m_pNext;
            pHead->m_pNext = pPre;
            pPre = pHead;
            pHead = pNext;
        }
        return pPre;
    }

    ListNode* mergeListNode(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr)
            return pHead2;
        if(pHead2 == nullptr)
            return pHead1;
        ListNode *pHead = nullptr;
        if (pHead1->m_nValue < pHead2->m_nValue) {
            pHead = pHead1;
            pHead1 = pHead1->m_pNext;
        } else {
            pHead = pHead2;
            pHead2 = pHead2->m_pNext;
        }
        ListNode* pNode = pHead;
        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1->m_nValue < pHead2->m_nValue) {
                pNode->m_pNext = pHead1;
                pHead1 = pHead1->m_pNext;
            } else {
                pNode->m_pNext = pHead2;
                pHead2 = pHead2->m_pNext;
            }
            pNode = pNode->m_pNext;
        }
        if (pHead1 == nullptr && pHead2!= nullptr)
            pNode->m_pNext = pHead2;
        if (pHead2 == nullptr && pHead1!= nullptr)
            pNode->m_pNext = pHead1;
        return pHead;
    }

    ListNode* mergeListNodeByRecursion(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr)
            return pHead2;
        if(pHead2 == nullptr)
            return pHead1;
        ListNode* pHead = nullptr;
        if(pHead1->m_nValue < pHead2->m_nValue) {
            pHead = pHead1;
            pHead->m_pNext = mergeListNodeByRecursion(pHead1->m_pNext, pHead2);
        } else {
            pHead = pHead2;
            pHead->m_pNext = mergeListNodeByRecursion(pHead1, pHead2->m_pNext);
        }
        return pHead;
    }

    bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;

        bool isHas = false;

        if (pRoot1->m_nValue == pRoot2->m_nValue) {
            isHas = coreHasSubtree(pRoot1, pRoot2);
        }

        if (!isHas)
            isHas = HasSubtree(pRoot1->m_pLeft, pRoot2);
        if (!isHas)
            isHas = HasSubtree(pRoot1->m_pRight, pRoot2);

        return isHas;
    }

    bool coreHasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
        if (pRoot2 == nullptr)
            return true;
//        if (pRoot1 == nullptr)
//            return false;
//        if (pRoot1->m_nValue != pRoot2->m_nValue)
//            return false;
//
        bool isEqual = false;
        if (pRoot1->m_nValue == pRoot2->m_nValue) {
            isEqual = coreHasSubtree(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
            coreHasSubtree(pRoot1->m_pRight, pRoot2->m_pRight);
        }
        return isEqual;
    }

    void MirrorRecursively(BinaryTreeNode* pRoot) {
        if (pRoot == nullptr)
            return;
        BinaryTreeNode *pTemp;
        pTemp = pRoot->m_pLeft;
        pRoot->m_pLeft = pRoot->m_pRight;
        pRoot->m_pRight = pTemp;
        MirrorRecursively(pRoot->m_pLeft);
        MirrorRecursively(pRoot->m_pRight);
    }

    bool isSymmetrical(BinaryTreeNode* pRoot) {
        return isSymmetrical(pRoot, pRoot);
    }
    bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
        if (pRoot1 == nullptr && pRoot2 == nullptr)
            return true;
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        if (pRoot1->m_nValue != pRoot2->m_nValue)
            return false;
        return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
    }

    void PrintMatrixClockwisely(int **numbers, int cols, int rows) {
        if (numbers == nullptr || cols <= 0 || rows <= 0)
            return;
        int start = 0;
        while (cols > start * 2 && rows > start * 2) {
            PrintMatrixCircle(numbers, cols, rows, start);
            ++start;
        }
    }
    //****************************************
    void PrintMatrixCircle(int **numbers, int cols, int rows, int start) {
        int endX = cols - start - 1;
        int endY = rows - start - 1;
        for (int i = start; i <= endX; ++i) {
            printf("%d ", numbers[start][i]);
        }
        if (start - endY) {
            for (int i = start + 1; i <= endY; ++i) {
                printf("%d ", numbers[i][endX]);
            }
        }

        if (start < endX && start < endY) {
            for (int i = endX - 1; i >= start; --i) {
                printf("%d ", numbers[endY][i]);
            }
        }

        if (start < endX && start < endY - 1) {
            for (int i = endY - 1; i >= start + 1; --i) {
                printf("%d ", numbers[i][start]);
            }
        }
//        //print a row
//        for (int i = start; i < cols - start; ++i) {
//            printf("%d ", numbers[start][i]);
//        }
//        // print a col rows - 1 - start
//        for (int j = start + 1; j < rows - start; ++j) {
//            printf("%d ", numbers[j][rows - 1 - start]);
//        }
//
//        // print bottom
//        for (int i = cols - start - 2; i >= 0 + start; --i) {
//            printf("%d ", numbers[cols - start - 1][i]);
//        }
//        //print left
//        for (int j = rows - start - 2; j >= 1 + start; --j) {
//            printf("%d ", numbers[j][start]);
//        }
    }

    bool isStackOrder(const int *pPush, const int *pPop, int length) {
        if (pPush == nullptr || pPop == nullptr || length <= 0)
            return false;
        const int *pNextPush = pPush;
        const int *pNextPop = pPop;
        std::stack <int>stack;
        while (pNextPop - pPop < length) {
            while (stack.empty() || stack.top() != *pNextPop) {
                if (pNextPush - pPush == length)
                    break;
                stack.push(*pNextPush);
                ++pNextPush;
            }
            if (stack.top() != *pNextPop)
                break;
            stack.pop();
            ++pNextPop;
    }
        return stack.empty() && (pNextPop - pPop) == length;
    }

    void PrintFromTopToBottom(BinaryTreeNode *pTreeRoot) {
        if (pTreeRoot == nullptr)
            return;
        std::deque<BinaryTreeNode*> deque;
        deque.emplace_back(pTreeRoot);
        while(!deque.empty()) {
            BinaryTreeNode* root = deque.front();
            printf("%d ", root->m_nValue);
            deque.pop_front();
            if (root->m_pLeft)
                deque.emplace_back(root->m_pLeft);
            if (root->m_pRight)
                deque.emplace_back(root->m_pRight);
        }
    }

    void PrintFromTopToBottom2(BinaryTreeNode *pTreeRoot) {
        if (pTreeRoot == nullptr)
            return;
        std::deque<BinaryTreeNode*> deque;
        deque.emplace_back(pTreeRoot);
        int nextLevel = 0;
        int toBePrint = 1;
        while(!deque.empty()) {
            BinaryTreeNode* root = deque.front();
            printf("%d ", root->m_nValue);
            deque.pop_front();

            if (root->m_pLeft) {
                deque.emplace_back(root->m_pLeft);
                ++nextLevel;
            }
            if (root->m_pRight) {
                deque.emplace_back(root->m_pRight);
                ++nextLevel;
            }
            --toBePrint;
            if (toBePrint == 0) {
                printf("\n");
                toBePrint = nextLevel;
                nextLevel = 0;
            }
        }
    }

    void PrintFromTopToBottom3(BinaryTreeNode *pTreeRoot) {
        if (pTreeRoot == nullptr)
            return;
        std::stack<BinaryTreeNode*> stack[2];
        stack[0].push(pTreeRoot);
        int current = 0;
        int next = 1;
        while (!stack[0].empty() || !stack[1].empty()) {
            BinaryTreeNode *root = stack[current].top();
            printf("%d", root->m_nValue);
            stack[current].pop();
            if (current) {
                if (root->m_pLeft)
                   stack[next].push(root->m_pLeft);
                if (root->m_pRight)
                   stack[next].push(root->m_pRight);
            } else {
                if (root->m_pRight)
                    stack[next].push(root->m_pRight);
                if (root->m_pLeft)
                    stack[next].push(root->m_pLeft);
            }
            if (stack[current].empty()) {
                printf("\n");
                current = 1 - current;
                next = 1 - next;
            }
        }

    }

    bool VerifySquenceOFBST(std::vector<int> &number) {
        if (number.size() == 0)
            return false;
        int root = number.back();
        int i = 0;
        while(number[i] < root) {
            ++i;
        }
        int j = i;
        while (j < number.size() - 1) {
            if (number[j++] < root)
                return false;
        }
        bool left = true;
        std::vector<int> arrayLeft;
        for (int i1 = 0; i1 < i; ++i1)
            arrayLeft.emplace_back(number[i1]);
        if (i > 0)
            left = VerifySquenceOFBST(arrayLeft);

        bool right = true;
        std::vector<int> arrayRight;
        for (int i1 = 0; i1 < number.size() - i - 1; ++i1)
            arrayRight.emplace_back(number[i + i1]);
        if (i < number.size() - 1)
            right = VerifySquenceOFBST(arrayRight);

        return left && right;
    }

    void FindPath(BinaryTreeNode* root, int expectNumber) {
        if (root == nullptr)
            return;
        std::vector<int> path;
        FindPathCore(root, expectNumber, path);
    }

    void FindPathCore(BinaryTreeNode* root, int expectNumber, std::vector<int> &path) {
        if (root == nullptr)
            return;
        path.emplace_back(root->m_nValue);
        int total = 0;
        for (auto &i: path) {
            total += i;
        }
        if (root->m_pRight == nullptr && root->m_pLeft == nullptr && total == expectNumber) {
            for (auto &i : path)
                printf("%d ", i);
            printf("\n");
        }
        FindPathCore(root->m_pLeft, expectNumber, path);
        FindPathCore(root->m_pRight, expectNumber, path);
        path.pop_back();
    }

    void CloneNodes(ComplexListNode *pHead) {
        ComplexListNode *p = pHead;
        while (p != nullptr) {
            ComplexListNode *pTemp = p->m_pNext;
            ComplexListNode *pCopy = new ComplexListNode;
            pCopy->m_nValue = p->m_nValue;
            p->m_pNext = pCopy;
            pCopy->m_pNext = pTemp;
            p = pCopy->m_pNext;
        }
    }
    void ConnectSiblingNodes(ComplexListNode *pHead) {
        ComplexListNode *p = pHead;
        while (p != nullptr) {
            if (p->m_pSlibling != nullptr) {
                p->m_pNext->m_pSlibling = p->m_pSlibling->m_pNext;
            }
            p = p->m_pNext;
        }
    }
    ComplexListNode* ReconnectNodes(ComplexListNode *pHead) {
        int k = 1;
        ComplexListNode *p1 = pHead;
        ComplexListNode *pHead2 = pHead->m_pNext;
        ComplexListNode *p2 = pHead2;
        p1->m_pNext = p2->m_pNext;
        while (p1->m_pNext != nullptr) {
            if (k % 2 == 0) {
                p2->m_pNext = p1->m_pNext;
                p2 = p2->m_pNext;
                p1->m_pNext = p2->m_pNext;
            } else
                p1 = p1->m_pNext;
            ++k;
        }
        return pHead2;

    }
    ComplexListNode* Clone(ComplexListNode *pHead) {
        if (pHead == nullptr)
            return nullptr;
        CloneNodes(pHead);
        ConnectSiblingNodes(pHead);
        return ReconnectNodes(pHead);
    }

    BinaryTreeNode *Convert(BinaryTreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr)
            return nullptr;
//        BinaryTreeNode *pRoot = pRootOfTree;
        BinaryTreeNode *pLastNodeList = nullptr;
        ConvertNode(pRootOfTree, &pLastNodeList);
        while (pLastNodeList->m_pLeft != nullptr && pLastNodeList != nullptr)
            pLastNodeList = pLastNodeList->m_pLeft;
        return pLastNodeList;
    }

    void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList) {
        if (pNode == nullptr)
            return ;
        BinaryTreeNode *pCurrent = pNode;
        if (pCurrent->m_pLeft)
            ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

        pCurrent->m_pLeft = *pLastNodeInList;
        if (*pLastNodeInList)
            (*pLastNodeInList)->m_pRight = pCurrent;
        *pLastNodeInList = pCurrent;

        if (pCurrent->m_pRight)
            ConvertNode(pCurrent->m_pRight, pLastNodeInList);

    }

    std::string Serialize(BinaryTreeNode* pRoot) {
        std::string tree;
        Serialize(pRoot, tree);
        tree.pop_back();
        return tree;
    }
    void Serialize(BinaryTreeNode* pRoot, std::string& tree) {
        if (pRoot == nullptr) {
            tree.append("#,");
            return;
        }
        tree.append(std::to_string(pRoot->m_nValue) + ",");
        Serialize(pRoot->m_pLeft, tree);
        Serialize(pRoot->m_pRight, tree);
    }

    BinaryTreeNode* Deserialize(BinaryTreeNode** pRoot, std::string& tree) {
        std::list<std::string> treeNode = gh::split(tree, ",");
        Deserialize(pRoot, treeNode);
        return *pRoot;
    }

    void Deserialize(BinaryTreeNode** pRoot, std::list<std::string> &treeNode) {
        int number;
        if (treeNode.front() != "#") {
            number = std::stoi(treeNode.front().c_str());
            *pRoot = new BinaryTreeNode;
            (*pRoot)->m_nValue = number;
            (*pRoot)->m_pRight = nullptr;
            (*pRoot)->m_pLeft = nullptr;
            treeNode.pop_front();
            Deserialize(&(*pRoot)->m_pLeft, treeNode);
            Deserialize(&(*pRoot)->m_pRight, treeNode);
        } else {
            treeNode.pop_front();

        }
    }

//    void Permutation(std::string& str) {
//        if (str.size() == 0)
//            return;
//        int index = 1;
//        Permutation(str, index);
//    }
//
//    void Permutation(std::string& str, int &index) {
//        if (index == str.length())
//            gh::print(str);
//        else
//            for (int i = 0; i < str.length(); ++i) {
//                char c = str.back();
//                Permutation(str, ++index);
//                str[str.length() - i] = c;
//            }
//    }

    void Permutation(char *pStr) {
        if (pStr == nullptr)
            return;
        Permutation(pStr, pStr);
    }

    void Permutation(char *pStr, char* pBegin) {
        if (*pBegin == '\0')
            printf("%s\n", pStr);
        else {
            for (char *pCh = pBegin; *pCh != '\0'; ++pCh) {
                char pTemp = *pCh;
                *pCh = *pBegin;
                *pBegin = pTemp;

                Permutation(pStr, pBegin + 1);

                pTemp = *pCh;
                *pCh = *pBegin;
                *pBegin = pTemp;
            }
        }
    }

    void Permutation(std::string& str) {
        if (str.length() == 0)
            return;
        int i = 0;
        Permutation(str, i);
    }
    void Permutation(std::string& str, int &i) {
        if (i >= str.length())
            return;
        if (i == str.length() - 1)
            gh::print(str);
        for (int j = i;j < str.length(); ++j) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            Permutation(str, ++i);
            --i;
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }

    void Combination(char* str) {
        if (str == nullptr)
            return;
        int length = strlen(str);
        std::vector<char> vector;
        for (int i = 1; i <= length; ++i)
            Combination(str, i, vector);

    }
    void Combination(char* str, int i, std::vector<char> &vector) {
        if (i == 0) {
            for (auto &c: vector)
                printf("%c ", c);
            printf("\n");
            return;
        }
        if (*str == '\0')
            return;

        vector.emplace_back(*str);
        Combination(str + 1, i - 1, vector);
        vector.pop_back();
        Combination(str + 1, i, vector);
    }

    int MoreThanHalfNum(int *numbers, int length, int& result) {
        if (numbers == nullptr)
            return -1;
        result = numbers[0];
        int times = 0;
        for (int i = 1; i < length; ++i) {
            if (times == 0) {
                result = numbers[i];
                ++times;
            } else if (result == numbers[i])
                ++times;
            else
                --times;
        }
        //check half
        int resultTimes = 0;
        for (int i = 0; i < length; ++i) {
            if (numbers[i] == result)
                ++resultTimes;
        }
        if (resultTimes > length/2)
            return 0;
        return -1;
    }

    void GetLeastNumbers(const std::vector<int> &data, std::multiset<int, std::greater<>> &lastNumbers, int k) {
        if (k < 0 || data.empty())
            return;
        for (auto &num: data) {
            if (lastNumbers.size() < 4) {
                lastNumbers.emplace(num);
                continue;
            } else {
                if (num < *lastNumbers.begin()) {
                    lastNumbers.erase(lastNumbers.begin());
                    lastNumbers.emplace(num);
                }
            }
        }
    }

    int FindGreatestSumOfSubArray(int *pData, int nLength) {
        int curSum = 0;
        int nGreatestSum = 0;
        for (int i = 0; i < nLength; ++i) {
            if (curSum <= 0)
                curSum = pData[i];
            else
                curSum += pData[i];
            if (nGreatestSum < curSum)
                nGreatestSum = curSum;
        }
        return nGreatestSum;
    }

    int digitAtIndex(int index) {
        if (index < 0)
            return -1;
        int digits = 1;
        while(true) {
            int numbers = countOfIntegers(digits);
            if (index < numbers * digits)
                return digitAtIndex(index, digits);
            index -= digits * numbers;
            digits++;
        }
        return -1;
    }

    int countOfIntegers(int digits) {
        if (digits == 1)
            return 10;
        int count = (int)std::pow(10, digits - 1);
        return 9 * count;
    }

    int digitAtIndex(int index, int digits) {
        int number = beginNumber(digits) + index/digits;
        int indexFromRight = digits - index % digits;
        for (int i = 1; i < indexFromRight; ++i)
            number /= 10;
        return number % 10;
    }
    int beginNumber(int digits) {
        if (digits == 1)
            return 0;
        return (int)std::pow(10, digits - 1);
    }

    int GetUglyNumber(int index) {
        if (index < 0)
            return -1;
        int *uglyArray = new int[index];
        uglyArray[0] = 1;
        int ugly2 = 1;
        int ugly3 = 1;
        int ugly5 = 1;
        int ugly_index2 = 0;
        int ugly_index3 = 0;
        int ugly_index5 = 0;
        int min;
        for (int i = 1; i < index; ++i) {
            min = uglyMin(ugly2 * 2, ugly3 * 3, ugly5 * 5);
            uglyArray[i] = min;
            while (ugly2 * 2 <= uglyArray[i])
                ugly2 = uglyArray[ugly_index2++];
            while (ugly3 * 3 <= uglyArray[i])
                ugly3 = uglyArray[ugly_index3++];
            while (ugly5 * 5 <= uglyArray[i])
                ugly5 = uglyArray[ugly_index5++];
        }
        int uglyIndex = uglyArray[index - 1];
        delete[] uglyArray;
        return uglyIndex;
    }
    int GetUglyNumber_solution2(int index) {
        if (index < 0)
            return -1;
        int *uglyArray = new int[index];
        uglyArray[0] = 1;
        int *ugly2 = uglyArray;
        int *ugly3 = uglyArray;
        int *ugly5 = uglyArray;
        for (int i = 1; i < index; ++i) {
            int min = uglyMin(*ugly2 * 2, *ugly3 * 3, *ugly5 * 5);
            uglyArray[i] = min;
            while (*ugly2 * 2 <= min)
                ++ugly2;
            while (*ugly3 * 3 <= min)
                ++ugly3;
            while (*ugly5 * 5 <= min)
                ++ugly5;
        }
        int result = uglyArray[index - 1];
        delete[] uglyArray;
        return result;
    }
    int uglyMin(int ugly2, int ugly3, int ugly5) {
        int min = ugly2 < ugly3 ? ugly2 : ugly3;
        return min < ugly5 ? min : ugly5;
    }

    int GetTranslationCount(int number) {
        if (number < 0)
            return 0;
        std::string numberString(std::to_string(number));
        return GetTranslationCount(numberString);
    }
    int GetTranslationCount(const std::string& number) {
//        int const length = 1;
        int length = static_cast<int>(number.length());
        int* counts = new int[length];
        int count = 0;
        for (int i = length - 1; i >= 0; --i) {
            if (i < length - 1)
                count = counts[i + 1];
            else
                count = 1;

            if (i < length - 1) {
                int num1 = number[i] - '0';
                int num2 = number[i + 1] - '0';
                int convert = num1 * 10 + num2;
                if (convert >=10 && convert <= 25) {
                    if (i < length - 2)
                        count += counts[i + 2];
                    else
                        count += 1;
                }
            }
            counts[i] = count;
            gh::print(count);
        }
        count = counts[0];
        delete[] counts;
        return count;
    }

    int getMaxValue_solution(const int *values, int rows, int cols) {
        if (values == nullptr || rows <= 0 || cols <= 0)
            return 0;
        int *maxValues = new int[cols];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = maxValues[j];
                if (j > 0);
                    left = maxValues[j - 1];
                maxValues[j] = std::max(up, left) + values[i * cols + j];
            }
        }
        int maxValue = maxValues[cols - 1];
//            for (int i = 0; i < cols; ++i)
//                gh::print("maxValues: ", maxValues[i]);
        delete[] maxValues;
        return maxValue;
    }

    int longestSubstringWithoutDuplicatiuon(const std::string& str) {
        int max = 1;
        int currMax = 1;
        int length = str.length();
        for (int i = 1; i < length; ++i) {
            bool isHave = false;
            int d = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (str[i] == str[j]) {
                    isHave = true;
                    d = i - j;
                    currMax = 1;
                     break;
                }
            }

            if (isHave) {
                if (d > currMax)
                    currMax += 1;
            } else {
                currMax += 1;
            }
            max = max > currMax ? max : currMax;
        }
        return max;
    }

    char FirstNotRepeating(std::string &str) {
        if (str.size() <= 0)
            return '\0';
        int hashMap[256] = {0};
        for (auto c: str) {
            hashMap[c]++;
        }
        for (int i = 0; i < 256; ++i) {
            if (hashMap[i] == 1) {
                return i;
            }
        }
    }

    ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode* pHead2) {
        int p1Length = getListLength(pHead1);
        int p2Length = getListLength(pHead2);
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        int i = p1Length - p2Length;
        if (i > 0)
            while(i--)
                p1 = p1->m_pNext;
        else {
            i = -i;
            while(i--)
                p2 = p2->m_pNext;
        }

        ListNode *p;
        while (p1->m_pNext != p2->m_pNext) {
            p1 = p1->m_pNext;
            p2 = p2->m_pNext;
        }
        p = p1->m_pNext;
        return p;
    }

    int getListLength(ListNode *pHead) {
        int length = 0;
        ListNode *p = pHead;
        while (p != nullptr) {
            ++length;
            p = p->m_pNext;
        }
        return length;
    }

    int GetNumberOfK(int *data, int length, int k) {
        if (data == nullptr || length <= 0)
            return -1;
        int startIndex = GetFirstK(data, length, k, 0, length - 1);
        int lastIndex = GetLastK(data, length, k, 0, length - 1);
        return lastIndex - startIndex + 1;
    }


    int GetFirstK(int *data, int length, int k, int start, int end) {
        int middleIndex = (start + end)/2;
        int middleData = data[middleIndex];
        if (middleData == k) {
            if ((middleIndex > 0 && data[middleIndex - 1] < k) || middleIndex == 0)
                return middleIndex;
            else
                end = middleIndex - 1;
        } else if(middleData < k) {
            start = middleIndex + 1;
        } else {
            end = middleIndex - 1;
        }
        return GetFirstK(data, length, k, start, end);
    }

    int GetLastK(int *data, int length, int k, int start, int end) {
        int middleIndex = (start + end)/2;
        int middleData = data[middleIndex];
        if (middleData == k) {
            if ((middleIndex < length - 1 && data[middleIndex + 1] > k) || middleIndex == length - 1)
                return middleIndex;
            else
                start = middleIndex + 1;
        } else if(middleData < k) {
            start = middleIndex + 1;
        } else {
            end = middleIndex - 1;
        }
        return GetLastK(data, length, k, start, end);
    }

    int GetMissingNumber(int *data, int length) {
        if (data == nullptr || length <= 0)
            return -1;
        int left = 0;
        int right = length - 1;
        while (left <= right) {
            int middleIndex = (right + left) / 2;
            if (middleIndex != data[middleIndex]) {
                if (middleIndex == 0 || data[middleIndex - 1] == middleIndex - 1)
                    return middleIndex;
                right = middleIndex - 1;
            }
            else
                left = middleIndex + 1;
        }
        if (left == length)
            return length;
        return -1;
    }

    int GetNumberSameAsIndex(int *numbers, int length) {
        if (numbers == nullptr || length <= 0)
            return -1;
        int left = 0;
        int right = length - 1;
        while (left <= right) {
            int middleIndex = (left + right) >> 1;
            if (middleIndex == numbers[middleIndex])
                return middleIndex;
            else if (numbers[middleIndex] < middleIndex)
                left = middleIndex + 1;
            else
                right = middleIndex - 1;
        }
    }

    BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, int k) {
        if (pRoot == nullptr || k == 0)
            return nullptr;
        return KthNodeCore(pRoot, k);
    }

    BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, int &k) {
        BinaryTreeNode *target = nullptr;
        if (pRoot->m_pLeft != nullptr)
            target =  KthNodeCore(pRoot->m_pLeft, k);
        if (target == nullptr) {
            if (k == 1)
                target = pRoot;
            k--;
        }
        if (target == nullptr && pRoot->m_pRight != nullptr)
            target = KthNodeCore(pRoot->m_pRight, k);
        return target;
    }
    int TreeDepth(BinaryTreeNode* pRoot) {
        if (pRoot == nullptr)
            return 0;
        int left = TreeDepth(pRoot->m_pLeft);
        int right = TreeDepth(pRoot->m_pRight);
        return left > right ? left+1 : right+1;
    }

    bool IsBalanced(BinaryTreeNode* pRoot, int *pDepth) {
        if (pRoot == nullptr) {
            *pDepth = 0;
            return true;
        }
        int left, right;
        if(IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right)) {
            int dis = right - left;
            if (abs(dis) <= 1) {
                *pDepth = 1 + (left > right) ? left : right;
                return true;
            }
        }
        return false;
    }
    bool IsBalanced(BinaryTreeNode* pRoot) {
        int depth = 0;
        bool res = IsBalanced(pRoot, &depth);
//        gh::print("depth:", depth);
        return res;
    }

    std::pair<int, int> FindNumsAppearOnce(std::vector<int> &nums) {
        int resultExclusive = 0;
        int resA = 0, resB = 0;
        for (auto &i: nums)
            resultExclusive ^= i;
        int index = 0;
        while ((resultExclusive & 1) != 1) {
            resultExclusive = resultExclusive >> 1;
            ++index;
        }
        for (auto &i: nums) {
            if (IsBit1(i, index))
                resA ^= i;
            else
                resB ^= i;
        }
        return std::make_pair(resA, resB);

    }

    bool IsBit1(int num, int index) {
        num = num >> index;
        return num & 1;
    }

    int FindNumsAppearThreeForOne(std::vector<int> &nums) {
        if (nums.size() == 0)
            return -1;
        int bits[32] = {0};
        for (auto num : nums) {
            int bitMask = 1;
            for (int i = 31; i >= 0; --i) {
                int bit = bitMask & num;
                if (bit != 0)
                    bits[i] += 1;
                bitMask = bitMask << 1;
            }
        }
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            result = result << 1;
            result += bits[i] % 3;
        }
        return result;
    }

    std::pair<int, int> FindNumbersWithSum(std::vector<int > &nums, int sum) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] == sum)
                return std::make_pair(nums[left], nums[right]);
            else if (nums[left] + nums[right] < sum)
                ++left;
            else
                --right;
        }
        return std::make_pair(-1,-1);
    }

    void FindContinuousSequence(int sum) {
        int left = 1, right = 2;
        int sumTemp;
        int middle = (1 + sum) / 2;
        while(left < middle) {
            sumTemp = 0;
            for (int i = left; i <= right; ++i)
                sumTemp+= i;
            if (sumTemp == sum) {
                PrintContinuousSequence(left++, right++);
            } else if (sumTemp < sum)
                right++;
            else
                left++;
        }

    }
    void PrintContinuousSequence(int start, int end) {
        for (int i = start; i <= end; ++i)
            printf("%d ", i);
        printf("\n");
    }

    void ReserveString(std::string &str, int start, int end) {
        while (start < end) {
            char tmpc = str[start];
            str[start] = str[end];
            str[end] = tmpc;
            start++;
            end--;
        }
    }
    void ReverseSentence(std::string &str) {
        if (str.empty())
            return;
        ReserveString(str, 0, str.size() - 1);
        int start, end;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != ' ')
                start = i;
            else
                start = ++i;

            while (str[i] != ' ' && i < str.size() - 1)
                ++i;
            if (i == str.size() - 1) {
                ReserveString(str, start, str.size() - 1);
                return;
            }
            end = i - 1;
            if (end < str.size())
                ReserveString(str, start, end);
        }
    }

    void LeftRotateString(std::string& str, int n) {
        if (str.size() == 0)
            return;
        ReserveString(str, 0, str.size() - 1);
        ReserveString(str, 0, str.size() - 1 - n);
        ReserveString(str, str.size() - n, str.size() - 1);
    }

    std::vector<int > maxInWindows(const std::vector<int >& num, int size) {
        using namespace std;
        vector<int > maxInWindow;
        if (num.size() < 1)
            return maxInWindow;
        deque<int > index;
        for (int i = 0; i < size; ++i) {
            while (!index.empty() && num[i] > num[index.back()])
                index.pop_back();
            index.emplace_back(i);
        }

        for (int i = size; i < num.size(); ++i) {
            maxInWindow.emplace_back(num[index.front()]);

            while (!index.empty() && num[i] >= num[index.back()]) {
                index.pop_back();
            }

            if (!index.empty() && index.front() <= (i - size))
                index.pop_front();

            index.emplace_back(i);
        }

        maxInWindow.emplace_back(num[index.front()]);
        return maxInWindow;
    }

    void PrintProbability(int number) {
        if (number < 1)
            return;
        int g_maxValue = 6;
        int *pProbabilities[2];
        pProbabilities[0] = new int[number * g_maxValue + 1]();
        pProbabilities[1] = new int[number * g_maxValue + 1]();

        int flag = 0;
        for (int i = 1; i <= g_maxValue; ++i)
            pProbabilities[flag][i] = 1;

        for (int i = 2; i <= number; ++i) {

            for (int k = 1; k <= number * g_maxValue; ++k)
                pProbabilities[1-flag][k] = 0;

            for (int j = i; j <= number * g_maxValue; ++j) {
                for (int k = 1; k<=j &&k <= g_maxValue; ++k) {
                    pProbabilities[1-flag][j] += pProbabilities[flag][j - k];
                }
            }

            flag = 1 - flag;
        }

        double total = pow(g_maxValue, number);

        for (int i = number; i <= g_maxValue * number; ++i) {
            double ratio = (double)pProbabilities[flag][i]/total;
            printf("%d: %f\n",i ,ratio);
        }
        delete[] pProbabilities[0];
        delete[] pProbabilities[1];
    }

    bool IsContinuous(std::vector<int >& numbers) {
        if (numbers.size() < 1)
            return false;
        int *pokeCount = new int[14]();

        for (auto num: numbers) {
            if (num >= 14)
                throw "";
            pokeCount[num]++;
        }

        int zeroCount = pokeCount[0];
        int gapCount = 0;

        int indexLeft = 1;
        int indexRight = 13;
        while (pokeCount[indexLeft] == 0)
            indexLeft++;

        while (pokeCount[indexRight] == 0)
            indexRight--;


        for (int i = indexLeft; i <= indexRight; ++i) {
            if (pokeCount[i] > 1)
                return false;
            if (pokeCount[i] == 0)
                gapCount++;
        }
        return zeroCount >= gapCount;
    }

    int LastRemaining(unsigned int n, unsigned int m) {
        if (n < 1 || m < 1)
            return -1;
        int last = 0;
        for (int i = 2; i <= n; i++) {
            last = (last + m) % i;
        }
        return last;
    }

    int MaxDiff(std::vector<int >& numbers) {
        if (numbers.size() < 2)
            return 0;

        int min = numbers[0];
        int maxDiff = numbers[1] - min;
        for (int i = 2; i < numbers.size(); ++i) {
            if (numbers[i - 1] < min)
                min = numbers[i - 1];
            if (numbers[i] - min > maxDiff)
                maxDiff = numbers[i] - min;
        }
        return maxDiff;
    }

    enum StrToIntState {success, fail};
    StrToIntState strToIntState = fail;
    int StrToInt(const char *string) {
        if (string == nullptr || *string == '\0') {
            return 0;
        }

        bool isPos = true;
        if (*string == '+')
            string++;
        if (*string == '-') {
            isPos = false;
            string++;
        }

        if (*string == '\0')
            return 0;

        long number = 0;
        while (*string != '\0') {
            if (*string - '0' >= 0 && *string - '0' <= 9) {
                number = number * 10 + *string - '0';
                string++;
            } else {
                return 0;
            }
        }

        if (number > MAXINT || number < -MAXINT) {
            return 0;
        }

        number = isPos ? number : -number;
        strToIntState = success;
        return number;

    }

}



