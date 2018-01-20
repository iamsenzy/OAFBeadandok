#ifndef _ENUMERATOR_
#define _ENUMERATOR_

template <typename Item>
class Enumerator
{
    public:
        virtual void First() = 0;
        virtual void Next() = 0;
        virtual bool End() const = 0;
        virtual Item Current() const = 0;
        virtual ~Enumerator(){}
};

#endif
