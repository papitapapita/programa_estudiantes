#include <iostream>

using namespace std;

class Students
{
private:
    string name, course, surname, result;
    float mark;
    int id;

public:
    Students()
    {
        name = course = surname = "";
        mark = id = 0;
    }
    Students(string name, string course, string surname, float mark, int id)
    {
        this->name = name;
        this->surname = surname;
        this->course = course;
        this->mark = mark;
        this->id = id;
    }
    string Aprobacion()
    {
        if (mark >= 3 && mark <= 5)
            return "aprobó";
        else if (mark < 3 && mark > 0)
            return "no aprobó";
        else
            return "nota invalida";
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
    float getMark()
    {
        return mark;
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
    void setSurname(int mark)
    {
        this->mark = mark;
    }
    void setSurname(int id)
    {
        this->id = id;
    }
};

int main()
{
    Students estudiantes[4];
    string nName, nSurname, nCourse, result;
    float nMark;
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
                cout << "Nota: ";
                cin >> nMark;
                estudiantes[i] = Students(nName, nCourse, nSurname, nMark, nId);
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
                     << "4. Nota\n"
                     << "5. Documento\n"
                     << "6. Menú principal\n";
                cin >> modificarOption;
                cout << "-----------\n";
                switch (modificarOption)
                {
                case 1:
                    cout << "Nuevo nombre: ";
                    cin >> estudiantes[studentOption].name;
                    break;
                case 2:
                    cout << "Nuevo apellido: ";
                    cin >> estudiantes[studentOption].surname;
                    break;
                case 3:
                    cout << "Nueva Materia: ";
                    cin >> estudiantes[studentOption].course;
                    break;
                case 4:
                    cout << "Nueva nota: ";
                    cin >> estudiantes[studentOption].mark;
                    break;
                case 5:
                    cout << "Nuevo documento: ";
                    cin >> estudiantes[studentOption].id;
                    break;
                case 6:
                    repeatME = 0;
                    break;
                default:
                    cout << "Ingresaste un valor erroneo";
                    break;
                }
            } while (repeatME == 1);
            break;
        case 3:
            studentOption = 0;
            cout << "Mostrar: \n";
            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << "." << estudiantes[i].getName() << "\n";
            }
            cin >> studentOption;
            studentOption -= 1;
            result = estudiantes[studentOption].Aprobacion();
            cout
                << "Nombre: " << estudiantes[studentOption].getName() << endl
                << "Apellido: " << estudiantes[studentOption].getSurname() << endl
                << "Documento: " << estudiantes[studentOption].getId() << endl
                << "Asignatura: " << estudiantes[studentOption].getCourse() << endl
                << "Nota: " << estudiantes[studentOption].getMark() << endl
                << "Resultados: " << result << endl;
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
            i--;
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