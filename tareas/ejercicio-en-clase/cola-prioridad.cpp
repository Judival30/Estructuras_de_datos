#include "cola-prioridad.h"

#include <algorithm>

Cola::Cola()
{
}

Elemento Cola::front()
{
    auto it = l.begin();
    Elemento ans = *it;
    return ans;
}
bool mayorQue(int a, int b)
{
    return a > b;
}
void Cola::enqueue(Elemento e)
{
    l.push_back(e);
    l.sort(mayorQue);
}

void Cola::deque()
{
    l.pop_front();
}

bool Cola::vaciaCola()
{
    bool ans;
    if (l.empty())
        ans = true;
    else
        ans = false;
    return ans;
}