#include <iostream>
#include <string>

#include "httplib.h"
#include "system_state.h"

// Function to start the web server
void startWebServer() {
    httplib::Server svr;  // Create the server instance

    // Route to fetch list of controllers
    svr.Get("/controllers", [](const httplib::Request& req,
                               httplib::Response& res) {
        // Manually create the JSON response for controllers
        std::string controller_list = "[";

        // Iterate over each controller (dereferencing the pointer)
        for (const auto& controller : controllers) {
            // Dereference the controller pointer to access the `Controller`
            // object
            controller_list +=
                "{\"type\": \"" + controller->type + "\", \"pins\": [";

            // Iterate over the pins of the controller (again, using pointer
            // dereferencing)
            for (const auto& pin : controller->pins) {
                controller_list +=
                    "{\"type\": \"" + pin.type +
                    "\", \"pin_number\": " + std::to_string(pin.pin_number) +
                    ", \"state\": \"" + pin.state + "\"}, ";
            }

            // Remove the trailing comma for pins
            if (!controller->pins.empty()) {
                controller_list.pop_back();
                controller_list.pop_back();
            }
            controller_list += "]}, ";
        }

        // Remove the trailing comma if there are controllers
        if (!controllers.empty()) {
            controller_list.pop_back();
            controller_list.pop_back();
        }

        controller_list += "]";

        // Send the response with the controller list as JSON
        res.set_content(controller_list, "application/json");
    });

    // Start the server on port 8080
    std::cout << "Web Server running on http://localhost:8080" << std::endl;
    svr.listen("localhost", 8080);  // Run the server
}
