#include <iostream>

int main()
{
    std::cout << std::endl
              << "Task 1" << std::endl;
    // Ищем подходяшую комбинацию переборо
    for (int pens = 0; pens <= 10; ++pens)
    {
        for (int pencils = 0; pencils <= 20; ++pencils)
        {
            for (int erasers = 0; erasers <= 50; ++erasers)
            {
                if (pens * 10 + pencils * 5 + erasers * 2 == 100 && pens + pencils + erasers == 30)
                {
                    std::cout << "Ручки: " << pens << " Карандаши: " << pencils << " Ластики: " << erasers << std::endl;
                }
            }
        }
    }
    return 0;
}
