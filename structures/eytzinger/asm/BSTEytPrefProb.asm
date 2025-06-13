
bst-bench:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000018ab0 <BSTEytPrefProb<int, 8ul>::contains(int const&) const>:
BSTEytPrefProb<int, 8ul>::contains(int const&) const:
   18ab0:	f3 0f 1e fa          	endbr64
   18ab4:	55                   	push   rbp
   18ab5:	48 89 e5             	mov    rbp,rsp
   18ab8:	41 57                	push   r15
   18aba:	41 56                	push   r14
   18abc:	41 55                	push   r13
   18abe:	49 89 f5             	mov    r13,rsi
   18ac1:	41 54                	push   r12
   18ac3:	41 52                	push   r10
   18ac5:	53                   	push   rbx
   18ac6:	48 89 fb             	mov    rbx,rdi
   18ac9:	48 83 ec 50          	sub    rsp,0x50
   18acd:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   18ad4:	00 00 
   18ad6:	48 89 45 c8          	mov    QWORD PTR [rbp-0x38],rax
   18ada:	31 c0                	xor    eax,eax
   18adc:	80 7f 38 00          	cmp    BYTE PTR [rdi+0x38],0x0
   18ae0:	75 05                	jne    18ae7 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x37>
   18ae2:	e8 19 0d ff ff       	call   9800 <BSTEyt<int>::freeze() [clone .part.0]>
   18ae7:	4c 8b 7b 10          	mov    r15,QWORD PTR [rbx+0x10]
   18aeb:	4c 8b 63 08          	mov    r12,QWORD PTR [rbx+0x8]
   18aef:	4d 39 e7             	cmp    r15,r12
   18af2:	74 64                	je     18b58 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0xa8>
   18af4:	80 7b 39 00          	cmp    BYTE PTR [rbx+0x39],0x0
   18af8:	0f 84 62 03 00 00    	je     18e60 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x3b0>
   18afe:	8b 43 40             	mov    eax,DWORD PTR [rbx+0x40]
   18b01:	8b 4b 3c             	mov    ecx,DWORD PTR [rbx+0x3c]
   18b04:	39 c1                	cmp    ecx,eax
   18b06:	0f 84 d4 02 00 00    	je     18de0 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x330>
   18b0c:	41 8b 55 00          	mov    edx,DWORD PTR [r13+0x0]
   18b10:	c5 f8 57 c0          	vxorps xmm0,xmm0,xmm0
   18b14:	29 c8                	sub    eax,ecx
   18b16:	29 ca                	sub    edx,ecx
   18b18:	c5 fb 2a ca          	vcvtsi2sd xmm1,xmm0,edx
   18b1c:	c5 fb 2a c0          	vcvtsi2sd xmm0,xmm0,eax
   18b20:	c5 f3 5e c8          	vdivsd xmm1,xmm1,xmm0
   18b24:	c5 f9 57 c0          	vxorpd xmm0,xmm0,xmm0
   18b28:	c5 f9 2f c1          	vcomisd xmm0,xmm1
   18b2c:	76 52                	jbe    18b80 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0xd0>
   18b2e:	c5 fb 10 05 62 33 00 	vmovsd xmm0,QWORD PTR [rip+0x3362]        # 1be98 <typeinfo name for variants::{lambda()#7}+0x198>
   18b35:	00 
   18b36:	c5 f1 57 c9          	vxorpd xmm1,xmm1,xmm1
   18b3a:	4d 29 e7             	sub    r15,r12
   18b3d:	4c 89 fb             	mov    rbx,r15
   18b40:	48 c1 fb 02          	sar    rbx,0x2
   18b44:	49 83 ff 04          	cmp    r15,0x4
   18b48:	77 52                	ja     18b9c <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0xec>
   18b4a:	48 85 db             	test   rbx,rbx
   18b4d:	0f 85 b8 01 00 00    	jne    18d0b <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x25b>
   18b53:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   18b58:	31 c0                	xor    eax,eax
   18b5a:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
   18b5e:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
   18b65:	00 00 
   18b67:	0f 85 b1 03 00 00    	jne    18f1e <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x46e>
   18b6d:	48 83 c4 50          	add    rsp,0x50
   18b71:	5b                   	pop    rbx
   18b72:	41 5a                	pop    r10
   18b74:	41 5c                	pop    r12
   18b76:	41 5d                	pop    r13
   18b78:	41 5e                	pop    r14
   18b7a:	41 5f                	pop    r15
   18b7c:	5d                   	pop    rbp
   18b7d:	c3                   	ret
   18b7e:	66 90                	xchg   ax,ax
   18b80:	c5 fb 10 05 10 33 00 	vmovsd xmm0,QWORD PTR [rip+0x3310]        # 1be98 <typeinfo name for variants::{lambda()#7}+0x198>
   18b87:	00 
   18b88:	4d 29 e7             	sub    r15,r12
   18b8b:	4c 89 fb             	mov    rbx,r15
   18b8e:	c5 fb 5d c9          	vminsd xmm1,xmm0,xmm1
   18b92:	48 c1 fb 02          	sar    rbx,0x2
   18b96:	49 83 ff 04          	cmp    r15,0x4
   18b9a:	76 ae                	jbe    18b4a <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x9a>
   18b9c:	41 0f 18 5c 24 04    	prefetcht2 BYTE PTR [r12+0x4]
   18ba2:	49 83 ff 08          	cmp    r15,0x8
   18ba6:	0f 86 2c 03 00 00    	jbe    18ed8 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x428>
   18bac:	c5 fb 10 15 f4 32 00 	vmovsd xmm2,QWORD PTR [rip+0x32f4]        # 1bea8 <typeinfo name for variants::{lambda()#7}+0x1a8>
   18bb3:	00 
   18bb4:	41 be 06 00 00 00    	mov    r14d,0x6
   18bba:	41 0f 18 5c 24 08    	prefetcht2 BYTE PTR [r12+0x8]
   18bc0:	c5 fb 5c c1          	vsubsd xmm0,xmm0,xmm1
   18bc4:	c5 fb 59 c2          	vmulsd xmm0,xmm0,xmm2
   18bc8:	e8 73 a8 fe ff       	call   3440 <round@plt>
   18bcd:	c5 fb 10 0d e3 32 00 	vmovsd xmm1,QWORD PTR [rip+0x32e3]        # 1beb8 <typeinfo name for variants::{lambda()#7}+0x1b8>
   18bd4:	00 
   18bd5:	c5 f9 2f c1          	vcomisd xmm0,xmm1
   18bd9:	0f 83 19 02 00 00    	jae    18df8 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x348>
   18bdf:	c4 e1 fb 2c c0       	vcvttsd2si rax,xmm0
   18be4:	31 f6                	xor    esi,esi
   18be6:	49 39 c6             	cmp    r14,rax
   18be9:	0f 83 22 02 00 00    	jae    18e11 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x361>
   18bef:	48 c7 45 80 01 00 00 	mov    QWORD PTR [rbp-0x80],0x1
   18bf6:	00 
   18bf7:	c5 f9 ef c0          	vpxor  xmm0,xmm0,xmm0
   18bfb:	41 b9 01 00 00 00    	mov    r9d,0x1
   18c01:	31 c9                	xor    ecx,ecx
   18c03:	c5 fe 7f 45 88       	vmovdqu YMMWORD PTR [rbp-0x78],ymm0
   18c08:	48 8d 7d 80          	lea    rdi,[rbp-0x80]
   18c0c:	c5 fe 7f 45 a0       	vmovdqu YMMWORD PTR [rbp-0x60],ymm0
   18c11:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   18c18:	48 8b 14 cf          	mov    rdx,QWORD PTR [rdi+rcx*8]
   18c1c:	48 8d 04 12          	lea    rax,[rdx+rdx*1]
   18c20:	48 ff c2             	inc    rdx
   18c23:	4c 8d 40 01          	lea    r8,[rax+0x1]
   18c27:	48 83 c0 02          	add    rax,0x2
   18c2b:	49 39 d8             	cmp    r8,rbx
   18c2e:	0f 83 2c 01 00 00    	jae    18d60 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x2b0>
   18c34:	4d 89 f2             	mov    r10,r14
   18c37:	43 0f 18 1c 84       	prefetcht2 BYTE PTR [r12+r8*4]
   18c3c:	49 ff ca             	dec    r10
   18c3f:	0f 85 5b 01 00 00    	jne    18da0 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x2f0>
   18c45:	48 85 f6             	test   rsi,rsi
   18c48:	0f 84 ba 00 00 00    	je     18d08 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x258>
   18c4e:	49 83 ff 08          	cmp    r15,0x8
   18c52:	0f 86 b0 00 00 00    	jbe    18d08 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x258>
   18c58:	48 c7 45 80 02 00 00 	mov    QWORD PTR [rbp-0x80],0x2
   18c5f:	00 
   18c60:	c5 f9 ef c0          	vpxor  xmm0,xmm0,xmm0
   18c64:	41 b9 01 00 00 00    	mov    r9d,0x1
   18c6a:	31 c9                	xor    ecx,ecx
   18c6c:	c5 fe 7f 45 88       	vmovdqu YMMWORD PTR [rbp-0x78],ymm0
   18c71:	c5 fe 7f 45 a0       	vmovdqu YMMWORD PTR [rbp-0x60],ymm0
   18c76:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   18c7d:	00 00 00 
   18c80:	48 8b 14 cf          	mov    rdx,QWORD PTR [rdi+rcx*8]
   18c84:	48 8d 04 12          	lea    rax,[rdx+rdx*1]
   18c88:	48 ff c2             	inc    rdx
   18c8b:	4c 8d 40 01          	lea    r8,[rax+0x1]
   18c8f:	48 83 c0 02          	add    rax,0x2
   18c93:	49 39 d8             	cmp    r8,rbx
   18c96:	73 28                	jae    18cc0 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x210>
   18c98:	49 89 f2             	mov    r10,rsi
   18c9b:	43 0f 18 1c 84       	prefetcht2 BYTE PTR [r12+r8*4]
   18ca0:	49 ff ca             	dec    r10
   18ca3:	74 63                	je     18d08 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x258>
   18ca5:	49 83 f9 07          	cmp    r9,0x7
   18ca9:	77 45                	ja     18cf0 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x240>
   18cab:	4d 8d 59 01          	lea    r11,[r9+0x1]
   18caf:	4e 89 44 cd 80       	mov    QWORD PTR [rbp+r9*8-0x80],r8
   18cb4:	4c 89 d6             	mov    rsi,r10
   18cb7:	4d 89 d9             	mov    r9,r11
   18cba:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   18cc0:	48 39 d8             	cmp    rax,rbx
   18cc3:	73 1b                	jae    18ce0 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x230>
   18cc5:	41 0f 18 1c d4       	prefetcht2 BYTE PTR [r12+rdx*8]
   18cca:	48 ff ce             	dec    rsi
   18ccd:	74 39                	je     18d08 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x258>
   18ccf:	49 83 f9 07          	cmp    r9,0x7
   18cd3:	77 0b                	ja     18ce0 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x230>
   18cd5:	4a 89 44 cd 80       	mov    QWORD PTR [rbp+r9*8-0x80],rax
   18cda:	49 ff c1             	inc    r9
   18cdd:	0f 1f 00             	nop    DWORD PTR [rax]
   18ce0:	48 ff c1             	inc    rcx
   18ce3:	4c 39 c9             	cmp    rcx,r9
   18ce6:	72 98                	jb     18c80 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x1d0>
   18ce8:	c5 f8 77             	vzeroupper
   18ceb:	e9 5a fe ff ff       	jmp    18b4a <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x9a>
   18cf0:	48 39 d8             	cmp    rax,rbx
   18cf3:	0f 83 37 01 00 00    	jae    18e30 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x380>
   18cf9:	41 0f 18 1c d4       	prefetcht2 BYTE PTR [r12+rdx*8]
   18cfe:	48 83 ee 02          	sub    rsi,0x2
   18d02:	75 dc                	jne    18ce0 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x230>
   18d04:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   18d08:	c5 f8 77             	vzeroupper
   18d0b:	41 8b 55 00          	mov    edx,DWORD PTR [r13+0x0]
   18d0f:	31 c0                	xor    eax,eax
   18d11:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   18d18:	41 3b 14 84          	cmp    edx,DWORD PTR [r12+rax*4]
   18d1c:	74 16                	je     18d34 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x284>
   18d1e:	7d 20                	jge    18d40 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x290>
   18d20:	48 8d 44 00 01       	lea    rax,[rax+rax*1+0x1]
   18d25:	48 39 d8             	cmp    rax,rbx
   18d28:	0f 83 2a fe ff ff    	jae    18b58 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0xa8>
   18d2e:	41 3b 14 84          	cmp    edx,DWORD PTR [r12+rax*4]
   18d32:	75 ea                	jne    18d1e <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x26e>
   18d34:	b8 01 00 00 00       	mov    eax,0x1
   18d39:	e9 1c fe ff ff       	jmp    18b5a <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0xaa>
   18d3e:	66 90                	xchg   ax,ax
   18d40:	48 8d 44 00 02       	lea    rax,[rax+rax*1+0x2]
   18d45:	48 39 d8             	cmp    rax,rbx
   18d48:	72 ce                	jb     18d18 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x268>
   18d4a:	e9 09 fe ff ff       	jmp    18b58 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0xa8>
   18d4f:	90                   	nop
   18d50:	4d 8d 59 01          	lea    r11,[r9+0x1]
   18d54:	4e 89 44 cd 80       	mov    QWORD PTR [rbp+r9*8-0x80],r8
   18d59:	4d 89 d6             	mov    r14,r10
   18d5c:	4d 89 d9             	mov    r9,r11
   18d5f:	90                   	nop
   18d60:	48 39 d8             	cmp    rax,rbx
   18d63:	73 1b                	jae    18d80 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x2d0>
   18d65:	41 0f 18 1c d4       	prefetcht2 BYTE PTR [r12+rdx*8]
   18d6a:	49 ff ce             	dec    r14
   18d6d:	74 4b                	je     18dba <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x30a>
   18d6f:	49 83 f9 07          	cmp    r9,0x7
   18d73:	77 0b                	ja     18d80 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x2d0>
   18d75:	4a 89 44 cd 80       	mov    QWORD PTR [rbp+r9*8-0x80],rax
   18d7a:	49 ff c1             	inc    r9
   18d7d:	0f 1f 00             	nop    DWORD PTR [rax]
   18d80:	48 ff c1             	inc    rcx
   18d83:	4c 39 c9             	cmp    rcx,r9
   18d86:	0f 82 8c fe ff ff    	jb     18c18 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x168>
   18d8c:	48 85 f6             	test   rsi,rsi
   18d8f:	75 32                	jne    18dc3 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x313>
   18d91:	e9 52 ff ff ff       	jmp    18ce8 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x238>
   18d96:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   18d9d:	00 00 00 
   18da0:	49 83 f9 07          	cmp    r9,0x7
   18da4:	76 aa                	jbe    18d50 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x2a0>
   18da6:	48 39 d8             	cmp    rax,rbx
   18da9:	0f 83 99 00 00 00    	jae    18e48 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x398>
   18daf:	41 0f 18 1c d4       	prefetcht2 BYTE PTR [r12+rdx*8]
   18db4:	49 83 ee 02          	sub    r14,0x2
   18db8:	75 c6                	jne    18d80 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x2d0>
   18dba:	48 85 f6             	test   rsi,rsi
   18dbd:	0f 84 45 ff ff ff    	je     18d08 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x258>
   18dc3:	49 83 ff 08          	cmp    r15,0x8
   18dc7:	0f 86 1b ff ff ff    	jbe    18ce8 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x238>
   18dcd:	48 8d 7d 80          	lea    rdi,[rbp-0x80]
   18dd1:	e9 82 fe ff ff       	jmp    18c58 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x1a8>
   18dd6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   18ddd:	00 00 00 
   18de0:	c5 fb 10 0d b8 30 00 	vmovsd xmm1,QWORD PTR [rip+0x30b8]        # 1bea0 <typeinfo name for variants::{lambda()#7}+0x1a0>
   18de7:	00 
   18de8:	c5 fb 10 05 a8 30 00 	vmovsd xmm0,QWORD PTR [rip+0x30a8]        # 1be98 <typeinfo name for variants::{lambda()#7}+0x198>
   18def:	00 
   18df0:	e9 45 fd ff ff       	jmp    18b3a <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x8a>
   18df5:	0f 1f 00             	nop    DWORD PTR [rax]
   18df8:	c5 fb 5c c1          	vsubsd xmm0,xmm0,xmm1
   18dfc:	31 f6                	xor    esi,esi
   18dfe:	c4 e1 fb 2c c0       	vcvttsd2si rax,xmm0
   18e03:	48 0f ba f8 3f       	btc    rax,0x3f
   18e08:	49 39 c6             	cmp    r14,rax
   18e0b:	0f 82 de fd ff ff    	jb     18bef <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x13f>
   18e11:	4c 89 f6             	mov    rsi,r14
   18e14:	48 85 c0             	test   rax,rax
   18e17:	74 aa                	je     18dc3 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x313>
   18e19:	4c 89 f6             	mov    rsi,r14
   18e1c:	49 89 c6             	mov    r14,rax
   18e1f:	48 29 c6             	sub    rsi,rax
   18e22:	e9 c8 fd ff ff       	jmp    18bef <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x13f>
   18e27:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   18e2e:	00 00 
   18e30:	48 ff c1             	inc    rcx
   18e33:	4c 89 d6             	mov    rsi,r10
   18e36:	4c 39 c9             	cmp    rcx,r9
   18e39:	0f 82 41 fe ff ff    	jb     18c80 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x1d0>
   18e3f:	e9 a4 fe ff ff       	jmp    18ce8 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x238>
   18e44:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   18e48:	48 ff c1             	inc    rcx
   18e4b:	4d 89 d6             	mov    r14,r10
   18e4e:	4c 39 c9             	cmp    rcx,r9
   18e51:	0f 82 c1 fd ff ff    	jb     18c18 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x168>
   18e57:	e9 30 ff ff ff       	jmp    18d8c <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x2dc>
   18e5c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   18e60:	49 8d 74 24 04       	lea    rsi,[r12+0x4]
   18e65:	41 8b 0c 24          	mov    ecx,DWORD PTR [r12]
   18e69:	49 39 f7             	cmp    r15,rsi
   18e6c:	0f 84 86 00 00 00    	je     18ef8 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x448>
   18e72:	45 8b 4c 24 04       	mov    r9d,DWORD PTR [r12+0x4]
   18e77:	41 39 c9             	cmp    r9d,ecx
   18e7a:	7c 6f                	jl     18eeb <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x43b>
   18e7c:	49 8d 44 24 08       	lea    rax,[r12+0x8]
   18e81:	49 39 c7             	cmp    r15,rax
   18e84:	74 75                	je     18efb <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x44b>
   18e86:	49 8d 54 24 0c       	lea    rdx,[r12+0xc]
   18e8b:	4c 39 fa             	cmp    rdx,r15
   18e8e:	75 29                	jne    18eb9 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x409>
   18e90:	eb 7a                	jmp    18f0c <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x45c>
   18e92:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   18e98:	39 f9                	cmp    ecx,edi
   18e9a:	0f 4f cf             	cmovg  ecx,edi
   18e9d:	45 39 c8             	cmp    r8d,r9d
   18ea0:	48 0f 4d f0          	cmovge rsi,rax
   18ea4:	48 83 c0 08          	add    rax,0x8
   18ea8:	49 39 c7             	cmp    r15,rax
   18eab:	74 4e                	je     18efb <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x44b>
   18ead:	48 83 c2 08          	add    rdx,0x8
   18eb1:	49 39 d7             	cmp    r15,rdx
   18eb4:	74 56                	je     18f0c <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x45c>
   18eb6:	44 8b 0e             	mov    r9d,DWORD PTR [rsi]
   18eb9:	8b 3a                	mov    edi,DWORD PTR [rdx]
   18ebb:	44 8b 00             	mov    r8d,DWORD PTR [rax]
   18ebe:	44 39 c7             	cmp    edi,r8d
   18ec1:	7c d5                	jl     18e98 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x3e8>
   18ec3:	44 39 c1             	cmp    ecx,r8d
   18ec6:	41 0f 4f c8          	cmovg  ecx,r8d
   18eca:	44 39 cf             	cmp    edi,r9d
   18ecd:	48 0f 4d f2          	cmovge rsi,rdx
   18ed1:	eb d1                	jmp    18ea4 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x3f4>
   18ed3:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   18ed8:	c5 fb 10 15 d0 2f 00 	vmovsd xmm2,QWORD PTR [rip+0x2fd0]        # 1beb0 <typeinfo name for variants::{lambda()#7}+0x1b0>
   18edf:	00 
   18ee0:	41 be 07 00 00 00    	mov    r14d,0x7
   18ee6:	e9 d5 fc ff ff       	jmp    18bc0 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x110>
   18eeb:	89 c8                	mov    eax,ecx
   18eed:	4c 89 e6             	mov    rsi,r12
   18ef0:	44 89 c9             	mov    ecx,r9d
   18ef3:	41 89 c1             	mov    r9d,eax
   18ef6:	eb 84                	jmp    18e7c <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x3cc>
   18ef8:	4c 89 e6             	mov    rsi,r12
   18efb:	89 4b 3c             	mov    DWORD PTR [rbx+0x3c],ecx
   18efe:	8b 06                	mov    eax,DWORD PTR [rsi]
   18f00:	c6 43 39 01          	mov    BYTE PTR [rbx+0x39],0x1
   18f04:	89 43 40             	mov    DWORD PTR [rbx+0x40],eax
   18f07:	e9 f8 fb ff ff       	jmp    18b04 <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x54>
   18f0c:	8b 10                	mov    edx,DWORD PTR [rax]
   18f0e:	39 ca                	cmp    edx,ecx
   18f10:	7c 08                	jl     18f1a <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x46a>
   18f12:	3b 16                	cmp    edx,DWORD PTR [rsi]
   18f14:	48 0f 4d f0          	cmovge rsi,rax
   18f18:	eb e1                	jmp    18efb <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x44b>
   18f1a:	89 d1                	mov    ecx,edx
   18f1c:	eb dd                	jmp    18efb <BSTEytPrefProb<int, 8ul>::contains(int const&) const+0x44b>
   18f1e:	e8 7d a6 fe ff       	call   35a0 <__stack_chk_fail@plt>

Disassembly of section .fini:
