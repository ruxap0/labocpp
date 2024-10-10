class Time 
{
    private:
        int hour;
        int minute;
    
    public:
        Time();
        Time(int ho, int min);
        Time(int ho, int min);
        Time(int min);
        ~Time(); // useless car pas de variables allouées dynamiquement
        int getHour();
        int getMinute();
        void setHour(int hour);
        void setMinute(int minute);
        void display();
}