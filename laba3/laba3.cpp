#include <iostream>
#include <cmath>
#include<memory>

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

class HListItem {
public:
  HListItem(const std::shared_ptr<Octagon> &octagon);
  friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<HListItem>&& obj);
  ~HListItem();
  std::shared_ptr<Octagon> octagon;
  std::shared_ptr<HListItem> next;
};

HListItem::HListItem(const std::shared_ptr<Octagon> &octagon) {
  this->octagon = octagon;
  this->next = nullptr;
}
std::ostream& operator<<(std::ostream& os,std::shared_ptr<HListItem>& obj) {
  os << "[" << obj->octagon << "]" << std::endl;
  return os;
}
HListItem::~HListItem() {
}

class TLinkedList {
public:
  TLinkedList();
  int size_of_list;
  size_t Length();
  std::shared_ptr<Octagon>& First();
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
  friend std::ostream& operator<<(std::ostream& os, TLinkedList& list);
  ~TLinkedList(); 
private:
  std::shared_ptr<HListItem> front;
  std::shared_ptr<HListItem> back;
};

TLinkedList::TLinkedList() {
  size_of_list = 0;
  std::shared_ptr<HListItem> front;
  std::shared_ptr<HListItem> back;
  std::cout << "Octagon List created" << std::endl; 
}
TLinkedList::TLinkedList(const std::shared_ptr<TLinkedList> &other){
  front = other->front;
  back = other->back;
}
size_t TLinkedList::Length() {
  return size_of_list;
}
bool TLinkedList::Empty() {
  return size_of_list;
}
std::shared_ptr<Octagon>& TLinkedList::GetItem(size_t idx){
  int k = 0;
  std::shared_ptr<HListItem> obj = front;
  while (k != idx){
    k++;
    obj = obj->next;
  }
  return obj->octagon;
}
std::shared_ptr<Octagon>& TLinkedList::First() {
  return front->octagon;
}
std::shared_ptr<Octagon>& TLinkedList::Last() {
  return back->octagon;
}
void TLinkedList::InsertLast(const std::shared_ptr<Octagon> &&octagon) {
  std::shared_ptr<HListItem> obj (new HListItem(octagon));
  if(size_of_list == 0) {
    front = obj;
    back = obj;
    size_of_list++;
    return;
  }
  back->next = obj;
  back = obj;
  obj->next = nullptr;
  size_of_list++;
}
void TLinkedList::RemoveLast() {
  if (size_of_list == 0) {
    std::cout << "Octagon does not pop_back, because the Octagon List is empty" << std:: endl;
  } else {
    if (front == back) {
      RemoveFirst();
      size_of_list--;
      return;
    }
    std::shared_ptr<HListItem> prev_del = front;
    while (prev_del->next != back) {
      prev_del = prev_del->next;
    }
    prev_del->next = nullptr;
    back = prev_del;
    size_of_list--;
    } 
}
void TLinkedList::InsertFirst(const std::shared_ptr<Octagon> &&octagon) {
    std::shared_ptr<HListItem> obj(new HListItem(octagon));
    if(size_of_list == 0) {
      front = obj;
      back = obj;
    } else {
      obj->next = front;
      front = obj;
    }
    size_of_list++;
}
void TLinkedList::RemoveFirst() {
    if (size_of_list == 0) {
      std::cout << "Octagon does not pop_front, because the Octagon List is empty" << std:: endl;
    } else {
    std::shared_ptr<HListItem> del = front;
    front = del->next;
    size_of_list--;
    }
}
void TLinkedList::Insert(const std::shared_ptr<Octagon> &&octagon,size_t position) {
  if (position <0) {
    std::cout << "Position < zero" << std::endl;
  } else if (position > size_of_list) {
    std::cout << " Position > size_of_list" << std::endl;
  } else {
    std::shared_ptr<HListItem> obj (new HListItem(octagon));
    if (position == 0) {
      front = obj;
      back = obj;
    } else {
      int k = 0;
      std::shared_ptr<HListItem> prev_insert = front;
      std::shared_ptr<HListItem> next_insert;
      while(k+1 != position) {
        k++;
        prev_insert = prev_insert->next;
      }
      next_insert = prev_insert->next;
      prev_insert->next = obj;
      obj->next = next_insert;
    }
    size_of_list++;
  }
}
void TLinkedList::Remove(size_t position) {
  if (position > size_of_list ) {
    std:: cout << "Position " << position << " > " << "size " << size_of_list << " Not correct erase" << std::endl;
  } else if (position < 0) {
    std::cout << "Position < 0" << std::endl;
  } else {
    if (position == 0) {
      RemoveFirst();
    } else {
      int k = 0;
      std::shared_ptr<HListItem> prev_erase = front;
      std::shared_ptr<HListItem> next_erase;
      std::shared_ptr<HListItem> del;
      while( k+1 != position) {
        k++;
        prev_erase = prev_erase->next;
      }
      next_erase = prev_erase->next;
      del = prev_erase->next;
      next_erase = del->next;
      prev_erase->next = next_erase;
    }
    size_of_list--;
  }
}
void TLinkedList::Clear() {
  std::shared_ptr<HListItem> del = front;
  std::shared_ptr<HListItem> prev_del;
  if(size_of_list !=0 ) {
    while(del->next != nullptr) {
      prev_del = del;
      del = del->next;
    }
    size_of_list = 0;
    //   std::cout << "HListItem deleted" << std::endl;
  } 
  size_of_list = 0;
  std::shared_ptr<HListItem>* front;
  std::shared_ptr<HListItem> back;
}
std::ostream& operator<<(std::ostream& os, TLinkedList& hl) {
  if (hl.size_of_list == 0) {
    os << "The Octagon list is empty, so there is nothing to output" << std::endl;
  } else {
    os << "Print Octagon List" << std::endl;
    std::shared_ptr<HListItem> obj = hl.front;
    while(obj != nullptr) {
      if (obj->next != nullptr) {
        os << obj->octagon << " " << "," << " ";
        obj = obj->next;
      } else {
        os << obj->octagon;
        obj = obj->next;
      }
    }
    os << std::endl;
  }
  return os;
}
TLinkedList::~TLinkedList() {
  std::shared_ptr<HListItem> del = front;
  std::shared_ptr<HListItem> prev_del;
  if(size_of_list !=0 ) {
    while(del->next != nullptr) {
      prev_del = del;
      del = del->next;
    }
    size_of_list = 0;
    std::cout << "Octagon List deleted" << std::endl;
  } 
}

