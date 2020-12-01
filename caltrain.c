#include "pintos_thread.h"

typedef struct lock lock ;
typedef struct condition condition;


struct station {
    int free_seats; // number of free seats in the train, -if one exists at station-.
    int passengers_waiting; // number of passengers waiting at station
    int passengers_leaving; // number of passengers who have found a free seat
    lock mutex;
    condition free_seats_available; // train arrived with free seats
    condition passengers_on_board; // all leaving passengers have been seated
};
void station_init(struct station *station) {
    /* initially, station is empty */
    station->free_seats = 0;
    station->passengers_waiting = 0;
    station->passengers_leaving = 0;
    /* initialize station mutex and condition variables */
    lock_init(&(station->mutex));
    cond_init(&(station->free_seats_available));
    cond_init(&(station->passengers_on_board));
}

void station_load_train(struct station *station, int count) {
    lock_acquire(&(station->mutex)); // enter critical section
    if (!count || !station->passengers_waiting) { // no free seats available or no passengers waiting
        lock_release(&(station->mutex)); // release the lock and leave critical section
        return; // train must leave the station promptly
    }
    station->free_seats = count;
    cond_broadcast(&(station->free_seats_available) , &(station->mutex)); // wake up all passengers waiting for a free seat
    cond_wait(&(station->passengers_on_board), &(station->mutex)); // waiting for all passengers to get on board
    station->free_seats = 0;
    lock_release(&(station->mutex)); // leave critical section
}

void station_wait_for_train(struct station *station) {
    lock_acquire(&(station->mutex)); // enter critical section
    station->passengers_waiting++;
    while (!station->free_seats)
        cond_wait(&(station->free_seats_available), &(station->mutex)); // waiting for a train with free seats
    station->passengers_waiting--;
    station->passengers_leaving++;
    station->free_seats--;
    lock_release(&(station->mutex)); // leave critical section
}

void station_on_board(struct station *station) {
    lock_acquire(&(station->mutex)); // enter critical section
    station->passengers_leaving--;
    if (!station->passengers_leaving && !(station->passengers_waiting && station->free_seats)) // all leaving passengers are on board, and no other passengers can get on the train
       cond_signal(&(station->passengers_on_board) , &(station->mutex));
    lock_release(&(station->mutex)); // leave critical section
}

