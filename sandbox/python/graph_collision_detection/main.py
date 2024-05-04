import pygame
import sys
import numpy as np
from pose import Pose

speed = 10
def get_time():
    return speed*pygame.time.get_ticks()/1000

glob_frame = Pose()
class Entity:
    def __init__(self, pos, vel, radius):
        self.pose = Pose(time=get_time(), pos=[*pos,0], pos_vel= [*vel,0])
        self.radius = radius

    def draw(self):
        pos = glob_frame.rel_pos(self.pose, get_time())[:-1]
        # circle
        pygame.draw.circle(screen, BLACK, pos, self.radius, 1)
        pygame.draw.circle(screen, BLACK, pos, 1, 1)
        # velocity
        vel = glob_frame.rel_vel(self.pose, get_time())[:-1]
        vel = self.radius * vel / np.linalg.norm(vel)
        pygame.draw.line(screen, RED, pos, pos+vel, 1)

class Edge:
    def __init__(self, n1, n2):
        self.n1 = n1
        self.n2 = n2

    def draw(self):
        pos1 = glob_frame.rel_pos(self.n1.pose, get_time())[:-1]
        pos2 = glob_frame.rel_pos(self.n2.pose, get_time())[:-1]
        pygame.draw.line(screen, BLACK, pos1, pos2,1)

# Initialize Pygame
pygame.init()

# Set up the display
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Collision Detection")
font = pygame.font.SysFont("Arial" , 18 , bold = True)

# Define colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)

entities = []
entities.append(Entity((100,100),(3,1),25))
entities.append(Entity((300,100),(1,2),20))
entities.append(Entity((100,200),(-1,1),15))

lines = []
lines.append(Edge(entities[0],entities[1]))
lines.append(Edge(entities[1],entities[2]))
lines.append(Edge(entities[2],entities[0]))


# Main loop
clock = pygame.time.Clock()
while True:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # Clear the screen
    screen.fill(WHITE)

    for entity in entities:
        entity.draw()
    for line in lines:
        line.draw()

    fps = f'FPS: {int(clock.get_fps())}'
    fps_t = font.render(fps , 1, RED)
    screen.blit(fps_t,(0,0))

    # Update the display
    pygame.display.update()

    clock.tick(60)


