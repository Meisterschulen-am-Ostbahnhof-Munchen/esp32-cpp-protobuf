#include <sstream>
#include <utility>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "test.pb.h"

static const char* TAG = "Main";

extern "C" {
    void app_main(void);
}

void app_main(void) 
{


    int32_t id = 0;
    while(1)
    {
        test::TestRequest request;
        request.set_index(id);
        std::stringstream ss;
        ss << "Hello World " << id++ << std::endl;
        request.set_text(ss.str());
        std::string data = request.SerializeAsString();
        ESP_LOGI(TAG, "Serialized TestRequest (%u bytes)", data.length());
        test::TestRequest deserialized_request;
        deserialized_request.ParseFromString(data);
        ESP_LOGI(TAG, "Deserialized: %s", deserialized_request.text().c_str());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
