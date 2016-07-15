#include "TemplateClass.h"
template <class T>
TemplateClass<T>::TemplateClass(T f, T s): first(f), second(s)
{
    //ctor
}
template <class T>
TemplateClass<T>::~TemplateClass()
{
    //dtor
}

template <class T>
T TemplateClass<T>::bigger(){ return first>second ? first : second;}


