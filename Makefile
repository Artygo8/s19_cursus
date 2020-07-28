PHILO_ONE = srcs/philo_one
PHILO_TWO = srcs/philo_two
PHILO_THREE = srcs/philo_three

CASES := $(PHILO_ONE)
SUBMAKE = make $@ -C $(case)

all:
	$(foreach case, $(CASES), $(SUBMAKE))

one:
	make -C $(PHILO_ONE)

two:
	make -C $(PHILO_TWO)

three:
	make -C $(PHILO_THREE)

re:	clean all

clean:
	$(foreach case, $(CASES), $(SUBMAKE))
