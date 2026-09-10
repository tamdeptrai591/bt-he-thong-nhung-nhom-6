typedef unsigned int uint32_t;

#define RCC_BASE      0x40021000
#define GPIOA_BASE    0x40010800

#define RCC_APB2ENR   (*(volatile uint32_t *)(RCC_BASE + 0x18))
#define GPIOA_CRL     (*(volatile uint32_t *)(GPIOA_BASE + 0x00)) 
#define GPIOA_IDR     (*(volatile uint32_t *)(GPIOA_BASE + 0x08)) 
#define GPIOA_ODR     (*(volatile uint32_t *)(GPIOA_BASE + 0x0C)) 

void delay(volatile uint32_t count) {
    while(count--) ;
}

int main(void) {
    RCC_APB2ENR |= (1 << 2);

    GPIOA_CRL &= ~(0xF00F); 
    GPIOA_CRL |= (0x2008); 

    GPIOA_ODR |= (1 << 0); 

    while (1) {
        if ((GPIOA_IDR & (1 << 0)) == 0) { 
            delay(20000); 
            if ((GPIOA_IDR & (1 << 0)) == 0) {
                while ((GPIOA_IDR & (1 << 0)) == 0) {
                }
                GPIOA_ODR ^= (1 << 3); 
                delay(20000);
            }
        }
    }
}
