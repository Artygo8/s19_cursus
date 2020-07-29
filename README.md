# Philosophers

Philosophers is a 42 school project to introduce the students to threads handling.
It is made of 3 sub-modules: the 1st one uses pthreads and mutex, the 2nd one uses pthreads and semaphores and the 3rd one uses processes and semaphores.

## ___Philo_one___

```C
#include <pthread.h>

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
int pthread_detach(pthread_t thread);
int pthread_join(pthread_t thread, void **value_ptr);
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```

[https://www.youtube.com/watch?v=7U3Eo0ynmHo](Interesting Resource)

## ___Philo_two___

```C
#include <semaphore.h>

sem_t *sem_open(const char *name, int oflag, ...);
sem_close
sem_post
sem_wait
sem_unlink
```
