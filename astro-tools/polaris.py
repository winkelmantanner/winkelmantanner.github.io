"""
This file contains python code to calculate
 the probability of having a better pole star than Polaris.
The probability is calculated both by simulation and calculation.
The simulation takes a long time to finish.
It takes around 10 times longer than my JavaScript implementation.
"""

import math
from random import random

# The number of stars visible to the naked eye is about 5000.
NUM_STARS_LIMIT = 5000

POLARIS_DISTANCE_FROM_POLE_DEGREES = 0.75
POLARIS_RANK = 50


def getProbabilityByCalculation(include_both_poles, N):
    """
    include_both_poles: bool
        if true, stars near either pole will be considered
        if false, stars near only one pole will be considered even though
            stars in both hemispheres are included in the ranking of stars

    N: float
        The pole star quality function must be
          1 / (rank * (distance_from_pole ** N))
    """

    r_p = POLARIS_DISTANCE_FROM_POLE_DEGREES * math.pi / 180
    p_not = 1
    for rank in range(1, 1 + NUM_STARS_LIMIT):
        max_dist_from_pole = (POLARIS_RANK * (r_p ** N) / rank) ** (1.0 / N)
        area_within_max_dist = 2 * math.pi * (1 - math.cos(max_dist_from_pole))
        if include_both_poles:
            area_within_max_dist *= 2
        p_not *= 1 - (area_within_max_dist / (4 * math.pi))
    return 1 - p_not


def getProbabilityBySimulation(
    num_rounds,
    include_both_poles,
    quality_function
):
    """
    num_rounds: int
        the number of rounds to run to get the probability.
        Go at least 10000 for accuracy.

    include_both_poles: bool
        if true, stars near either pole will be considered
        if false, stars near only one pole will be considered even though
            stars in both hemispheres are included in the ranking of stars

    quality_function: function(rank, radius) => float
        This function is called for each star.
        The higher the quality, the better the star is as a pole star.
        A planet will be counted if it has at least one star with
            quality >= the quality of Polaris.
        The rank is the brightness rank of the star, counting from 1.
        The radius is the angle in radians between
            the star and the celestial pole.
    """

    polaris_quality = quality_function(
        POLARIS_RANK,
        POLARIS_DISTANCE_FROM_POLE_DEGREES * math.pi / 180
    )

    num_rounds_with_better_pole_star_than_polaris = 0
    for round_index in range(num_rounds):
        found_better_pole_star = False
        for star_index in range(NUM_STARS_LIMIT):
            x = 0
            y = 0
            z = 0
            distance_squared = 0
            while x*y*z == 0 or distance_squared >= 1:
                x = (random() * 2) - 1
                y = (random() * 2) - 1
                z = (random() * 2) - 1
                distance_squared = (x*x) + (y*y) + (z*z)
            # <x, y, z> is now guaranteed to be in the unit sphere.
            # Also, x, y, and z are guaranteed to be nonzero.

            if include_both_poles or z > 0:
                quality = quality_function(
                    star_index + 1,
                    math.atan2(math.sqrt((x * x) + (y * y)), abs(z))
                )
                if quality >= polaris_quality:
                    found_better_pole_star = True
                    break
        if found_better_pole_star:
            num_rounds_with_better_pole_star_than_polaris += 1

    return num_rounds_with_better_pole_star_than_polaris * 1.0 / num_rounds


if __name__ == '__main__':
    N = 2
    INCLUDE_BOTH_POLES = False
    NUM_PLANETS_TO_SIMULATE = 10000

    print("N:", N)
    print("INCLUDE_BOTH_POLES:", INCLUDE_BOTH_POLES)
    print("NUM_PLANETS_TO_SIMULATE:", NUM_PLANETS_TO_SIMULATE)
    print("By calculation:", getProbabilityByCalculation(
        INCLUDE_BOTH_POLES,
        N
    ))
    print("By simulation:", getProbabilityBySimulation(
        NUM_PLANETS_TO_SIMULATE,
        INCLUDE_BOTH_POLES,
        lambda rank, radius: 1 / (rank * (radius ** N))
    ))
