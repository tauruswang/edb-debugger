/*
Copyright (C) 2006 - 2015 Evan Teran
                          evan.teran@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BREAKPOINT_20060720_H_
#define BREAKPOINT_20060720_H_

#include "IBreakpoint.h"
#include <array>

namespace DebuggerCorePlugin {

class Breakpoint : public IBreakpoint {
public:
	enum class TypeId {
		Automatic,
		ARM32,
		Thumb2Byte,
		Thumb4Byte,
		UniversalThumbARM32,
		ARM32BKPT,
		ThumbBKPT,
	};
public:
	Breakpoint(edb::address_t address);
	virtual ~Breakpoint();
	TypeId type() const { return type_; }
	void set_type(TypeId type);

public:
	virtual edb::address_t address() const override { return address_; }
	virtual quint64 hit_count() const      override { return hit_count_; }
	virtual bool enabled() const           override { return enabled_; }
	virtual bool one_time() const          override { return one_time_; }
	virtual bool internal() const          override { return internal_; }
	virtual size_t size() const            override { return original_bytes_.size(); }
	virtual const quint8* original_bytes() const override { return &original_bytes_[0]; }

public:
	virtual bool enable() override;
	virtual bool disable() override;
	virtual void hit() override;
	virtual void set_one_time(bool value) override;
	virtual void set_internal(bool value) override;

private:
	std::vector<quint8> original_bytes_;
	edb::address_t        address_;
	quint64               hit_count_;
	bool                  enabled_ ;
	bool                  one_time_;
	bool                  internal_;
	TypeId                type_;
};

}

#endif

