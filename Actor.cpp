Actor::Actor(int health, std::string type) : health(health), type(type) {}

Actor::Actor(const Actor & actor) : health(actor.health), type(actor.type), moves(actor.moves){}

Actor & Actor::operator= (const Actor & actor) {
    health = actor.health;
    type = actor.type;
    moves = actor.moves;

    return *this;
}

void Actor::Hit(int damage) {
    std::cout << (*this) << " is Hit with " << damage << " damage.\n";
    health -= damage;
}

std::string Actor::GetType() const {
    return type;
}

void Actor::Heal(int amount) {
    std::cout << (*this) << " is healed by " << amount << "hp.\n";
    health += amount;
}

const std::vector<MoveType> & Actor::GetMoves() const {
    return moves;
}

bool Actor::IsDead() const {
    return health <= 0;
}

void Actor::doMove(MoveManager & mgr, const MoveType & moveType, Actor * other )  {
    std::cout << type << " ,(" << health << ") used " << MoveTypeStrings[(int)moveType] << '\n'; 
    mgr.ExecuteMove(MoveFactory::BuildMove(moveType, this, other));
}

std::ostream & operator<< (std::ostream & out, const Actor & actor) {
    out << actor.type << ", (" << std::to_string(actor.health) << ")";
    return out;
}