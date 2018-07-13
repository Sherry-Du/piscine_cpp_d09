
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(CommunicationAPI &api)
    : _api(api)
{
}

CommunicationDevice::CommunicationDevice(std::istream &input, std::ostream &output)
    : _input(input),
      _output(output)
{
    if (!_input.good())
        throw std::runtime_error("Invalid input stream.");
    if (!_output.good())
        throw std::runtime_error("Invalid output stream.");
}

CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                   std::string *users,
                                   size_t nbUsers) {
    for (size_t i = 0; i < nbUsers; ++i)
        _api.addUser(users[i]);
    _api.startMission(missionName);
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
    _api.sendMessage(user, message);
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
    _api.receiveMessage(user, message);
}
