#include <stdio.h>
#include <list>

struct Station {
    const char* name;
};

void printStations(const std::list<Station>& stations) {
    for (const auto& station : stations) {
        printf("%s\n", station.name);
    }
    printf("\n");
}
int main() {
    //1970年
    std::list<Station> yamanoteLine1970 = {
        {"Tokyo"}, {"Kanda"}, {"Akihabara"}, {"Okachimachi"}, {"Ueno"},
        {"Uguisudani"}, {"Nippori"}, {"Tabata"}, {"Komagome"}, {"Sugamo"},
        {"Otsuka"}, {"Ikebukuro"}, {"Mejiro"}, {"Takadanobaba"}, {"Shin-Okubo"},
        {"Shinjuku"}, {"Yoyogi"}, {"Harajuku"}, {"Shibuya"}, {"Ebisu"},
        {"Meguro"}, {"Gotanda"}, {"Osaki"}, {"Shinagawa"}, {"Tamachi"},
        {"Hamamatsucho"}, {"Shimbashi"}, {"Yurakucho"}
    };

    printf("1970:\n");
    printStations(yamanoteLine1970);

    //2019年
    std::list<Station> yamanoteLine2019 = yamanoteLine1970;
    auto it = yamanoteLine2019.begin();
    std::advance(it, 7); //西日暮里を追加
    yamanoteLine2019.insert(it, { "Nishi-Nippori" });

    printf("2019:\n");
    printStations(yamanoteLine2019);

    //2022年
    std::list<Station> yamanoteLine2022 = yamanoteLine2019;
    it = yamanoteLine2022.begin();
    std::advance(it, 25); //高輪ゲートウェイを追加
    yamanoteLine2022.insert(it, { "Takanawa Gateway" });

    printf("2022:\n");
    printStations(yamanoteLine2022);

    return 0;
}