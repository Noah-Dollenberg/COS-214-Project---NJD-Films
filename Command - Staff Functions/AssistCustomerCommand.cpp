#include "AssistCustomerCommand.h"
#include "SalesStaff.h"

AssistCustomerCommand::AssistCustomerCommand(SalesStaff* staff)
    : receiver(staff) {
}

void AssistCustomerCommand::execute() {
    if (receiver) {
        receiver->assistCustomer();
    }
}
