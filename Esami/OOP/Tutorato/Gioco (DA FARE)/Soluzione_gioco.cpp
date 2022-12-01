#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

template<class T>
class Character {

private:
  T*** power;

protected:
  int rows;
  int columns;

  T** getColumn(int index) {
    T** arr = new T*[columns];
    for(int i = 0; i < rows; i++) {
      arr[i] = power[i][index];
    }
    return arr;
  }

public:
  Character(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    power = new T**[rows];
    for(int i = 0; i < rows; i++) {
      power[i] = new T*[columns];
      for(int j = 0; j < columns; j++) {
	      power[i][j] = new T((T)(rand()) / RAND_MAX);
      }
    }
  }

  void traspose() {
    int tmp = rows;
    rows = columns;
    columns = tmp;
    T pt[rows][columns];
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < columns; j++) {
	      pt[i][j] = *power[j][i];
      }
    }
    for(int i = 0; i < columns; i++) {
      for(int j = 0; j < rows; j++) {
	      delete[] power[i][j];
      }
      delete[] power[i];
    }
    delete[] power;
    power = new T**[rows];
    for(int i = 0; i < rows; i++) {
        power[i] = new T*[columns];
      for(int j = 0; j < columns; j++) {
	      power[i][j] = new T(pt[i][j]);
      }
    }
  }

  virtual T attack() = 0;

  virtual ostream& put(ostream& os) {
    os << "----------------------------------";
    os << typeid(*this).name() << ":" << endl;
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < columns; j++) {
	      os << *power[i][j] << " ";
      }
      os << endl;
    }
    return os;
  }
};

template<class T>
ostream& operator<<(ostream& os, Character<T>& obj) {
  obj.put(os);
  return os;
}

template<class T>
class Wizard : public Character<T> {

public:
  Wizard(int rows, int columns) : Character<T>::Character(rows, columns) {
    Character<T>::traspose();
  }

  T attack() {
    int dado = rand() % 12 + 1;
    cout << "Dado: " << dado << ", Attacco: ";
    if(dado % 2 == 0) {
      Character<T>::traspose();
      return 0;
    }
    int col = 0;
    do {
       col = rand() % Character<T>::columns;
    } while(col%2 == 0);
    T** c = Character<T>::getColumn(col);
    T somma = 0;
    for(int i = 0; i < Character<T>::rows; i++) {
      somma += *c[i];
    }
    delete[] c;
    somma += dado % 6;
    return somma;
  }

  ostream& put(ostream& os) {
    Character<T>::put(os);
    os << attack();
    return os;
  }
};

template<class T>
class Cleric : public Character<T> {
public:
  Cleric(int rows, int columns) : Character<T>::Character(rows, columns) {}

  T attack() {
    int dado = rand() % 6 + 1;
    cout << "Dado: " << dado << ", Attacco: ";
    switch(dado) {
      case 1:
      case 5: {
        return 0;
      }
      case 2:
      case 4:
      case 6: {
        int col = rand() % Character<T>::columns;
        T** c = Character<T>::getColumn(col);
        T somma = 0;
        for(int i = 0; i < Character<T>::rows; i++) {
	        somma += *c[i];
        }
        delete[] c;
        return dado + somma;
      }
      default: {
        return dado / 2.0;
      } 
    }
  }

  ostream& put(ostream& os) {
    Character<T>::put(os);
    os << attack();
    return os;
  }
};

int main() {
  srand(11223344);
  
  const int DIM = 10;

  Character<double>* vett[DIM];

  for(int i = 0; i < DIM; i++) {
    int r = rand() % 2;
    if(r == 0) {
      vett[i] = new Wizard<double>(rand()%5 + 2, rand()%5 + 2);
    }
    else {
      vett[i] = new Cleric<double>(rand()%5 + 2, rand()%5 + 2);
    }
  }

  for(int i = 0; i < DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
  }
}
