What this module do:
--------------------------------------------
Provides a way to schedule basic operations on nodes: (un)publish, un(promote)
and (un)stiky.
Check if the user who last modified the node has rights to edit the node at
the moment of taking actions.

What this module DOESN'T do:
--------------------------------------------
Integrate with revisions or workflows: I don't use revisions or workflows
so it's not tested against them.
Provide a special permission to schedule actions: if an user can edit nodes
he can publish, promote, etc. them, so he cant schedule an alarm at given
time, log into the site, and perform the operation.
Provide a way to select wich content types to operate: same as above, if
an operation can be made by hand, there isn't necessary to exclude from
scheduling.

Scheduler module is a very robust and mantained module I suggest to use
it if you have any concerns about this module features o lack of them.
