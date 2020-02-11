#include <cstring>
#include "Team.hpp"
#include "Planning.hpp"
#include "utils/console.hpp"

namespace stb {
    Logger log = Logger();
}

static void usage() {
    std::cout << "Usage :" << std::endl;
    std::cout << "\t./automatic_assignations Asteks Planning Availabilities Preferences ToAvoid AssignAllDay" << std::endl;
    std::cout << "\n";
    std::cout << "\t\tAsteks : List of all Asteks" << std::endl;
    std::cout << "\t\tPlanning : List of all activities for a weak" << std::endl;
    std::cout << "\t\tAvailabilities : csv formated file containing Asteks' availabilities" << std::endl;
    std::cout << "\t\tPreferences : List of prefered modules for each Astek" << std::endl;
    std::cout << "\t\tToAvoid : List of module to avoid for each Astek" << std::endl;
    std::cout << "\t\tAssignAllDay : boolean (true or false)" << std::endl;
}

int main(int ac, char **av) {
    if (ac < 7) {
        usage();
        return 84;
    }
    stb::log.displayLevel(stb::Logger::Level::WARNING);

    Team labAstek(av[1]);
    Planning planning(av[2]);
    bool allDay = std::strcmp(av[6], "true") == 0;

    labAstek.assignAllDay(allDay);
    labAstek.fetchAvailabities(av[3]);
    labAstek.fetchPreferences(av[4]);
    labAstek.fetchToAvoid(av[5]);
    labAstek.doTheThing(planning);
    planning.display();
    return 0;
}