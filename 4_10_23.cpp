https://leetcode.com/problems/design-hashmap/?envType=daily-question&envId=2023-10-04
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 
 class MyHashMap
{
public:
    vector<pair<int, int>> map;
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
        for (int i = 0; i < map.size(); i++)
        {
            if (map[i].first == key)
            {
                map[i].second = value;
                return;
            }
        }
        map.push_back(make_pair(key, value));
    }

    int get(int key)
    {
        for (int i = 0; i < map.size(); i++)
        {
            if (map[i].first == key)
            {
                return map[i].second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        for (int i = 0; i < map.size(); i++)
        {
            if (map[i].first == key)
            {
                map.erase(map.begin() + i);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

class MyHashMap
{
public:
    int arr[1000001];
    MyHashMap()
    {
        for (int i = 0; i < 1000001; i++)
        {
            arr[i] = -1;
        }
    }

    void put(int key, int value)
    {
        arr[key] = value;
    }

    int get(int key)
    {
        return arr[key];
    }

    void remove(int key)
    {
        arr[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */