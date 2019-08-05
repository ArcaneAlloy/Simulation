# Simulation
A simulation based on 4 traits and numerous specializations. Fairly well balanced as each simulation can lead to different results.
Simulation is based around food, a limited resource that determines both reproduction and survival.
Traits determine different base stats for each unit.
Each unit also has a chance to be specialized upon creation, which determines specific behaviors.
Traits:
  The first trait, at traits[0], is aggressiveness. This trait determines placement in the que for food, as in a unit with high aggressiveness
  would have the first chance at gathering food.
  Gathering food is based off of the next two traits, traits[1] and traits[2], speed and intelligence. 
  Speed determines a unit's chance at receiving two food as opposed to one. Two food are necessary for reproduction, one for survival.
  Intelligence determines the chance for gathering food, it is given a natural boost because it needs to be closer to 90%.
  The last trait is immunity, traits[3], which determines the chance to nullify the effects of a killer or siphon.
Specializations:
  These are fairly evident when viewing the behaviors() function.
  An unbounded's traits grow over time.
  A siphon can steal points from the traits of other units.
  A transmutation can turn points into food to survive and food into points to grow.
  A vigilante can survive and reproduce by killing a killer.
  A killer has multiple chances to kill another unit and replicate.
  A loaner creates loans between itself and other units who would otherwise die.
    The recipients of loans are given a boost to speed as from that point on, they need two to survive, giving one to the loaner
    and using the other to survive. Loaners can have odd impacts on the population.
  God was never furthered as the chance of spawning a God is too high.

