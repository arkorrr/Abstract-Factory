#include <iostream>
#include <string>
using namespace std;

class Drum
{
public:
    void Spin()
    {
        cout << "The drum is spinning" << endl;
    }
};

class Engine
{
public:
    void Start()
    {
        cout << "the engine is running" << endl;
    }
    void Finish()
    {
        cout << "The engine is finishing" << endl;
    }
};

class WaterFillingSystem
{
public:
    void FillWater()
    {
        cout << "The water is filling" << endl;
    }
};

class DrainageSystem
{
public:
    void Drainage()
    {
        cout << "The water is drained" << endl;
    }
};

class WashingMachineFacade
{
    Drum drum;
    Engine engine;
    WaterFillingSystem fillingSystem;
    DrainageSystem drainageSystem;
public:
    WashingMachineFacade(Drum drum, Engine engine, WaterFillingSystem fillingsystem, DrainageSystem drainageSystem)
    {
        this->drum = drum;
        this->engine = engine;
        this->fillingSystem = fillingsystem;
        this->drainageSystem = drainageSystem;    
    }
    void Start()
    {
        engine.Start();
        drum.Spin();
        fillingSystem.FillWater();
    }
    void Stop()
    {
        drainageSystem.Drainage();
        engine.Finish();
    }
};

class WashingMachine
{
public:
    void WashClothes(WashingMachineFacade facade)
    {
        facade.Start();
        facade.Stop();
    }
};

int main()
{
    Drum drum;
    Engine engine;
    WaterFillingSystem fillingsystem;
    DrainageSystem drainageSystem;

    WashingMachineFacade client(drum, engine, fillingsystem, drainageSystem);

    WashingMachine washingMachine;
    washingMachine.WashClothes(client);
}

