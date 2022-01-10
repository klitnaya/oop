#include <iostream>
#include <cmath>
#include <memory>


class Point {
public:
  Point();
  Point(std::istream &is);
  Point(double x, double y);

  double dist(Point& other);
  
  friend std::istream& operator>>(std::istream& is, Point& p);
  friend std::ostream& operator<<(std::ostream& os, Point& p);

  double x();
  double y();

private:
  double x_;
  double y_;
};
Point::Point() : x_(0.0), y_(0.0) {}

Point::Point(double x, double y) : x_(x), y_(y) {}

Point::Point(std::istream &is) {
  is >> x_ >> y_;
}

double Point::dist(Point& other) {
  double dx = (other.x_ - x_);
  double dy = (other.y_ - y_);
  return std::sqrt(dx*dx + dy*dy);
}

std::istream& operator>>(std::istream& is, Point& p) {
  is >> p.x_ >> p.y_;
  return is;
}

class Figure {
public:
    virtual double Area() = 0;
    virtual size_t VertexesNumber() = 0;
    virtual ~Figure() {};
};

class Octagon : public Figure {
public:
    Octagon();
    Octagon(std::istream &is);
    Octagon(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h);
    Octagon(Octagon &other);
    double Area();
    size_t VertexesNumber();
    virtual ~Octagon();
    Octagon& operator=(const Octagon& other);
    Octagon& operator==(const Octagon& other);
    friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<Octagon>& h);
private:
    Point a, b, c, d, e, f, g, h;
};


Octagon::Octagon(): a(0,0),b(0,0),c(0,0),d(0,0),e(0,0),f(0,0), g(0,0), h(0,0) {
} 
Octagon::Octagon(std::istream &is) {
    is >> a; 
    is >> b;
    is >> c;
    is >> d;
    is >> e;
    is >> f;
}
Octagon::Octagon(Point a1, Point b1,Point c1, Point d1, Point e1, Point f1, Point g1, Point h1): a(a1),b(b1),c(c1),d(d1),e(e1),f(f1), g(g1),h(h1) {
}
double Octagon::Area() {
    return 0.5*abs(a.x() * b.y() + b.x() * c.y() + c.x() *d.y() + d.x() * e.y() +e.x() * f.y() + f.x() * g.y() + g.x() * h.y() + h.x() * a.y() - b.x() * a.y() -c.x() * b.y() - d.x() * c.y() - e.x() * d.y() - f.x() * e.y() - g.x() * f.y() - h.x() * g.y() - a.x() * h.y());
}
Octagon::~Octagon() {
}
size_t Octagon::VertexesNumber() {
    return 8;
}
Octagon::Octagon(Octagon& other):Octagon(other.a,other.b,other.c,other.d,other.e,other.f, other.g, other.h) {
} 
Octagon& Octagon::operator = (const Octagon& other) {
  if (this == &other) return *this;
  a = other.a;
  b = other.b;
  c = other.c;
  d = other.d;
  e = other.e;
  f = other.f;
  g = other.g;
  h = other.h;
 
  return *this;
} 
Octagon& Octagon::operator == (const Octagon& other) {
  if (this == &other){
    std::cout << "Octagons are equal" << std::endl;
  } else {
    std::cout << "Octagons are not equal" << std::endl;
  } 
} 
std::ostream& operator<<(std::ostream& os, std::shared_ptr<Octagon>& h) {
  os << h->a << h->b << h->c << h->d << h->e << h->f << h->g << h->h;
  return os;
}


template<typename T> 
class SpehelList_item {
    public:
        SpehelList_item(): data(0) {};
        SpehelList_item(T t): data(t){};
        std::shared_ptr<SpehelList_item<T>> Get_next(){
            return next;
        };
        void Set_next(std::shared_ptr<SpehelList_item<T>> next_){
            next = next_;
        };
        T Get_data(){
            return data;
        }
    private:
        std::shared_ptr<SpehelList_item<T>> next = nullptr;
        T data;
};


