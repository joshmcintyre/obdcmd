/* This file contains function declarations and includes for elm327 specific code
* such as command generation

*
*Author: Josh McIntyre
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/join.hpp>

/* This class abstracts away the details of generating ELM327 commands
* and processing responses generated by the chip
*/
class Command
{
	//private:
		
	public:
	
		// Declare constant ELM327/OBDII command strings
		static const char CMD_ECHO_OFF[];
		
		static const char CMD_GET_DTCS[];
		static const char CMD_GET_COOLANT_TEMP[];
		static const char CMD_GET_ENGINE_RPM[];
		static const char CMD_GET_VEHICLE_SPEED[];
		static const char CMD_GET_THROTTLE_POS[];
		
		static const char RET_NO_DATA[];

		// Declare an enum of supported commands
		enum COMMAND { GET_DTCS,
						GET_COOLANT_TEMP, 
						GET_ENGINE_RPM, 
						GET_VEHICLE_SPEED, 
						GET_THROTTLE_POS
					  };	

		// This map will contain a dictionary of prefix chars to DTC prefixes such as 0 -> P0
		static std::map<char, std::string> dtc_prefixes;

		// Main data interpretation functions
		static std::string interpret_raw(std::string raw_data, COMMAND command);
		
		static std::string interpret_dtcs(std::string trimmed_data);
		static std::string interpret_coolant_temp(std::string trimmed_data);
		static std::string interpret_engine_rpm(std::string trimmed_data);
		static std::string interpret_vehicle_speed(std::string trimmed_data);
		static std::string interpret_throttle_pos(std::string trimmed_data);
		
		// Some helper functions for data interpretation
		static std::string parse_raw_dtc(std::string raw_dtc);
		static int hex_data_to_int(std::string hex_string);
		static std::string trim_raw(std::string raw_data);
};


