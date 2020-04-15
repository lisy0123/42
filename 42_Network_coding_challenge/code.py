import sys
import math
from inspect import currentframe
import numpy
import time
from numpy import array


class DebugTool:
    def __init__(self):
        try:
            self.fd = open(r"C:\Users\JUNJI\Documents\Condingame\pyCharmProject\FantasticBits\input.txt")
        except (ImportError, OSError):
            self.debug_mode = False
        else:
            import matplotlib.pyplot as plt
            self.plt = plt
            self.fg = None
            self.ax = None
            self.debug_mode = True

    def input(self):
        if self.debug_mode:
            data = self.fd.readline()
        else:
            data = input()
        print(data, file=sys.stderr, flush=True)
        return data

    def start_timer(self):
        self.timer = time.time()

    def elapsed_time(self):
        end_time = time.time()
        interval = end_time - self.timer
        self.stderr(interval * 1000, "m sec")

    @staticmethod
    def stderr(*args):
        cf = currentframe()
        print(*args, "@" + str(cf.f_back.f_lineno), file=sys.stderr, flush=True)

    def plot_vector_clock(self, vct, clr="b", txt=""):
        # todo: refactor in OO style
        self.plt.plot((0, vct[0]), (0, vct[1]), color=clr)
        self.plt.text(vct[0], vct[1], txt)


class Entity:
    def __init__(self, entity_id, entity_type, x, y, vx, vy, state):
        self.entity_id = int(entity_id)
        self.entity_type = str(entity_type)
        self.x = int(x)
        self.y = int(y)
        self.location = array([self.x, self.y])
        self.vx = int(vx)
        self.vy = int(vy)
        self.velocity = array([self.vx, self.vy])
        self.state = int(state)

        self.command = ""
        self.target = None  # type: Entity
        self.magic_cost = 0
        #self.obliviate_effect = 0

    def __lt__(self, other):
        return self.entity_id < other.entity_id

    def throw(self):
        # always shoot to the mid of the goal
        self.command = "THROW {0} {1} {2}".format(opp_goal_x, int(FIELD_LENGTH_Y / 2), 500)

    def thrust_to(self, x, y, thrust=150):
        self.command = "MOVE {0} {1} {2}".format(x, y, thrust)

    def move_to_target(self):
        self.thrust_to(*(self.target.location + self.target.velocity - self.velocity))

    def accio_to_target(self):
        self.command = "WINGARDIUM {0} {1} {2} 50".format(self.target.entity_id, opp_goal_x, int(FIELD_LENGTH_Y / 2))
        self.magic_cost = 20

    def predict_distance(self, ent):
        return numpy.linalg.norm((ent.predict_location()) - (self.predict_location()))

    def predict_location(self):
        vctr = self.vector_of_command()
        return self.location + self.velocity + vctr

    def set_throw_target(self, snaffles, wizards, role="ALL"):
        # NEW LOGIC PENDING
        # distance_list=[] # type:list[int, Entity]
        # for wiz in wizards:
        #     distance_list.append(wiz.list_distance(snaffles))

        if len(snaffles) == 1:
            self.target = snaffles[0]
        else:
            # remove snaffles already targeted
            snfls = [snf for snf in snaffles if snf not in [wiz.target for wiz in wizards]]

            # filter snaffles by field position
            if role == "FWD":
                snfls1 = [snf for snf in snfls if abs(snf.x - opp_goal_x) <= (FIELD_LENGTH_X * 1 / 4)]
                if snfls1:
                    snfls = snfls1
            elif role == "BACK":
                snfls1 = [snf for snf in snfls if abs(snf.x - opp_goal_x) > (FIELD_LENGTH_X * 1 / 4)]
                if snfls1:
                    snfls = snfls1
            # set target closest one as in next turn
            self.target = min([[snf.predict_distance(self), snf] for snf in snfls])[1]

    def command_for_throw(self, opponents):
        # use ACCIO if condition below matched
        # distance to target, distance opponent to target, direction of target, spell_gauge
        if (self.predict_distance(self.target) >
                min(min([opp.predict_distance(self.target) for opp in opponents]), 4000)) \
                and abs(self.target.x - opp_goal_x) > abs(self.x - opp_goal_x) \
                and magic_gauge > 10 + 10:
            self.accio_to_target()
        else:
            self.move_to_target()

    def dodge_bludgers(self, bludgers):
        close_bld_dist = min([[self.predict_distance(bld), bld] for bld in bludgers])
        if close_bld_dist[0] < BLUDGER_SIZE + WIZARD_SIZE:
            bld = close_bld_dist[1]  # type: Entity
            direction = self.predict_location() - bld.predict_location()
            norm = numpy.linalg.norm(direction)
            dodge_vector = direction / norm * ((BLUDGER_SIZE + WIZARD_SIZE) * 2 - close_bld_dist[0])
            print(dodge_vector, file=sys.stderr)

            # adjust if move command already ordered
            dodge_vector += self.vector_of_command()
            print(dodge_vector, file=sys.stderr)
            print(self.vector_of_command(), file=sys.stderr)

            self.thrust_to(int(dodge_vector[0]), int(dodge_vector[1]), min(int(numpy.linalg.norm(dodge_vector)), 150))

            print("{0}, {1}, {2}".format(dodge_vector[0], dodge_vector[1],
                                         int(numpy.linalg.norm(dodge_vector))), file=sys.stderr)

    def vector_of_command(self):
        cmd_list = self.command.split()
        if len(cmd_list) > 0 and cmd_list[0] == "MOVE":
            direction = array([int(cmd_list[1]), int(cmd_list[2])]) - self.location
            norm = numpy.linalg.norm(direction)
            vector = direction / norm * int(cmd_list[3])
            # print(self.entity_id, file=sys.stderr)
            # print(cmd_list, file=sys.stderr)
            # print(numpy.linalg.norm(vector), file=sys.stderr)
        else:
            vector = array([0, 0])
        return vector

