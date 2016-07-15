#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

/* ** the reason we have to include the source in header file is because class definitons is only unfolded at runtime
* and it can not kept in seperate files
* there are some workarounds
* http://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp
*/

template <class T>
class TemplateClass
{
    public:
        TemplateClass(T, T);
        virtual ~TemplateClass();
        T bigger();
    protected:
    private:
        T first, second;
};

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



#endif // TEMPLATECLASS_H
