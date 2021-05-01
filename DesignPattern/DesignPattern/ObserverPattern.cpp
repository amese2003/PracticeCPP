#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer
{
public:
    virtual void Update(const string& watch) = 0;
    virtual const string& GetName() const = 0;
};

class User : public Observer
{
public:
    User(const string& name) : _name(name) {}

public:
    void Update(const string& watch) override
    {
        cout << _name << ":" << watch << endl;
    }

    const string& GetName() const { return _name; }


private:
    string _name;
};

class Observable
{
protected:
    vector<shared_ptr<Observer>> _observerList;

protected:
    void Update(const string& watch) {
        for (int i = 0; i < _observerList.size(); i++) {
            _observerList[i].get()->Update(watch);
        }
    }

public:
    virtual void BroadCast(const string& watch) = 0;

public:
    virtual void AddObserver(shared_ptr<Observer>) {};
    virtual void RemoveObserver(shared_ptr<Observer>) {};
};


class BroadModel : public Observable {
public:
    virtual void BroadCast(const string& watch) {
        Update(watch);
    }

    virtual void AddObserver(shared_ptr<Observer> user) override {
        _observerList.push_back(user);
    }

    virtual void RemoveObserver(shared_ptr<Observer> user) override {

        vector<shared_ptr<Observer>>::iterator itor = find(_observerList.begin(), _observerList.end(), user);

        if (itor != _observerList.end()) {
            _observerList.erase(itor);
        }
    }

};


int ObserverMain()
{
    unique_ptr<Observable> broadCaster = make_unique<BroadModel>();

    shared_ptr<Observer> user1 = make_shared<User>("tester1");
    shared_ptr<Observer> user2 = make_shared<User>("tester2");
    shared_ptr<Observer> user3 = make_shared<User>("tester3");

    broadCaster->AddObserver(user1);
    broadCaster->AddObserver(user2);
    broadCaster->AddObserver(user3);

    broadCaster->BroadCast("规价茄促!");

    broadCaster->RemoveObserver(user1);
    broadCaster->RemoveObserver(user2);

    broadCaster->BroadCast("曹离规价");
    return 0;
}