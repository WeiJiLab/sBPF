//
// Created by XingfengYang on 2020/5/13.
//

#include "../include/AbstractServiceListener.h"


void hm::netd::AbstractServiceListener::SetNetlink(std::shared_ptr<NetlinkManager> netlinkManager) {
    this->netlinkManager = netlinkManager;
}
