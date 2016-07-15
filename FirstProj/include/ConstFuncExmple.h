#ifndef CONSTFUNCEXMPLE_H
#define CONSTFUNCEXMPLE_H


class ConstFuncExmple
{
    int var;
    const int constvar;
    public:
        ConstFuncExmple(int a, int b);
        virtual ~ConstFuncExmple();
        void regfunc();
        void constfunc() const;
        void printvar();

};

#endif // CONSTFUNCEXMPLE_H
