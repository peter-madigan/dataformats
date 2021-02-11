/**
 * @file GeoID_test.cxx GeoID struct Unit Tests
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "dataformats/GeoID.hpp"

/**
 * @brief Name of this test module
 */
#define BOOST_TEST_MODULE GeoID_test // NOLINT

#include "boost/test/unit_test.hpp"

#include <string>
#include <vector>

using namespace dunedaq::dataformats;

BOOST_AUTO_TEST_SUITE(GeoID_test)

/**
 * @brief Test that GeoID::operator<< functions as expected 
*/
BOOST_AUTO_TEST_CASE(StreamOperator) 
{
  GeoID test;
  test.m_apa_number = 1;
  test.m_link_number = 2;

  std::ostringstream ostr;
  ostr << test;

  std::string output = ostr.str();
  std::cout << "Stream operator: " << output << std::endl;

  BOOST_REQUIRE(!output.empty());
  auto pos = output.find("APA: 1,");
  BOOST_REQUIRE(pos != std::string::npos);
}

/**
 * @brief Test that GeoID::operator< functions as expected
 */
BOOST_AUTO_TEST_CASE(ComparisonOperator)
{
  GeoID lesser, greater;
  lesser.m_apa_number = 1;
  lesser.m_link_number = 2;
  greater.m_apa_number = 3;
  greater.m_link_number = 4;

  BOOST_REQUIRE(lesser < greater);
  BOOST_REQUIRE(!(greater < lesser));
}

BOOST_AUTO_TEST_SUITE_END()