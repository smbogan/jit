#ifndef __JIT_INSTRUCTION_H__
#define __JIT_INSTRUCTION_H__

typedef enum
{
	push,
	mov,
	sub,
	call,
	ret,
	add
} op;

typedef enum
{
	none,

	//8-byte
	rax,
	rcx,
	rdx,
	rbx,
	rsi,
	rdi,
	rsp,
	rbp,
	r8,
	r9,
	r10,
	r11,
	r12,
	r13,
	r14,
	r15,

	//bytes 5 to 8
	eax,
	ecx,
	edx,
	ebx,
	esi,
	edi,
	esp,
	ebp,
	r8d,
	r9d,
	r10d,
	r11d,
	r12d,
	r13d,
	r14d,
	r15d,

	//bytes 7 to 8
	ax,
	cx,
	dx,
	bx,
	si,
	di,
	sp,
	bp,
	r8w,
	r9w,
	r10w,
	r11w,
	r12w,
	r13w,
	r14w,
	r15w,

	//byte 8
	al,
	cl,
	dl,
	bl,
	sil,
	dil,
	spl,
	bpl,
	r8b,
	r9b,
	r10b,
	r11b,
	r12b,
	r13b,
	r14b,
	r15b
} reg;

typedef struct 
{
	op operation;
	reg register1;
	reg register2;
} instruction;



#endif