/*
Copyright 2014 Florian Wolf, SAP AG

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "TransactionalStatistic.h"

using namespace std;

TransactionalStatistic::TransactionalStatistic(){
	for(int i=0; i<5; i++){
		executeTPCCSuccessCount[i] = 0;
		executeTPCCFailCount[i] = 0;
	}
}

void TransactionalStatistic::addResult(unsigned long long& transcationalResults){
	transcationalResults += executeTPCCSuccessCount[0];
}

void TransactionalStatistic::executeTPCCSuccess(int transactionNumber, bool success){
	if(success)
		executeTPCCSuccessCount[transactionNumber-1]++;
	else
		executeTPCCFailCount[transactionNumber-1]++;
}
