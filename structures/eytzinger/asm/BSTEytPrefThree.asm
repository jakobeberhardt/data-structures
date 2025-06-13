
bst-bench:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000019090 <BSTEytPrefThree<int>::contains(int const&) const>:
BSTEytPrefThree<int>::contains(int const&) const:
   19090:	f3 0f 1e fa          	endbr64
   19094:	41 54                	push   r12
   19096:	55                   	push   rbp
   19097:	48 89 fd             	mov    rbp,rdi
   1909a:	53                   	push   rbx
   1909b:	48 89 f3             	mov    rbx,rsi
   1909e:	80 7f 38 00          	cmp    BYTE PTR [rdi+0x38],0x0
   190a2:	75 05                	jne    190a9 <BSTEytPrefThree<int>::contains(int const&) const+0x19>
   190a4:	e8 57 07 ff ff       	call   9800 <BSTEyt<int>::freeze() [clone .part.0]>
   190a9:	48 8b 55 08          	mov    rdx,QWORD PTR [rbp+0x8]
   190ad:	48 8b 45 10          	mov    rax,QWORD PTR [rbp+0x10]
   190b1:	31 f6                	xor    esi,esi
   190b3:	48 29 d0             	sub    rax,rdx
   190b6:	48 c1 f8 02          	sar    rax,0x2
   190ba:	e9 e9 00 00 00       	jmp    191a8 <BSTEytPrefThree<int>::contains(int const&) const+0x118>
   190bf:	90                   	nop
   190c0:	48 8d 0c 36          	lea    rcx,[rsi+rsi*1]
   190c4:	4c 8d 46 01          	lea    r8,[rsi+0x1]
   190c8:	4c 8d 49 01          	lea    r9,[rcx+0x1]
   190cc:	48 8d 71 02          	lea    rsi,[rcx+0x2]
   190d0:	49 39 c1             	cmp    r9,rax
   190d3:	73 05                	jae    190da <BSTEytPrefThree<int>::contains(int const&) const+0x4a>
   190d5:	42 0f 18 1c 8a       	prefetcht2 BYTE PTR [rdx+r9*4]
   190da:	4a 8d 0c c5 00 00 00 	lea    rcx,[r8*8+0x0]
   190e1:	00 
   190e2:	48 39 c6             	cmp    rsi,rax
   190e5:	73 04                	jae    190eb <BSTEytPrefThree<int>::contains(int const&) const+0x5b>
   190e7:	0f 18 1c 0a          	prefetcht2 BYTE PTR [rdx+rcx*1]
   190eb:	4a 8d 3c 85 00 00 00 	lea    rdi,[r8*4+0x0]
   190f2:	00 
   190f3:	4f 8d 5c 09 01       	lea    r11,[r9+r9*1+0x1]
   190f8:	4c 8d 57 01          	lea    r10,[rdi+0x1]
   190fc:	48 8d 6f 02          	lea    rbp,[rdi+0x2]
   19100:	49 39 c3             	cmp    r11,rax
   19103:	73 05                	jae    1910a <BSTEytPrefThree<int>::contains(int const&) const+0x7a>
   19105:	42 0f 18 1c 9a       	prefetcht2 BYTE PTR [rdx+r11*4]
   1910a:	48 39 c7             	cmp    rdi,rax
   1910d:	73 0c                	jae    1911b <BSTEytPrefThree<int>::contains(int const&) const+0x8b>
   1910f:	4d 89 c4             	mov    r12,r8
   19112:	49 c1 e4 04          	shl    r12,0x4
   19116:	42 0f 18 1c 22       	prefetcht2 BYTE PTR [rdx+r12*1]
   1911b:	49 39 c2             	cmp    r10,rax
   1911e:	73 05                	jae    19125 <BSTEytPrefThree<int>::contains(int const&) const+0x95>
   19120:	42 0f 18 1c 92       	prefetcht2 BYTE PTR [rdx+r10*4]
   19125:	48 39 c5             	cmp    rbp,rax
   19128:	73 04                	jae    1912e <BSTEytPrefThree<int>::contains(int const&) const+0x9e>
   1912a:	0f 18 1c aa          	prefetcht2 BYTE PTR [rdx+rbp*4]
   1912e:	4f 8d 5c 1b 01       	lea    r11,[r11+r11*1+0x1]
   19133:	49 39 c3             	cmp    r11,rax
   19136:	73 05                	jae    1913d <BSTEytPrefThree<int>::contains(int const&) const+0xad>
   19138:	42 0f 18 1c 9a       	prefetcht2 BYTE PTR [rdx+r11*4]
   1913d:	48 39 c1             	cmp    rcx,rax
   19140:	73 09                	jae    1914b <BSTEytPrefThree<int>::contains(int const&) const+0xbb>
   19142:	49 c1 e0 05          	shl    r8,0x5
   19146:	42 0f 18 1c 02       	prefetcht2 BYTE PTR [rdx+r8*1]
   1914b:	48 ff c1             	inc    rcx
   1914e:	48 39 c1             	cmp    rcx,rax
   19151:	73 04                	jae    19157 <BSTEytPrefThree<int>::contains(int const&) const+0xc7>
   19153:	0f 18 1c 8a          	prefetcht2 BYTE PTR [rdx+rcx*4]
   19157:	4b 8d 0c 12          	lea    rcx,[r10+r10*1]
   1915b:	48 39 c1             	cmp    rcx,rax
   1915e:	73 05                	jae    19165 <BSTEytPrefThree<int>::contains(int const&) const+0xd5>
   19160:	42 0f 18 1c d2       	prefetcht2 BYTE PTR [rdx+r10*8]
   19165:	4c 8d 41 01          	lea    r8,[rcx+0x1]
   19169:	49 39 c0             	cmp    r8,rax
   1916c:	73 05                	jae    19173 <BSTEytPrefThree<int>::contains(int const&) const+0xe3>
   1916e:	42 0f 18 1c 82       	prefetcht2 BYTE PTR [rdx+r8*4]
   19173:	4c 8d 41 02          	lea    r8,[rcx+0x2]
   19177:	49 39 c0             	cmp    r8,rax
   1917a:	73 04                	jae    19180 <BSTEytPrefThree<int>::contains(int const&) const+0xf0>
   1917c:	0f 18 1c ea          	prefetcht2 BYTE PTR [rdx+rbp*8]
   19180:	4c 8d 41 03          	lea    r8,[rcx+0x3]
   19184:	49 39 c0             	cmp    r8,rax
   19187:	73 05                	jae    1918e <BSTEytPrefThree<int>::contains(int const&) const+0xfe>
   19189:	42 0f 18 1c 82       	prefetcht2 BYTE PTR [rdx+r8*4]
   1918e:	48 83 c1 04          	add    rcx,0x4
   19192:	48 39 c1             	cmp    rcx,rax
   19195:	73 05                	jae    1919c <BSTEytPrefThree<int>::contains(int const&) const+0x10c>
   19197:	0f 18 5c fa 18       	prefetcht2 BYTE PTR [rdx+rdi*8+0x18]
   1919c:	8b 7c 3a fc          	mov    edi,DWORD PTR [rdx+rdi*1-0x4]
   191a0:	39 3b                	cmp    DWORD PTR [rbx],edi
   191a2:	74 1c                	je     191c0 <BSTEytPrefThree<int>::contains(int const&) const+0x130>
   191a4:	49 0f 4c f1          	cmovl  rsi,r9
   191a8:	48 39 c6             	cmp    rsi,rax
   191ab:	0f 82 0f ff ff ff    	jb     190c0 <BSTEytPrefThree<int>::contains(int const&) const+0x30>
   191b1:	5b                   	pop    rbx
   191b2:	31 c0                	xor    eax,eax
   191b4:	5d                   	pop    rbp
   191b5:	41 5c                	pop    r12
   191b7:	c3                   	ret
   191b8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   191bf:	00 
   191c0:	5b                   	pop    rbx
   191c1:	b8 01 00 00 00       	mov    eax,0x1
   191c6:	5d                   	pop    rbp
   191c7:	41 5c                	pop    r12
   191c9:	c3                   	ret

Disassembly of section .fini:
