#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/config.hpp>
#include <boost/json.hpp>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <thread>
#include <functional>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace json = boost::json;
using tcp = net::ip::tcp;

// Include all greenhouse system headers
#include "Plant - Abstract Base/Plant.h"
#include "Factory - Plant Creation/PlantFactory.h"
#include "Factory - Plant Creation/RoseFactory.h"
#include "Factory - Plant Creation/CactusFactory.h"
#include "Factory - Plant Creation/SucculentFactory.h"
#include "Factory - Plant Creation/LavenderFactory.h"
#include "Factory - Plant Creation/BaobabFactory.h"
#include "Composite - The Store layout/GreenhouseComponent.h"
#include "Composite - The Store layout/Greenhouse.h"
#include "Composite - The Store layout/GreenhouseSection.h"
#include "Composite - The Store layout/Shelf.h"
#include "Composite - The Store layout/PlantLeaf.h"
#include "Iterator - Inventory Management/PlantIterator.h"
#include "Iterator - Inventory Management/GreenhouseInventory.h"
#include "State - Plant lifecycle/PlantContext.h"
#include "State - Plant lifecycle/SeedlingState.h"
#include "State - Plant lifecycle/GrowingState.h"
#include "State - Plant lifecycle/MatureState.h"
#include "State - Plant lifecycle/FloweringState.h"
#include "State - Plant lifecycle/DormantState.h"
#include "Decorator - Plant Decoration/PlantProduct.h"
#include "Decorator - Plant Decoration/BasicPlant.h"
#include "Decorator - Plant Decoration/PlantDecorator.h"
#include "Decorator - Plant Decoration/DecorativePotDecorator.h"
#include "Decorator - Plant Decoration/GiftWrappingDecorator.h"
#include "Decorator - Plant Decoration/GreetingCardDecorator.h"
#include "Strategy - Watering Methods/PlantCareStrategy.h"
#include "Strategy - Watering Methods/FrequentWatering.h"
#include "Strategy - Watering Methods/ModerateWatering.h"
#include "Strategy - Watering Methods/MinimalWatering .h"
#include "Strategy - Watering Methods/PlantCareContext.h"
#include "Builder - Plant Bundle Creator/PlantArrangement.h"
#include "Builder - Plant Bundle Creator/PlantArrangementBuilder.h"
#include "Builder - Plant Bundle Creator/GiftArrangementBuilder.h"
#include "Builder - Plant Bundle Creator/LandscapeArrangementBuilder.h"
#include "Builder - Plant Bundle Creator/ArrangementDirector.h"

// Global data
std::vector<Plant*> plants;
Greenhouse* greenhouse = nullptr;
GreenhouseInventory* inventory = nullptr;
std::map<int, PlantProduct*> decoratedPlants;  // Maps plant ID to decorated product
std::map<int, std::string> plantStrategies;     // Maps plant ID to watering strategy
std::vector<PlantArrangement*> arrangements;    // Stores created arrangements

// Helper function to create CORS headers
void add_cors_headers(http::response<http::string_body>& res) {
    res.set(http::field::access_control_allow_origin, "*");
    res.set(http::field::access_control_allow_methods, "GET, POST, OPTIONS");
    res.set(http::field::access_control_allow_headers, "Content-Type");
}

// API handler for creating plants (Factory Pattern)
json::object handle_factory_create(const std::string& plant_type) {
    json::object response;

    Plant* plant = nullptr;

    if (plant_type == "rose") {
        RoseFactory factory;
        plant = factory.createPlant();
    } else if (plant_type == "cactus") {
        CactusFactory factory;
        plant = factory.createPlant();
    } else if (plant_type == "succulent") {
        SucculentFactory factory;
        plant = factory.createPlant();
    } else if (plant_type == "lavender") {
        LavenderFactory factory;
        plant = factory.createPlant();
    } else if (plant_type == "baobab") {
        BaobabFactory factory;
        plant = factory.createPlant();
    } else {
        response["error"] = "Unknown plant type";
        return response;
    }

    if (plant) {
        plant->setPlantId(plants.size() + 1);
        plants.push_back(plant);

        response["success"] = true;
        response["id"] = plant->getPlantId();
        response["type"] = plant->getType();
        response["price"] = plant->getBasePrice();
        response["health"] = plant->getHealthLevel();
    } else {
        response["error"] = "Failed to create plant";
    }

    return response;
}

