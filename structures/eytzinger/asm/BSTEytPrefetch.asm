
bst-bench:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000019290 <BSTEytPref<int>::contains(int const&) const>:
BSTEytPref<int>::contains(int const&) const:
   19290:	f3 0f 1e fa          	endbr64
   19294:	55                   	push   rbp
   19295:	48 89 fd             	mov    rbp,rdi
   19298:	53                   	push   rbx
   19299:	48 89 f3             	mov    rbx,rsi
   1929c:	48 83 ec 08          	sub    rsp,0x8
   192a0:	80 7f 38 00          	cmp    BYTE PTR [rdi+0x38],0x0
   192a4:	75 05                	jne    192ab <BSTEytPref<int>::contains(int const&) const+0x1b>
   192a6:	e8 55 05 ff ff       	call   9800 <BSTEyt<int>::freeze() [clone .part.0]>
   192ab:	4c 8b 45 08          	mov    r8,QWORD PTR [rbp+0x8]
   192af:	48 8b 4d 10          	mov    rcx,QWORD PTR [rbp+0x10]
   192b3:	31 c0                	xor    eax,eax
   192b5:	4c 29 c1             	sub    rcx,r8
   192b8:	48 c1 f9 02          	sar    rcx,0x2
   192bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   192c0:	48 89 c2             	mov    rdx,rax
   192c3:	48 39 ca             	cmp    rdx,rcx
   192c6:	73 33                	jae    192fb <BSTEytPref<int>::contains(int const&) const+0x6b>
   192c8:	48 8d 04 12          	lea    rax,[rdx+rdx*1]
   192cc:	48 8d 78 01          	lea    rdi,[rax+0x1]
   192d0:	48 83 c0 02          	add    rax,0x2
   192d4:	48 39 cf             	cmp    rdi,rcx
   192d7:	73 05                	jae    192de <BSTEytPref<int>::contains(int const&) const+0x4e>
   192d9:	41 0f 18 1c b8       	prefetcht2 BYTE PTR [r8+rdi*4]
   192de:	48 39 c8             	cmp    rax,rcx
   192e1:	73 06                	jae    192e9 <BSTEytPref<int>::contains(int const&) const+0x59>
   192e3:	41 0f 18 5c d0 08    	prefetcht2 BYTE PTR [r8+rdx*8+0x8]
   192e9:	41 8b 34 90          	mov    esi,DWORD PTR [r8+rdx*4]
   192ed:	39 33                	cmp    DWORD PTR [rbx],esi
   192ef:	74 17                	je     19308 <BSTEytPref<int>::contains(int const&) const+0x78>
   192f1:	7d cd                	jge    192c0 <BSTEytPref<int>::contains(int const&) const+0x30>
   192f3:	48 89 fa             	mov    rdx,rdi
   192f6:	48 39 ca             	cmp    rdx,rcx
   192f9:	72 cd                	jb     192c8 <BSTEytPref<int>::contains(int const&) const+0x38>
   192fb:	48 83 c4 08          	add    rsp,0x8
   192ff:	31 c0                	xor    eax,eax
   19301:	5b                   	pop    rbx
   19302:	5d                   	pop    rbp
   19303:	c3                   	ret
   19304:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   19308:	48 83 c4 08          	add    rsp,0x8
   1930c:	b8 01 00 00 00       	mov    eax,0x1
   19311:	5b                   	pop    rbx
   19312:	5d                   	pop    rbp
   19313:	c3                   	ret

Disassembly of section .fini:
