//
// Created by XingfengYang on 2020/5/29.
//

#ifndef NMCS_INSTRUCTION_H
#define NMCS_INSTRUCTION_H

#define u8 unsigned char
#define s16 signed short
#define u16 unsigned short

#define u32 unsigned int
#define s32 signed int

#define u64 unsigned long

typedef struct BPFInstruction{
    u8 opcode;
    u8 destRegister:4;
    u8 sourceRegister:4;
    s16 offset;
    s32 immediate;
} BPFInstruction_t;

enum ALUInstructions{
    // 64 bits
    ADD_IMM_64 = 0x07, // 0x07	add dst, imm	dst += imm
    ADD_REG_64 = 0x0f,// 0x0f	add dst, src	dst += src
    SUB_IMM_64 = 0x17,// 0x17	sub dst, imm	dst -= imm
    SUB_REG_64 = 0x1f,// 0x1f	sub dst, src	dst -= src
    MUL_IMM_64 = 0x27,// 0x27	mul dst, imm	dst *= imm
    MUL_REG_64 = 0x2f,// 0x2f	mul dst, src	dst *= src
    DIV_IMM_64 = 0x37,// 0x37	div dst, imm	dst /= imm
    DIV_REG_64 = 0x3f,// 0x3f	div dst, src	dst /= src
    OR_IMM_64 = 0x47,// 0x47	or dst, imm	dst |= imm
    OR_REG_64 = 0x4f,// 0x4f	or dst, src	dst |= src
    AND_IMM_64 = 0x57,// 0x57	and dst, imm	dst &= imm
    AND_REG_64 = 0x5f,// 0x5f	and dst, src	dst &= src
    LSH_IMM_64 = 0x67,// 0x67	lsh dst, imm	dst <<= imm
    LSH_REG_64 = 0x6f,// 0x6f	lsh dst, src	dst <<= src
    RSH_IMM_64 = 0x77,// 0x77	rsh dst, imm	dst >>= imm (logical)
    RSH_REG_64 = 0x7f,// 0x7f	rsh dst, src	dst >>= src (logical)
    NEG_REG_64 = 0x87,// 0x87	neg dst	dst = -dst
    MOD_IMM_64 = 0x97,// 0x97	mod dst, imm	dst %= imm
    MOD_REG_64 = 0x9f,// 0x9f	mod dst, src	dst %= src
    XOR_IMM_64 = 0xa7,// 0xa7	xor dst, imm	dst ^= imm
    XOR_REG_64 = 0xaf,// 0xaf	xor dst, src	dst ^= src
    MOV_IMM_64 = 0xb7,// 0xb7	mov dst, imm	dst = imm
    MOV_REG_64 = 0xbf,// 0xbf	mov dst, src	dst = src
    ARSH_IMM_64 = 0xc7,// 0xc7	arsh dst, imm	dst >>= imm (arithmetic)
    ARSH_REG_64 = 0xcf,// 0xcf	arsh dst, src	dst >>= src (arithmetic)

