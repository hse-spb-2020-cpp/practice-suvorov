// Один из вариантов.

// Терминологическая путаница:
// Термин из С++ (строгий): abstract class - есть хотя бы одна чисто виртуальная функция.
// Термин из ООП (рухомахательный про проектирование):
//     abstract base class (ABC): нет данных, нет реализаций методов, всё чисто виртуальное.
struct GameObject {
    // TODO: запретить копирования и перемещения
    virtual ~GameObject() {}

    virtual int x() = 0;
    virtual int y() = 0;
    virtual void draw() = 0;
};

struct DestroyableGameObject : virtual GameObject {  // ABC
    virtual int health_points() = 0;
    virtual void damage(int points) = 0;
};

struct GameObjectWithInventory : virtual GameObject {  // ABC
    virtual int total_weight() = 0;
    // TODO: добавить чтение vector<> с инвентарём.
};

struct Player : DestroyableGameObject, GameObjectWithInventory {
};

struct Enemy : DestroyableGameObject {
};

struct Chest : DestroyableGameObject, GameObjectWithInventory {
};

struct Wall : GameObject {
};

//vector<std::unique_ptr<GameObject>> objects;

int main() {
    Player *p = nullptr;
    GameObject *o = p;
}
