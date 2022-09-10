/**
 * @file YourModule.cpp
 *
 * Implementations of YourModule's functions
 *
 * This is part of the DUNE DAQ Software Suite, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "YourModule.hpp"

#include "yourpackage/yourmodule/Nljs.hpp"
#include "skeleton/yourmoduleinfo/InfoNljs.hpp"

#include <string>

namespace dunedaq::yourpackage {

YourModule::YourModule(const std::string& name)
  : dunedaq::appfwk::DAQModule(name)
{
  register_command("conf", &YourModule::do_conf);
}

void
YourModule::init(const data_t& /* structured args */)
{}

void
YourModule::get_info(opmonlib::InfoCollector& ci, int /* level */)
{
  yourmoduleinfo::Info info;
  info.total_amount = m_total_amount;
  info.amount_since_last_get_info_call = m_amount_since_last_get_info_call.exchange(0);

  ci.add(info);
}

void
YourModule::do_conf(const data_t& conf_as_json)
{
  auto conf_as_cpp = conf_as_json.get<yourmodule::Conf>();
  m_some_configured_value = conf_as_cpp.some_configured_value;
}

} // namespace dunedaq::yourpackage

DEFINE_DUNE_DAQ_MODULE(dunedaq::yourpackage::YourModule)
