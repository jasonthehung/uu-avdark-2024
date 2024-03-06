#include "user_locks.hpp"

// Constructor for user_lock_dekker class
user_lock_dekker::user_lock_dekker()
    : user_lock() {
    // Initialize flags for both threads as false
    m_flag[0] = m_flag[1] = false;
    // Initialize turn as false
    m_turn = false;
}

// Function to acquire lock
void user_lock_dekker::lock(int thread_id) {
    // Set the flag for the current thread as true
    m_flag[thread_id] = true;

    // while other thread is in critical section
    while (m_flag[!thread_id])
    {
        // If it's not the turn of the current thread
        if (m_turn != thread_id)
        {
            // Set the flag for the current thread as false
            m_flag[thread_id] = false;
            // Wait until it's the turn of the current thread
            while (m_turn != thread_id);
            // Set the flag for the current thread as true
            m_flag[thread_id] = true;
        }
    }
}

// Function to release lock
void user_lock_dekker::unlock(int thread_id) {
    // Change the turn to the other thread
    m_turn = !thread_id;
    // Set the flag for the current thread as false
    m_flag[thread_id] = false;
}