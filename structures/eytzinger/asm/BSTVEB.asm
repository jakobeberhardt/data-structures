
bst-bench:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000019590 <BSTVEB<int>::contains(int const&) const>:
BSTVEB<int>::contains(int const&) const:
   19590:	f3 0f 1e fa          	endbr64
   19594:	41 57                	push   r15
   19596:	41 56                	push   r14
   19598:	41 55                	push   r13
   1959a:	49 89 fd             	mov    r13,rdi
   1959d:	41 54                	push   r12
   1959f:	55                   	push   rbp
   195a0:	53                   	push   rbx
   195a1:	48 89 f3             	mov    rbx,rsi
   195a4:	48 83 ec 18          	sub    rsp,0x18
   195a8:	80 7f 20 00          	cmp    BYTE PTR [rdi+0x20],0x0
   195ac:	74 5a                	je     19608 <BSTVEB<int>::contains(int const&) const+0x78>
   195ae:	4d 8b 55 08          	mov    r10,QWORD PTR [r13+0x8]
   195b2:	49 8b 55 10          	mov    rdx,QWORD PTR [r13+0x10]
   195b6:	31 c9                	xor    ecx,ecx
   195b8:	45 31 c0             	xor    r8d,r8d
   195bb:	4c 29 d2             	sub    rdx,r10
   195be:	48 c1 fa 02          	sar    rdx,0x2
   195c2:	eb 2b                	jmp    195ef <BSTVEB<int>::contains(int const&) const+0x5f>
   195c4:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   195c8:	8b 3b                	mov    edi,DWORD PTR [rbx]
   195ca:	41 8b 34 8a          	mov    esi,DWORD PTR [r10+rcx*4]
   195ce:	39 f7                	cmp    edi,esi
   195d0:	0f 84 7a 01 00 00    	je     19750 <BSTVEB<int>::contains(int const&) const+0x1c0>
   195d6:	4a 8d 04 02          	lea    rax,[rdx+r8*1]
   195da:	4c 8d 49 01          	lea    r9,[rcx+0x1]
   195de:	48 d1 e8             	shr    rax,1
   195e1:	39 f7                	cmp    edi,esi
   195e3:	0f 8d 7f 01 00 00    	jge    19768 <BSTVEB<int>::contains(int const&) const+0x1d8>
   195e9:	4c 89 c9             	mov    rcx,r9
   195ec:	48 89 c2             	mov    rdx,rax
   195ef:	49 39 d0             	cmp    r8,rdx
   195f2:	72 d4                	jb     195c8 <BSTVEB<int>::contains(int const&) const+0x38>
   195f4:	48 83 c4 18          	add    rsp,0x18
   195f8:	31 c0                	xor    eax,eax
   195fa:	5b                   	pop    rbx
   195fb:	5d                   	pop    rbp
   195fc:	41 5c                	pop    r12
   195fe:	41 5d                	pop    r13
   19600:	41 5e                	pop    r14
   19602:	41 5f                	pop    r15
   19604:	c3                   	ret
   19605:	0f 1f 00             	nop    DWORD PTR [rax]
   19608:	48 8b 6f 30          	mov    rbp,QWORD PTR [rdi+0x30]
   1960c:	4c 8b 7f 28          	mov    r15,QWORD PTR [rdi+0x28]
   19610:	4c 39 fd             	cmp    rbp,r15
   19613:	0f 84 f7 01 00 00    	je     19810 <BSTVEB<int>::contains(int const&) const+0x280>
   19619:	49 89 ee             	mov    r14,rbp
   1961c:	ba 3f 00 00 00       	mov    edx,0x3f
   19621:	48 89 ee             	mov    rsi,rbp
   19624:	4c 89 ff             	mov    rdi,r15
   19627:	4d 29 fe             	sub    r14,r15
   1962a:	4d 8d 67 04          	lea    r12,[r15+0x4]
   1962e:	4c 89 f0             	mov    rax,r14
   19631:	48 c1 f8 02          	sar    rax,0x2
   19635:	f3 48 0f bd c0       	lzcnt  rax,rax
   1963a:	29 c2                	sub    edx,eax
   1963c:	48 63 d2             	movsxd rdx,edx
   1963f:	48 01 d2             	add    rdx,rdx
   19642:	e8 c9 c4 fe ff       	call   5b10 <void std::__introsort_loop<__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, long, __gnu_cxx::__ops::_Iter_less_iter>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, long, __gnu_cxx::__ops::_Iter_less_iter) [clone .isra.0]>
   19647:	49 83 fe 40          	cmp    r14,0x40
   1964b:	0f 8e 2f 01 00 00    	jle    19780 <BSTVEB<int>::contains(int const&) const+0x1f0>
   19651:	4d 8d 77 40          	lea    r14,[r15+0x40]
   19655:	eb 40                	jmp    19697 <BSTVEB<int>::contains(int const&) const+0x107>
   19657:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1965e:	00 00 
   19660:	4c 89 e2             	mov    rdx,r12
   19663:	4c 29 fa             	sub    rdx,r15
   19666:	48 83 fa 04          	cmp    rdx,0x4
   1966a:	0f 8e d7 02 00 00    	jle    19947 <BSTVEB<int>::contains(int const&) const+0x3b7>
   19670:	bf 04 00 00 00       	mov    edi,0x4
   19675:	4c 89 fe             	mov    rsi,r15
   19678:	89 4c 24 08          	mov    DWORD PTR [rsp+0x8],ecx
   1967c:	48 29 d7             	sub    rdi,rdx
   1967f:	4c 01 e7             	add    rdi,r12
   19682:	e8 e9 9f fe ff       	call   3670 <memmove@plt>
   19687:	8b 4c 24 08          	mov    ecx,DWORD PTR [rsp+0x8]
   1968b:	49 83 c4 04          	add    r12,0x4
   1968f:	41 89 0f             	mov    DWORD PTR [r15],ecx
   19692:	4d 39 e6             	cmp    r14,r12
   19695:	74 3c                	je     196d3 <BSTVEB<int>::contains(int const&) const+0x143>
   19697:	41 8b 0c 24          	mov    ecx,DWORD PTR [r12]
   1969b:	41 8b 07             	mov    eax,DWORD PTR [r15]
   1969e:	4c 89 e6             	mov    rsi,r12
   196a1:	39 c1                	cmp    ecx,eax
   196a3:	7c bb                	jl     19660 <BSTVEB<int>::contains(int const&) const+0xd0>
   196a5:	41 8b 54 24 fc       	mov    edx,DWORD PTR [r12-0x4]
   196aa:	49 8d 44 24 fc       	lea    rax,[r12-0x4]
   196af:	39 d1                	cmp    ecx,edx
   196b1:	7d 15                	jge    196c8 <BSTVEB<int>::contains(int const&) const+0x138>
   196b3:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   196b8:	89 50 04             	mov    DWORD PTR [rax+0x4],edx
   196bb:	48 89 c6             	mov    rsi,rax
   196be:	48 83 e8 04          	sub    rax,0x4
   196c2:	8b 10                	mov    edx,DWORD PTR [rax]
   196c4:	39 d1                	cmp    ecx,edx
   196c6:	7c f0                	jl     196b8 <BSTVEB<int>::contains(int const&) const+0x128>
   196c8:	49 83 c4 04          	add    r12,0x4
   196cc:	89 0e                	mov    DWORD PTR [rsi],ecx
   196ce:	4d 39 e6             	cmp    r14,r12
   196d1:	75 c4                	jne    19697 <BSTVEB<int>::contains(int const&) const+0x107>
   196d3:	49 8b 7d 30          	mov    rdi,QWORD PTR [r13+0x30]
   196d7:	4d 8b 7d 28          	mov    r15,QWORD PTR [r13+0x28]
   196db:	4c 39 f5             	cmp    rbp,r14
   196de:	74 33                	je     19713 <BSTVEB<int>::contains(int const&) const+0x183>
   196e0:	41 8b 0e             	mov    ecx,DWORD PTR [r14]
   196e3:	41 8b 56 fc          	mov    edx,DWORD PTR [r14-0x4]
   196e7:	49 8d 46 fc          	lea    rax,[r14-0x4]
   196eb:	39 d1                	cmp    ecx,edx
   196ed:	0f 8d 3d 02 00 00    	jge    19930 <BSTVEB<int>::contains(int const&) const+0x3a0>
   196f3:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   196f8:	89 50 04             	mov    DWORD PTR [rax+0x4],edx
   196fb:	48 89 c6             	mov    rsi,rax
   196fe:	48 83 e8 04          	sub    rax,0x4
   19702:	8b 10                	mov    edx,DWORD PTR [rax]
   19704:	39 d1                	cmp    ecx,edx
   19706:	7c f0                	jl     196f8 <BSTVEB<int>::contains(int const&) const+0x168>
   19708:	49 83 c6 04          	add    r14,0x4
   1970c:	89 0e                	mov    DWORD PTR [rsi],ecx
   1970e:	4c 39 f5             	cmp    rbp,r14
   19711:	75 cd                	jne    196e0 <BSTVEB<int>::contains(int const&) const+0x150>
   19713:	49 8d 6d 28          	lea    rbp,[r13+0x28]
   19717:	4c 39 ff             	cmp    rdi,r15
   1971a:	0f 84 7d 02 00 00    	je     1999d <BSTVEB<int>::contains(int const&) const+0x40d>
   19720:	4c 89 fa             	mov    rdx,r15
   19723:	eb 0f                	jmp    19734 <BSTVEB<int>::contains(int const&) const+0x1a4>
   19725:	0f 1f 00             	nop    DWORD PTR [rax]
   19728:	8b 70 04             	mov    esi,DWORD PTR [rax+0x4]
   1972b:	39 72 fc             	cmp    DWORD PTR [rdx-0x4],esi
   1972e:	0f 84 74 01 00 00    	je     198a8 <BSTVEB<int>::contains(int const&) const+0x318>
   19734:	48 89 d0             	mov    rax,rdx
   19737:	48 8d 52 04          	lea    rdx,[rdx+0x4]
   1973b:	48 39 d7             	cmp    rdi,rdx
   1973e:	75 e8                	jne    19728 <BSTVEB<int>::contains(int const&) const+0x198>
   19740:	48 89 f9             	mov    rcx,rdi
   19743:	e9 b8 01 00 00       	jmp    19900 <BSTVEB<int>::contains(int const&) const+0x370>
   19748:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1974f:	00 
   19750:	48 83 c4 18          	add    rsp,0x18
   19754:	b8 01 00 00 00       	mov    eax,0x1
   19759:	5b                   	pop    rbx
   1975a:	5d                   	pop    rbp
   1975b:	41 5c                	pop    r12
   1975d:	41 5d                	pop    r13
   1975f:	41 5e                	pop    r14
   19761:	41 5f                	pop    r15
   19763:	c3                   	ret
   19764:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   19768:	4c 29 c1             	sub    rcx,r8
   1976b:	4c 8d 40 01          	lea    r8,[rax+0x1]
   1976f:	48 8d 4c 08 01       	lea    rcx,[rax+rcx*1+0x1]
   19774:	e9 76 fe ff ff       	jmp    195ef <BSTVEB<int>::contains(int const&) const+0x5f>
   19779:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   19780:	4c 39 e5             	cmp    rbp,r12
   19783:	75 3a                	jne    197bf <BSTVEB<int>::contains(int const&) const+0x22f>
   19785:	e9 02 02 00 00       	jmp    1998c <BSTVEB<int>::contains(int const&) const+0x3fc>
   1978a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   19790:	4c 89 e2             	mov    rdx,r12
   19793:	4c 29 fa             	sub    rdx,r15
   19796:	48 83 fa 04          	cmp    rdx,0x4
   1979a:	0f 8e 98 01 00 00    	jle    19938 <BSTVEB<int>::contains(int const&) const+0x3a8>
   197a0:	bf 04 00 00 00       	mov    edi,0x4
   197a5:	4c 89 fe             	mov    rsi,r15
   197a8:	48 29 d7             	sub    rdi,rdx
   197ab:	4c 01 e7             	add    rdi,r12
   197ae:	e8 bd 9e fe ff       	call   3670 <memmove@plt>
   197b3:	49 83 c4 04          	add    r12,0x4
   197b7:	45 89 37             	mov    DWORD PTR [r15],r14d
   197ba:	4c 39 e5             	cmp    rbp,r12
   197bd:	74 3e                	je     197fd <BSTVEB<int>::contains(int const&) const+0x26d>
   197bf:	45 8b 34 24          	mov    r14d,DWORD PTR [r12]
   197c3:	41 8b 07             	mov    eax,DWORD PTR [r15]
   197c6:	4c 89 e6             	mov    rsi,r12
   197c9:	41 39 c6             	cmp    r14d,eax
   197cc:	7c c2                	jl     19790 <BSTVEB<int>::contains(int const&) const+0x200>
   197ce:	41 8b 54 24 fc       	mov    edx,DWORD PTR [r12-0x4]
   197d3:	49 8d 44 24 fc       	lea    rax,[r12-0x4]
   197d8:	41 39 d6             	cmp    r14d,edx
   197db:	7d 14                	jge    197f1 <BSTVEB<int>::contains(int const&) const+0x261>
   197dd:	0f 1f 00             	nop    DWORD PTR [rax]
   197e0:	89 50 04             	mov    DWORD PTR [rax+0x4],edx
   197e3:	48 89 c6             	mov    rsi,rax
   197e6:	48 83 e8 04          	sub    rax,0x4
   197ea:	8b 10                	mov    edx,DWORD PTR [rax]
   197ec:	41 39 d6             	cmp    r14d,edx
   197ef:	7c ef                	jl     197e0 <BSTVEB<int>::contains(int const&) const+0x250>
   197f1:	49 83 c4 04          	add    r12,0x4
   197f5:	44 89 36             	mov    DWORD PTR [rsi],r14d
   197f8:	4c 39 e5             	cmp    rbp,r12
   197fb:	75 c2                	jne    197bf <BSTVEB<int>::contains(int const&) const+0x22f>
   197fd:	49 8b 7d 30          	mov    rdi,QWORD PTR [r13+0x30]
   19801:	4d 8b 7d 28          	mov    r15,QWORD PTR [r13+0x28]
   19805:	e9 09 ff ff ff       	jmp    19713 <BSTVEB<int>::contains(int const&) const+0x183>
   1980a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   19810:	48 8d 6f 28          	lea    rbp,[rdi+0x28]
   19814:	4c 8d 67 08          	lea    r12,[rdi+0x8]
   19818:	45 31 f6             	xor    r14d,r14d
   1981b:	31 c9                	xor    ecx,ecx
   1981d:	49 8b 55 08          	mov    rdx,QWORD PTR [r13+0x8]
   19821:	49 8b 45 18          	mov    rax,QWORD PTR [r13+0x18]
   19825:	48 29 d0             	sub    rax,rdx
   19828:	4c 39 f0             	cmp    rax,r14
   1982b:	72 23                	jb     19850 <BSTVEB<int>::contains(int const&) const+0x2c0>
   1982d:	48 c1 f9 02          	sar    rcx,0x2
   19831:	31 d2                	xor    edx,edx
   19833:	48 89 ee             	mov    rsi,rbp
   19836:	4c 89 e7             	mov    rdi,r12
   19839:	e8 62 fb ff ff       	call   193a0 <void help::build_veb<int>(std::vector<int, std::allocator<int> >&, std::vector<int, std::allocator<int> > const&, unsigned long, unsigned long)>
   1983e:	41 c6 45 20 01       	mov    BYTE PTR [r13+0x20],0x1
   19843:	e9 66 fd ff ff       	jmp    195ae <BSTVEB<int>::contains(int const&) const+0x1e>
   19848:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1984f:	00 
   19850:	4d 8b 7d 10          	mov    r15,QWORD PTR [r13+0x10]
   19854:	4c 89 f7             	mov    rdi,r14
   19857:	49 29 d7             	sub    r15,rdx
   1985a:	e8 11 9d fe ff       	call   3570 <operator new(unsigned long)@plt>
   1985f:	4d 8b 45 08          	mov    r8,QWORD PTR [r13+0x8]
   19863:	49 8b 55 10          	mov    rdx,QWORD PTR [r13+0x10]
   19867:	48 89 c1             	mov    rcx,rax
   1986a:	4c 29 c2             	sub    rdx,r8
   1986d:	48 85 d2             	test   rdx,rdx
   19870:	0f 8f e0 00 00 00    	jg     19956 <BSTVEB<int>::contains(int const&) const+0x3c6>
   19876:	4d 85 c0             	test   r8,r8
   19879:	0f 85 15 01 00 00    	jne    19994 <BSTVEB<int>::contains(int const&) const+0x404>
   1987f:	49 01 cf             	add    r15,rcx
   19882:	c4 e1 f9 6e c9       	vmovq  xmm1,rcx
   19887:	4c 01 f1             	add    rcx,r14
   1988a:	c4 c3 f1 22 c7 01    	vpinsrq xmm0,xmm1,r15,0x1
   19890:	c4 c1 7a 7f 04 24    	vmovdqu XMMWORD PTR [r12],xmm0
   19896:	49 89 4d 18          	mov    QWORD PTR [r13+0x18],rcx
   1989a:	49 8b 4d 30          	mov    rcx,QWORD PTR [r13+0x30]
   1989e:	49 2b 4d 28          	sub    rcx,QWORD PTR [r13+0x28]
   198a2:	eb 89                	jmp    1982d <BSTVEB<int>::contains(int const&) const+0x29d>
   198a4:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   198a8:	48 39 c7             	cmp    rdi,rax
   198ab:	0f 84 8f fe ff ff    	je     19740 <BSTVEB<int>::contains(int const&) const+0x1b0>
   198b1:	48 8d 50 08          	lea    rdx,[rax+0x8]
   198b5:	48 39 d7             	cmp    rdi,rdx
   198b8:	74 32                	je     198ec <BSTVEB<int>::contains(int const&) const+0x35c>
   198ba:	8b 30                	mov    esi,DWORD PTR [rax]
   198bc:	8b 0a                	mov    ecx,DWORD PTR [rdx]
   198be:	39 f1                	cmp    ecx,esi
   198c0:	74 21                	je     198e3 <BSTVEB<int>::contains(int const&) const+0x353>
   198c2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   198c8:	48 83 c2 04          	add    rdx,0x4
   198cc:	89 48 04             	mov    DWORD PTR [rax+0x4],ecx
   198cf:	48 8d 70 04          	lea    rsi,[rax+0x4]
   198d3:	48 39 d7             	cmp    rdi,rdx
   198d6:	74 17                	je     198ef <BSTVEB<int>::contains(int const&) const+0x35f>
   198d8:	48 89 f0             	mov    rax,rsi
   198db:	89 ce                	mov    esi,ecx
   198dd:	8b 0a                	mov    ecx,DWORD PTR [rdx]
   198df:	39 f1                	cmp    ecx,esi
   198e1:	75 e5                	jne    198c8 <BSTVEB<int>::contains(int const&) const+0x338>
   198e3:	48 83 c2 04          	add    rdx,0x4
   198e7:	48 39 d7             	cmp    rdi,rdx
   198ea:	75 ef                	jne    198db <BSTVEB<int>::contains(int const&) const+0x34b>
   198ec:	48 89 c6             	mov    rsi,rax
   198ef:	48 8d 4e 04          	lea    rcx,[rsi+0x4]
   198f3:	48 39 cf             	cmp    rdi,rcx
   198f6:	0f 84 44 fe ff ff    	je     19740 <BSTVEB<int>::contains(int const&) const+0x1b0>
   198fc:	49 89 4d 30          	mov    QWORD PTR [r13+0x30],rcx
   19900:	4c 29 f9             	sub    rcx,r15
   19903:	48 b8 fc ff ff ff ff 	movabs rax,0x7ffffffffffffffc
   1990a:	ff ff 7f 
   1990d:	4d 8d 65 08          	lea    r12,[r13+0x8]
   19911:	49 89 ce             	mov    r14,rcx
   19914:	48 39 c8             	cmp    rax,rcx
   19917:	0f 83 00 ff ff ff    	jae    1981d <BSTVEB<int>::contains(int const&) const+0x28d>
   1991d:	48 8d 3d 2f 09 00 00 	lea    rdi,[rip+0x92f]        # 1a253 <_IO_stdin_used+0x253>
   19924:	e8 77 9b fe ff       	call   34a0 <std::__throw_length_error(char const*)@plt>
   19929:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   19930:	4c 89 f6             	mov    rsi,r14
   19933:	e9 d0 fd ff ff       	jmp    19708 <BSTVEB<int>::contains(int const&) const+0x178>
   19938:	0f 85 75 fe ff ff    	jne    197b3 <BSTVEB<int>::contains(int const&) const+0x223>
   1993e:	41 89 04 24          	mov    DWORD PTR [r12],eax
   19942:	e9 6c fe ff ff       	jmp    197b3 <BSTVEB<int>::contains(int const&) const+0x223>
   19947:	0f 85 3e fd ff ff    	jne    1968b <BSTVEB<int>::contains(int const&) const+0xfb>
   1994d:	41 89 04 24          	mov    DWORD PTR [r12],eax
   19951:	e9 35 fd ff ff       	jmp    1968b <BSTVEB<int>::contains(int const&) const+0xfb>
   19956:	4c 89 c6             	mov    rsi,r8
   19959:	48 89 c7             	mov    rdi,rax
   1995c:	4c 89 44 24 08       	mov    QWORD PTR [rsp+0x8],r8
   19961:	e8 0a 9d fe ff       	call   3670 <memmove@plt>
   19966:	49 8b 75 18          	mov    rsi,QWORD PTR [r13+0x18]
   1996a:	4c 8b 44 24 08       	mov    r8,QWORD PTR [rsp+0x8]
   1996f:	48 89 c1             	mov    rcx,rax
   19972:	4c 29 c6             	sub    rsi,r8
   19975:	4c 89 c7             	mov    rdi,r8
   19978:	48 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],rcx
   1997d:	e8 fe 9b fe ff       	call   3580 <operator delete(void*, unsigned long)@plt>
   19982:	48 8b 4c 24 08       	mov    rcx,QWORD PTR [rsp+0x8]
   19987:	e9 f3 fe ff ff       	jmp    1987f <BSTVEB<int>::contains(int const&) const+0x2ef>
   1998c:	48 89 ef             	mov    rdi,rbp
   1998f:	e9 7f fd ff ff       	jmp    19713 <BSTVEB<int>::contains(int const&) const+0x183>
   19994:	49 8b 75 18          	mov    rsi,QWORD PTR [r13+0x18]
   19998:	4c 29 c6             	sub    rsi,r8
   1999b:	eb d8                	jmp    19975 <BSTVEB<int>::contains(int const&) const+0x3e5>
   1999d:	4d 8d 65 08          	lea    r12,[r13+0x8]
   199a1:	31 c9                	xor    ecx,ecx
   199a3:	e9 85 fe ff ff       	jmp    1982d <BSTVEB<int>::contains(int const&) const+0x29d>

Disassembly of section .fini:
