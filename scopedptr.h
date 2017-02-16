#ifndef SCOPEDPTR_H
#define SCOPEDPTR_H


struct Expression;
struct Number;
struct BinaryOperation;

struct ScopedPtr
{
    explicit ScopedPtr(Expression *ptr = 0):ptr_(ptr){}
     ~ScopedPtr();
    Expression* get() const;
    Expression* release();
    void reset(Expression *ptr = 0);
    Expression& operator*() const;
    Expression* operator->() const;


private:
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};

#endif // SCOPEDPTR_H
