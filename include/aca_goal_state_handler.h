// Copyright 2019 The Alcor Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ACA_GOAL_STATE_HANDLER_H
#define ACA_GOAL_STATE_HANDLER_H

#include "aca_net_programming_if.h"
#include "goalstateprovisioner.grpc.pb.h"

namespace aca_goal_state_handler
{
class Aca_Goal_State_Handler {
  public:
  static Aca_Goal_State_Handler &get_instance();

  // process ONE VPC state
  int update_vpc_state_workitem(const alcor::schema::VpcState current_VpcState,
                                alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process 0 to N VPC states
  int update_vpc_states(alcor::schema::GoalState &parsed_struct,
                        alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process ONE subnet state
  int update_subnet_state_workitem(const alcor::schema::SubnetState current_SubnetState,
                                   alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process 0 to N subnet states
  int update_subnet_states(alcor::schema::GoalState &parsed_struct,
                           alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process ONE port state
  int update_port_state_workitem(const alcor::schema::PortState current_PortState,
                                 alcor::schema::GoalState &parsed_struct,
                                 alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process 0 to N port states
  int update_port_states(alcor::schema::GoalState &parsed_struct,
                         alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process ONE port state for GoalStateV2
  int update_port_state_workitem_v2(const alcor::schema::PortState current_PortState,
                                    alcor::schema::GoalStateV2 &parsed_struct,
                                    alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process 0 to N port states for GoalStateV2
  int update_port_states(alcor::schema::GoalStateV2 &parsed_struct,
                         alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process ONE neighbor state
  int update_neighbor_state_workitem(const alcor::schema::NeighborState current_NeighborState,
                                     alcor::schema::GoalState &parsed_struct,
                                     alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process 0 to N neighbor states
  int update_neighbor_states(alcor::schema::GoalState &parsed_struct,
                             alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process ONE neighbor state for GoalStateV2
  int update_neighbor_state_workitem_v2(const alcor::schema::NeighborState current_NeighborState,
                                        alcor::schema::GoalStateV2 &parsed_struct,
                                        alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process 0 to N neighbor states for GoalStateV2
  int update_neighbor_states(alcor::schema::GoalStateV2 &parsed_struct,
                             alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process ONE router state
  int update_router_state_workitem(const alcor::schema::RouterState current_RouterState,
                                   alcor::schema::GoalState &parsed_struct,
                                   alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process 0 to N router states
  int update_router_states(alcor::schema::GoalState &parsed_struct,
                           alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process ONE router state for GoalStateV2
  int update_router_state_workitem_v2(const alcor::schema::RouterState current_RouterState,
                                      alcor::schema::GoalStateV2 &parsed_struct,
                                      alcor::schema::GoalStateOperationReply &gsOperationReply);

  // process 0 to N router states for GoalStateV2
  int update_router_states(alcor::schema::GoalStateV2 &parsed_struct,
                           alcor::schema::GoalStateOperationReply &gsOperationReply);

  void add_goal_state_operation_status(
          alcor::schema::GoalStateOperationReply &gsOperationReply, std::string id,
          alcor::schema::ResourceType resource_type, alcor::schema::OperationType operation_type,
          int operation_rc, ulong culminative_dataplane_programming_time,
          ulong culminative_network_configuration_time, ulong state_elapse_time);

  // compiler will flag error when below is called
  Aca_Goal_State_Handler(Aca_Goal_State_Handler const &) = delete;
  void operator=(Aca_Goal_State_Handler const &) = delete;

  private:
  // constructor and destructor marked as private so that noone can call it
  // for the singleton implementation
  Aca_Goal_State_Handler();
  ~Aca_Goal_State_Handler();

  aca_net_programming_if::ACA_Core_Net_Programming_Interface *core_net_programming_if;
};
} // namespace aca_goal_state_handler
#endif // @ifndef ACA_GOAL_STATE_HANDLER_H