// API handler for getting all plants
json::array handle_get_plants() {
    json::array plant_array;

    for (Plant* plant : plants) {
        json::object plant_obj;
        plant_obj["id"] = plant->getPlantId();
        plant_obj["type"] = plant->getType();
        plant_obj["price"] = plant->getBasePrice();
        plant_obj["health"] = plant->getHealthLevel();
        plant_array.push_back(plant_obj);
    }

    return plant_array;
}

// API handler for cloning a plant (Prototype Pattern)
json::object handle_prototype_clone(int plant_id) {
    json::object response;

    Plant* original = nullptr;
    for (Plant* p : plants) {
        if (p->getPlantId() == plant_id) {
            original = p;
            break;
        }
    }

    if (!original) {
        response["error"] = "Plant not found";
        return response;
    }

    Plant* clone = original->clone();
    clone->setPlantId(plants.size() + 1);
    clone->setHealthLevel(85);
    plants.push_back(clone);

    response["success"] = true;
    response["original_id"] = original->getPlantId();
    response["clone_id"] = clone->getPlantId();
    response["type"] = clone->getType();

    return response;
}

// API handler for getting greenhouse structure (Composite Pattern)
json::object handle_get_greenhouse() {
    json::object response;

    if (!greenhouse) {
        // Create greenhouse structure
        greenhouse = new Greenhouse("NJD Films Greenhouse");

        auto* tropical = new GreenhouseSection("Tropical Section");
        auto* desert = new GreenhouseSection("Desert Section");

        auto* shelf1 = new Shelf(1);
        auto* shelf2 = new Shelf(2);

        if (plants.size() >= 2) {
            shelf1->add(new PlantLeaf(plants[0]));
            shelf2->add(new PlantLeaf(plants[1]));
        }

        tropical->add(shelf1);
        desert->add(shelf2);

        greenhouse->add(tropical);
        greenhouse->add(desert);
    }

    response["name"] = "NJD Films Greenhouse";
    response["sections"] = 2;
    response["total_plants"] = static_cast<int>(plants.size());

    return response;
}

// API handler for changing plant state (State Pattern)
json::object handle_state_change(int plant_id, const std::string& new_state) {
    json::object response;

    Plant* plant = nullptr;
    for (Plant* p : plants) {
        if (p->getPlantId() == plant_id) {
            plant = p;
            break;
        }
    }

    if (!plant) {
        response["error"] = "Plant not found";
        return response;
    }

    PlantContext* context = new PlantContext(plant);

    if (new_state == "seedling") {
        context->setState(new SeedlingState());
    } else if (new_state == "growing") {
        context->setState(new GrowingState());
    } else if (new_state == "mature") {
        context->setState(new MatureState());
    } else if (new_state == "flowering") {
        context->setState(new FloweringState());
    } else if (new_state == "dormant") {
        context->setState(new DormantState());
    } else {
        response["error"] = "Unknown state";
        delete context;
        return response;
    }

    response["success"] = true;
    response["plant_id"] = plant_id;
    response["new_state"] = new_state;

    delete context;
    return response;
}

// API handler for decorating plants (Decorator Pattern)
json::object handle_decorator_add(int plant_id, const json::array& decorations) {
    json::object response;

    Plant* plant = nullptr;
    for (Plant* p : plants) {
        if (p->getPlantId() == plant_id) {
            plant = p;
            break;
        }
    }

    if (!plant) {
        response["error"] = "Plant not found";
        return response;
    }

    // Start with basic plant or existing decorated plant
    PlantProduct* product = nullptr;
    if (decoratedPlants.find(plant_id) != decoratedPlants.end()) {
        product = decoratedPlants[plant_id];
    } else {
        product = new BasicPlant(plant);
    }

    // Apply decorations
    for (const auto& decoration : decorations) {
        std::string decor = decoration.as_string().c_str();
        if (decor == "pot") {
            product = new DecorativePotDecorator(product, "ceramic", "white");
        } else if (decor == "wrapping") {
            product = new GiftWrappingDecorator(product);
        } else if (decor == "card") {
            product = new GreetingCardDecorator(product, "Best wishes!");
        }
    }

    decoratedPlants[plant_id] = product;

    response["success"] = true;
    response["plant_id"] = plant_id;
    response["price"] = product->getPrice();
    response["description"] = product->getDescription();

    return response;
}

