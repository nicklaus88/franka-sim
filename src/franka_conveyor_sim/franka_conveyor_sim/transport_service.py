"""Service-only worker: isolates blocking transport calls from Python callbacks."""
from gz.transport13 import Node
from gz.msgs10.boolean_pb2 import Boolean
from gz.msgs10.entity_factory_pb2 import EntityFactory
from gz.msgs10.entity_pb2 import Entity
from gz.msgs10.world_control_pb2 import WorldControl

_node = None


def request_boolean(service, payload, create, timeout=3000):
    global _node
    if _node is None:
        _node = Node()
    message_type = WorldControl if create == 'control' else (EntityFactory if create else Entity)
    message = message_type()
    message.ParseFromString(payload)
    ok, reply = _node.request(service, message, message_type, Boolean, timeout)
    return bool(ok), bool(reply.data)
