// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#pragma once
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.Terminal.TerminalControl.h>
#include "Pane.h"

class Tab
{

public:
    Tab(GUID profile, winrt::Microsoft::Terminal::TerminalControl::TermControl control);
    ~Tab();

    winrt::Microsoft::UI::Xaml::Controls::TabViewItem GetTabViewItem();
    winrt::Windows::UI::Xaml::UIElement GetRootElement();
    winrt::Microsoft::Terminal::TerminalControl::TermControl GetFocusedTerminalControl();

    bool IsFocused();
    void SetFocused(bool focused);

    // GUID GetProfile() const noexcept;

    // void Scroll(int delta);

private:

    std::shared_ptr<Pane> _rootPane;

    // winrt::Microsoft::Terminal::TerminalControl::TermControl _control;
    bool _focused;
    // GUID _profile;
    winrt::Microsoft::UI::Xaml::Controls::TabViewItem _tabViewItem;

    void _MakeTabViewItem();
    void _Focus();
};