// API handler for setting watering strategy (Strategy Pattern)
json::object handle_strategy_set(int plant_id, const std::string& strategy) {
    json::object response;

    Plant* plant = nullptr;
    for (Plant* p : plants) {
        if (p->getPlantId() == plant_id) {
            plant = p;
            break;
        }
    }

    if (!plant) {
        response["error"] = "Plant not found";
        return response;
    }

    PlantCareStrategy* careStrategy = nullptr;
    std::string strategyDesc;

    if (strategy == "frequent") {
        careStrategy = new FrequentWatering();
        strategyDesc = "Frequent Watering: Water daily to keep soil consistently moist. Perfect for tropical plants.";
    } else if (strategy == "moderate") {
        careStrategy = new ModerateWatering();
        strategyDesc = "Moderate Watering: Water 2-3 times per week when top soil is dry. Good for most plants.";
    } else if (strategy == "minimal") {
        careStrategy = new MinimalWatering();
        strategyDesc = "Minimal Watering: Water once every 1-2 weeks. Ideal for succulents and cacti.";
    } else {
        response["error"] = "Unknown strategy";
        return response;
    }

    plantStrategies[plant_id] = strategy;

    response["success"] = true;
    response["plant_id"] = plant_id;
    response["strategy"] = strategy;
    response["description"] = strategyDesc;

    delete careStrategy;
    return response;
}

// API handler for creating arrangements (Builder Pattern)
json::object handle_builder_create(const std::string& type) {
    json::object response;

    PlantArrangementBuilder* builder = nullptr;

    if (type == "gift") {
        builder = new GiftArrangementBuilder();
    } else if (type == "landscape") {
        builder = new LandscapeArrangementBuilder();
    } else {
        response["error"] = "Unknown arrangement type";
        return response;
    }

    // Set available plants for the builder
    if (auto* giftBuilder = dynamic_cast<GiftArrangementBuilder*>(builder)) {
        giftBuilder->setAvailablePlants(plants);
    } else if (auto* landscapeBuilder = dynamic_cast<LandscapeArrangementBuilder*>(builder)) {
        landscapeBuilder->setAvailablePlants(plants);
    }

    ArrangementDirector director;
    director.setBuilder(builder);
    PlantArrangement* arrangement = director.constructDeluxeArrangement();

    if (arrangement) {
        arrangements.push_back(arrangement);

        response["success"] = true;
        response["name"] = arrangement->getName();
        response["description"] = arrangement->getDescription();
        response["container"] = arrangement->getContainerType();
        response["plant_count"] = arrangement->getPlantCount();
        response["total_price"] = arrangement->getTotalPrice();
    } else {
        response["error"] = "Failed to create arrangement";
    }

    return response;
}

