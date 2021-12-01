#include <iostream>
#include <iomanip>

using namespace std;

class Students
{
private:
    string name, course, surname, result;
    float mark1, mark2, mark3, promedio;
    int id;

public:
    Students()
    {
        name = course = surname = "";
        id = mark1 = mark2 = mark3 = 0;
    }
    Students(string name, string course, string surname, float mark1, float mark2, float mark3, int id)
    {
        this->name = name;
        this->surname = surname;
        this->course = course;
        this->mark1 = mark1;
        this->mark2 = mark2;
        this->mark3 = mark3;
        this->id = id;
    }

    string getName()
    {
        return name;
    }
    string getSurname()
    {
        return surname;
    }
    string getCourse()
    {
        return course;
    }
    int getId()
    {
        return id;
    }
    float getMark1()
    {
        return mark1;
    }
    float getMark2()
    {
        return mark2;
    }
    float getMark3()
    {
        return mark3;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setCourse(string course)
    {
        this->course = course;
    }
    void setSurname(string surname)
    {
        this->surname = surname;
    }
    void setMark1(int mark1)
    {
        this->mark1 = mark1;
    }
    void setMark2(int mark2)
    {
        this->mark2 = mark2;
    }
    void setMark3(int mark3)
    {
        this->mark3 = mark3;
    }
    void setId(int id)
    {
        this->id = id;
    }

    void Promedio()
    {
        promedio = mark1 + mark2 + mark3;
        promedio /= 3;
    }

    string Aprobacion()
    {
        string result;
        if (promedio >= 3 && promedio <= 5)
            return "aprobó";
        else if (promedio < 3 && promedio > 0)
            return "no aprobó";
        else
            return "nota invalida";
    }

    void toString()
    {
        string result;
        Promedio();
        result = Aprobacion();
        cout
            << "Nombre: " << name << endl
            << "Apellido: " << surname << endl
            << "Documento: " << id << endl
            << "Asignatura: " << course << endl
            << "Nota: " << fixed << setprecision(2) << promedio << endl
            << "Resultado: " << result << endl;
    }
};

int main()
{
    Students estudiantes[4];
    string nName, nSurname, nCourse, result;
    float nMark1, nMark2, nMark3;
    int option, nId;
    int out = 1;
    int i = 0;
    int studentOption;
    int repeatME;
    do
    {

        cout << "\n---------------\n"
             << "Menú: \n"
             << "1. Crear un estudiante \n"
             << "2. Modificar datos de estudiante\n"
             << "3. Mostrar datos estudiantes\n"
             << "4. Eliminar estudiantes\n"
             << "5. Salir\n";
        cin >> option;
        switch (option)
        {
        case 1:
            if (i == 3)
            {
                i = 0;
            }
            while (i < 3)
            {
                cout << "Nombre: ";
                cin >> nName;
                cout << "Apellido: ";
                cin >> nSurname;
                cout << "Documento: ";
                cin >> nId;
                cout << "Asignatura: ";
                cin >> nCourse;
                cout << "Nota Primer Corte: ";
                cin >> nMark1;
                cout << "Nota Segundo Corte: ";
                cin >> nMark2;
                cout << "Nota Tercer Corte: ";
                cin >> nMark3;
                estudiantes[i] = Students(nName, nCourse, nSurname, nMark1, nMark2, nMark3, nId);
                i++;
                break;
            }
            break;
        case 2:
            studentOption = 0;
            repeatME = 1;
            cout << "Estudiante: \n";
            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << "." << estudiantes[i].getName() << "\n";
            }
            cin >> studentOption;
            studentOption -= 1;
            do
            {
                int modificarOption;
                cout << "\n-----------\n"
                     << "Modificar: \n"
                     << "1. Nombre\n"
                     << "2. Apellido\n"
                     << "3. Asignatura\n"
                     << "4. Nota 1\n"
                     << "5. Nota 2\n"
                     << "6. Nota 3\n"
                     << "7. Documento\n"
                     << "8. Menú principal\n";
                cin >> modificarOption;
                cout << "-----------\n";
                switch (modificarOption)
                {
                case 1:
                    cout << "Nuevo nombre: ";
                    cin >> nName;
                    estudiantes[studentOption].setName(nName);
                    break;
                case 2:
                    cout << "Nuevo apellido: ";
                    cin >> nSurname;
                    estudiantes[studentOption].setSurname(nSurname);
                    break;
                case 3:
                    cout << "Nueva Materia: ";
                    cin >> nCourse;
                    estudiantes[studentOption].setCourse(nCourse);
                    break;
                case 4:
                    cout << "Nueva nota: ";
                    cin >> nMark1;
                    estudiantes[studentOption].setMark1(nMark1);
                    break;
                case 5:
                    cout << "Nueva nota: ";
                    cin >> nMark2;
                    estudiantes[studentOption].setMark2(nMark2);
                    break;
                case 6:
                    cout << "Nueva nota: ";
                    cin >> nMark3;
                    estudiantes[studentOption].setMark3(nMark3);
                    break;
                case 7:
                    cout << "Nuevo documento: ";
                    cin >> nId;
                    estudiantes[studentOption].setId(nId);
                    break;
                case 8:
                    repeatME = 0;
                    break;
                default:
                    cout << "Ingresaste un valor erroneo";
                    break;
                }
            } while (repeatME == 1);
            break;
        case 3:
            cout << "Mostrar: \n";
            studentOption = 0;
            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << "." << estudiantes[i].getName() << "\n";
            }
            cin >> studentOption;
            studentOption -= 1;
            estudiantes[studentOption].toString();
            break;
        case 4:
            studentOption = 0;
            cout << "Eliminar: \n";
            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << "." << estudiantes[i].getName() << "\n";
            }
            cin >> studentOption;
            studentOption -= 1;
            estudiantes[studentOption] = Students();
            i = studentOption;
            break;
        case 5:
            out = 0;
            break;
        default:
            break;
        }
    } while (out == 1);

    return 0;
}