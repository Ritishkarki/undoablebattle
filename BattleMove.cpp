// BattleMove constructor
BattleMove::BattleMove(Actor * self, Actor * other) : self(self), other(other){}

// Attack One constructor
AttackOne::AttackOne(Actor * self, Actor * other) : BattleMove(self, other), amount(0){}

void AttackOne::execute() {
    // random number between 10 and 15
    int randomAmount = 10 + rand()%(5);
    other->Hit(randomAmount);
    amount = randomAmount;
}

void AttackOne::undo() {
    other->Heal(amount);
    amount = 0;
}

// Attack Two constructor
AttackTwo::AttackTwo(Actor * self, Actor * other) : BattleMove(self, other), amount(0){}

void AttackTwo::execute() {
    // random number between 0 and 25
    int randomAmount = rand()%(25);
    other->Hit(randomAmount);
    amount = randomAmount;
}

void AttackTwo::undo() {
    other->Heal(amount);
    amount = 0;
}

// Heal constructor
Heal::Heal(Actor * self, Actor * other) : BattleMove(self, other), amount(0){}

void Heal::execute() {
    // random number between 10 and 15
    int randomAmount = 10 + rand()%(5);
    self->Heal(randomAmount);
    amount = randomAmount;
}

void Heal::undo() {
    self->Hit(amount);
    amount = 0;
}