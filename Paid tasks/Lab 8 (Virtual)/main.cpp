#include <iostream>
using namespace std;

class base_conversion{
private:
    double m_initialValue, m_convertedValue;

public:
    base_conversion(double initial){
        m_initialValue = initial;
    }

/*
    virtual void convert_it(){
        cout << "\nBase conversion by super class" << endl;
        m_convertedValue = m_initialValue*2 ;
    }
*/
    virtual void convert_it() = 0;

    double get_initial() const{
        return m_initialValue;
    }
    double get_converted() const{
        return m_convertedValue;
    }

    void set_initial(double initial){
        m_initialValue = initial;
    }
    void set_converted(double converted){
        m_convertedValue = converted;
    }
};

class kilos_miles: public base_conversion{
public:
    kilos_miles(double initial):base_conversion(initial){}

    void convert_it(){
        cout << "\nConversion by kilos_miles class" << endl;
        set_converted(get_initial() * 0.6);
    }
};

class miles_kilos: public base_conversion{
public:
    miles_kilos(double initial):base_conversion(initial){}

    void convert_it(){
        cout << "\nConversion by miles_kilos class" << endl;
        set_converted(get_initial() / 0.6);
    }
};

class yard_meter: public base_conversion{
public:
    yard_meter(double initial):base_conversion(initial){}

    void newConvert(){
        cout << "\nNot able to convert yet" << endl;
    }

    void convert_it(){
        cout << "\nConversion by yard_meter class" << endl;
        set_converted(get_initial() * 0.9);
    }

};

int main()
{
/*
    // task 1.2 instructions

    base_conversion baseOBJ(100);
    baseOBJ.convert_it();
    cout << "Initial value is: " << baseOBJ.get_initial()<<endl;
    cout << "Converted value is: " << baseOBJ.get_converted()<<endl;

    kilos_miles kmOBJ(100);
    kmOBJ.convert_it();
    cout << "Distance in kilometers is: " << kmOBJ.get_initial()<<endl;
    cout << "Distance in miles is: " << kmOBJ.get_converted()<<endl;

    miles_kilos mkOBJ(60);
    mkOBJ.convert_it();
    cout << "Distance in miles is: " << mkOBJ.get_initial()<<endl;
    cout << "Distance in kilometers is: " << mkOBJ.get_converted()<<endl;

    yard_meter ymOBJ(50);
    ymOBJ.convert_it();
    cout << "yard_meter initial value is: " << ymOBJ.get_initial()<<endl;
    cout << "yard_meter converted value is: " << ymOBJ.get_converted()<<endl;
*/

/*
    // task 1.3.3 instructions

    base_conversion baseOBJ(100);
    baseOBJ.convert_it();
*/


    yard_meter ymOBJ(50);
    ymOBJ.convert_it();
	cout << "yard_meter initial value is: " << ymOBJ.get_initial()<<endl;
    cout << "yard_meter converted value is: " << ymOBJ.get_converted()<<endl;


    return 0;
}