    // 32 bits
    ADD_IMM_32 = 0x04,// 0x04	add32 dst, imm	dst += imm
    ADD_REG_32 = 0x0c,// 0x0c	add32 dst, src	dst += src
    SUB_IMM_32 = 0x14,// 0x14	sub32 dst, imm	dst -= imm
    SUB_REG_32 = 0x1c,// 0x1c	sub32 dst, src	dst -= src
    MUL_IMM_32 = 0x24,// 0x24	mul32 dst, imm	dst *= imm
    MUL_REG_32 = 0x2c,// 0x2c	mul32 dst, src	dst *= src
    DIV_IMM_32 = 0x34,// 0x34	div32 dst, imm	dst /= imm
    DIV_REG_32 = 0x3c,// 0x3c	div32 dst, src	dst /= src
    OR_IMM_32 = 0x44,// 0x44	or32 dst, imm	dst |= imm
    OR_REG_32 = 0x4c,// 0x4c	or32 dst, src	dst |= src
    AND_IMM_32 = 0x54,// 0x54	and32 dst, imm	dst &= imm
    AND_REG_32 = 0x5c,// 0x5c	and32 dst, src	dst &= src
    LSH_IMM_32 = 0x64,// 0x64	lsh32 dst, imm	dst <<= imm
    LSH_REG_32 = 0x6c,// 0x6c	lsh32 dst, src	dst <<= src
    RSH_IMM_32 = 0x74,// 0x74	rsh32 dst, imm	dst >>= imm (logical)
    RSH_REG_32 = 0x7c,// 0x7c	rsh32 dst, src	dst >>= src (logical)
    NEG_REG_32 = 0x84,// 0x84	neg32 dst	dst = -dst
    MOD_IMM_32 = 0x94,// 0x94	mod32 dst, imm	dst %= imm
    MOD_REG_32 = 0x9c,// 0x9c	mod32 dst, src	dst %= src
    XOR_IMM_32 = 0xa4,// 0xa4	xor32 dst, imm	dst ^= imm
    XOR_REG_32 = 0xac,// 0xac	xor32 dst, src	dst ^= src
    MOV_IMM_32 = 0xb4,// 0xb4	mov32 dst, imm	dst = imm
    MOV_REG_32 = 0xbc,// 0xbc	mov32 dst, src	dst = src
    ARSH_IMM_32 = 0xc4,// 0xc4	arsh32 dst, imm	dst >>= imm (arithmetic)
    ARSH_REG_32 = 0xcc,// 0xcc	arsh32 dst, src	dst >>= src (arithmetic)

    // Byteswap instructions
    LE_REG = 0xd4,// 0xd4 (imm == 16)	le16 dst	dst = htole16(dst)
                  // 0xd4 (imm == 32)	le32 dst	dst = htole32(dst)
                  // 0xd4 (imm == 64)	le64 dst	dst = htole64(dst)
    BE_REG = 0xdc,// 0xdc (imm == 16)	be16 dst	dst = htobe16(dst)
                  // 0xdc (imm == 32)	be32 dst	dst = htobe32(dst)
                  // 0xdc (imm == 64)	be64 dst	dst = htobe64(dst)

    // Memory Instructions
    LDDW = 0x18,// 0x18	lddw dst, imm	dst = imm
    LDABSW = 0x20,// 0x20	ldabsw src, dst, imm	See kernel documentation
    LDABSH = 0x28,// 0x28	ldabsh src, dst, imm	...
    LDABSB = 0x30,// 0x30	ldabsb src, dst, imm	...
    LDABSDW = 0x38,// 0x38	ldabsdw src, dst, imm	...
    LDINDW = 0x40,// 0x40	ldindw src, dst, imm	...
    LDINDH = 0x48,// 0x48	ldindh src, dst, imm	...
    LDINDB = 0x50,// 0x50	ldindb src, dst, imm	...
    LDINDDW = 0x58,// 0x58	ldinddw src, dst, imm	...
    LDXW = 0x61,// 0x61	ldxw dst, [src+off]	dst = *(uint32_t *) (src + off)
    LDXH = 0x69,// 0x69	ldxh dst, [src+off]	dst = *(uint16_t *) (src + off)
    LDXB = 0x71,// 0x71	ldxb dst, [src+off]	dst = *(uint8_t *) (src + off)
    LDXDW = 0x79,// 0x79	ldxdw dst, [src+off]	dst = *(uint64_t *) (src + off)
    STW = 0x62,// 0x62	stw [dst+off], imm	*(uint32_t *) (dst + off) = imm
    STH = 0x6a,// 0x6a	sth [dst+off], imm	*(uint16_t *) (dst + off) = imm
    STB = 0x72,// 0x72	stb [dst+off], imm	*(uint8_t *) (dst + off) = imm
    STDW = 0x7a,// 0x7a	stdw [dst+off], imm	*(uint64_t *) (dst + off) = imm
    STXW = 0x63,// 0x63	stxw [dst+off], src	*(uint32_t *) (dst + off) = src
    STXH = 0x6b,// 0x6b	stxh [dst+off], src	*(uint16_t *) (dst + off) = src
    STXB = 0x73,// 0x73	stxb [dst+off], src	*(uint8_t *) (dst + off) = src
    STXDW = 0x7b,// 0x7b	stxdw [dst+off], src	*(uint64_t *) (dst + off) = src

