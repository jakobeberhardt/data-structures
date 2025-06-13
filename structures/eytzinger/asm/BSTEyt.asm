
bst-bench:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000019320 <BSTEyt<int>::contains(int const&) const>:
BSTEyt<int>::contains(int const&) const:
   19320:	f3 0f 1e fa          	endbr64
   19324:	55                   	push   rbp
   19325:	48 89 f5             	mov    rbp,rsi
   19328:	53                   	push   rbx
   19329:	48 89 fb             	mov    rbx,rdi
   1932c:	48 83 ec 08          	sub    rsp,0x8
   19330:	80 7f 38 00          	cmp    BYTE PTR [rdi+0x38],0x0
   19334:	75 05                	jne    1933b <BSTEyt<int>::contains(int const&) const+0x1b>
   19336:	e8 c5 04 ff ff       	call   9800 <BSTEyt<int>::freeze() [clone .part.0]>
   1933b:	48 8b 4b 08          	mov    rcx,QWORD PTR [rbx+0x8]
   1933f:	48 8b 53 10          	mov    rdx,QWORD PTR [rbx+0x10]
   19343:	48 29 ca             	sub    rdx,rcx
   19346:	48 c1 fa 02          	sar    rdx,0x2
   1934a:	74 1d                	je     19369 <BSTEyt<int>::contains(int const&) const+0x49>
   1934c:	8b 75 00             	mov    esi,DWORD PTR [rbp+0x0]
   1934f:	31 c0                	xor    eax,eax
   19351:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   19358:	3b 34 81             	cmp    esi,DWORD PTR [rcx+rax*4]
   1935b:	74 2a                	je     19387 <BSTEyt<int>::contains(int const&) const+0x67>
   1935d:	7d 19                	jge    19378 <BSTEyt<int>::contains(int const&) const+0x58>
   1935f:	48 8d 44 00 01       	lea    rax,[rax+rax*1+0x1]
   19364:	48 39 d0             	cmp    rax,rdx
   19367:	72 ef                	jb     19358 <BSTEyt<int>::contains(int const&) const+0x38>
   19369:	48 83 c4 08          	add    rsp,0x8
   1936d:	31 c0                	xor    eax,eax
   1936f:	5b                   	pop    rbx
   19370:	5d                   	pop    rbp
   19371:	c3                   	ret
   19372:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   19378:	48 8d 44 00 02       	lea    rax,[rax+rax*1+0x2]
   1937d:	48 39 d0             	cmp    rax,rdx
   19380:	73 e7                	jae    19369 <BSTEyt<int>::contains(int const&) const+0x49>
   19382:	3b 34 81             	cmp    esi,DWORD PTR [rcx+rax*4]
   19385:	75 d6                	jne    1935d <BSTEyt<int>::contains(int const&) const+0x3d>
   19387:	48 83 c4 08          	add    rsp,0x8
   1938b:	b8 01 00 00 00       	mov    eax,0x1
   19390:	5b                   	pop    rbx
   19391:	5d                   	pop    rbp
   19392:	c3                   	ret

Disassembly of section .fini:
