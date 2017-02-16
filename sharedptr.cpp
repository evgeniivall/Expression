#include "sharedptr.h"

SharedPtr::SharedPtr(Expression *ptr)
{
    if(ptr)
    {
        ptr_ = new SharedPtrData(ptr);
    }
    else
    {
        ptr_ = 0;
    }
}

SharedPtr::~SharedPtr()
{
    if(ptr_)
    {
        ptr_->counter--;
        if(!ptr_->counter)
        {
            delete ptr_;
        }
    }
}
SharedPtr::SharedPtr(const SharedPtr &other)
{
    if(other.ptr_)
    {
        ptr_ = other.ptr_;
        ptr_-> counter++;
    }
    else
    {
        ptr_ = other.ptr_;
    }
}
SharedPtr& SharedPtr::operator=(const SharedPtr &other)
{
    if(this != &other)
    {
        if(ptr_)
        {
            ptr_->counter--;
            if(!ptr_->counter)
            {
                delete ptr_;
            }
        }
    if(other.ptr_)
    {
        other.ptr_->counter++;
    }
    ptr_ = other.ptr_;
    }
    return *this;
}
Expression* SharedPtr::get() const
{
  return (ptr_->pointer_);
}
void SharedPtr::reset(Expression *ptr)
{
    if(ptr_)
    {
        if(ptr_->counter > 1)
        {
            ptr_->counter--;
        }
        else
        {
            delete ptr_;
        }
    }
    if(ptr)
    {
        ptr_ = new SharedPtrData(ptr);
    }
    else
    {
        ptr_ = 0;
    }

}
Expression& SharedPtr::operator*() const
{
    return *(ptr_->pointer_);
}
Expression* SharedPtr::operator->() const
{
    return ptr_->pointer_;
}
