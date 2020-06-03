class HashEntry {
private:
      int key;
      int value;
public:
      HashEntry(int key, int value) {
            this->key = key;
            this->value = value;
      }
 
      int getKey() {
            return key;
      }
 
      int getValue() {
            return value;
      }
 
      void setValue(int value) {
            this->value = value;
      }
};