#    def obliviate_bludgers(self, bludgers):
#        close_bld_dist = min([[self.predict_distance(bld), bld] for bld in bludgers])
#        print(close_bld_dist[0], file=sys.stderr)
#        if self.obliviate_effect <= 0 and close_bld_dist[0] < (BLUDGER_SIZE + WIZARD_SIZE) * 2 and magic_gauge > 20 + 5:
#            self.command = "OBLIVIATE {0}".format(close_bld_dist[1].entity_id)
#            self.magic_cost = 5
#            self.obliviate_effect = 3
#        else:
#            self.obliviate_effect -= 1
#            self.dodge_bludgers(bludgers)

    def is_obstacle(self, start, end, size1=0, size2=0):
        vctr1 = array(end - start)
        vctr2 = array(self.location - start)
        distance = abs(numpy.cross(vctr1, vctr2) / numpy.linalg.norm(vctr1))
        if distance <= size1 + size2:
            return True

    def search_flipendo_target(self, snaffles, obstruct):
        # able to goal or not
        if magic_gauge > 20 + 20:
            for snf in snaffles:
                vctr = ((snf.predict_location() - self.predict_location()) *
                        (opp_goal_x - self.predict_location()[0]) / (
                            snf.predict_location()[0] - self.predict_location()[0]))

                print(snf.entity_id, vctr, self.predict_location(), file=sys.stderr)
                print(snf.predict_location() - self.predict_location(),
                      int((opp_goal_x - self.predict_location()[0]) / (
                          snf.predict_location()[0] - self.predict_location()[0])),
                      self.predict_location()[1] + vctr[1],
                      file=sys.stderr)

                if TOP_GOAL_Y < self.predict_location()[1] + vctr[1] < BOTTOM_GOAL_Y \
                        and (opp_goal_x - self.predict_location()[0]) / (
                                    snf.predict_location()[0] - self.predict_location()[0]) > 0 \
                        and self.predict_distance(snf) > 2000:
                    if not [obs for obs in obstruct
                            if obs.is_obstacle(self.predict_location(), self.predict_location() + vctr, 700)]:
                        self.target = snf.entity_id
                        return snf.entity_id
        return None

#    def flipend_to_target(self):
#        self.command = "FLIPENDO {0}".format(self.target)
#        self.magic_cost = 20


def vector_size_of(vctr, size):
    norm = numpy.linalg.norm(vctr)
    return vctr / norm * size


def output_command(list_of_entity):
    for ent in list_of_entity:  # type:Entity
        print(ent.command)


DT = DebugTool()

# constants
FIELD_LENGTH_X = 16001
FIELD_LENGTH_Y = 7501
LEFT_GOAL_X = 0
RIGHT_GOAL_X = 16000
TOP_GOAL_Y = int((FIELD_LENGTH_Y - 4000 + 300 + 150) / 2)
BOTTOM_GOAL_Y = int(3750 + 4000 - 300 / 2 - 150 / 2)
BLUDGER_SIZE = 200
WIZARD_SIZE = 400

# global var
magic_gauge = 0
turn_count = 0

# game start
my_team_id = int(DT.input())  # if 0 you need to score on the right of the map, if 1 , on the left
if my_team_id == 0:
    opp_goal_x = RIGHT_GOAL_X
    my_goal_x = LEFT_GOAL_X
else:
    opp_goal_x = LEFT_GOAL_X
    my_goal_x = RIGHT_GOAL_X

# game loop
while True:
    my_score, my_magic_point = map(int, DT.input().split())
    opp_score, opp_magic_point = map(int, DT.input().split())
    number_of_entities = int(DT.input())

    entities = []  # type:list[Entity]
    for i in range(number_of_entities):  # type:int
        entities.append(Entity(*(DT.input().split())))

    # WARNING! entity_id  NOT EQUAL to list index
    wizs = [entity for entity in entities if entity.entity_type == "WIZARD"]
    snfs = [entity for entity in entities if entity.entity_type == "SNAFFLE"]
    blds = [entity for entity in entities if entity.entity_type == "BLUDGER"]
    opps = [entity for entity in entities if entity.entity_type == "OPPONENT_WIZARD"]

    # choose forward
    forward = max([[wiz.x, wiz] for wiz in wizs])[1]

    for wiz in wizs:
        if wiz.state == 0:
#            if wiz.search_flipendo_target(snfs, blds + opps):
#                wiz.flipend_to_target()
 #           else:
            if wiz is forward:
                wiz.set_throw_target(snfs, wizs, "FWD")
            else:
                wiz.set_throw_target(snfs, wizs, "BACK")
            wiz.command_for_throw(opps)
            # wiz.obliviate_bludgers(blds)
            # wiz.dodge_bludgers(blds)
        else:
            wiz.throw()

    # for debug, print(afo, file=sys.stderr)
    print(magic_gauge, file=sys.stderr)

    output_command(wizs)
    for wiz in wizs:
        magic_gauge -= wiz.magic_cost
    magic_gauge = min(magic_gauge + 1, 100)
    turn_count += 1