int main() {
  TLinkedList tlinkedlist;
  tlinkedlist.Empty();
  tlinkedlist.InsertLast(std::shared_ptr<Octagon>(new Octagon(Point(1,2),Point(2,3),Point(3,4),Point(5,6),Point(7,8),Point(9,10), Point(11, 12), Point(13,14))));
  tlinkedlist.InsertLast(std::shared_ptr<Octagon>(new Octagon(Point(11,12),Point(12,13),Point(13,14),Point(14,15),Point(15,16),Point(16,17), Point(17,18),Point(18,19))));
  tlinkedlist.InsertLast(std::shared_ptr<Octagon>(new Octagon(Point(17,18),Point(18,19),Point(19,20),Point(20,21),Point(21,22),Point(23,24),Point(25,26), Point(26,27))));
  tlinkedlist.InsertLast(std::shared_ptr<Octagon>(new Octagon(Point(17,18),Point(18,19),Point(19,20),Point(20,21),Point(21,22),Point(23,24), Point(25,26), Point(27,28))));
  std::cout << tlinkedlist;
  tlinkedlist.RemoveLast();
  std::cout << tlinkedlist.Length() << std::endl;
  tlinkedlist.RemoveFirst();
  tlinkedlist.InsertFirst(std::shared_ptr<Octagon>(new Octagon(Point(2,3),Point(3,4),Point(4,5),Point(5,6),Point(6,7),Point(7,8), Point(8,9), Point(9,10))));
  tlinkedlist.Insert(std::shared_ptr<Octagon>(new Octagon(Point(1,1),Point(2,3),Point(3,4),Point(5,6),Point(7,8),Point(9,10), Point(10,11), Point(12,13))),2);
  std::cout << tlinkedlist.Empty() << std::endl;
  std::cout << tlinkedlist.First() << std::endl;
  std::cout << tlinkedlist.Last() << std::endl;
  std::cout << tlinkedlist.GetItem(2) << std::endl;
  tlinkedlist.Remove(2);
  std::cout << tlinkedlist;
  tlinkedlist.Clear();
  return 0;
}