template <typename>
class SmartPointer;

template <typename T>
class uPtr {
    private:
        uPtr(T* p) : ptr { p }, count { 1 } {}

        ~uPtr()
        {
            delete ptr;
        }

        T* ptr;
        int count;

        friend class SmartPointer<T>;
};
template <typename T>
class SmartPointer {
    public:
        SmartPointer(T* p) : mPointer { new uPtr<T>{ p } } {}

        SmartPointer(const SmartPointer& rhs) : mPointer { rhs.mPointer }
        {
            ++mPointer->count;
        }

        SmartPointer& operator = (const SmartPointer& rhs)
        {
            ++rhs.mPointer->count;

            if (--mPointer->count == 0)
                delete mPointer;

            mPointer = rhs.mPointer;

            return *this;
        }

        ~SmartPointer()
        {
            if (--mPointer->count == 0)
                delete mPointer;
        }

        T& operator * () const
        {
            return *(mPointer->ptr);
        }

        T* operator -> () const
        {
            return mPointer->ptr;
        }

    private:
        uPtr<T>* mPointer;
};
