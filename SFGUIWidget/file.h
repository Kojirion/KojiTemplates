#pragma once
#include <SFGUI/Widget.hpp>

class %{CN} : public sfg::Widget
{
public:
    typedef std::shared_ptr<%{CN}> Ptr;
    typedef std::shared_ptr<const %{CN}> PtrConst;
    
    static Ptr Create();

protected:  
    %{CN}() = default;

private:

};