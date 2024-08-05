#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
using namespace std;
// 定义抽象的产品类和具体的产品子类（ProductA、ProductB 和 ProductC）
class Product
{
public:
    virtual void process() = 0;
    virtual string type() const = 0; 
    virtual ~Product() = default;
};

class ProductA:public Product
{
public:
    void process() override;
    string type() const override { return "ProductA"; }
};

class ProductB : public Product
{
public:
    void process() override;
    string type() const override { return "ProductB"; }
};

class ProductC:public Product
{
public:
    void process() override;
    string type() const override { return "ProductC"; }
};

// 定义抽象的加工策略接口，并为每种加工方式实现具体的策略类（如加热策略、冷却策略、混合策略）。
class ProcessingStrategy
{
public:
    virtual void apply() = 0;
    virtual ~ProcessingStrategy() = default;
};

class HeatingStrategy : public ProcessingStrategy
{
public:
    void apply() override;
};

class CoolingStrategy : public ProcessingStrategy
{
public:
    void apply() override;
};

class MixingStrategy : public ProcessingStrategy
{
public:
    void apply() override;
};

// 实现一个策略工厂类，用于根据策略类型创建相应的加工策略。
class StrategyFactory
{
public:
    shared_ptr<ProcessingStrategy> createStrategy(const string &type);
};

//  实现一个工厂类，用于根据产品类型创建产品对象。
class Factory
{
public:
    unique_ptr<Product> createProduct(const string &type);
};

//实现一个工厂管理者类，使用单例模式确保该类在系统中只有一个实例，负责创建产品和分配加工策略。
class FactoryManager:public Factory
{
private:
    unordered_map<string, unique_ptr<Product>> products;
    unordered_map<string, shared_ptr<ProcessingStrategy>> strategies;
    StrategyFactory strategyFactory;
    FactoryManager() {} 

public:
    static FactoryManager& getInstance();
    void assignStrategy(Product *product, const string &strategyType);
};
