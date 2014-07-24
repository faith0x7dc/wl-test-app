%bcond_with wayland

Name:           wl-test-app
Version:        0.1.4
Release:        0
Summary:        Wayland test application
License:        MIT
Group:          Graphics

Source0:        %name-%version.tar.xz
BuildRequires:  pkgconfig(wayland-client)
BuildRequires:  pkgconfig(wayland-egl)
BuildRequires:  pkgconfig(wayland-cursor)
BuildRequires:  pkgconfig(egl)
BuildRequires:  mesa-devel

%if !%{with wayland}
ExclusiveArch:
%endif


%description
Wayland test application

%prep
%setup -q

%build
%autogen
make V=1

%install
%make_install

mkdir -p %{buildroot}%{_bindir}/wl-test-app/

install -m 755 solid-surf-egl %{buildroot}%{_bindir}/wl-test-app/

%define _unpackaged_files_terminate_build 0

%files
%defattr(-,root,root)
%_bindir/wl-test-app/solid-surf-egl

