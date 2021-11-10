#include<string.h>
using namespace std;

template <typename V>
class Mapnode{
    public:
    string key;
    V value;
    Mapnode* next;

    Mapnode(string key,V value){//constructor
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Mapnode(){//destructor
        delete next;
    }
};

template <typename V>
class ourmap{
    Mapnode<V>** buckets;
    int count;
    int numBuckets;
    int getBucketIndex(string key){
        int hashCode = 0;
        int currCoeff = 1;
        for (int i = key.length() - 1; i >= 0 ; i++){
            hashCode += key[i] * currCoeff;
            hashCode = hashCode % numBuckets;
            currCoeff *= 37;//random prime numeber as a base
            currCoeff = currCoeff % numBuckets;
        }
        
        return hashcode % numBuckets;
    }

    public:
    ourmap(){//constructor
        count = 0;
        numBuckets = 20;
        buckets = new Mapnode<V>*[numBuckets];
        for (int i = 0; i < numBuckets; i++){
            buckets[i] = NULL;
        }
    }

    ~ourmap(){//destructor
        for (int i = 0; i < numBuckets; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    int size{
        return count;
    }

    void insert(string key,V value){
        int bucketIndex = getBucketIndex(key);
        Mapnode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){//changing the Value
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        Mapnode<V>* node = new Mapnode(key,value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
    }

    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        Mapnode<V>* prev = NULL;
        V value;
        while (head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }
                else{
                    prev->next = head->next;
                }
                value = head->value;
                head->next = NULL;
                delete [] head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
    
    V getValue(string key){
       int bucketIndex = getBucketIndex(key);
       MapNode<V>* head = buckets[bucketIndex];
       while (head != NULL){
           if(head ->key == key){
               return head->value;
           }
           head = head->next;
       }
       return 0;

    }
};