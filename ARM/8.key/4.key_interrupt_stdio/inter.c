#include "inter.h"
#include "stdio.h"


void reset_exception(void)
{
	printf("exception_reset.\n");
}

void undef_exception(void)
{
	printf("exception_undef.\n");
}

void sotf_int_exception(void)
{
	printf("exception_sotf_int.\n");
}

void prefetch_exception(void)
{
	printf("exception_prefetch.\n");
}

void data_exception(void)
{
	printf("exception_data.\n");
}

void irq_handler(void)
{
	printf("irq_handler.\n");
}

void fiq_exception(void)
{
	printf("exception_fiq.\n");
}

void system_init_exception(void)
{
	r_exception_reset 		= (unsigned int)reset_exception;
	r_exception_undef 		= (unsigned int)undef_exception;
	r_exception_sotf_int 	= (unsigned int)sotf_int_exception;
	r_exception_prefetch 	= (unsigned int)prefetch_exception;
	r_exception_data 		= (unsigned int)data_exception;
	r_exception_irq 		= (unsigned int)irq_handler;
	r_exception_fiq 		= (unsigned int)fiq_exception;
}





