// Main request handler
http::response<http::string_body> handle_request(http::request<http::string_body>&& req) {
    http::response<http::string_body> res;
    res.version(req.version());
    res.set(http::field::server, "Greenhouse API Server");
    res.set(http::field::content_type, "application/json");
    add_cors_headers(res);

    // Handle OPTIONS request for CORS
    if (req.method() == http::verb::options) {
        res.result(http::status::ok);
        res.body() = "";
        res.prepare_payload();
        return res;
    }

    std::string target = std::string(req.target());
    json::object response_json;

    try {
        if (req.method() == http::verb::get && target == "/api/plants") {
            // Get all plants
            json::array plants_array = handle_get_plants();
            response_json["plants"] = plants_array;
            res.result(http::status::ok);

        } else if (req.method() == http::verb::post && target.find("/api/factory/create") == 0) {
            // Create plant using factory
            auto body = json::parse(req.body());
            std::string plant_type = body.as_object()["type"].as_string().c_str();
            response_json = handle_factory_create(plant_type);
            res.result(http::status::ok);

        } else if (req.method() == http::verb::post && target.find("/api/prototype/clone") == 0) {
            // Clone plant using prototype
            auto body = json::parse(req.body());
            int plant_id = body.as_object()["id"].as_int64();
            response_json = handle_prototype_clone(plant_id);
            res.result(http::status::ok);

        } else if (req.method() == http::verb::get && target == "/api/greenhouse") {
            // Get greenhouse structure
            response_json = handle_get_greenhouse();
            res.result(http::status::ok);

        } else if (req.method() == http::verb::post && target.find("/api/state/change") == 0) {
            // Change plant state
            auto body = json::parse(req.body());
            int plant_id = body.as_object()["id"].as_int64();
            std::string new_state = body.as_object()["state"].as_string().c_str();
            response_json = handle_state_change(plant_id, new_state);
            res.result(http::status::ok);

        } else if (req.method() == http::verb::post && target.find("/api/decorator/add") == 0) {
            // Decorate plant
            auto body = json::parse(req.body());
            int plant_id = body.as_object()["id"].as_int64();
            json::array decorations = body.as_object()["decorations"].as_array();
            response_json = handle_decorator_add(plant_id, decorations);
            res.result(http::status::ok);

        } else if (req.method() == http::verb::post && target.find("/api/strategy/set") == 0) {
            // Set watering strategy
            auto body = json::parse(req.body());
            int plant_id = body.as_object()["id"].as_int64();
            std::string strategy = body.as_object()["strategy"].as_string().c_str();
            response_json = handle_strategy_set(plant_id, strategy);
            res.result(http::status::ok);

        } else if (req.method() == http::verb::post && target.find("/api/builder/create") == 0) {
            // Create arrangement
            auto body = json::parse(req.body());
            std::string type = body.as_object()["type"].as_string().c_str();
            response_json = handle_builder_create(type);
            res.result(http::status::ok);

        } else {
            response_json["error"] = "Endpoint not found";
            res.result(http::status::not_found);
        }

        res.body() = json::serialize(response_json);

    } catch (std::exception const& e) {
        response_json["error"] = e.what();
        res.body() = json::serialize(response_json);
        res.result(http::status::internal_server_error);
    }

    res.prepare_payload();
    return res;
}

// Session handler
void do_session(tcp::socket socket) {
    try {
        beast::flat_buffer buffer;
        http::request<http::string_body> req;
        http::read(socket, buffer, req);

        auto res = handle_request(std::move(req));
        http::write(socket, res);
        socket.shutdown(tcp::socket::shutdown_send);

    } catch (beast::system_error const& se) {
        if (se.code() != http::error::end_of_stream)
            std::cerr << "Error: " << se.code().message() << std::endl;
    } catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    try {
        auto const address = net::ip::make_address("127.0.0.1");
        unsigned short port = 8080;

        net::io_context ioc{1};
        tcp::acceptor acceptor{ioc, {address, port}};

        std::cout << "Greenhouse API Server running on http://127.0.0.1:8080" << std::endl;
        std::cout << "Available endpoints:" << std::endl;
        std::cout << "  GET  /api/plants - Get all plants" << std::endl;
        std::cout << "  POST /api/factory/create - Create plant (body: {\"type\": \"rose\"})" << std::endl;
        std::cout << "  POST /api/prototype/clone - Clone plant (body: {\"id\": 1})" << std::endl;
        std::cout << "  GET  /api/greenhouse - Get greenhouse structure" << std::endl;
        std::cout << "  POST /api/state/change - Change plant state (body: {\"id\": 1, \"state\": \"growing\"})" << std::endl;
        std::cout << "  POST /api/decorator/add - Decorate plant (body: {\"id\": 1, \"decorations\": [\"pot\", \"wrapping\", \"card\"]})" << std::endl;
        std::cout << "  POST /api/strategy/set - Set watering strategy (body: {\"id\": 1, \"strategy\": \"frequent\"})" << std::endl;
        std::cout << "  POST /api/builder/create - Create arrangement (body: {\"type\": \"gift\"})" << std::endl;

        while (true) {
            tcp::socket socket{ioc};
            acceptor.accept(socket);
            std::thread([sock = std::move(socket)]() mutable {
                do_session(std::move(sock));
            }).detach();
        }

    } catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
