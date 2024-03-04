#include "atomic_counters.hpp"

atomic_counter_atomic_incdec::atomic_counter_atomic_incdec()
    : atomic_counter()
    , m_value(0) {
}

int atomic_counter_atomic_incdec::increment() {
    // TODO: Modify this code using atomic fetch_add operations
    int prev_value = m_value;
    // m_value = m_value + 1;
    m_value.fetch_add(1, std::memory_order_seq_cst);
    return prev_value;
}

int atomic_counter_atomic_incdec::decrement() {
    // TODO: Modify this code using atomic fetch_sub operations
    int prev_value = m_value;
    // m_value = m_value - 1;
    m_value.fetch_sub(1, std::memory_order_seq_cst);
    return prev_value;
}

void atomic_counter_atomic_incdec::set(int value) {
    // TODO: Modify this code using atomic store operations
    // m_value = value; (Still works but slower)
    m_value.store(value);
    
}

int atomic_counter_atomic_incdec::get() {
    // TODO: Modify this code using atomic load operations
    // return m_value; (Still works but slower)
    return m_value.load();
}
