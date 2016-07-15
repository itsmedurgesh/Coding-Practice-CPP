#ifndef FUNCTIONTEMPLATE_H
#define FUNCTIONTEMPLATE_H


class FunctionTemplate
{
    public:
        FunctionTemplate();

        template <class object> // here a template is defined and it is used in function definition
        static object add(object a, object b){ return a+b;}

        template <class F, class S>
        static F smaller(F f, S s){ return f<s ? f : s;}
        // by using two templates we are handling two types of parameters
        // but we are also forcing the return type to be of first type
};

#endif // FUNCTIONTEMPLATE_H
