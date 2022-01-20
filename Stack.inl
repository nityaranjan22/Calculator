template <typename T>
inline
size_t Stack <T>::size (void) const
{

    return this->arr.size();
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    //check for empty Stack
    if(this->is_empty())
    {

        //throw error if empty
        throw empty_exception();
    }
    else
    {
        //otherwise get value off the top of the stack
        return this->arr.get(this->arr.size()-1);
    }
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    //if the size is zero, the stack is empty
    if(this->size() == 0)
    {
        return true;

    }
    return false;
}
