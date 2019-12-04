BattleMove::BattleMove(Actor * s, Actor * o) : self(s), other(o)
{
	// empty
}

// Attack One
AttackOne::AttackOne(Actor * s, Actor * o) : BattleMove(s, o), amount(0)
{
    // empty
}

void AttackOne::execute()
{
    int r = 10 + rand()%(6);
    other->hit(r);
    amount = r;
}

void AttackOne::undo()
{
    other->heal(amount);
    amount = 0;
}

// Attack Two
AttackTwo::AttackTwo(Actor * s, Actor * o) : BattleMove(s, o), amount(0)
{
    // empty
}

void AttackTwo::execute()
{
    int r = rand()%(26);
    other->hit(r);
    amount = r;
}

void AttackTwo::undo()
{
    other->heal(amount);
    amount = 0;
}

// Heal
Heal::Heal(Actor * s, Actor * o) : BattleMove(s, o), amount(0)
{
    // empty
}

void Heal::execute()
{
    int r = 10 + rand()%(15-10+1);
    self->heal(r);
    amount = r;
}

void Heal::undo()
{
    self->hit(amount);
    amount = 0;
}