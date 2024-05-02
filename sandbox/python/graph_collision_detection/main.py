import pygame
import sys
import numpy as np

speed = 10
def get_time():
    return speed*pygame.time.get_ticks()/1000

class Entity:
    def __init__(self, pos, vel, radius):
        self.pos = np.array(pos)
        self.vel = np.array(vel)
        self.radius = radius
        self.time = get_time()

    def cur_pos(self):
        dt = get_time() - self.time
        return self.pos + dt*self.vel
    def draw(self):
        # circle
        pygame.draw.circle(screen, BLACK, self.cur_pos(), self.radius, 1)
        pygame.draw.circle(screen, BLACK, self.cur_pos(), 1, 1)
        # velocity
        vel = self.cur_pos() + self.radius*self.vel/np.linalg.norm(self.vel)
        pygame.draw.line(screen, RED, self.cur_pos(), vel, 1)

class Edge:
    def __init__(self, n1, n2):
        self.n1 = n1
        self.n2 = n2

    def draw(self):
        pygame.draw.line(screen, BLACK, self.n1.cur_pos(), self.n2.cur_pos(),1)

# Initialize Pygame
pygame.init()

# Set up the display
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Pygame Example")
clock = pygame.time.Clock()
font = pygame.font.SysFont("Arial" , 18 , bold = True)


# Define colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)

entities = []
entities.append(Entity((10,10),(3,1),25))
entities.append(Entity((30,10),(1,2),20))
entities.append(Entity((100,20),(-1,1),15))

lines = []
lines.append(Edge(entities[0],entities[1]))
lines.append(Edge(entities[1],entities[2]))
lines.append(Edge(entities[2],entities[0]))


# Main loop
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

    clock.tick(60)
    fps = f'FPS: {int(clock.get_fps())}'
    fps_t = font.render(fps , 1, pygame.Color("RED"))
    screen.blit(fps_t,(0,0))

    # Update the display
    pygame.display.update()


