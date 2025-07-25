#include<stdio.h>

int get_bit(int num, int pos){
    return ((num>>pos)&1);
}

int set_bit(int num, int pos){
    return (num|(1<<pos));
}

int clear_bit(int num, int pos){
    return (num & (~(1<<pos)));
}

int update_bit(int num, int pos, int val){
    num = clear_bit(num, pos);
    return (num | (val << pos));
}

int main() {
    int num = 29;  // Binary: 11101
    int pos = 3;

    printf("Original number: %d\n", num);

    printf("Get Bit at position %d: %d\n", pos, get_bit(num, pos));

    int set = set_bit(num, pos);
    printf("After setting bit %d: %d\n", pos, set);

    int cleared = clear_bit(num, pos);
    printf("After clearing bit %d: %d\n", pos, cleared);

    int updated0 = update_bit(num, pos, 0);
    printf("After updating bit %d to 0: %d\n", pos, updated0);

    int updated1 = update_bit(num, pos, 1);
    printf("After updating bit %d to 1: %d\n", pos, updated1);

    return 0;
}