template <class node, class T> class Titerator {
public:
  Titerator(std::shared_ptr<node> n) { node_ptr = n; }
  std::shared_ptr<T> operator*() { return node_ptr->GetValue(); }
  std::shared_ptr<T> operator->() { return node_ptr->GetValue(); }
  void operator++() { node_ptr = node_ptr->GetNext(); }
  Titerator operator++(int) {
    Titerator other(*this);
    ++(*this);
    return other;
  }
  bool operator==(Titerator const &i) { return node_ptr == i.node_ptr; };
  bool operator!=(Titerator const &i) { return node_ptr != i.node_ptr; };

private:
  std::shared_ptr<node> node_ptr;
};

template<typename T>
class SpehelList {
public:
    SpehelList() {
        arr_ = new T[1];
        capacity_ = 1;
    }

    SpehelList(SpehelList &other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
    }

    SpehelList(SpehelList &&other) noexcept {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
    }

    SpehelList &operator=(SpehelList &other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    SpehelList &operator=(SpehelList &&other) noexcept {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    ~SpehelList() {
        delete[] arr_;
    }

public:
    [[nodiscard]] bool isEmpty() const {
        return size_ == 0;
    }

    [[nodiscard]] size_t size() const {
        return size_;
    }

    [[nodiscard]] size_t capacity() const {
        return capacity_;
    }

    void push_back(const T &value) {
        if (size_ >= capacity_) addMemory();
        arr_[size_++] = value;
    }

    void pop() {
        --size_;
    }

    T &back() {
        return arr_[size_ - 1];
    }

    void remove(size_t index) {
        for (size_t i = index + 1; i < size_; ++i) {
            arr_[i - 1] = arr_[i];
        }
        --size_;
    }

public:
    T *begin() {
        return &arr_[0];
    }

    const T *begin() const {
        return &arr_[0];
    }

    T *end() {
        return &arr_[size_];
    }

    const T *end() const {
        return &arr_[size_];
    }

public:
    T &operator[](size_t index) {
        return arr_[index];
    }

    const T &operator[](size_t index) const {
        return arr_[index];
    }

private:

    void addMemory() {
        capacity_ *= 2;
        T *tmp = arr_;
        arr_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) arr_[i] = tmp[i];
        delete[] tmp;
    }

    T *arr_;
    size_t size_{};
    size_t capacity_{};
};

template<typename T>
inline std::ostream &operator<<(std::ostream &os, const SpehelList<T> &vec) {
    for (const T &val: vec) os << val << " ";
    return os;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
  os << "(" << p.x_ << ", " << p.y_ << ")";
  return os;
}

double Point::x(){
  return x_;
}

double Point::y(){
  return y_;
}

template <class T> class HListItem {
public:
  HListItem(const std::shared_ptr<Octagon> &octagon);
  template <class A> friend std::ostream& operator<<(std::ostream& os, HListItem<A> &obj);
  ~HListItem();
  std::shared_ptr<T> octagon;
  std::shared_ptr<HListItem<T>> next;
  std::shared_ptr<HListItem<T>> SetNext(std::shared_ptr<HListItem<T>> &next_);
  std::shared_ptr<HListItem<T>> GetNext();
  std::shared_ptr<T>& GetValue();
};

template <class T> HListItem<T>::HListItem(const std::shared_ptr<Octagon> &octagon) {
  this->octagon = octagon;
  this->next = nullptr;
}
template <class T> std::shared_ptr<HListItem<T>> HListItem<T>::SetNext(std::shared_ptr<HListItem<T>> &next_) {
  std::shared_ptr<HListItem<T>> prev = this->next;
  this->next = next_;
  return prev;
}
template <class T> std::shared_ptr<T>& HListItem<T>::GetValue() {
  return this->octagon;
}
template <class T> std::shared_ptr<HListItem<T>> HListItem<T>::GetNext() {
  return this->next;
}
template <class A> std::ostream& operator<<(std::ostream& os,HListItem<A> &obj) {
  os << "[" << obj.hexagon << "]" << std::endl;
  return os;
}
template <class T> HListItem<T>::~HListItem() {
}

template <class T> class TLinkedList {
public:
  TLinkedList();
  int size_of_list;
  size_t Length();
  std::shared_ptr<T>& First();
  std::shared_ptr<Octagon>& Last();
  std::shared_ptr<Octagon>& GetItem(size_t idx);
  bool Empty();
  TLinkedList(const std::shared_ptr<TLinkedList> &other);
  void InsertFirst(const std::shared_ptr<Octagon> &&octagon);
  void InsertLast(const std::shared_ptr<Octagon> &&octagon);
  void RemoveLast();
  void RemoveFirst();
  void Insert(const std::shared_ptr<Octagon> &&octagon, size_t position);
  void Remove(size_t position);
  void Clear();
  template <class A> friend std::ostream& operator<<(std::ostream& os, TLinkedList<A>& list);
  ~TLinkedList();
  Titerator<HListItem<T>, T> begin();
  Titerator<HListItem<T>, T> end();  
private:
  std::shared_ptr<HListItem<T>> front;
  std::shared_ptr<HListItem<T>> back;
};

template <class T>
Titerator<HListItem<T>, T> TLinkedList<T>::begin() {
  return Titerator<HListItem<T>, T> (front);
}

template <class T>
Titerator<HListItem<T>, T> TLinkedList<T>::end() {
  return Titerator<HListItem<T>, T>(back);
}

template <class T> TLinkedList<T>::TLinkedList() {
  size_of_list = 0;
  std::shared_ptr<HListItem<T>> front = nullptr;
  std::shared_ptr<HListItem<T>> back = nullptr;
  std::cout << "Octagon List created" << std::endl; 
}
template <class T> TLinkedList<T>::TLinkedList(const std::shared_ptr<TLinkedList> &other){
  front = other->front;
  back = other->back;
}
template <class T> size_t TLinkedList<T>::Length() {
  return size_of_list;
}
template <class T> bool TLinkedList<T>::Empty() {
  return size_of_list;
}
template <class T> std::shared_ptr<Octagon>& TLinkedList<T>::GetItem(size_t idx){
  int k = 0;
  std::shared_ptr<HListItem<T>> obj = front;
  while (k != idx){
    k++;
    obj = obj->GetNext();
  }
  return obj->GetValue();
}
template <class T> std::shared_ptr<T>& TLinkedList<T>::First() {
    return front->GetValue();
}
template <class T> std::shared_ptr<Octagon>& TLinkedList<T>::Last() {
  return back->GetValue();
}
template <class T> void TLinkedList<T>::InsertLast(const std::shared_ptr<Octagon> &&octagon) {
  std::shared_ptr<HListItem<T>> obj (new HListItem<T>(octagon));
 // std::shared_ptr<HListItem<T>> obj = std::make_shared<HListItem<T>>(HListItem<T>(hexagon));
  if(size_of_list == 0) {
    front = obj;
    back = obj;
    size_of_list++;
    return;
  }
  back->SetNext(obj); // = obj;
  back = obj;
  obj->next = nullptr; // = nullptr;
  size_of_list++;
}
template <class T> void TLinkedList<T>::RemoveLast() {
  if (size_of_list == 0) {
    std::cout << "Octagon does not pop_back, because the Octagon List is empty" << std:: endl;
  } else {
    if (front == back) {
      RemoveFirst();
      size_of_list--;
      return;
    }
    std::shared_ptr<HListItem<T>> prev_del = front;
    while (prev_del->GetNext() != back) {
      prev_del = prev_del->GetNext();
    }
    prev_del->next = nullptr;
    back = prev_del;
    size_of_list--;
    } 
}
template <class T> void TLinkedList<T>::InsertFirst(const std::shared_ptr<Octagon> &&octagon) {
    std::shared_ptr<HListItem<T>> obj (new HListItem<T>(octagon));
    if(size_of_list == 0) {
      front = obj;
      back = obj;
    } else {
      obj->SetNext(front); // = front;
      front = obj;
    }
    size_of_list++;
}
template <class T> void TLinkedList<T>::RemoveFirst() {
    if (size_of_list == 0) {
      std::cout << "Octagon does not pop_front, because the Octagon List is empty" << std:: endl;
    } else {
    std::shared_ptr<HListItem<T>> del = front;
    front = del->GetNext();
    size_of_list--;
    }
}
template <class T> void TLinkedList<T>::Insert(const std::shared_ptr<Octagon> &&octagon,size_t position) {
  if (position <0) {
    std::cout << "Position < zero" << std::endl;
  } else if (position > size_of_list) {
    std::cout << " Position > size_of_list" << std::endl;
  } else {
    std::shared_ptr<HListItem<T>> obj (new HListItem<T>(octagon));
    if (position == 0) {
      front = obj;
      back = obj;
    } else {
      int k = 0;
      std::shared_ptr<HListItem<T>> prev_insert = front;
      std::shared_ptr<HListItem<T>> next_insert;
      while(k+1 != position) {
        k++;
        prev_insert = prev_insert->GetNext();
      }
      next_insert = prev_insert->GetNext();
      prev_insert->SetNext(obj); // = obj;
      obj->SetNext(next_insert); // = next_insert;
    }
    size_of_list++;
  }
}
template <class T> void TLinkedList<T>::Remove(size_t position) {
  if (position > size_of_list ) {
    std:: cout << "Position " << position << " > " << "size " << size_of_list << " Not correct erase" << std::endl;
  } else if (position < 0) {
    std::cout << "Position < 0" << std::endl;
  } else {
    if (position == 0) {
      RemoveFirst();
    } else {
      int k = 0;
      std::shared_ptr<HListItem<T>> prev_erase = front;
      std::shared_ptr<HListItem<T>> next_erase;
      std::shared_ptr<HListItem<T>> del;
      while( k+1 != position) {
        k++;
        prev_erase = prev_erase->GetNext();
      }
      next_erase = prev_erase->GetNext();
      del = prev_erase->GetNext();
      next_erase = del->GetNext();
      prev_erase->SetNext(next_erase); // = next_erase;
    }
    size_of_list--;
  }
}
template <class T> void TLinkedList<T>::Clear() {
  std::shared_ptr<HListItem<T>> del = front;
  std::shared_ptr<HListItem<T>> prev_del;
  if(size_of_list !=0 ) {
    while(del->GetNext() != nullptr) {
      prev_del = del;
      del = del->GetNext();
    }
    size_of_list = 0;
    //   std::cout << "HListItem deleted" << std::endl;
  } 
  size_of_list = 0;
  std::shared_ptr<HListItem<T>> front;
  std::shared_ptr<HListItem<T>> back;
}
template <class T> std::ostream& operator<<(std::ostream& os, TLinkedList<T>& hl) {
  if (hl.size_of_list == 0) {
    os << "The octagon list is empty, so there is nothing to output" << std::endl;
  } else {
    os << "Print Octagon List" << std::endl;
    std::shared_ptr<HListItem<T>> obj = hl.front;
    while(obj != nullptr) {
      if (obj->GetNext() != nullptr) {
        os << obj->GetValue() << " " << "," << " ";
        obj = obj->GetNext();
      } else {
        os << obj->GetValue();
        obj = obj->GetNext();
      }
    }
    os << std::endl;
  }
  return os;
}
template <class T> TLinkedList<T>::~TLinkedList() {
  std::shared_ptr<HListItem<T>> del = front;
  std::shared_ptr<HListItem<T>> prev_del;
  if(size_of_list !=0 ) {
    while(del->GetNext() != nullptr) {
      prev_del = del;
      del = del->GetNext();
    }
    size_of_list = 0;
    std::cout << "octagon List deleted" << std::endl;
  } 
}

class TAllocationBlock {
 public:
  TAllocationBlock(size_t size, size_t count);
  void* allocate();
  void deallocate(void* pointer);
  bool has_free_blocks();

