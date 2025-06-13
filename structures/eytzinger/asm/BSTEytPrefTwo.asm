
bst-bench:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .plt.sec:

Disassembly of section .text:

00000000000191d0 <BSTEytPrefTwo<int>::contains(int const&) const>:
BSTEytPrefTwo<int>::contains(int const&) const:
   191d0:	f3 0f 1e fa          	endbr64
   191d4:	55                   	push   rbp
   191d5:	48 89 fd             	mov    rbp,rdi
   191d8:	53                   	push   rbx
   191d9:	48 89 f3             	mov    rbx,rsi
   191dc:	48 83 ec 08          	sub    rsp,0x8
   191e0:	80 7f 38 00          	cmp    BYTE PTR [rdi+0x38],0x0
   191e4:	75 05                	jne    191eb <BSTEytPrefTwo<int>::contains(int const&) const+0x1b>
   191e6:	e8 15 06 ff ff       	call   9800 <BSTEyt<int>::freeze() [clone .part.0]>
   191eb:	48 8b 75 08          	mov    rsi,QWORD PTR [rbp+0x8]
   191ef:	48 8b 55 10          	mov    rdx,QWORD PTR [rbp+0x10]
   191f3:	31 c9                	xor    ecx,ecx
   191f5:	48 29 f2             	sub    rdx,rsi
   191f8:	48 c1 fa 02          	sar    rdx,0x2
   191fc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   19200:	48 89 c8             	mov    rax,rcx
   19203:	48 39 d0             	cmp    rax,rdx
   19206:	73 65                	jae    1926d <BSTEytPrefTwo<int>::contains(int const&) const+0x9d>
   19208:	48 8d 0c 00          	lea    rcx,[rax+rax*1]
   1920c:	48 8d 79 01          	lea    rdi,[rcx+0x1]
   19210:	48 83 c1 02          	add    rcx,0x2
   19214:	48 39 d7             	cmp    rdi,rdx
   19217:	73 04                	jae    1921d <BSTEytPrefTwo<int>::contains(int const&) const+0x4d>
   19219:	0f 18 1c be          	prefetcht2 BYTE PTR [rsi+rdi*4]
   1921d:	48 39 d1             	cmp    rcx,rdx
   19220:	73 05                	jae    19227 <BSTEytPrefTwo<int>::contains(int const&) const+0x57>
   19222:	0f 18 5c c6 08       	prefetcht2 BYTE PTR [rsi+rax*8+0x8]
   19227:	48 c1 e0 02          	shl    rax,0x2
   1922b:	4c 8d 50 03          	lea    r10,[rax+0x3]
   1922f:	4c 8d 48 05          	lea    r9,[rax+0x5]
   19233:	4c 8d 40 07          	lea    r8,[rax+0x7]
   19237:	49 39 d2             	cmp    r10,rdx
   1923a:	73 05                	jae    19241 <BSTEytPrefTwo<int>::contains(int const&) const+0x71>
   1923c:	42 0f 18 1c 96       	prefetcht2 BYTE PTR [rsi+r10*4]
   19241:	49 39 d1             	cmp    r9,rdx
   19244:	73 0c                	jae    19252 <BSTEytPrefTwo<int>::contains(int const&) const+0x82>
   19246:	4e 8d 0c 8e          	lea    r9,[rsi+r9*4]
   1924a:	41 0f 18 19          	prefetcht2 BYTE PTR [r9]
   1924e:	41 0f 18 19          	prefetcht2 BYTE PTR [r9]
   19252:	49 39 d0             	cmp    r8,rdx
   19255:	73 05                	jae    1925c <BSTEytPrefTwo<int>::contains(int const&) const+0x8c>
   19257:	42 0f 18 1c 86       	prefetcht2 BYTE PTR [rsi+r8*4]
   1925c:	8b 04 06             	mov    eax,DWORD PTR [rsi+rax*1]
   1925f:	39 03                	cmp    DWORD PTR [rbx],eax
   19261:	74 1d                	je     19280 <BSTEytPrefTwo<int>::contains(int const&) const+0xb0>
   19263:	7d 9b                	jge    19200 <BSTEytPrefTwo<int>::contains(int const&) const+0x30>
   19265:	48 89 f8             	mov    rax,rdi
   19268:	48 39 d0             	cmp    rax,rdx
   1926b:	72 9b                	jb     19208 <BSTEytPrefTwo<int>::contains(int const&) const+0x38>
   1926d:	48 83 c4 08          	add    rsp,0x8
   19271:	31 c0                	xor    eax,eax
   19273:	5b                   	pop    rbx
   19274:	5d                   	pop    rbp
   19275:	c3                   	ret
   19276:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1927d:	00 00 00 
   19280:	48 83 c4 08          	add    rsp,0x8
   19284:	b8 01 00 00 00       	mov    eax,0x1
   19289:	5b                   	pop    rbx
   1928a:	5d                   	pop    rbp
   1928b:	c3                   	ret

Disassembly of section .fini:
