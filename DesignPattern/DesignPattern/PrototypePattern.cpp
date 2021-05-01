#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

enum RECORD_TYPE
{
    CAR = 0,
    BIKE,
    PERSON,
    SIZE
};

class Record
{
public:
    Record() {}
    virtual ~Record() {}

public:
    virtual Record* Clone() const = 0;
    virtual void Print() const = 0;
};

class CarRecord : public Record
{
public:

    CarRecord(const string& carName, int id) : Record(), _carName(carName), _id(id)
    {
    }

    CarRecord(const CarRecord& _oCarRecord) : Record()
    {
        _carName = _oCarRecord._carName;
        _id = _oCarRecord._id;
    }

    ~CarRecord() {}

public:
    CarRecord* Clone() const
    {
        return new CarRecord(*this);
    }

    void Print() const
    {
        cout << "Car Record" << endl
            << "Name : " << _carName << endl
            << "Number: " << _id << endl << endl;
    }

private:
    string _carName;
    int _id;
};


class BikeRecord : public Record
{
public:
    BikeRecord(const string& bikeName, int id) : Record(), _bikeName(bikeName), _id(id)
    {
    }

    BikeRecord(const BikeRecord& _oBikeRecord) : Record()
    {
        _bikeName = _oBikeRecord._bikeName;
        _id = _oBikeRecord._id;
    }

    ~BikeRecord() {}

public:
    BikeRecord* Clone() const
    {
        return new BikeRecord(*this);
    }

    void Print() const
    {
        cout << "Bike Record" << endl
            << "Name : " << _bikeName << endl
            << "Number: " << _id << endl << endl;
    }

private:
    string _bikeName;
    int _id;
};

class PersonRecord : public Record
{
private:
    string _name;
    int _age;

public:
    PersonRecord(const string& name, int age) : Record(), _name(name), _age(age)
    {
    }

    PersonRecord(const PersonRecord& person) : Record()
    {
        _name = person._name;
        _age = person._age;
    }

    ~PersonRecord() {}

public:
    Record* Clone() const
    {
        return new PersonRecord(*this);
    }

    void Print() const
    {
        cout << "Person Record" << endl
            << "Name: " << _name << endl
            << "Age : " << _age << endl << endl;
    }
};

class RecordFactory
{
public:
    RecordFactory()
    {
        _recordMap[CAR] = new CarRecord("Ferrari", 5050);
        _recordMap[BIKE] = new BikeRecord("Yamaha", 2525);
        _recordMap[PERSON] = new PersonRecord("Tom", 25);
    }

    ~RecordFactory()
    {
        delete _recordMap[CAR];
        delete _recordMap[BIKE];
        delete _recordMap[PERSON];
    }

    Record* CreateRecord(RECORD_TYPE enType)
    {
        return _recordMap[enType]->Clone();
    }


private:
    map<RECORD_TYPE, Record* > _recordMap;
};

int main()
{
    RecordFactory* poRecordFactory = new RecordFactory();

    Record* poRecord;
    poRecord = poRecordFactory->CreateRecord(CAR);
    poRecord->Print();
    delete poRecord;

    poRecord = poRecordFactory->CreateRecord(BIKE);
    poRecord->Print();
    delete poRecord;

    poRecord = poRecordFactory->CreateRecord(PERSON);
    poRecord->Print();
    delete poRecord;

    delete poRecordFactory;
    return 0;
}