  virtual ~TAllocationBlock();

 private:
  size_t _size;
  size_t _count;
  char* _used_blocks;
  SpehelList<void*> vec_free_blocks;
  size_t _free_count;
};

TAllocationBlock::TAllocationBlock(size_t size, size_t count)
        : _size(size), _count(count) {
    _used_blocks = (char *) malloc(_size * _count);
    for (size_t i = 0; i < _count; ++i) {
        vec_free_blocks.push_back(_used_blocks + i * _size);
        std::cout << i << " OK" << std::endl;
    }
    _free_count = _count;
    std::cout << "TAllocationBlock: Memory init" << std::endl;
}

void *TAllocationBlock::allocate() {
    void *result = nullptr;

    if (_free_count > 0) {
        std::cout << vec_free_blocks.size() << std::endl;
        result = vec_free_blocks.back();
        vec_free_blocks.pop();
        _free_count--;
        std::cout << "TAllocationBlock: Allocate " << (_count - _free_count);
        std::cout << " of " << _count << std::endl;

    } else {
        std::cout << "TAllocationBlock: No memory exception :-)" << std::endl;
    }

    return result;
}

void TAllocationBlock::deallocate(void *pointer) {
    std::cout << "TAllocationBlock: Deallocate block " << std::endl;

    vec_free_blocks[_free_count] = pointer;
    _free_count++;
}

bool TAllocationBlock::has_free_blocks() {
    return _free_count > 0;
}

TAllocationBlock::~TAllocationBlock() {
    if (_free_count < _count) {
        std::cout << "TAllocationBlock: Memory leak?" << std::endl;
    } else {
        std::cout << "TAllocationBlock: Memory freed" << std::endl;
    }
    delete _used_blocks;
}

int main() {
  
  TLinkedList<Octagon> tlinkedlist;
  std::cout << tlinkedlist.Empty() << std::endl;
  tlinkedlist.InsertLast(std::shared_ptr<Octagon>(new Octagon(Point(1,2),Point(2,3),Point(3,4),Point(5,6),Point(7,8),Point(9,10), Point(11,12), Point(12,13))));
  tlinkedlist.InsertLast(std::shared_ptr<Octagon>(new Octagon(Point(13,14),Point(14,15),Point(15,16),Point(16,17),Point(17,18),Point(18,19),Point(19,20),Point(20,21))));
  tlinkedlist.InsertLast(std::shared_ptr<Octagon>(new Octagon(Point(17,18),Point(18,19),Point(19,20),Point(20,21),Point(21,22),Point(23,24), Point(25,26),Point(27,28))));
  tlinkedlist.InsertLast(std::shared_ptr<Octagon>(new Octagon(Point(17,18),Point(18,19),Point(19,20),Point(20,21),Point(21,22),Point(23,24), Point(25,26),Point(27,28))));
  std::cout << tlinkedlist;
  tlinkedlist.RemoveLast();
  std::cout << tlinkedlist.Length() << std::endl;
  tlinkedlist.RemoveFirst();
  tlinkedlist.InsertFirst(std::shared_ptr<Octagon>(new Octagon(Point(2,3),Point(3,4),Point(4,5),Point(5,6),Point(6,7),Point(7,8), Point(8,9),Point(9,10))));
  tlinkedlist.Insert(std::shared_ptr<Octagon>(new Octagon(Point(1,1),Point(2,3),Point(3,4),Point(5,6),Point(7,8),Point(9,10), Point(11,12),Point(13,18))),2);
  
  std::cout << tlinkedlist.Empty() << std::endl;
  std::cout << tlinkedlist.First() << std::endl;
  std::cout << tlinkedlist.Last() << std::endl;
  std::cout << tlinkedlist.GetItem(2) << std::endl;
 
  tlinkedlist.Remove(2);
  std::cout << tlinkedlist;
  tlinkedlist.Clear();
  TAllocationBlock allocator(sizeof(int), 10);
    int *a1 = nullptr;
    int *a2 = nullptr;
    int *a3 = nullptr;
    int *a4 = nullptr;
    int *a5 = nullptr;

  a1 = (int *)allocator.allocate();
  *a1 = 1;
  std::cout << "a1 pointer value:" << *a1 << std::endl;

  a2 = (int *) allocator.allocate();
  *a2 = 2;
  std::cout << "a2 pointer value:" << *a2 << std::endl;

  a3 = (int *) allocator.allocate();
  *a3 = 3;
  std::cout << "a3 pointer value:" << *a3 << std::endl;

  allocator.deallocate(a1);
  allocator.deallocate(a3);

  a4 = (int *) allocator.allocate();
  *a4 = 4;
  std::cout << "a4 pointer value:" << *a4 << std::endl;

  a5 = (int *) allocator.allocate();
  *a5 = 5;
  std::cout << "a5 pointer value:" << *a5 << std::endl;

  allocator.deallocate(a2);
  allocator.deallocate(a4);
  allocator.deallocate(a5);
  return 0;
}

