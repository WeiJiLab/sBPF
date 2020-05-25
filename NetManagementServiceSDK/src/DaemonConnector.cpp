//
// Created by XingfengYang on 2020/5/15.
//

#include "../include/DaemonConnector.h"

hm::netd::DaemonConnector::~DaemonConnector() noexcept = default;

hm::netd::DaemonConnector::DaemonConnector(hm::netd::DaemonConnector &&) noexcept = default;

hm::netd::DaemonConnector &hm::netd::DaemonConnector::operator=(hm::netd::DaemonConnector &&) noexcept = default;

hm::netd::DaemonConnector::DaemonConnector() {

}
