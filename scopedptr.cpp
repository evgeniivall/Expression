#include "scopedptr.h"

ScopedPtr::~ScopedPtr()
{
    delete ptr_;
}
Expression* ScopedPtr::get() const
{
    return ptr_;
}
Expression* ScopedPtr::release()
{
    Expression* temp = ptr_;
    ptr_ = 0;
    return temp;
}
void ScopedPtr::reset(Expression *ptr)
{
    delete ptr_;
    ptr_ = ptr;
}
Expression& ScopedPtr::operator*() const
{
    return *ptr_;
}
Expression* ScopedPtr::operator->() const
{
    return ptr_;
}
