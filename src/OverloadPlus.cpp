#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Data {
public:
	int high;
	int low;
};

class DataList {
private:
	vector<Data> dataVector;
public:
//	DataList();
	//DataList operator+(Data, Data);
	void print();
	void add(Data);
	void addAll(DataList);
	vector<Data> getDataVector();
};

DataList operator+(Data d1, Data d2) {
	DataList dataList;
	dataList.add(d1);
	dataList.add(d2);
	return dataList;
}

DataList operator+(DataList dl, Data d) {
	dl.add(d);
	return dl;
}

DataList operator+(DataList dl1, DataList dl2) {
	dl1.addAll(dl2);
	return dl1;
}

void DataList::print(){
    for (Data data : dataVector)
        cout << std::to_string(data.low)+ ":" + std::to_string(data.high) << endl;
}

void DataList::add(Data data){
	dataVector.push_back(data);
}

vector<Data> DataList::getDataVector(){
	return dataVector;
}

void DataList::addAll(DataList dataList){
	for (Data data: dataList.getDataVector())
		dataVector.push_back(data);
}

int main() {
	Data d1;
	d1.low = 10;
	d1.high = 20;
	Data d2;
	d2.low = 30;
	d2.high = 40;

	cout << "Added data" << endl;

	DataList dataList = d1 + d2;
	dataList.print();

	cout << "Added list and data" << endl;

	Data d3;
	d3.low = 40;
	d3.high = 50;
	DataList dataListAdded = dataList + d3;
	dataListAdded.print();

	cout << "Added two lists" << endl;
	DataList twoDataListAdded = dataList + dataListAdded;
	twoDataListAdded.print();

	return 0;
}
