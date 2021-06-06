#ifndef SCENE_HPP
#define SCENE_HPP

#include <Figure.hpp>
#include <Gnuplot.hpp>
#include <vector>
#include <memory>
#include "Vector.hpp"
#include "Drone.hpp"

/*!
 * @file
 * @brief Definicja klasy Scene
 *
 */

/**
 * @brief Klasa modeluje pojęcie wielu brył naraz w przestrzeni 3D
 *
 * Zawiera ona kontener przechopwujący wszystkie bryły
 * oraz elementy niezbędne do wyświetlania operacji w programie gnuplot.
 */
class Scene
        : private PzG::LaczeDoGNUPlota
{
    /**
     * @brief Wektor przechowujący wszystkie figury
     *
     * Może ich od 1 do bardzo dużej ilości ograniczoną pamięcią urządzenia.
     */
    std::vector<std::shared_ptr<Figure>> objects;
    std::vector<std::shared_ptr<Drone>> drones;
    
    double range;
    
    const float frequency;
    
public:
    bool AddNewFile(std::string fileName, PzG::RodzajRysowania drawType = PzG::RR_Ciagly, int width = 2);
    
    
    double Frequency() const { return frequency; }
    
    /*
     * @brief Inicjalizuje scene za pomocą zakresu wartości na osiach.
     */
    Scene(float fr = 60);
    
    void SetRange(double rangee);
    double GetRange() {return range;}
    
    /**
     * @brief Odświeżenie obszaru roboczego programu gnuplot
     */
    void Draw();

    /**
     * @brief Dodanie nowej figury
     */
    void AddObject(const std::shared_ptr<Figure>& object);
    
    /**
     * @brief Dodanie nowego drona
     */
    void AddDrone(const std::shared_ptr<Drone>& drone);

    /**
     * @brief Zwracanie ilości figur w przestrzeni
     *
     * @return Rozmiar wektora, przechowującego wszystkie figury
     */
    [[nodiscard]] std::size_t size() const { return objects.size(); }

    /**
    * \brief Operator dostępowy do figur na scenie
    */
    const Figure& operator[](unsigned int n) const;

    /**
    * \brief Operator dostępowy do figur na scenie
    */
    Figure& operator[](unsigned int n);

    /**
     * @brief Destruktor
     *
     * Usuwa plik "temp.dat" który służy do komunikacji miedzy programem, a gnuplotem.
     */
    ~Scene() override;
    
};

#endif //SCENE_HPP
