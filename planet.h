class StandardPlanet {
    protected:
        int nextId;
        std::map<int, Citizen> idToName;

    public:
        virtual Citizen& findCitizen(int id);

        virtual Citizen registerCitizen(std::string& name);
};

class Earth : StandardPlanet {};
class Qonos : StandardPlanet {};
