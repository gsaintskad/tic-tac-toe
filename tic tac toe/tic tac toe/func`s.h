#pragma once
#include<iostream>
#include<vector>
#include <windows.h>
#include<ctime>
#include"cell.h"
using namespace std;

void print(vector<vector<cell>>* f);
bool isFinished(vector<vector<cell>>f);
bool wincheck(vector<vector<cell>>f);