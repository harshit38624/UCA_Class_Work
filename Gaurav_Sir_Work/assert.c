#include <stdio.h>
#include <assert.h>

int main() {
    assert((10 + 1) == 10);//failed
    assert((10 + 1) == 11);//passed
}