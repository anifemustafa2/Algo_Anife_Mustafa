#include<stdio.h> 
#include<stdlib.h> 
#include<malloc.h>
#include "stdafx.h"
#include<conio.h>
#include<iostream>

using namespace std;

//Клас,съдържащ данни за списък
class Node
{
public:
	int nData; //Поле за стойност на елемента
	struct Node* pNext; //Указател към следващия елемент

	Node() {} //Подразбиращ конструктор
};

///<summary>Метод за създаване на свързан списък</summary>
///<param="nNumberOfElements">Променлива за дължината на списъка</param>
///<returns>Връщаме началото на списъка</returns>
Node * CreateLinkedList(int nNumberOfElements)
{
	Node * pHead = NULL; //Указател към началото на списъка
	Node * pTemp = NULL;  //Указател за временно съхраняване на нови елементи
	Node * p = NULL; //Указател за новите елементи в списъка

	for (int i = 0; i < nNumberOfElements; i++) //Цикъл, за въвеждане на елементи в списъка
	{
		pTemp = new Node(); //Създаване на нов възел
		cout << "Enter the data for node number " << i + 1<<": "; //Въвеждане на стойност на възлите
		cin >> pTemp->nData; 
		pTemp->pNext = NULL;//Указваме, че елементът няма друг елемент след себе си

		if (pHead == NULL) //Ако началният елемент e NULL, въведеният елемент става начален
		{
			pHead = pTemp; //Присвояваме въведената стойност на началния елемент

		}
		else //Ако вече има елементи в списъка
		{
			p = pHead; 
			while (p->pNext != NULL)
				p = p->pNext;//Създаваме връзки между елементите
			p->pNext = pTemp; //Присвояваме стойност
		}
	}
	cout << "Linked List created!"; //Извеждане на съобщения за потребителя
	return pHead;
}

///<summary>Метод за създаване на възли</summary>
///<param="nKey">Стойност на елемента</param>
///<returns>Връщаме създадения елемент</returns>
Node *newNode(int nKey)
{
	Node *pTemp = new Node(); //Указател към нов възел
	pTemp->nData = nKey; //Задаване стойност на елемента
	pTemp->pNext = NULL; //Задаване на елемента като краен
	return pTemp;
}

///<summary>Метод за преброяване на възлите в списъка</summary>
///<param="pNode">Указател към елемент в списъка</param>
///<returns>Връщаме брой елементи в списъка</returns>
int countNodes(Node * pNode)
{
	int nCount = 1; //Ппоменлива за брой елементи
	Node *pTemp = pNode; 
	while (pTemp->pNext != pNode) //Обхождаме списъка
	{
		nCount++; //Увеличаваме брой елементи
		pTemp = pTemp->pNext; //Преминаваме към следващия елемент
	}
	return nCount;
}

///<summary>Метод за създаване на loop</summary>
///<param="pHead">Указател към списъка</param>
///<param="nLoopElement">Променлива, за елемента, към който се свързва последният елемент</param>
void makeloop(Node** pHead, int nLoopElement)
{
	Node* pTemp = *pHead; //Създаване на временна променлива, сочеща към началото на списъка
	int count = 1;
	while (count < nLoopElement) { //Обхождаме списъка докато намерим елемента за loop
		pTemp = pTemp->pNext;
		count++;
	}

	Node* pJoint = pTemp; //Указател към елемента където ще създаваме loop

	while (pTemp->pNext != NULL) //Обхождаме останалата част от списъка
		pTemp = pTemp->pNext;

	pTemp->pNext = pJoint; //Създаваме loop

	cout << "Loop created from node " << nLoopElement << " to the last node!"; //Извеждаме съобщения за потребителя
}

///<summary>Метод за преброяване на възлите в loop</summary>
///<param="pList">Указател към списъка</param>
///<returns>Ако има loop връщаме броя елементи в него, ако няма -1</returns>
int countNodesinLoop(Node *pList)
{
	Node  *pFirst = pList, *pSecond = pList; //Указатели към списъка

	while (pFirst && pSecond && pSecond->pNext)
	{
		pFirst = pFirst->pNext; //Местим първия укатазетел с 1
		pSecond = pSecond->pNext->pNext;//Местим втория указател с 2

		if (pFirst == pSecond) //Ако двата указателя се срещнат значи има loop
			return countNodes(pFirst); //Връщаме указател към елемента където сме намерили loop
	}

	cout << "\nNo Loop"; //Ако не сме намерили loop 
	return -1; //Връщаме -1
}

///<summary>Метод за извеждане на списъка</summary>
///<param="pHead">Указател към списъка</param>
///<param="nTotalNodes">Променлива за брой елементи в списъка</param>
void displayList(Node * pHead, int nTotalNodes)
{
	Node * p = pHead; //Създаване на указател, сочещ началото на списъка

	for (int i = 0; i < nTotalNodes; i++) //Цикъл, въртящ до броя елементи
	{
		while (p != NULL) //Докато не стигнем края на списъка
		{
			cout << " " << p->nData; //Извеждаме елемент
			p = p->pNext; //Местим към следващия елемент
		}
		
	}
	cout << endl;
}

int main()
{
	int nElements = 0; //Променлива за брой елементи, които ще въведем в списъка
	Node * pHead = NULL; //Указател към списъка
	cout << "Number of nodes: "; 
	cin >> nElements; //Въвеждаме брой елементи
	pHead = CreateLinkedList(nElements); //Създаване на списък

	cout << "Your Linked List is: " << endl;
	displayList(pHead, nElements); //Извеждане на списъка преди създаване на loop

	int nNodeNumber; 
	cout << "Enter node number to connect it to the last node(create loop): ";
	cin >> nNodeNumber; //Въвеждаме на коя позиция ще имаме loop
	makeloop(&pHead,nNodeNumber); //Създаване на loop

	int nNodesInLoop = countNodesinLoop(pHead); //Променлива за брой елементи в loop
	cout << "\nNodes in loop are: " << nNodesInLoop;

	cout << "\nPress any key to exit!"; //Съобщение към потребителя 
	_getch(); 

	return 0;
}