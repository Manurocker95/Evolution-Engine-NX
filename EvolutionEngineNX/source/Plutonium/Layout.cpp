#include "pu/Layout.hpp"

namespace pu
{
    Layout::Layout(bool UseFocus)
    {
        this->onipt = [&](u64 Down, u64 Up, u64 Held, bool Touch){};
        this->efocus = NULL;
        this->ufocus = UseFocus;
    }

    Layout::~Layout()
    {
        this->ClearChildren();
    }

    void Layout::AddChild(element::Element *Child)
    {
        if(this->efocus == NULL) this->efocus = Child;
        this->chld.push_back(Child);
    }

    void Layout::ClearChildren()
    {
        if(!this->chld.empty()) for(u32 i = 0; i < this->chld.size(); i++) delete this->chld[i];
        this->chld.clear();
    }

    element::Element *Layout::GetChildAt(u32 Index)
    {
        return this->chld[Index];
    }

    u32 Layout::GetChildCount()
    {
        return this->chld.size();
    }

    bool Layout::HasChilds()
    {
        return !this->chld.empty();
    }

    void Layout::SetElementOnFocus(element::Element *OnFocus)
    {
        this->efocus = OnFocus;
    }

    element::Element *Layout::GetElementOnFocus()
    {
        return this->efocus;
    }

    void Layout::SetOnInput(std::function<void(u64 Down, u64 Up, u64 Held, bool Touch)> Callback)
    {
        this->onipt = Callback;
    }

    std::function<void(u64 Down, u64 Up, u64 Held, bool Touch)> Layout::GetOnInput()
    {
        return this->onipt;
    }

    void Layout::AddThread(std::function<void()> Callback)
    {
        this->thds.push_back(Callback);
    }

    std::vector<std::function<void()>> Layout::GetAllThreads()
    {
        return this->thds;
    }

    bool Layout::UsesFocus()
    {
        return this->ufocus;
    }

    void Layout::SetUseFocus(bool Focus)
    {
        this->ufocus = Focus;
    }
}