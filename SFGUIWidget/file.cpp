#include "%{HdrFileName}"

%{CN}::Ptr %{CN}::Create()
{
        Ptr widget(new %{CN}());
        return widget;
}

