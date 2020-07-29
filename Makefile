PHILO_ONE = srcs/philo_one
PHILO_TWO = srcs/philo_two
PHILO_THREE = srcs/philo_three

CASES := $(PHILO_ONE)
SUBMAKE = make $@ -C $(case)

all:
	$(foreach case, $(CASES), $(SUBMAKE))

one:
	make -C $(PHILO_ONE)
	$(PHILO_ONE)/philo_one

two:
	make -C $(PHILO_TWO)
	$(PHILO_TWO)/philo_two

three:
	make -C $(PHILO_THREE)
	$(PHILO_TWO)/philo_three

re:	clean all

clean:
	$(foreach case, $(CASES), $(SUBMAKE))

fclean:
	$(foreach case, $(CASES), $(SUBMAKE))
