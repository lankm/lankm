import pygame
import sys
import numpy as np
from time import time
from pose import Pose

glob_frame = Pose()
class Entity:
    def __init__(self, pos, vel, radius):
        self.pose = Pose(time=get_time(), pos=[*pos,0], pos_vel= [*vel,0])
        self.radius = radius

    def draw(self, screen):
        pos = glob_frame.rel_pos(self.pose, get_time())[:-1]
        # circle
        pygame.draw.circle(screen, BLACK, pos, self.radius, 1)
        pygame.draw.circle(screen, BLACK, pos, 1, 1)

class Edge:
    def __init__(self, n1, n2):
        self.n1 = n1
        self.n2 = n2

    def draw(self, screen):
        pos1 = glob_frame.rel_pos(self.n1.pose, get_time())[:-1]
        pos2 = glob_frame.rel_pos(self.n2.pose, get_time())[:-1]
        pygame.draw.line(screen, BLACK, pos1, pos2,1)

# =============================================================================

# Define colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED =   (255, 0, 0)
GREEN = (0, 255, 0)
BLUE =  (0, 0, 255)

game_speed = 1
def get_time():
    return game_speed*pygame.time.get_ticks()/1000

def display_time(screen):
    font = pygame.font.SysFont("Arial" , 18 , bold = True)
    time = f'TIME: {get_time()}'
    time_t = font.render(time, 1, BLUE)
    screen.blit(time_t,(0,0))
def display_fps(screen, clock):
    font = pygame.font.SysFont("Arial" , 18 , bold = True)
    fps = f'FPS: {int(clock.get_fps())}'
    fps_t = font.render(fps, 1, RED)
    screen.blit(fps_t,(0,20))

def run_simulatin(screen, display_size):
    # Generate random entities
    count, max_velocity, max_radius = 20, 25, 50
    positions = np.random.uniform(low=0, high=display_size-max_radius*2, size=(count,2))
    velocities = np.random.uniform(low=-max_velocity, high=max_velocity, size=(count,2))
    radii = np.random.uniform(low=5, high=max_radius, size=count)
    entities = []
    for pos, vel, r in zip(positions, velocities, radii):
        pos += max_radius
        entities.append(Entity(pos,vel,r))

    # generate edges
    lines = []
    lines.append(Edge(entities[0],entities[1]))
    lines.append(Edge(entities[1],entities[2]))
    lines.append(Edge(entities[2],entities[0]))
    lines.append(Edge(entities[3],entities[0]))
    lines.append(Edge(entities[2],entities[3]))


    # Main loop
    clock = pygame.time.Clock()
    while True:
        # Handle events
        for event in pygame.event.get():
            match event.type:
                # if exiting
                case pygame.QUIT:
                    return False
                # restarting sim
                case pygame.KEYDOWN:
                    return True
                            
        # Clear the screen
        screen.fill(WHITE)

        # Render sim
        for entity in entities:
            entity.draw(screen)
        for line in lines:
            line.draw(screen)

        # display info
        display_time(screen)
        display_fps(screen, clock)

        # Update the display
        pygame.display.update()
        clock.tick()

def main():
    # Initialize Pygame
    pygame.init()

    # Set up the display
    display_size = 1024
    screen = pygame.display.set_mode((display_size, display_size))
    pygame.display.set_caption("Collision Detection")

    running = True
    while running:
        running = run_simulatin(screen, display_size)

    pygame.quit()
    sys.exit()

if __name__ == '__main__':
    main()
