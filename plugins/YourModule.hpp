/**
 * @file YourModule.hpp
 *
 * Developer(s) of this DAQModule have yet to replace this line with a brief description of the DAQModule.
 *
 * This is part of the DUNE DAQ Software Suite, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef YOURPACKAGE_PLUGINS_YOURMODULE_HPP_
#define YOURPACKAGE_PLUGINS_YOURMODULE_HPP_

#include "appfwk/DAQModule.hpp"

#include <atomic>
#include <limits>
#include <string>

namespace dunedaq::yourpackage {

class YourModule : public dunedaq::appfwk::DAQModule
{
public:
  explicit YourModule(const std::string& name);

  void init(const data_t&) override;

  void get_info(opmonlib::InfoCollector&, int /*level*/) override;

  YourModule(const YourModule&) = delete;
  YourModule& operator=(const YourModule&) = delete;
  YourModule(YourModule&&) = delete;
  YourModule& operator=(YourModule&&) = delete;

  ~YourModule() = default;

private:
  // Commands YourModule can receive

  // TO yourpackage DEVELOPERS: PLEASE DELETE THIS FOLLOWING COMMENT AFTER READING IT
  // For any run control command it is possible for a DAQModule to
  // register an action that will be executed upon reception of the
  // command. do_conf is a very common example of this; in
  // YourModule.cpp you would implement do_conf so that members of
  // YourModule get assigned values from a configuration passed as 
  // an argument and originating from the CCM system.
  // To see an example of this value assignment, look at the implementation of 
  // do_conf in YourModule.cpp

  void do_conf(const data_t&);

  int m_some_configured_value { std::numeric_limits<int>::max() }; // Intentionally-ridiculous value pre-configuration

  // TO yourpackage DEVELOPERS: PLEASE DELETE THIS FOLLOWING COMMENT AFTER READING IT 
  // m_total_amount and m_amount_since_last_get_info_call are examples
  // of variables whose values get reported to OpMon
  // (https://github.com/mozilla/opmon) each time get_info() is
  // called. "amount" represents a (discrete) value which changes as YourModule
  // runs and whose value we'd like to keep track of during running;
  // obviously you'd want to replace this "in real life"

  std::atomic<int64_t> m_total_amount {0};
  std::atomic<int>     m_amount_since_last_get_info_call {0};
};

} // namespace dunedaq::yourpackage

#endif // YOURPACKAGE_PLUGINS_YOURMODULE_HPP_
