import random

def randomSolution(tsp):
    cities = list(range(len(tsp)))
    random.shuffle(cities)
    return cities

def routeLength(tsp, solution):
    length = 0
    for i in range(len(solution)):
        length += tsp[solution[i - 1]][solution[i]]
    return length

def getNeighbours(solution):
    neighbours = []
    for i in range(len(solution)):
        for j in range(i + 1, len(solution)):
            neighbour = solution.copy()
            neighbour[i], neighbour[j] = neighbour[j], neighbour[i]
            neighbours.append(neighbour)
    return neighbours

def getBestNeighbour(tsp, neighbours):
    bestNeighbour = None
    bestRouteLength = float('inf')
    for neighbour in neighbours:
        currentRouteLength = routeLength(tsp, neighbour)
        if currentRouteLength < bestRouteLength:
            bestRouteLength = currentRouteLength
            bestNeighbour = neighbour
    return bestNeighbour, bestRouteLength

def hillClimbing(tsp):
    currentSolution = randomSolution(tsp)
    currentRouteLength = routeLength(tsp, currentSolution)
    
    while True:
        neighbours = getNeighbours(currentSolution)
        bestNeighbour, bestNeighbourRouteLength = getBestNeighbour(tsp, neighbours)
        
        if bestNeighbourRouteLength >= currentRouteLength:
            break
        
        currentSolution = bestNeighbour
        currentRouteLength = bestNeighbourRouteLength

    return currentSolution, currentRouteLength

def main():
    tsp = [
        [0, 400, 500, 300],
        [400, 0, 300, 500],
        [500, 300, 0, 400],
        [300, 500, 400, 0]
    ]

    solution, length = hillClimbing(tsp)
    print("Optimal route:", solution)
    print("Route length:", length)

if __name__ == "__main__":
    main()
