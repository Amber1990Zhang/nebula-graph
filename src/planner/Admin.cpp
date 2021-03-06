
/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include "planner/Admin.h"

#include "util/ToJson.h"

namespace nebula {
namespace graph {

std::unique_ptr<PlanNodeDescription> CreateSpace::explain() const {
    auto desc = SingleInputNode::explain();
    addDescription("ifNotExists", util::toJson(ifNotExists_), desc.get());
    addDescription("spaceDesc", folly::toJson(util::toJson(spaceDesc_)), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> DropSpace::explain() const {
    auto desc = SingleInputNode::explain();
    addDescription("spaceName", spaceName_, desc.get());
    addDescription("ifExists", util::toJson(ifExists_), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> DescSpace::explain() const {
    auto desc = SingleInputNode::explain();
    addDescription("spaceName", spaceName_, desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> ShowCreateSpace::explain() const {
    auto desc = SingleInputNode::explain();
    addDescription("spaceName", spaceName_, desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> DropSnapshot::explain() const {
    auto desc = SingleInputNode::explain();
    addDescription("snapshotName", snapshotName_, desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> ShowParts::explain() const {
    auto desc = SingleInputNode::explain();
    addDescription("spaceId", folly::to<std::string>(spaceId_), desc.get());
    addDescription("partIds", folly::toJson(util::toJson(partIds_)), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> ShowConfigs::explain() const {
    auto desc = SingleInputNode::explain();
    addDescription("module", meta::cpp2::_ConfigModule_VALUES_TO_NAMES.at(module_), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> SetConfig::explain() const {
    auto desc = SingleInputNode::explain();
    addDescription("module", meta::cpp2::_ConfigModule_VALUES_TO_NAMES.at(module_), desc.get());
    addDescription("name", name_, desc.get());
    addDescription("value", value_.toString(), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> GetConfig::explain() const {
    auto desc = SingleInputNode::explain();
    addDescription("module", meta::cpp2::_ConfigModule_VALUES_TO_NAMES.at(module_), desc.get());
    addDescription("name", name_, desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> CreateNode::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("ifNotExist", util::toJson(ifNotExist_), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> DropNode::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("ifExist", util::toJson(ifExist_), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> CreateUser::explain() const {
    auto desc = CreateNode::explain();
    addDescription("username", *username_, desc.get());
    addDescription("password", "******", desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> DropUser::explain() const {
    auto desc = DropNode::explain();
    addDescription("username", *username_, desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> UpdateUser::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("username", *username_, desc.get());
    addDescription("password", "******", desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> GrantRole::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("username", *username_, desc.get());
    addDescription("spaceName", *spaceName_, desc.get());
    addDescription("role", meta::cpp2::_RoleType_VALUES_TO_NAMES.at(role_), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> RevokeRole::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("username", *username_, desc.get());
    addDescription("spaceName", *spaceName_, desc.get());
    addDescription("role", meta::cpp2::_RoleType_VALUES_TO_NAMES.at(role_), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> ChangePassword::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("username", *username_, desc.get());
    addDescription("password", "******", desc.get());
    addDescription("newPassword", "******", desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> ListUserRoles::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("username", *username_, desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> ListRoles::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("space", util::toJson(space_), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> SubmitJob::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("operation", meta::cpp2::_AdminJobOp_VALUES_TO_NAMES.at(op_), desc.get());
    addDescription("command", meta::cpp2::_AdminCmd_VALUES_TO_NAMES.at(cmd_), desc.get());
    addDescription("parameters", folly::toJson(util::toJson(params_)), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> Balance::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("deleteHosts", folly::toJson(util::toJson(deleteHosts_)), desc.get());
    return desc;
}

std::unique_ptr<PlanNodeDescription> ShowBalance::explain() const {
    auto desc = SingleDependencyNode::explain();
    addDescription("balanceId", util::toJson(id_), desc.get());
    return desc;
}

}   // namespace graph
}   // namespace nebula
