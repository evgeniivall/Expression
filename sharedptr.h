#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H


struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtrData
{
  SharedPtrData(Expression* ptr):pointer_(ptr), counter(1){}
  Expression* pointer_;
  int counter;
  ~SharedPtrData()
  {
    delete pointer_;
  }
};

struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = 0);
    ~SharedPtr();
    SharedPtr(const SharedPtr &other);
    SharedPtr& operator=(const SharedPtr &other);
    Expression* get() const;
    void reset(Expression *ptr = 0);
    Expression& operator*() const;
    Expression* operator->() const;
private:
  SharedPtrData* ptr_;
};

#endif // SHAREDPOINTER_H
