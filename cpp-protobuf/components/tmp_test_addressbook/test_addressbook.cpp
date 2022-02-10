/* test_addressbook.c: Implementation of a testable component.

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/


#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"

#include "esp_log.h"


static const char * const TAG = "test_addressbook"; // @suppress("Unused variable declaration in file scope")

static const char * const test_name = "Herbert";




using namespace std;
using namespace tutorial;

void try_addressbook_main(void)
{

	ESP_LOGI(TAG, "--- Before the Test --- ");
	  // Verify that the version of the library that we linked against is
	  // compatible with the version of the headers we compiled against.
	  GOOGLE_PROTOBUF_VERIFY_VERSION;

	  AddressBook* address_book = new AddressBook;

	  Person* person = address_book->add_people();

	  person->set_name("sepp");
	  person->set_id(25);

	  Person::PhoneNumber* phone_number = person->add_phones();

	  phone_number->set_number("+49123456789");
	  phone_number->set_type(Person::MOBILE);

	  std::string debug_string = address_book->DebugString();

		ESP_LOGI(TAG, "debug_string %s", debug_string.c_str());


	  // Optional:  Delete all global objects allocated by libprotobuf.
	  google::protobuf::ShutdownProtobufLibrary();

	ESP_LOGI(TAG, "--- After the Test --- ");
}

