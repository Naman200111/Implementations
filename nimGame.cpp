/*
    We are given a heaps of stones each having different stones
    we are asked to find out that if 2 player A&B play optimally (A always goes first)
    who will be the winner
    In one turn a player can remove minimum 1 or all stones from a particular heap

    Just find XOR of stones in all the heaps
    if XOR is not equal to 0 then A wins else B wins
    This XOR is also called nimSum
*/