//1
template <class E>
class Conjunto {
  vector<E> cadena;
  int cont;
  
public:
  //Constructor
  Conjunto();
  
  //Funciones
  void inserta(const E &e){
    this.cadena.push_back(e);
    this.cont++;
  }
  
  void elimina(const E &e){
    bool encontrado = false;
    for(int i = 0; i < cont && !encontrado; i++){
      if(this.cadena[i] == e) encontrado = true;
    }
    this.cont--;
  }
   
  bool contiene(const E &e) const{
    for(int i = 0; i < cont && !encontrado; i++){
      if(this.cadena[i] == e) return true;
    }
    return false;
  }
  
  E unitario(){}
  
  int cardinal() {
   return this.cont;
  }
  

};
