class Fecha{
  private: 
    int dia;
    int mes; 
    int anyo;
  
  public:
    Fecha(int dia, int mes, int anyo);
    
    int distancia(const Fecha &otra) const;
    int dia() const;
    int diaSemana() const;
    int mes() const;
    int anyo() const;
}
