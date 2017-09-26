template <typename T>
class SmartPointer {
    public:
        SmartPointer() : mPointer { nullptr } {}
        SmartPointer(T* p) : mPointer { p } {}

        ~SmartPointer()
        {
            if (mPointer)
                delete mPointer;
        }

    private:
        T* mPointer;
};
