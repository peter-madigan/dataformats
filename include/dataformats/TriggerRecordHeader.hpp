/**
 * @file TriggerRecordHeader.hpp  TriggerRecordHeader struct definition
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef DATAFORMATS_INCLUDE_DATAFORMATS_TRIGGERRECORDHEADER_HPP_
#define DATAFORMATS_INCLUDE_DATAFORMATS_TRIGGERRECORDHEADER_HPP_

#include "dataformats/ComponentRequest.hpp"
#include "dataformats/Types.hpp"

#include <ostream>
#include <vector>

namespace dunedaq {
namespace dataformats {

struct TriggerRecordHeader
{
#define TRIGGER_RECORD_HEADER_MAGIC 0x33334444
#define TRIGGER_RECORD_HEADER_VERSION 1

  uint32_t trigger_record_header_marker = TRIGGER_RECORD_HEADER_MAGIC; // NOLINT(build/unsigned)
  uint32_t version = TRIGGER_RECORD_HEADER_VERSION;                    // NOLINT(build/unsigned)

  trigger_number_t trigger_number;
  run_number_t run_number;
  timestamp_t trigger_timestamp;
  trigger_type_t trigger_type;

  timestamp_t trigger_record_start_time;
  timestamp_t trigger_record_end_time;

  uint32_t error_bits; // NOLINT(build/unsigned)

  uint64_t num_requested_components; // NOLINT(build/unsigned)
};

inline std::ostream&
operator<<(std::ostream& o, TriggerRecordHeader const& hdr)
{
  return o << "version: " << hdr.version << ", "

           << "trigger_number: " << hdr.trigger_number << ", "
           << "run_number: " << hdr.run_number << ", "
           << "trigger_timestamp: " << hdr.trigger_timestamp << ", "
           << "trigger_type: " << hdr.trigger_type << ", "

           << "trigger_record_start_time: " << hdr.trigger_record_start_time << ", "
           << "trigger_record_end_time: " << hdr.trigger_record_end_time << ", "

           << "error_bits: " << hdr.error_bits << ", "

           << "num_requested_components: " << hdr.num_requested_components;
}

} // namespace dataformats
} // namespace dunedaq

#endif // DATAFORMATS_INCLUDE_DATAFORMATS_TRIGGERRECORDHEADER_HPP_