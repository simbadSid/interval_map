#include <map>


template<typename K, typename V>
class interval_map
{
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val
    template<typename V_forward>
    interval_map(V_forward&& val)
            : m_valBegin(std::forward<V_forward>(val))
    {}

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    template<typename V_forward>
    void assign(K const& keyBegin, K const& keyEnd, V_forward&& val)
    requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value)
    {
        if (keyBegin >= keyEnd)
        {
            return; // Empty interval, do nothing
        }

        auto itLow = m_map.lower_bound(keyBegin);
        auto itHigh = m_map.lower_bound(keyEnd);

        bool removeInterval = true;
        V pastValue;

        // Check if we need to adjust itLow to merge with an existing interval
        if (itLow != m_map.begin())
        {
            --itLow; // Move to the previous element
            pastValue = itLow->second;
            if (itLow->second == val)
            {
                // The value at keyBegin matches the new value, no need to insert keyBegin
                ++itLow;
                // Remove entries up to keyEnd
                m_map.erase(itLow, itHigh);
                removeInterval = false;
            }
            else
            {
                ++itLow; // Restore iterator position
            }
        }

        // Handle the case where we might want to merge with the end interval
        if (itHigh != m_map.begin())
        {
            --itHigh;
            if (itHigh->second == val)
            {
                // The value at keyEnd matches the new value, merge intervals
                ++itHigh;
            }
            else
            {
                itHigh = m_map.upper_bound(keyEnd); // Move to the next higher
            }
        }

        // Remove affected intervals
        if (removeInterval)
        {
            m_map.erase(itLow, itHigh);
            // Insert the new interval
            m_map[keyBegin] = val;
        }

        // Insert the original value at keyEnd if necessary
        if (itHigh != m_map.end() && itHigh->first > keyEnd)
        {
            m_map[keyEnd] = pastValue; // Set the next value at keyEnd
        }
        else if (itHigh == m_map.end() || itHigh->first != keyEnd)
        {
            // If itHigh is at the end or not exactly at keyEnd, we insert the default value
            m_map[keyEnd] = m_valBegin; // Insert m_valBegin for the gap at keyEnd
        }
    }


    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        auto it=m_map.upper_bound(key);
        if(it==m_map.begin()) {
            return m_valBegin;
        }
        else {
            return (--it)->second;
        }
    }

    bool consecutive_duplicates()
    {
        // Check for no consecutive duplicates in m_map
        auto it = this->m_map.begin();
        while (it != this->m_map.end())
        {
            auto next_it = std::next(it);
            if (next_it != this->m_map.end() && it->second == next_it->second)
            {
                return true;
            }
            it++;
        }

        return false;
    }

};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.