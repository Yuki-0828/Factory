#include "Factory.h"
#include <iostream>
using namespace std;

void ProductA::process()
{
    cout << "Processing ProductA using Heating strategy." << endl;
}

void ProductB::process()
{
    cout << "Processing ProductB using Cooling strategy." << endl;
}

void ProductC::process()
{
    cout << "Processing ProductC using Mixing strategy." << endl;
}

void HeatingStrategy::apply()
{
    cout << "Applying Heating strategy." << endl;
}

void CoolingStrategy::apply()
{
    cout << "Applying Cooling strategy." << endl;
}

void MixingStrategy::apply()
{
    cout << "Applying Mixing strategy." << endl;
}

shared_ptr<ProcessingStrategy> StrategyFactory::createStrategy(const string &type)
{
    if (type == "Heating")
    {
        return make_shared<HeatingStrategy>();
    }
    else if (type == "Cooling")
    {
        return make_shared<CoolingStrategy>();
    }
    else if (type == "Mixing")
    {
        return make_shared<MixingStrategy>();
    }
    else
    {
        return nullptr;
    }
}

unique_ptr<Product> Factory::createProduct(const string &type)
{
    if (type == "ProductA") 
    {
        return make_unique<ProductA>();
    }
    else if (type =="ProductB")
    {
        return make_unique<ProductB>();
    }
    else if (type=="ProductC")
    {
        return make_unique<ProductC>();
    }
    else
    {
        return nullptr;
    }
}

FactoryManager& FactoryManager:: getInstance()
{
    static FactoryManager instance;
    return instance;
}
 
void FactoryManager::assignStrategy(Product *product, const string &strategyType)
{
    auto strategy = strategyFactory.createStrategy(strategyType);
    strategies[product->type()] = strategy;
    if (strategy)
    {
        strategy->apply();
    }
    else
    {
        cout << "No strategy assigned for this product." << endl;
    }
}