    // Branch Instructions
    JA = 0x05,// 0x05	ja +off	PC += off
    JEQ_IMM = 0x15,// 0x15	jeq dst, imm, +off	PC += off if dst == imm
    JEQ_REG = 0x1d,// 0x1d	jeq dst, src, +off	PC += off if dst == src
    JGT_IMM = 0x25,// 0x25	jgt dst, imm, +off	PC += off if dst > imm
    JGT_REG = 0x2d,// 0x2d	jgt dst, src, +off	PC += off if dst > src
    JGE_IMM = 0x35,// 0x35	jge dst, imm, +off	PC += off if dst >= imm
    JGE_REG = 0x3d,// 0x3d	jge dst, src, +off	PC += off if dst >= src
    JLT_IMM = 0xa5,// 0xa5	jlt dst, imm, +off	PC += off if dst < imm
    JLT_REG = 0xad,// 0xad	jlt dst, src, +off	PC += off if dst < src
    JLE_IMM = 0xb5,// 0xb5	jle dst, imm, +off	PC += off if dst <= imm
    JLE_REG = 0xbd,// 0xbd	jle dst, src, +off	PC += off if dst <= src
    JSET_IMM = 0x45,// 0x45	jset dst, imm, +off	PC += off if dst & imm
    JSET_REG = 0x4d,// 0x4d	jset dst, src, +off	PC += off if dst & src
    JNE_IMM = 0x55,// 0x55	jne dst, imm, +off	PC += off if dst != imm
    JNE_REG = 0x5d,// 0x5d	jne dst, src, +off	PC += off if dst != src
    JSGT_IMM = 0x65,// 0x65	jsgt dst, imm, +off	PC += off if dst > imm (signed)
    JSGT_REG = 0x6d,// 0x6d	jsgt dst, src, +off	PC += off if dst > src (signed)
    JSGE_IMM = 0x75,// 0x75	jsge dst, imm, +off	PC += off if dst >= imm (signed)
    JSGE_REG = 0x7d,// 0x7d	jsge dst, src, +off	PC += off if dst >= src (signed)
    JSLT_IMM = 0xc5,// 0xc5	jslt dst, imm, +off	PC += off if dst < imm (signed)
    JSLT_REG = 0xcd,// 0xcd	jslt dst, src, +off	PC += off if dst < src (signed)
    JSLE_IMM = 0xd5,// 0xd5	jsle dst, imm, +off	PC += off if dst <= imm (signed)
    JSLE_REG = 0xdd,// 0xdd	jsle dst, src, +off	PC += off if dst <= src (signed)
    CALL_IMM = 0x85,// 0x85	call imm	Function call
    EXIT = 0x95,// 0x95	exit	return r0
};



typedef struct VM{
    u64 *memory;
    u64 regs[10];
    BPFInstruction_t currentInstruction;
    u64 currentCode;
    u32 pc;
    u32 sp;
    void(*handlers[0xFF])(BPFInstruction_t instruction);
} VM_t;

/**
 * init the vm and it's memory space
 **/
void vm_init(u32 memorySize);


/**
 * verify code
 **/
bool vm_verify_code(u64 code);


/**
 * load program (u64 vector)
 **/
void vm_load_program(u64 *program);


/**
 * fetch code from memory[pc]
 **/
u64 vm_fetch_code(u32 pc);

/**
 * decode the innstruction from u64 code
 **/
BPFInstruction_t vm_decode_code(u64 code);

/**
 * execute the current instruction
 **/
void vm_execute();

/**
 * run the vm
 **/
void vm_run();

/**
 * print the instruction 
 **/
void vm_print_instruction(BPFInstruction_t instruction);


#endif //NMCS_INSTRUCTION_H
